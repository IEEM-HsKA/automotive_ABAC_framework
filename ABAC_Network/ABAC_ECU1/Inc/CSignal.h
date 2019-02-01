/**
*	@file CSignal.h
*	@author Alexander Duda
*
*	@date	27.11.2017
*	@edit by Alexander Duda
*
*	@Version 2.0
*/
#pragma once
#include <stdint.h>
/**
*
*	1: Factor: Int Offset: Int Min/Max: Int
*	2: Factor: Float Offset: Float Min/Max: Float
*	3: Factor: Float Offset: Int Min/Max: Float
*	4: Factor: Float Offset: Float Min/Max: Int
*	5: Factor: Float Offset: Int Min/Max: Int
*/


template <typename SigType, typename FactorType, typename OffsetType, typename MinMaxType> //Factor: uint32_t Offset: int32_t MinMax: int32_t
class CSignalBase
{
public:

	CSignalBase(uint8_t StartBit, uint8_t StopBit, uint8_t Length, SigType InitValue, 
				FactorType Factor, OffsetType Offset, MinMaxType Min, MinMaxType Max, uint8_t signFlag) :
				mStartBit(StartBit), mStopBit(StopBit), mLength(Length), mInitValue(InitValue),
				mFactor(Factor), mOffset(Offset), mMin(Min), mMax(Max), mSignFlag(signFlag)
			{
				this->setValues(InitValue);
			};

	uint8_t getStartBit() { return mStartBit; }
	uint8_t getStopBit() { return mStopBit; }
	uint8_t getLength() { return mLength; }
	SigType getInitValue() { return mInitValue; }

	double getPhyValue() { return mPhysicalValue; }; // get the physical value 
	SigType getRawValue() { return mRawValue; }

	//set phyiscal value
	int setPhyValue(double PhyVal) {
		if ((double)mMin <= PhyVal && PhyVal <= (double)mMin) {			// validate Value
			mPhysicalValue = PhyVal;					// set Physical Value
			mRawValue = (PhyVal - (double)mOffset) / (double)mFactor;	// set Raw Value
			return 0;
		}
		else {	//in case of failure, set to max Value and return 1
			mRawValue = (mMax - (double)mOffset) / (double)mFactor;
			mPhysicalValue = mMax;
			return 1;
		}
	}
	// set raw Value
	int setValues(SigType value) {
		mRawValue = value;
		mPhysicalValue = ((double)value * (double)mFactor) + (double)mOffset;
		return 0;
	}
	
	int update(uint8_t &inputMsg);
	int update(uint16_t &inputMsg);
	int update(uint32_t &inputMsg);
	int update(uint64_t &inputMsg);

private:
	
	const uint8_t mStartBit;
	const uint8_t mStopBit;
	const uint8_t mLength;
	const SigType mInitValue;

	const FactorType mFactor;
	const OffsetType mOffset;
	const MinMaxType mMin;
	const MinMaxType mMax;
	const uint8_t mSignFlag;

	double mPhysicalValue;
	SigType mRawValue;
};



template <typename SigType> //Factor: uint32_t Offset: int32_t MinMax: int32_t
class CSignalVar1 : public CSignalBase <SigType, uint32_t, int32_t, int32_t>
{
public:
	CSignalVar1(uint8_t StartBit, uint8_t StopBit, uint8_t Length, SigType InitValue, uint32_t Factor, int32_t Offset, int32_t Min, int32_t Max, uint8_t signFlag) :
		CSignalBase<SigType, uint32_t, int32_t, int32_t>(StartBit, StopBit, Length, InitValue, Factor, Offset, Min, Max, signFlag)
	{
		this->setValues(InitValue);
	};
};


template <typename SigType> //Factor: double Offset: double MinMax: double
class CSignalVar2 : public CSignalBase <SigType, double, double, double>
{
public:
	CSignalVar2(uint8_t StartBit, uint8_t StopBit, uint8_t Length, SigType InitValue, double Factor, double Offset, double Min, double Max, uint8_t signFlag) :
		CSignalBase<SigType, double, double, double>(StartBit, StopBit, Length, InitValue, Factor, Offset, Min, Max, signFlag)
	{
		this->setValues(InitValue);
	};
};

template <typename SigType> //Factor: double Offset: int32_t MinMax: double
class CSignalVar3 : public CSignalBase <SigType, double, int32_t, double>
{
public:
	CSignalVar3(uint8_t StartBit, uint8_t StopBit, uint8_t Length, SigType InitValue, double Factor, int32_t Offset, double Min, double Max, uint8_t signFlag) :   //mFactor(Factor), mOffset(Offset), mMin(Min), mMax(Max),
		CSignalBase<SigType, double, int32_t, double>(StartBit, StopBit, Length, InitValue, Factor, Offset, Min, Max, signFlag)
	{
		this->setValues(InitValue);
	};
};

template <typename SigType> //Factor: double Offset: double MinMax: int32_t
class CSignalVar4 : public CSignalBase <SigType, double, double, int32_t>
{
public:
	CSignalVar4(uint8_t StartBit, uint8_t StopBit, uint8_t Length, SigType InitValue, double Factor, double Offset, int32_t Min, int32_t Max, uint8_t signFlag) :   //mFactor(Factor), mOffset(Offset), mMin(Min), mMax(Max),
		CSignalBase<SigType, double, double, int32_t>(StartBit, StopBit, Length, InitValue, Factor, Offset, Min, Max, signFlag)
	{
		this->setValues(InitValue);
	};
};

