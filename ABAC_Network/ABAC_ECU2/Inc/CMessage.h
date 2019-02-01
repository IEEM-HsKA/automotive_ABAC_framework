/**
*	@file CMessage.h
*	@author Alexander Duda
*
*	@date	27.11.2017
*	@edit by Alexander Duda
*
*	@Version 2.0
*/

#pragma once
#include <cstdint>
#include <string.h>
#include "CSignal.h"

template<typename Type>
Type clearMask(uint8_t &Length) {
	return ((1 << Length) - 1); //ClearMask
}

template<typename Type>
Type setMask(int Value, uint8_t &Length) {
	return (Value >> 0) & ((1 << Length) - 1); //SetMask
}

template<typename MsgType>
union UCanObj {
	MsgType Msg;
	uint8_t Data[8];
};

template <typename MsgType>
class CMessage
{
public:
	CMessage(uint16_t ID,
		uint16_t IDE,
		uint8_t DLC,
		uint8_t RTR,
		uint16_t CycleTime,
		uint16_t CycleTimeFast,
		uint8_t CycleTimeActive,
		uint16_t DelayTime,
		uint16_t TimeoutTime);

	uint16_t getID() { return mID; }
	uint8_t getDLC() { return mDLC; }
	uint16_t getCycleTime() { return mCycleTime; }
	uint16_t getCycleTimeFast() { return mCycleTimeFast; }
	uint16_t getTimeoutTime() { return mTimeoutTime; }
	uint8_t getCycleTimeActive() { return mCycleTimeActive; }
	uint16_t getDelayTime() { return mDelayTime; }
	uint32_t getTimeStamp() { return mTimeStamp; }
	int validate(uint32_t currentTimestamp, float missingFactor);

	int Merge(uint8_t DataIn[]);
	int Merge(uint8_t DataIn[], uint32_t currentTimestamp);

	//Push SignalValue to MsgObj
	template<typename SignalType>
	int push(CSignalVar1<SignalType> *Signal);

	template<typename SignalType>
	int push(CSignalVar2<SignalType> *Signal);

	template<typename SignalType>
	int push(CSignalVar3<SignalType> *Signal);

	template<typename SignalType>
	int push(CSignalVar4<SignalType> *Signal);

	template<typename SignalType>
	int push(CSignalVar5<SignalType> *Signal);


	//Pull SignalValue from MsgObj
	template<typename SignalType>
	int pull(CSignalVar1<SignalType> *Signal);

	template<typename SignalType>
	int pull(CSignalVar2<SignalType> *Signal);

	template<typename SignalType>
	int pull(CSignalVar3<SignalType> *Signal);

	template<typename SignalType>
	int pull(CSignalVar4<SignalType> *Signal);

	template<typename SignalType>
	int pull(CSignalVar5<SignalType> *Signal);

	MsgType & getPtrMsg() { return mUCanMsg.Msg; }
	uint8_t * getData() { return mUCanMsg.Data; }

	void operator =(uint8_t Data[]) {
		memcpy(mUCanMsg.Data, Data, mDLC);
	}

	void operator <<(uint32_t currentTimestamp) {
		mTimeStamp = currentTimestamp;
	}


private:
	//Signal constants
	const uint16_t mID;
	const uint16_t mIDE;
	const uint8_t mDLC;
	const uint8_t mRTR;

	//Attributes
	const uint16_t mCycleTime;			// normal cycle time
	const uint16_t mCycleTimeFast;		// fast cycle time
	const uint8_t mCycleTimeActive;		// start up delay
	const uint16_t mDelayTime;			// min. time between two sends
	const uint16_t mTimeoutTime;		// max. time between two reads
	uint32_t mTimeStamp;

	UCanObj<MsgType> mUCanMsg;
};

