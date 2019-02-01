#include <ABAC.h>
#include <iostream>

using namespace std;


bool CAN_Transmit(uint8_t *pData){
	ABAC_Command Command = (ABAC_Command)pData[0];
	switch (Command) {
		case ACCESS:
			break;
		case INFORMATION:
			break;
		case DECISIONRESP:
			break;
		case UNLOCK_RESOURCE:
			break;
		case NONCE:
			break;
	}
	return true;
}

Policies PolicyObj(CAN_Transmit);

uint8_t TestFrame1[8] = {ACCESS,ACCESS_SUBJECT,0x29,0xA7,0x9D,0x12};
uint8_t TestFrame2[8] = {ACCESS,ACTION,0x41,0x8C,0xEC,0xAE};
uint8_t TestFrame3[8] = {ACCESS,RESOURCE,0x6F,0x47,0x20,0x92};

int main() {

	const Attribute role_mechanic(0x29A7, 0xBCD8, ACCESS_SUBJECT);
	const Attribute action_read(0x418C, 0xECAE, ACTION);
	const Attribute resourceType_diagnosisData(0x6F47, 0x2092, RESOURCE);
	const Attribute testerConnectionStatus_connected(0xE6D1, 0x06AA, ENVIRONMENT);
	const Attribute empty(0x0000, 0x0000, NONE);
	Decision ret;


	PolicyObj.sendRequest(role_mechanic,action_read,resourceType_diagnosisData);


//	PolicyObj.RxABACmsgHandle(TestFrame1);
//	ret = PolicyObj.request();
//	PolicyObj.RxABACmsgHandle(TestFrame2);
//	ret = PolicyObj.request();
//	PolicyObj.RxABACmsgHandle(TestFrame3);
//	ret = PolicyObj.request();
	PolicyObj.setInformation(testerConnectionStatus_connected);
	ret = PolicyObj.request();

	return 0;
}
