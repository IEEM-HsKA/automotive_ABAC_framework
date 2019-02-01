/**
*		@file	ABAC_Com_20181007_dbc.cpp
*		@author	Alexander Duda
*		@date	07.10.2018
*
*		Generated Code from ABAC_Com.dbc
*/

#include "CMessage.h"
#include "CSignal.h"
#include "ABAC_Com_20181007_dbc.h"

/* -------------------------- ID: 0x610 ----- Name: ABAC_InformationMsg -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> ABAC_InformationMsg_ABAC_Attribute_ID(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> ABAC_InformationMsg_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> ABAC_InformationMsg_ABAC_Attribute_Value(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> ABAC_InformationMsg_ABAC_Command(0,7,8,100,1,0,0,255,0);


//Define MessageObj
CMessage<uint64_t> ABAC_InformationMsg(0x610,0,6,0,100,10,10,10,0);

void pushABAC_InformationMsg() {
	ABAC_InformationMsg.push<uint16_t>(&ABAC_InformationMsg_ABAC_Attribute_ID);
	ABAC_InformationMsg.push<uint8_t>(&ABAC_InformationMsg_ABAC_Attribute_Type);
	ABAC_InformationMsg.push<uint16_t>(&ABAC_InformationMsg_ABAC_Attribute_Value);
	ABAC_InformationMsg.push<uint8_t>(&ABAC_InformationMsg_ABAC_Command);
};

void pullABAC_InformationMsg() {
	ABAC_InformationMsg_ABAC_Attribute_ID.update(ABAC_InformationMsg.getPtrMsg());
	ABAC_InformationMsg_ABAC_Attribute_Type.update(ABAC_InformationMsg.getPtrMsg());
	ABAC_InformationMsg_ABAC_Attribute_Value.update(ABAC_InformationMsg.getPtrMsg());
	ABAC_InformationMsg_ABAC_Command.update(ABAC_InformationMsg.getPtrMsg());
};

/* -------------------------- ID: 0x700 ----- Name: ECU1_ABAC_ECU_Resp -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> ECU1_ABAC_ECU_Resp_ABAC_Attribute_ID(0,15,16,100,1,0,0,65535,0);
CSignalVar1<uint16_t> ECU1_ABAC_ECU_Resp_ABAC_Attribute_Value(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> ECU1_ABAC_ECU_Resp_ABAC_ResourceResp(32,39,8,100,1,0,0,255,0);


//Define MessageObj
CMessage<uint64_t> ECU1_ABAC_ECU_Resp(0x700,0,5,0,100,10,10,10,0);

void pushECU1_ABAC_ECU_Resp() {
	ECU1_ABAC_ECU_Resp.push<uint16_t>(&ECU1_ABAC_ECU_Resp_ABAC_Attribute_ID);
	ECU1_ABAC_ECU_Resp.push<uint16_t>(&ECU1_ABAC_ECU_Resp_ABAC_Attribute_Value);
	ECU1_ABAC_ECU_Resp.push<uint8_t>(&ECU1_ABAC_ECU_Resp_ABAC_ResourceResp);
};

void pullECU1_ABAC_ECU_Resp() {
	ECU1_ABAC_ECU_Resp_ABAC_Attribute_ID.update(ECU1_ABAC_ECU_Resp.getPtrMsg());
	ECU1_ABAC_ECU_Resp_ABAC_Attribute_Value.update(ECU1_ABAC_ECU_Resp.getPtrMsg());
	ECU1_ABAC_ECU_Resp_ABAC_ResourceResp.update(ECU1_ABAC_ECU_Resp.getPtrMsg());
};

/* -------------------------- ID: 0x710 ----- Name: ECU1_Send_Nonce -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> ECU1_Send_Nonce_ABAC_Attribute_ID(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> ECU1_Send_Nonce_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> ECU1_Send_Nonce_ABAC_Attribute_Value(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> ECU1_Send_Nonce_ABAC_Command(0,7,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> ECU1_Send_Nonce_ABAC_Nonce(48,63,16,100,1,0,0,65535,0);


//Define MessageObj
CMessage<uint64_t> ECU1_Send_Nonce(0x710,0,8,0,100,10,10,10,0);

void pushECU1_Send_Nonce() {
	ECU1_Send_Nonce.push<uint16_t>(&ECU1_Send_Nonce_ABAC_Attribute_ID);
	ECU1_Send_Nonce.push<uint8_t>(&ECU1_Send_Nonce_ABAC_Attribute_Type);
	ECU1_Send_Nonce.push<uint16_t>(&ECU1_Send_Nonce_ABAC_Attribute_Value);
	ECU1_Send_Nonce.push<uint8_t>(&ECU1_Send_Nonce_ABAC_Command);
	ECU1_Send_Nonce.push<uint16_t>(&ECU1_Send_Nonce_ABAC_Nonce);
};

void pullECU1_Send_Nonce() {
	ECU1_Send_Nonce_ABAC_Attribute_ID.update(ECU1_Send_Nonce.getPtrMsg());
	ECU1_Send_Nonce_ABAC_Attribute_Type.update(ECU1_Send_Nonce.getPtrMsg());
	ECU1_Send_Nonce_ABAC_Attribute_Value.update(ECU1_Send_Nonce.getPtrMsg());
	ECU1_Send_Nonce_ABAC_Command.update(ECU1_Send_Nonce.getPtrMsg());
	ECU1_Send_Nonce_ABAC_Nonce.update(ECU1_Send_Nonce.getPtrMsg());
};

/* -------------------------- ID: 0x701 ----- Name: ECU2_ABAC_ECU_Resp -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> ECU2_ABAC_ECU_Resp_ABAC_Attribute_ID(0,15,16,100,1,0,0,65535,0);
CSignalVar1<uint16_t> ECU2_ABAC_ECU_Resp_ABAC_Attribute_Value(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> ECU2_ABAC_ECU_Resp_ABAC_ResourceResp(32,39,8,100,1,0,0,255,0);


//Define MessageObj
CMessage<uint64_t> ECU2_ABAC_ECU_Resp(0x701,0,5,0,100,10,10,10,0);

void pushECU2_ABAC_ECU_Resp() {
	ECU2_ABAC_ECU_Resp.push<uint16_t>(&ECU2_ABAC_ECU_Resp_ABAC_Attribute_ID);
	ECU2_ABAC_ECU_Resp.push<uint16_t>(&ECU2_ABAC_ECU_Resp_ABAC_Attribute_Value);
	ECU2_ABAC_ECU_Resp.push<uint8_t>(&ECU2_ABAC_ECU_Resp_ABAC_ResourceResp);
};

void pullECU2_ABAC_ECU_Resp() {
	ECU2_ABAC_ECU_Resp_ABAC_Attribute_ID.update(ECU2_ABAC_ECU_Resp.getPtrMsg());
	ECU2_ABAC_ECU_Resp_ABAC_Attribute_Value.update(ECU2_ABAC_ECU_Resp.getPtrMsg());
	ECU2_ABAC_ECU_Resp_ABAC_ResourceResp.update(ECU2_ABAC_ECU_Resp.getPtrMsg());
};

/* -------------------------- ID: 0x711 ----- Name: ECU2_Send_Nonce -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> ECU2_Send_Nonce_ABAC_Attribute_ID(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> ECU2_Send_Nonce_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> ECU2_Send_Nonce_ABAC_Attribute_Value(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> ECU2_Send_Nonce_ABAC_Command(0,7,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> ECU2_Send_Nonce_ABAC_Nonce(48,63,16,100,1,0,0,65535,0);


//Define MessageObj
CMessage<uint64_t> ECU2_Send_Nonce(0x711,0,8,0,100,10,10,10,0);

void pushECU2_Send_Nonce() {
	ECU2_Send_Nonce.push<uint16_t>(&ECU2_Send_Nonce_ABAC_Attribute_ID);
	ECU2_Send_Nonce.push<uint8_t>(&ECU2_Send_Nonce_ABAC_Attribute_Type);
	ECU2_Send_Nonce.push<uint16_t>(&ECU2_Send_Nonce_ABAC_Attribute_Value);
	ECU2_Send_Nonce.push<uint8_t>(&ECU2_Send_Nonce_ABAC_Command);
	ECU2_Send_Nonce.push<uint16_t>(&ECU2_Send_Nonce_ABAC_Nonce);
};

void pullECU2_Send_Nonce() {
	ECU2_Send_Nonce_ABAC_Attribute_ID.update(ECU2_Send_Nonce.getPtrMsg());
	ECU2_Send_Nonce_ABAC_Attribute_Type.update(ECU2_Send_Nonce.getPtrMsg());
	ECU2_Send_Nonce_ABAC_Attribute_Value.update(ECU2_Send_Nonce.getPtrMsg());
	ECU2_Send_Nonce_ABAC_Command.update(ECU2_Send_Nonce.getPtrMsg());
	ECU2_Send_Nonce_ABAC_Nonce.update(ECU2_Send_Nonce.getPtrMsg());
};

/* -------------------------- ID: 0x350 ----- Name: ECU_1_Resource -------------------------- */
//Define SignalObjs
CSignalVar1<uint8_t> ECU_1_Resource_Counter(0,7,8,100,1,0,0,0,0);