template <typename MsgType>
CMessage<MsgType>::CMessage(uint16_t ID,
	uint16_t IDE,
	uint8_t DLC,
	uint8_t RTR,
	uint16_t CycleTime,
	uint16_t CycleTimeFast,
	uint8_t CycleTimeActive,
	uint16_t DelayTime,
	uint16_t TimeoutTime) :
	mID(ID),
	mIDE(IDE),
	mDLC(DLC),
	mRTR(RTR),
	mCycleTime(CycleTime),
	mCycleTimeFast(CycleTimeFast),
	mCycleTimeActive(CycleTimeActive),
	mDelayTime(DelayTime),
	mTimeoutTime(TimeoutTime),
	mTimeStamp(0) {}

//Merges Byts into a bigger Datatype i.e. 4xuint8_t -> uint32_t
template <typename MsgType>
int CMessage<MsgType>::Merge(uint8_t DataIn[]) { //use when received
	memcpy(mUCanMsg.Data, DataIn, mDLC);
	return 0;
} //always merge after receive

  //Merges Byts into a bigger Datatype i.e. 4xuint8_t -> uint32_t
template <typename MsgType>
int CMessage<MsgType>::Merge(uint8_t DataIn[], uint32_t currentTimestamp) { //use when received
	mTimeStamp = currentTimestamp;
	memcpy(mUCanMsg.Data, DataIn, mDLC);
	return 0;
} //always merge after receive


