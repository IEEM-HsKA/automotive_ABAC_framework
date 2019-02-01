/*
 * ABAC.h
 *
 *  Created on: 02.10.2018
 *  Author: Alexander Duda
 */

#ifndef __ABAC_H_
#define __ABAC_H_
#include <Attribute.h>


class ABAC_Base {
	public:
		/*!---------------------------------------------
		* \brief	Extracts Command and Attributes from incoming ABAC Frame
		* 			and assign values to associated member
		*
		* \param *pFrame_ 	pointer to uint8_t Frame Array
		*//*--------------------------------------------*/
		void RxABACmsgHandle(const uint8_t *pFrame_);

		/*!---------------------------------------------
		* \brief	Send request from Requester to PEP  or
		* 			from PEP to PDP
		*
		* \param pAccessSubject_	Subject Attribute, e.g. role_mechanic
		* \param pAction_			Action Attribute, e.g. read
		* \param pResource_			Resource Attribute, e.g. diagnosis_data
		*//*--------------------------------------------*/
		void sendRequest(Attribute pAccessSubject_, Attribute pAction_, Attribute pResource_);

		/*!---------------------------------------------
		* \brief	Forward received request from PEP to PDP,
		* 			Attributes are already assigned by RxABACmsgHandle
		*
		*//*--------------------------------------------*/
		void sendRequest();

		/*!---------------------------------------------
		* \brief	Testing method to evaluate Policies without PEP and Request
		*
		* \param pAccessSubject_	Subject Attribute, e.g. role_mechanic
		* \param pAction_			Action Attribute, e.g. read
		* \param pResource_			Resource Attribute, e.g. diagnosis_data
		*
		* \return Decision
		*
		* \retval 0xFF Indeterminate
		* \retval 0x01 Not applicable
		* \retval 0x02 Deny
		* \retval 0x03 Permit
		*//*--------------------------------------------*/
		Decision request(Attribute pAccessSubject_, Attribute pAction_, Attribute pResource_);

		/*!---------------------------------------------
		* \brief	Evaluate Policies
		*
		* \return Decision
		*
		* \retval 0xFF Indeterminate
		* \retval 0x01 Not applicable
		* \retval 0x02 Deny
		* \retval 0x03 Permit
		*//*--------------------------------------------*/
		Decision request();

		/*!---------------------------------------------
		* \brief	Set/Unset System as PDP
		*
		*//*--------------------------------------------*/
		bool isPDP(bool pIsPDP_) { mIsPDP = pIsPDP_; return true; }
	protected:
		bool (*TxABACmsgHandle)(uint8_t *);
		/*!---------------------------------------------
		* \brief	Virtual method for policy evaluation
		*
		* \return Decision
		*
		* \retval 0xFF Indeterminate
		* \retval 0x01 Not applicable
		* \retval 0x02 Deny
		* \retval 0x03 Permit
		*//*--------------------------------------------*/
		virtual Decision PolicyEvaluation() = 0;
		/*!---------------------------------------------
		* \brief	Virtual method for setting additional informations members
		*
		* \param pInformation_	Additional Attribute,e.g Environment Attributes
		*//*--------------------------------------------*/
		virtual void setInformation(Attribute pInformation_) = 0;
		/*!---------------------------------------------
		* \brief	Send Decision made by the PDP to PEP or Requester
		*
		* \param pDecision_	Decision from policy evaluation
		*//*--------------------------------------------*/
		void sendDecision(Decision pDecision_);
		/*!---------------------------------------------
		* \brief	Sends Unlock request to resource
		*
		* \param pResource_	Resource to be unlocked
		* \param pKey_	Key to unlock the resource, combination of nonce and private key
		*//*--------------------------------------------*/
		void sendResourceUnlock(Attribute pResource_,uint16_t pKey_);

		/*!---------------------------------------------
		* \brief	Sends Lock request to resource
		*
		**//*--------------------------------------------*/
		void sendResourceLock(Attribute pResource_);

		/*!---------------------------------------------
		* \brief	Requests nonce from requested resource
		*
		*//*--------------------------------------------*/
		void getNonce();

		Attribute mAccessSubject;
		Attribute mAction;
		Attribute mResourceType;
		Attribute mEnviroment;
		uint16_t mNonce;
		bool mIsPDP = false;
	private:
		bool nonceRequested = false;
		/*!---------------------------------------------
		* \brief	Resets all key attributes (mAccessSubject, mAction, mResourceType)
		*
		*//*--------------------------------------------*/
		void clear();

