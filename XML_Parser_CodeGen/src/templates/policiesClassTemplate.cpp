class Policies : public ABAC_Base {
	public:
		Policies(bool (*TxMsgHandle)(uint8_t *)) : {{ MEMBER_ENVIROMENT }}(0, 0, ENVIRONMENT) {
			TxABACmsgHandle = TxMsgHandle;
			mIsPDP = false;
		}
		Policies(bool (*TxMsgHandle)(uint8_t *), bool pIsPDP_) : {{ memberEnviroment }}(0, 0, ENVIRONMENT) {
			TxABACmsgHandle = TxMsgHandle;
			mIsPDP = pIsPDP_;
		}
		void setInformation(Attribute pInformation_) {
			const Attribute {{ LOCAL_ENVIROMENT_ATTR }};
			if({{ LOCAL_ENVIROMENT }}.getID() == pInformation_.getID()){
				{{ MEMBER_ENVIROMENT }} = pInformation_;
			}
		}
	private:
		Decision PolicyEvaluation() {
			Decision policyResponse;
			policyResponse = {{ POLICY_NAME }}();
			return policyResponse;
		}

{{ POLICIES }}

{{ RULES }}

	Attribute {{ MEMBER_ENVIROMENT }};

};