template<typename MsgType>
template<typename SignalType>
int CMessage<MsgType>::push(CSignalVar1<SignalType> *Signal) 
{
	uint8_t StartBit = Signal->getStartBit();
	uint8_t Length = Signal->getLength();

	switch (sizeof(MsgType))
	{
	case 1:
		mUCanMsg.Msg &= ~(clearMask<uint8_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint8_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 2:
		mUCanMsg.Msg &= ~(clearMask<uint16_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint16_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 4:
		mUCanMsg.Msg &= ~(clearMask<uint32_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint32_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 8:
		mUCanMsg.Msg &= ~(clearMask<uint64_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint64_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	default:
		mUCanMsg.Msg &= ~(clearMask<uint64_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint64_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	}
	return 0;
}

template<typename MsgType>
template<typename SignalType>
int CMessage<MsgType>::push(CSignalVar2<SignalType> *Signal)
{
	uint8_t StartBit = Signal->getStartBit();
	uint8_t Length = Signal->getLength();

	switch (sizeof(MsgType))
	{
	case 1:
		mUCanMsg.Msg &= ~(clearMask<uint8_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint8_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 2:
		mUCanMsg.Msg &= ~(clearMask<uint16_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint16_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 4:
		mUCanMsg.Msg &= ~(clearMask<uint32_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint32_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 8:
		mUCanMsg.Msg &= ~(clearMask<uint64_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint64_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	default:
		mUCanMsg.Msg &= ~(clearMask<uint64_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint64_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	}
	return 0;
}

template<typename MsgType>
template<typename SignalType>
int CMessage<MsgType>::push(CSignalVar3<SignalType> *Signal)
{
	uint8_t StartBit = Signal->getStartBit();
	uint8_t Length = Signal->getLength();

	switch (sizeof(MsgType))
	{
	case 1:
		mUCanMsg.Msg &= ~(clearMask<uint8_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint8_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 2:
		mUCanMsg.Msg &= ~(clearMask<uint16_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint16_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 4:
		mUCanMsg.Msg &= ~(clearMask<uint32_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint32_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 8:
		mUCanMsg.Msg &= ~(clearMask<uint64_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint64_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	default:
		mUCanMsg.Msg &= ~(clearMask<uint64_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint64_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	}
	return 0;
}

template<typename MsgType>
template<typename SignalType>
int CMessage<MsgType>::push(CSignalVar4<SignalType> *Signal)
{
	uint8_t StartBit = Signal->getStartBit();
	uint8_t Length = Signal->getLength();

	switch (sizeof(MsgType))
	{
	case 1:
		mUCanMsg.Msg &= ~(clearMask<uint8_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint8_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 2:
		mUCanMsg.Msg &= ~(clearMask<uint16_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint16_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 4:
		mUCanMsg.Msg &= ~(clearMask<uint32_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint32_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 8:
		mUCanMsg.Msg &= ~(clearMask<uint64_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint64_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	default:
		mUCanMsg.Msg &= ~(clearMask<uint64_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint64_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	}
	return 0;
}

template<typename MsgType>
template<typename SignalType>
int CMessage<MsgType>::push(CSignalVar5<SignalType> *Signal)
{
	uint8_t StartBit = Signal->getStartBit();
	uint8_t Length = Signal->getLength();

	switch (sizeof(MsgType))
	{
	case 1:
		mUCanMsg.Msg &= ~(clearMask<uint8_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint8_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 2:
		mUCanMsg.Msg &= ~(clearMask<uint16_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint16_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 4:
		mUCanMsg.Msg &= ~(clearMask<uint32_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint32_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	case 8:
		mUCanMsg.Msg &= ~(clearMask<uint64_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint64_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	default:
		mUCanMsg.Msg &= ~(clearMask<uint64_t>(Length) << StartBit); //clear old value in Msg
		mUCanMsg.Msg = mUCanMsg.Msg | (setMask<uint64_t>(Signal->getRawValue(), Length) << StartBit); //set new value in Msg
		break;
	}
	return 0;
}

template<typename MsgType>
template<typename SignalType>
int CMessage<MsgType>::pull(CSignalVar1<SignalType> *Signal) {
	uint8_t StopBit = Signal->getStopBit();
	uint8_t StartBit = Signal->getStartBit();
	uint8_t Length = Signal->getLength();
	SignalType tempVal = ((mUCanMsg.Msg >> StartBit) & ((1 << Length) - 1));
	Signal->setValues(tempVal);
	return 0;
}

template<typename MsgType>
template<typename SignalType>
int CMessage<MsgType>::pull(CSignalVar2<SignalType> *Signal) {
	uint8_t StopBit = Signal->getStopBit();
	uint8_t StartBit = Signal->getStartBit();
	uint8_t Length = Signal->getLength();
	SignalType tempVal = ((mUCanMsg.Msg >> StartBit) & ((1 << Length) - 1));
	Signal->setValues(tempVal);
	return 0;
}

template<typename MsgType>
template<typename SignalType>
int CMessage<MsgType>::pull(CSignalVar3<SignalType> *Signal) {
	uint8_t StopBit = Signal->getStopBit();
	uint8_t StartBit = Signal->getStartBit();
	uint8_t Length = Signal->getLength();
	SignalType tempVal = ((mUCanMsg.Msg >> StartBit) & ((1 << Length) - 1));
	Signal->setValues(tempVal);
	return 0;
}

template<typename MsgType>
template<typename SignalType>
int CMessage<MsgType>::pull(CSignalVar4<SignalType> *Signal) {
	uint8_t StopBit = Signal->getStopBit();
	uint8_t StartBit = Signal->getStartBit();
	uint8_t Length = Signal->getLength();
	SignalType tempVal = ((mUCanMsg.Msg >> StartBit) & ((1 << Length) - 1));
	Signal->setValues(tempVal);
	return 0;
}

template<typename MsgType>
template<typename SignalType>
int CMessage<MsgType>::pull(CSignalVar5<SignalType> *Signal) {
	uint8_t StopBit = Signal->getStopBit();
	uint8_t StartBit = Signal->getStartBit();
	uint8_t Length = Signal->getLength();
	SignalType tempVal = ((mUCanMsg.Msg >> StartBit) & ((1 << Length) - 1));
	Signal->setValues(tempVal);
	return 0;
}


template<typename MsgType>
int CMessage<MsgType>::validate(uint32_t currentTimestamp, float missingFactor)
{
	uint32_t timeDelta = currentTimestamp - mTimeStamp;

	if((float)(timeDelta/mCycleTime) < missingFactor)
	{
		return 1;
	}
	else {
		return 0;
	}
}