		/*!---------------------------------------------
		* \brief 	Checks if any of the key attributes (mAccessSubject, mAction, mResourceType)
		* 			is empty ID = 0, Value = 0, Category = 0
		*
		* \return bool
		*
		* \retval TRUE one or more key attribute is empty
		* \retval FALSE all attributes are valid/not empty
		*//*--------------------------------------------*/
		bool checkKeyAttributes();

		/*!---------------------------------------------
		* \brief 	Converts Attirbute to 5 Byte Array and
		*  			assigns to correct position in ABAC Frame
		*
		* \param pAttribute_	Attribute to be assigned to the Frame
		* \param *rOut_Frame_	pointer to ABAC Frame
		*//*--------------------------------------------*/
		void attributeToFrame(Attribute pAttribute_, uint8_t *rOut_Frame_);
};




class Policies : public ABAC_Base {
	public:
		Policies(bool (*TxMsgHandle)(uint8_t *)) : mTesterConnectionStatus(0, 0, ENVIRONMENT) {
			TxABACmsgHandle = TxMsgHandle;
			mIsPDP = false;
		}
		Policies(bool (*TxMsgHandle)(uint8_t *), bool pIsPDP_) : mTesterConnectionStatus(0, 0, ENVIRONMENT) {
			TxABACmsgHandle = TxMsgHandle;
			mIsPDP = pIsPDP_;
		}
		void setInformation(Attribute pInformation_) {
			const Attribute testerConnectionStatus_connected(0xE6D1, 0x06AA, ENVIRONMENT);
			if(testerConnectionStatus_connected.getID() == pInformation_.getID()){
				mTesterConnectionStatus = pInformation_;
			}
		}
	private:
		Decision PolicyEvaluation() {
			Decision policyResponse;
			policyResponse = AccessDiagnosisData();
			if(policyResponse == PERMIT) { return policyResponse; }
			policyResponse = ExtendedAccessForEngineersAndTechnician();
			return policyResponse;
		}

		Decision AccessDiagnosisData() {
			const Attribute role_engineer(0x29A7, 0x9D12, ACCESS_SUBJECT);
			const Attribute role_technician(0x29A7, 0xEB91, ACCESS_SUBJECT);
			const Attribute role_mechanic(0x29A7, 0xBCD8, ACCESS_SUBJECT);

			if (role_engineer == mAccessSubject || role_technician == mAccessSubject || role_mechanic == mAccessSubject ) {
				if (readDiagnosis()) {
					return PERMIT;
				}
				else {
					return DENY;
				}
			}
			else {
				return NOT_APPLICABLE;
			}
			return NOT_APPLICABLE;
		}

		Decision ExtendedAccessForEngineersAndTechnician() {
			const Attribute role_engineer(0x29A7, 0x9D12, ACCESS_SUBJECT);
			const Attribute role_technician(0x29A7, 0xEB91, ACCESS_SUBJECT);
			if (role_engineer == mAccessSubject || role_technician == mAccessSubject ) {
				if (permitExtendedAccess()) {
					return PERMIT;
				}
				else {
					return DENY;
				}
			}
			else {
				return NOT_APPLICABLE;
			}
			return NOT_APPLICABLE;
		}

		bool readDiagnosis() {
			const Attribute action_read(0x418C, 0xECAE, ACTION);
			const Attribute testerConnectionStatus_connected(0xE6D1, 0x06AA, ENVIRONMENT);
			const Attribute resourceType_diagnosisData(0x6F47, 0x2092, RESOURCE);

			if (action_read == mAction && testerConnectionStatus_connected == mTesterConnectionStatus && resourceType_diagnosisData == mResourceType ) {
				return true; //Permit
			}
			else {
				return false; //Deny
			}
		}

		bool permitExtendedAccess() {
			const Attribute action_extendedAccess(0x418C, 0x8339, ACTION);
			const Attribute testerConnectionStatus_connected(0xE6D1, 0x06AA, ENVIRONMENT);
			const Attribute resourceType_parameters(0x6F47, 0x166E, RESOURCE);

			if (action_extendedAccess == mAction && testerConnectionStatus_connected == mTesterConnectionStatus && resourceType_parameters == mResourceType ) {
				return true; //Permit
			}
			else {
				return false; //Deny
			}
		}

		Attribute mTesterConnectionStatus;
};


#endif /* __ABAC_H_ */