//Define MessageObj
CMessage<uint8_t> ECU_1_Resource(0x350,0,1,0,100,10,10,10,0);

void pushECU_1_Resource() {
	ECU_1_Resource.push<uint8_t>(&ECU_1_Resource_Counter);
};

void pullECU_1_Resource() {
	ECU_1_Resource_Counter.update(ECU_1_Resource.getPtrMsg());
};

/* -------------------------- ID: 0x325 ----- Name: ECU_2_Resource -------------------------- */
//Define SignalObjs
CSignalVar1<uint8_t> ECU_2_Resource_Counter(0,7,8,100,1,0,0,0,0);


//Define MessageObj
CMessage<uint8_t> ECU_2_Resource(0x325,0,1,0,100,10,10,10,0);

void pushECU_2_Resource() {
	ECU_2_Resource.push<uint8_t>(&ECU_2_Resource_Counter);
};

void pullECU_2_Resource() {
	ECU_2_Resource_Counter.update(ECU_2_Resource.getPtrMsg());
};

/* -------------------------- ID: 0x601 ----- Name: Extern_ABAC_AccessMsg -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> Extern_ABAC_AccessMsg_ABAC_Attribute_ID(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> Extern_ABAC_AccessMsg_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> Extern_ABAC_AccessMsg_ABAC_Attribute_Value(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> Extern_ABAC_AccessMsg_ABAC_Command(0,7,8,100,1,0,0,255,0);


//Define MessageObj
CMessage<uint64_t> Extern_ABAC_AccessMsg(0x601,0,6,0,100,10,10,10,0);

void pushExtern_ABAC_AccessMsg() {
	Extern_ABAC_AccessMsg.push<uint16_t>(&Extern_ABAC_AccessMsg_ABAC_Attribute_ID);
	Extern_ABAC_AccessMsg.push<uint8_t>(&Extern_ABAC_AccessMsg_ABAC_Attribute_Type);
	Extern_ABAC_AccessMsg.push<uint16_t>(&Extern_ABAC_AccessMsg_ABAC_Attribute_Value);
	Extern_ABAC_AccessMsg.push<uint8_t>(&Extern_ABAC_AccessMsg_ABAC_Command);
};

void pullExtern_ABAC_AccessMsg() {
	Extern_ABAC_AccessMsg_ABAC_Attribute_ID.update(Extern_ABAC_AccessMsg.getPtrMsg());
	Extern_ABAC_AccessMsg_ABAC_Attribute_Type.update(Extern_ABAC_AccessMsg.getPtrMsg());
	Extern_ABAC_AccessMsg_ABAC_Attribute_Value.update(Extern_ABAC_AccessMsg.getPtrMsg());
	Extern_ABAC_AccessMsg_ABAC_Command.update(Extern_ABAC_AccessMsg.getPtrMsg());
};

/* -------------------------- ID: 0x620 ----- Name: PDP_ABAC_DecisionMsg -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> PDP_ABAC_DecisionMsg_ABAC_Attribute_ID(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PDP_ABAC_DecisionMsg_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> PDP_ABAC_DecisionMsg_ABAC_Attribute_Value(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PDP_ABAC_DecisionMsg_ABAC_Command(0,7,8,100,1,0,0,255,0);
CSignalVar1<uint8_t> PDP_ABAC_DecisionMsg_ABAC_Decision(48,55,8,100,1,0,0,255,0);


//Define MessageObj
CMessage<uint64_t> PDP_ABAC_DecisionMsg(0x620,0,7,0,100,10,10,10,0);

void pushPDP_ABAC_DecisionMsg() {
	PDP_ABAC_DecisionMsg.push<uint16_t>(&PDP_ABAC_DecisionMsg_ABAC_Attribute_ID);
	PDP_ABAC_DecisionMsg.push<uint8_t>(&PDP_ABAC_DecisionMsg_ABAC_Attribute_Type);
	PDP_ABAC_DecisionMsg.push<uint16_t>(&PDP_ABAC_DecisionMsg_ABAC_Attribute_Value);
	PDP_ABAC_DecisionMsg.push<uint8_t>(&PDP_ABAC_DecisionMsg_ABAC_Command);
	PDP_ABAC_DecisionMsg.push<uint8_t>(&PDP_ABAC_DecisionMsg_ABAC_Decision);
};

void pullPDP_ABAC_DecisionMsg() {
	PDP_ABAC_DecisionMsg_ABAC_Attribute_ID.update(PDP_ABAC_DecisionMsg.getPtrMsg());
	PDP_ABAC_DecisionMsg_ABAC_Attribute_Type.update(PDP_ABAC_DecisionMsg.getPtrMsg());
	PDP_ABAC_DecisionMsg_ABAC_Attribute_Value.update(PDP_ABAC_DecisionMsg.getPtrMsg());
	PDP_ABAC_DecisionMsg_ABAC_Command.update(PDP_ABAC_DecisionMsg.getPtrMsg());
	PDP_ABAC_DecisionMsg_ABAC_Decision.update(PDP_ABAC_DecisionMsg.getPtrMsg());
};

/* -------------------------- ID: 0x625 ----- Name: PDP_ABAC_Get_Nonce -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> PDP_ABAC_Get_Nonce_ABAC_Attribute_ID(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PDP_ABAC_Get_Nonce_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> PDP_ABAC_Get_Nonce_ABAC_Attribute_Value(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PDP_ABAC_Get_Nonce_ABAC_Command(0,7,8,100,1,0,0,255,0);


//Define MessageObj
CMessage<uint64_t> PDP_ABAC_Get_Nonce(0x625,0,6,0,100,10,10,10,0);

void pushPDP_ABAC_Get_Nonce() {
	PDP_ABAC_Get_Nonce.push<uint16_t>(&PDP_ABAC_Get_Nonce_ABAC_Attribute_ID);
	PDP_ABAC_Get_Nonce.push<uint8_t>(&PDP_ABAC_Get_Nonce_ABAC_Attribute_Type);
	PDP_ABAC_Get_Nonce.push<uint16_t>(&PDP_ABAC_Get_Nonce_ABAC_Attribute_Value);
	PDP_ABAC_Get_Nonce.push<uint8_t>(&PDP_ABAC_Get_Nonce_ABAC_Command);
};

void pullPDP_ABAC_Get_Nonce() {
	PDP_ABAC_Get_Nonce_ABAC_Attribute_ID.update(PDP_ABAC_Get_Nonce.getPtrMsg());
	PDP_ABAC_Get_Nonce_ABAC_Attribute_Type.update(PDP_ABAC_Get_Nonce.getPtrMsg());
	PDP_ABAC_Get_Nonce_ABAC_Attribute_Value.update(PDP_ABAC_Get_Nonce.getPtrMsg());
	PDP_ABAC_Get_Nonce_ABAC_Command.update(PDP_ABAC_Get_Nonce.getPtrMsg());
};

/* -------------------------- ID: 0x632 ----- Name: PDP_ABAC_Lock_ResourceMsg -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_ID(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Value(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PDP_ABAC_Lock_ResourceMsg_ABAC_Command(0,7,8,100,1,0,0,255,0);


//Define MessageObj
CMessage<uint64_t> PDP_ABAC_Lock_ResourceMsg(0x632,0,6,0,100,10,10,10,0);

void pushPDP_ABAC_Lock_ResourceMsg() {
	PDP_ABAC_Lock_ResourceMsg.push<uint16_t>(&PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_ID);
	PDP_ABAC_Lock_ResourceMsg.push<uint8_t>(&PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Type);
	PDP_ABAC_Lock_ResourceMsg.push<uint16_t>(&PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Value);
	PDP_ABAC_Lock_ResourceMsg.push<uint8_t>(&PDP_ABAC_Lock_ResourceMsg_ABAC_Command);
};

void pullPDP_ABAC_Lock_ResourceMsg() {
	PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_ID.update(PDP_ABAC_Lock_ResourceMsg.getPtrMsg());
	PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Type.update(PDP_ABAC_Lock_ResourceMsg.getPtrMsg());
	PDP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Value.update(PDP_ABAC_Lock_ResourceMsg.getPtrMsg());
	PDP_ABAC_Lock_ResourceMsg_ABAC_Command.update(PDP_ABAC_Lock_ResourceMsg.getPtrMsg());
};

/* -------------------------- ID: 0x631 ----- Name: PDP_ABAC_Unlock_ResourceMsg -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_ID(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Value(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PDP_ABAC_Unlock_ResourceMsg_ABAC_Command(0,7,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> PDP_ABAC_Unlock_ResourceMsg_ABAC_Key(48,63,16,100,1,0,0,65535,0);


//Define MessageObj
CMessage<uint64_t> PDP_ABAC_Unlock_ResourceMsg(0x631,0,8,0,100,10,10,10,0);

void pushPDP_ABAC_Unlock_ResourceMsg() {
	PDP_ABAC_Unlock_ResourceMsg.push<uint16_t>(&PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_ID);
	PDP_ABAC_Unlock_ResourceMsg.push<uint8_t>(&PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Type);
	PDP_ABAC_Unlock_ResourceMsg.push<uint16_t>(&PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Value);
	PDP_ABAC_Unlock_ResourceMsg.push<uint8_t>(&PDP_ABAC_Unlock_ResourceMsg_ABAC_Command);
	PDP_ABAC_Unlock_ResourceMsg.push<uint16_t>(&PDP_ABAC_Unlock_ResourceMsg_ABAC_Key);
};

void pullPDP_ABAC_Unlock_ResourceMsg() {
	PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_ID.update(PDP_ABAC_Unlock_ResourceMsg.getPtrMsg());
	PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Type.update(PDP_ABAC_Unlock_ResourceMsg.getPtrMsg());
	PDP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Value.update(PDP_ABAC_Unlock_ResourceMsg.getPtrMsg());
	PDP_ABAC_Unlock_ResourceMsg_ABAC_Command.update(PDP_ABAC_Unlock_ResourceMsg.getPtrMsg());
	PDP_ABAC_Unlock_ResourceMsg_ABAC_Key.update(PDP_ABAC_Unlock_ResourceMsg.getPtrMsg());
};

/* -------------------------- ID: 0x600 ----- Name: PEP_ABAC_AccessMsg -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> PEP_ABAC_AccessMsg_ABAC_Attribute_ID(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PEP_ABAC_AccessMsg_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> PEP_ABAC_AccessMsg_ABAC_Attribute_Value(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PEP_ABAC_AccessMsg_ABAC_Command(0,7,8,100,1,0,0,255,0);


//Define MessageObj
CMessage<uint64_t> PEP_ABAC_AccessMsg(0x600,0,6,0,100,10,10,10,0);

void pushPEP_ABAC_AccessMsg() {
	PEP_ABAC_AccessMsg.push<uint16_t>(&PEP_ABAC_AccessMsg_ABAC_Attribute_ID);
	PEP_ABAC_AccessMsg.push<uint8_t>(&PEP_ABAC_AccessMsg_ABAC_Attribute_Type);
	PEP_ABAC_AccessMsg.push<uint16_t>(&PEP_ABAC_AccessMsg_ABAC_Attribute_Value);
	PEP_ABAC_AccessMsg.push<uint8_t>(&PEP_ABAC_AccessMsg_ABAC_Command);
};

void pullPEP_ABAC_AccessMsg() {
	PEP_ABAC_AccessMsg_ABAC_Attribute_ID.update(PEP_ABAC_AccessMsg.getPtrMsg());
	PEP_ABAC_AccessMsg_ABAC_Attribute_Type.update(PEP_ABAC_AccessMsg.getPtrMsg());
	PEP_ABAC_AccessMsg_ABAC_Attribute_Value.update(PEP_ABAC_AccessMsg.getPtrMsg());
	PEP_ABAC_AccessMsg_ABAC_Command.update(PEP_ABAC_AccessMsg.getPtrMsg());
};

/* -------------------------- ID: 0x621 ----- Name: PEP_ABAC_DecisionMsg -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> PEP_ABAC_DecisionMsg_ABAC_Attribute_ID(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PEP_ABAC_DecisionMsg_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> PEP_ABAC_DecisionMsg_ABAC_Attribute_Value(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PEP_ABAC_DecisionMsg_ABAC_Command(0,7,8,100,1,0,0,255,0);
CSignalVar1<uint8_t> PEP_ABAC_DecisionMsg_ABAC_Decision(48,55,8,100,1,0,0,255,0);


//Define MessageObj
CMessage<uint64_t> PEP_ABAC_DecisionMsg(0x621,0,7,0,100,10,10,10,0);

void pushPEP_ABAC_DecisionMsg() {
	PEP_ABAC_DecisionMsg.push<uint16_t>(&PEP_ABAC_DecisionMsg_ABAC_Attribute_ID);
	PEP_ABAC_DecisionMsg.push<uint8_t>(&PEP_ABAC_DecisionMsg_ABAC_Attribute_Type);
	PEP_ABAC_DecisionMsg.push<uint16_t>(&PEP_ABAC_DecisionMsg_ABAC_Attribute_Value);
	PEP_ABAC_DecisionMsg.push<uint8_t>(&PEP_ABAC_DecisionMsg_ABAC_Command);
	PEP_ABAC_DecisionMsg.push<uint8_t>(&PEP_ABAC_DecisionMsg_ABAC_Decision);
};

void pullPEP_ABAC_DecisionMsg() {
	PEP_ABAC_DecisionMsg_ABAC_Attribute_ID.update(PEP_ABAC_DecisionMsg.getPtrMsg());
	PEP_ABAC_DecisionMsg_ABAC_Attribute_Type.update(PEP_ABAC_DecisionMsg.getPtrMsg());
	PEP_ABAC_DecisionMsg_ABAC_Attribute_Value.update(PEP_ABAC_DecisionMsg.getPtrMsg());
	PEP_ABAC_DecisionMsg_ABAC_Command.update(PEP_ABAC_DecisionMsg.getPtrMsg());
	PEP_ABAC_DecisionMsg_ABAC_Decision.update(PEP_ABAC_DecisionMsg.getPtrMsg());
};

/* -------------------------- ID: 0x633 ----- Name: PEP_ABAC_Lock_ResourceMsg -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_ID(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Value(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PEP_ABAC_Lock_ResourceMsg_ABAC_Command(0,7,8,100,1,0,0,255,0);


//Define MessageObj
CMessage<uint64_t> PEP_ABAC_Lock_ResourceMsg(0x633,0,6,0,100,10,10,10,0);

void pushPEP_ABAC_Lock_ResourceMsg() {
	PEP_ABAC_Lock_ResourceMsg.push<uint16_t>(&PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_ID);
	PEP_ABAC_Lock_ResourceMsg.push<uint8_t>(&PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Type);
	PEP_ABAC_Lock_ResourceMsg.push<uint16_t>(&PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Value);
	PEP_ABAC_Lock_ResourceMsg.push<uint8_t>(&PEP_ABAC_Lock_ResourceMsg_ABAC_Command);
};

void pullPEP_ABAC_Lock_ResourceMsg() {
	PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_ID.update(PEP_ABAC_Lock_ResourceMsg.getPtrMsg());
	PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Type.update(PEP_ABAC_Lock_ResourceMsg.getPtrMsg());
	PEP_ABAC_Lock_ResourceMsg_ABAC_Attribute_Value.update(PEP_ABAC_Lock_ResourceMsg.getPtrMsg());
	PEP_ABAC_Lock_ResourceMsg_ABAC_Command.update(PEP_ABAC_Lock_ResourceMsg.getPtrMsg());
};

/* -------------------------- ID: 0x630 ----- Name: PEP_ABAC_Unlock_ResourceMsg -------------------------- */
//Define SignalObjs
CSignalVar1<uint16_t> PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_ID(16,31,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Type(8,15,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Value(32,47,16,100,1,0,0,65535,0);
CSignalVar1<uint8_t> PEP_ABAC_Unlock_ResourceMsg_ABAC_Command(0,7,8,100,1,0,0,255,0);
CSignalVar1<uint16_t> PEP_ABAC_Unlock_ResourceMsg_ABAC_Key(48,63,16,100,1,0,0,65535,0);


//Define MessageObj
CMessage<uint64_t> PEP_ABAC_Unlock_ResourceMsg(0x630,0,8,0,100,10,10,10,0);

void pushPEP_ABAC_Unlock_ResourceMsg() {
	PEP_ABAC_Unlock_ResourceMsg.push<uint16_t>(&PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_ID);
	PEP_ABAC_Unlock_ResourceMsg.push<uint8_t>(&PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Type);
	PEP_ABAC_Unlock_ResourceMsg.push<uint16_t>(&PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Value);
	PEP_ABAC_Unlock_ResourceMsg.push<uint8_t>(&PEP_ABAC_Unlock_ResourceMsg_ABAC_Command);
	PEP_ABAC_Unlock_ResourceMsg.push<uint16_t>(&PEP_ABAC_Unlock_ResourceMsg_ABAC_Key);
};

void pullPEP_ABAC_Unlock_ResourceMsg() {
	PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_ID.update(PEP_ABAC_Unlock_ResourceMsg.getPtrMsg());
	PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Type.update(PEP_ABAC_Unlock_ResourceMsg.getPtrMsg());
	PEP_ABAC_Unlock_ResourceMsg_ABAC_Attribute_Value.update(PEP_ABAC_Unlock_ResourceMsg.getPtrMsg());
	PEP_ABAC_Unlock_ResourceMsg_ABAC_Command.update(PEP_ABAC_Unlock_ResourceMsg.getPtrMsg());
	PEP_ABAC_Unlock_ResourceMsg_ABAC_Key.update(PEP_ABAC_Unlock_ResourceMsg.getPtrMsg());
};

