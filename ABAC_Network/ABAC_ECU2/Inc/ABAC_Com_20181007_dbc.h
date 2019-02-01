/**
*		@file	ABAC_Com_20181007_dbc.h
*		@author	Alexander Duda
*		@date	07.10.2018
*
*		Generated Code from ABAC_Com.dbc
*/
#ifndef __ABAC_Com_20181007_DBC_H
#define __ABAC_Com_20181007_DBC_H

//InitFunction Prototypes
void pushABAC_InformationMsg();
void pushECU1_ABAC_ECU_Resp();
void pushECU1_Send_Nonce();
void pushECU2_ABAC_ECU_Resp();
void pushECU2_Send_Nonce();
void pushECU_1_Resource();
void pushECU_2_Resource();
void pushExtern_ABAC_AccessMsg();
void pushPDP_ABAC_DecisionMsg();
void pushPDP_ABAC_Get_Nonce();
void pushPDP_ABAC_Lock_ResourceMsg();
void pushPDP_ABAC_Unlock_ResourceMsg();
void pushPEP_ABAC_AccessMsg();
void pushPEP_ABAC_DecisionMsg();
void pushPEP_ABAC_Lock_ResourceMsg();
void pushPEP_ABAC_Unlock_ResourceMsg();

//UpdateFunction Prototypes
void pullABAC_InformationMsg();
void pullECU1_ABAC_ECU_Resp();
void pullECU1_Send_Nonce();
void pullECU2_ABAC_ECU_Resp();
void pullECU2_Send_Nonce();
void pullECU_1_Resource();
void pullECU_2_Resource();
void pullExtern_ABAC_AccessMsg();
void pullPDP_ABAC_DecisionMsg();
void pullPDP_ABAC_Get_Nonce();
void pullPDP_ABAC_Lock_ResourceMsg();
void pullPDP_ABAC_Unlock_ResourceMsg();
void pullPEP_ABAC_AccessMsg();
void pullPEP_ABAC_DecisionMsg();
void pullPEP_ABAC_Lock_ResourceMsg();
void pullPEP_ABAC_Unlock_ResourceMsg();

#endif /* ABAC_Com_20181007_DBC_H */

