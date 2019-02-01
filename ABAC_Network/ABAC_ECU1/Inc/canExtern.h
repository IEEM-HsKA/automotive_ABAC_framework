/**
*		@file	canExtern.h
*		@author	ABC
*		@date	07.11.2018
*
*		Generated Code from ABAC_Com.dbc
*/

#include "CMessage.h"
#include "CSignal.h"

/* -------------------------- ID: 0x610 ----- Name: ABAC_InformationMsg -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> ABAC_InformationMsg_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> ABAC_InformationMsg_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> ABAC_InformationMsg_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> ABAC_InformationMsg_ABAC_Command;


//Define MessageObj
extern CMessage<uint64_t> ABAC_InformationMsg;

/* -------------------------- ID: 0x700 ----- Name: ECU1_ABAC_ECU_Resp -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> ECU1_ABAC_ECU_Resp_ABAC_Attribute_ID;
extern CSignalVar1<uint16_t> ECU1_ABAC_ECU_Resp_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> ECU1_ABAC_ECU_Resp_ABAC_ResourceResp;


//Define MessageObj
extern CMessage<uint64_t> ECU1_ABAC_ECU_Resp;

/* -------------------------- ID: 0x710 ----- Name: ECU1_Send_Nonce -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> ECU1_Send_Nonce_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> ECU1_Send_Nonce_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> ECU1_Send_Nonce_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> ECU1_Send_Nonce_ABAC_Command;
extern CSignalVar1<uint16_t> ECU1_Send_Nonce_ABAC_Nonce;


//Define MessageObj
extern CMessage<uint64_t> ECU1_Send_Nonce;

/* -------------------------- ID: 0x701 ----- Name: ECU2_ABAC_ECU_Resp -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> ECU2_ABAC_ECU_Resp_ABAC_Attribute_ID;
extern CSignalVar1<uint16_t> ECU2_ABAC_ECU_Resp_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> ECU2_ABAC_ECU_Resp_ABAC_ResourceResp;


//Define MessageObj
extern CMessage<uint64_t> ECU2_ABAC_ECU_Resp;

/* -------------------------- ID: 0x711 ----- Name: ECU2_Send_Nonce -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> ECU2_Send_Nonce_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> ECU2_Send_Nonce_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> ECU2_Send_Nonce_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> ECU2_Send_Nonce_ABAC_Command;
extern CSignalVar1<uint16_t> ECU2_Send_Nonce_ABAC_Nonce;


//Define MessageObj
extern CMessage<uint64_t> ECU2_Send_Nonce;

/* -------------------------- ID: 0x350 ----- Name: ECU_1_Resource -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint8_t> ECU_1_Resource_Counter;


//Define MessageObj
extern CMessage<uint8_t> ECU_1_Resource;

/* -------------------------- ID: 0x325 ----- Name: ECU_2_Resource -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint8_t> ECU_2_Resource_Counter;


//Define MessageObj
extern CMessage<uint8_t> ECU_2_Resource;

/* -------------------------- ID: 0x601 ----- Name: Extern_ABAC_AccessMsg -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> Extern_ABAC_AccessMsg_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> Extern_ABAC_AccessMsg_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> Extern_ABAC_AccessMsg_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> Extern_ABAC_AccessMsg_ABAC_Command;


//Define MessageObj
extern CMessage<uint64_t> Extern_ABAC_AccessMsg;

/* -------------------------- ID: 0x620 ----- Name: PDP_ABAC_DecisionMsg -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> PDP_ABAC_DecisionMsg_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> PDP_ABAC_DecisionMsg_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> PDP_ABAC_DecisionMsg_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> PDP_ABAC_DecisionMsg_ABAC_Command;
extern CSignalVar1<uint8_t> PDP_ABAC_DecisionMsg_ABAC_Decision;


//Define MessageObj
extern CMessage<uint64_t> PDP_ABAC_DecisionMsg;

/* -------------------------- ID: 0x625 ----- Name: PDP_ABAC_Get_Nonce -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> PDP_ABAC_Get_Nonce_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> PDP_ABAC_Get_Nonce_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> PDP_ABAC_Get_Nonce_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> PDP_ABAC_Get_Nonce_ABAC_Command;


//Define MessageObj
extern CMessage<uint64_t> PDP_ABAC_Get_Nonce;

/* -------------------------- ID: 0x632 ----- Name: PDP_ABAC_Lock_ResourceMsg -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> PDP_ABAC_Lock_ResourceMsg_ABAC_Command;


//Define MessageObj
extern CMessage<uint64_t> PDP_ABAC_Lock_ResourceMsg;

/* -------------------------- ID: 0x631 ----- Name: PDP_ABAC_Unlock_ResourceMsg -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> PDP_ABAC_Unlock_ResourceMsg_ABAC_Command;
extern CSignalVar1<uint16_t> PDP_ABAC_Unlock_ResourceMsg_ABAC_Key;


//Define MessageObj
extern CMessage<uint64_t> PDP_ABAC_Unlock_ResourceMsg;

/* -------------------------- ID: 0x600 ----- Name: PEP_ABAC_AccessMsg -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> PEP_ABAC_AccessMsg_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> PEP_ABAC_AccessMsg_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> PEP_ABAC_AccessMsg_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> PEP_ABAC_AccessMsg_ABAC_Command;


//Define MessageObj
extern CMessage<uint64_t> PEP_ABAC_AccessMsg;

/* -------------------------- ID: 0x621 ----- Name: PEP_ABAC_DecisionMsg -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> PEP_ABAC_DecisionMsg_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> PEP_ABAC_DecisionMsg_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> PEP_ABAC_DecisionMsg_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> PEP_ABAC_DecisionMsg_ABAC_Command;
extern CSignalVar1<uint8_t> PEP_ABAC_DecisionMsg_ABAC_Decision;


//Define MessageObj
extern CMessage<uint64_t> PEP_ABAC_DecisionMsg;

/* -------------------------- ID: 0x633 ----- Name: PEP_ABAC_Lock_ResourceMsg -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> PEP_ABAC_Lock_ResourceMsg_ABAC_Command;


//Define MessageObj
extern CMessage<uint64_t> PEP_ABAC_Lock_ResourceMsg;

/* -------------------------- ID: 0x630 ----- Name: PEP_ABAC_Unlock_ResourceMsg -------------------------- */
//Define SignalObjs
extern CSignalVar1<uint16_t> PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_ID;
extern CSignalVar1<uint8_t> PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Type;
extern CSignalVar1<uint16_t> PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Value;
extern CSignalVar1<uint8_t> PEP_ABAC_Unlock_ResourceMsg_ABAC_Command;
extern CSignalVar1<uint16_t> PEP_ABAC_Unlock_ResourceMsg_ABAC_Key;


//Define MessageObj
extern CMessage<uint64_t> PEP_ABAC_Unlock_ResourceMsg;