template <typename SigType> //Factor: double Offset: int32_t MinMax: int32_t
class CSignalVar5 : public CSignalBase <SigType, double, int32_t, int32_t>
{
public:
	CSignalVar5(uint8_t StartBit, uint8_t StopBit, uint8_t Length, SigType InitValue, double Factor, int32_t Offset, int32_t Min, int32_t Max, uint8_t signFlag) :   //mFactor(Factor), mOffset(Offset), mMin(Min), mMax(Max),
		CSignalBase<SigType, double, int32_t, int32_t>(StartBit, StopBit, Length, InitValue, Factor, Offset, Min, Max, signFlag)
	{
		this->setValues(InitValue);
	};
};


template <typename SigType, typename FactorType, typename OffsetType, typename MinMaxType>
int CSignalBase<SigType, FactorType, OffsetType, MinMaxType>::update(uint8_t &inputMsg) {
	SigType tempVal = 0;

	uint8_t StopBit = this->getStopBit();
	uint8_t StartBit = this->getStartBit();
	uint8_t Length = this->getLength();

	if (mSignFlag == 0) 
	{
		tempVal = ((inputMsg >> StartBit) & ((1 << Length) - 1));
		this->setValues(tempVal);
		return 0;
	}
	else if (mSignFlag == 1) //signFlag indicates if Signaltype is signed 
	{
		//Mask and shift signal to position 0
		tempVal = (inputMsg >> StartBit) & ((1 << Length) - 1);
		//Check if signbit is set
		if ((tempVal >> (Length - 1)) == 1)
		{
			SigType mask = 0;
			//Creat Mask and fill signed datatyp
			mask = (~mask) << Length;
			tempVal = tempVal | mask;
		}
		this->setValues(tempVal);
		return 1;
	}
	return -1;
}


template <typename SigType, typename FactorType, typename OffsetType, typename MinMaxType>
int CSignalBase<SigType, FactorType, OffsetType, MinMaxType>::update(uint16_t &inputMsg) {
	SigType tempVal = 0;

	uint8_t StopBit = this->getStopBit();
	uint8_t StartBit = this->getStartBit();
	uint8_t Length = this->getLength();

	if (mSignFlag == 0) 
	{
		tempVal = ((inputMsg >> StartBit) & ((1 << Length) - 1));
		this->setValues(tempVal);
		return 0;
	}
	else if (mSignFlag == 1) //signFlag indicates if Signaltype is signed 
	{
		//Mask and shift signal to position 0
		tempVal = (inputMsg >> StartBit) & ((1 << Length) - 1);
		//Check if signbit is set
		if ((tempVal >> (Length - 1)) == 1)
		{
			SigType mask = 0;
			//Creat Mask and fill signed datatyp
			mask = (~mask) << Length;
			tempVal = tempVal | mask;
		}
		this->setValues(tempVal);
		return 1;
	}
	return -1;
}


template <typename SigType, typename FactorType, typename OffsetType, typename MinMaxType>
int CSignalBase<SigType, FactorType, OffsetType, MinMaxType>::update(uint32_t &inputMsg) {
	SigType tempVal = 0;

	uint8_t StopBit = this->getStopBit();
	uint8_t StartBit = this->getStartBit();
	uint8_t Length = this->getLength();

	if (mSignFlag == 0) 
	{
		tempVal = ((inputMsg >> StartBit) & ((1 << Length) - 1));
		this->setValues(tempVal);
		return 0;
	}
	else if (mSignFlag == 1) //signFlag indicates if Signaltype is signed 
	{
		//Mask and shift signal to position 0
		tempVal = (inputMsg >> StartBit) & ((1 << Length) - 1);
		//Check if signbit is set
		if ((tempVal >> (Length - 1)) == 1)
		{
			SigType mask = 0;
			//Creat Mask and fill signed datatyp
			mask = (~mask) << Length;
			tempVal = tempVal | mask;
		}
		this->setValues(tempVal);
		return 1;
	}
	return -1;
}


template <typename SigType, typename FactorType, typename OffsetType, typename MinMaxType>
int CSignalBase<SigType, FactorType, OffsetType, MinMaxType>::update(uint64_t &inputMsg) {
	SigType tempVal = 0;

	uint8_t StopBit = this->getStopBit();
	uint8_t StartBit = this->getStartBit();
	uint8_t Length = this->getLength();
	
	if (mSignFlag == 0) 
	{
		tempVal = ((inputMsg >> StartBit) & ((1 << Length) - 1));
		this->setValues(tempVal);
		return 0;
	}
	else if (mSignFlag == 1)//signFlag indicates if Signaltype is signed 
	{
		//Mask and shift signal to position 0
		tempVal = (inputMsg >> StartBit) & ((1 << Length) - 1);
		//Check if signbit is set
		if ((tempVal >> (Length - 1)) == 1) //signFlag indicates if Signaltype is signed 
		{	
			SigType mask = 0;
			//Creat Mask and fill signed datatyp
			mask = (~mask) << Length;
			tempVal = tempVal | mask;
		}
		this->setValues(tempVal);
		return 1;
	}
	return -1;
}