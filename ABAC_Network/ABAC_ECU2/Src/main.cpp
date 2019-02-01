
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */
#include "ABAC_Com_20181007_dbc.h"
#include "canExtern.h"
#include "Attribute.h"

const Attribute resourceType_diagnosisData(0x6F47, 0x2092, RESOURCE);
const Attribute resourceType_parameters(0x6F47, 0x166E, RESOURCE);

#ifdef __cplusplus
extern "C" {
#endif
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;

osThreadId Thread_Main_Handle;
osThreadId Thread_Nonce_Gen_Handle;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/


CAN_TxHeaderTypeDef TxCan1Header;
CAN_RxHeaderTypeDef RxCan1Header;

CAN_TxHeaderTypeDef TxCan2Header;
CAN_RxHeaderTypeDef RxCan2Header;


uint8_t RxCan1Data[8];

uint8_t TxCan2Data[8];
uint8_t RxCan2Data[8];
uint32_t TxCan2Mailbox;

bool timerStart = false;

uint16_t newNonce = 0;
uint16_t oldNonce = 0;

/* USER CODE END PV */



/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN1_Init(void);
static void MX_CAN2_Init(void);
void Thread_Main(void const * argument);
void Thread_Nonce_Gen(void const * argument);
static void MX_NVIC_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
static void CAN_Config(void);


/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

#ifdef __cplusplus
}
#endif
bool send(CMessage<uint8_t> pMsgObj_,CAN_HandleTypeDef pChannel_);
bool send(CMessage<uint16_t> pMsgObj_,CAN_HandleTypeDef pChannel_);
bool send(CMessage<uint32_t> pMsgObj_,CAN_HandleTypeDef pChannel_);
bool send(CMessage<uint64_t> pMsgObj_,CAN_HandleTypeDef pChannel_);
bool send(CAN_TxHeaderTypeDef pHeader_,uint8_t *pData_, CAN_HandleTypeDef pChannel_);

void attributeToFrame(Attribute pAttribute_, uint8_t *rOut_Frame_){
	rOut_Frame_[1] = pAttribute_.getCategory();
	rOut_Frame_[2] = LOWBYTE(pAttribute_.getID());
	rOut_Frame_[3] = HIGHBYTE(pAttribute_.getID());
	rOut_Frame_[4] = LOWBYTE(pAttribute_.getValue());
	rOut_Frame_[5] = HIGHBYTE(pAttribute_.getValue());
}
Attribute frameToAttribute(uint8_t *pFrame_){
	Attribute tmpAttribute;
	AttributeCategory Type = (AttributeCategory)pFrame_[1];
	uint16_t AttributeID;
	uint16_t AttributeValue;
	AttributeID = ((pFrame_[3] << 8) | pFrame_[2]);
	AttributeValue = ((pFrame_[5] << 8) | pFrame_[4]);
	tmpAttribute.set(AttributeID,AttributeValue,Type);
	return tmpAttribute;
}
void sendNonce(Attribute pAttribute_){
	uint8_t frame[8];
	frame[0] = NONCE;
	attributeToFrame(pAttribute_,frame);
	ECU2_Send_Nonce.Merge(frame);
	ECU2_Send_Nonce_ABAC_Nonce.setValues(oldNonce);
	ECU2_Send_Nonce.push<uint16_t>(&ECU2_Send_Nonce_ABAC_Nonce);
	send(ECU2_Send_Nonce,hcan1);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN1_Init();
  MX_CAN2_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */
  CAN_Config();
  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of Main */
  osThreadDef(Main, Thread_Main, osPriorityNormal, 0, 128);
  Thread_Main_Handle = osThreadCreate(osThread(Main), NULL);

  osThreadDef(Nonce, Thread_Nonce_Gen, osPriorityNormal, 0, 128);
  Thread_Nonce_Gen_Handle = osThreadCreate(osThread(Nonce), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
 

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 144;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* CAN1_TX_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(CAN1_TX_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(CAN1_TX_IRQn);
  /* CAN1_RX0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(CAN1_RX0_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);
  /* CAN1_RX1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(CAN1_RX1_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(CAN1_RX1_IRQn);
  /* CAN1_SCE_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(CAN1_SCE_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(CAN1_SCE_IRQn);
  /* CAN2_TX_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(CAN2_TX_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(CAN2_TX_IRQn);
  /* CAN2_RX0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(CAN2_RX0_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(CAN2_RX0_IRQn);
  /* CAN2_RX1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(CAN2_RX1_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(CAN2_RX1_IRQn);
  /* CAN2_SCE_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(CAN2_SCE_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(CAN2_SCE_IRQn);
}

/* CAN1 init function */
static void MX_CAN1_Init(void)
{

  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 3;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_8TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_3TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = ENABLE;
  hcan1.Init.AutoWakeUp = ENABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* CAN2 init function */
static void MX_CAN2_Init(void)
{

  hcan2.Instance = CAN2;
  hcan2.Init.Prescaler = 3;
  hcan2.Init.Mode = CAN_MODE_NORMAL;
  hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan2.Init.TimeSeg1 = CAN_BS1_8TQ;
  hcan2.Init.TimeSeg2 = CAN_BS2_3TQ;
  hcan2.Init.TimeTriggeredMode = DISABLE;
  hcan2.Init.AutoBusOff = ENABLE;
  hcan2.Init.AutoWakeUp = ENABLE;
  hcan2.Init.AutoRetransmission = DISABLE;
  hcan2.Init.ReceiveFifoLocked = DISABLE;
  hcan2.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Pinout Configuration
*/
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
static void CAN_Config(void) {
	CAN_FilterTypeDef sFilterConfig;

	/*##-2- Configure the CAN Filter ###########################################*/
	sFilterConfig.FilterBank = 0;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = 0x0000;
	sFilterConfig.FilterIdLow = 0x0000;
	sFilterConfig.FilterMaskIdHigh = 0x0000;
	sFilterConfig.FilterMaskIdLow = 0x0000;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig) != HAL_OK) {
		/* Filter configuration Error */
		Error_Handler();
	}

	/*##-2- Configure the CAN Filter ###########################################*/
	sFilterConfig.FilterBank = 14;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = 0x0000;
	sFilterConfig.FilterIdLow = 0x0000;
	sFilterConfig.FilterMaskIdHigh = 0x0000;
	sFilterConfig.FilterMaskIdLow = 0x0000;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO1;
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(&hcan2, &sFilterConfig) != HAL_OK) {
		/* Filter configuration Error */
		Error_Handler();
	}

	/*##-3- Start the CAN peripheral ###########################################*/
	if (HAL_CAN_Start(&hcan1) != HAL_OK) {
		/* Start Error */
		Error_Handler();
	}

	if (HAL_CAN_Start(&hcan2) != HAL_OK) {
		/* Start Error */
		Error_Handler();
	}
	/*##-4- Activate CAN RX notification #######################################*/
	if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING)
			!= HAL_OK) {
		/* Notification Error */
		Error_Handler();
	}
	if (HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO1_MSG_PENDING)
			!= HAL_OK) {
		/* Notification Error */
		Error_Handler();
	}

}

/**
 * @brief  Rx Fifo 0 message pending callback
 * @param  hcan: pointer to a CAN_HandleTypeDef structure that contains
 *         the configuration information for the specified CAN.
 * @retval None
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
	/* Get RX message */
	if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxCan1Header, RxCan1Data)
			!= HAL_OK) {
		/* Reception Error */
		Error_Handler();
	}

	/* Display LEDx */
	if (RxCan1Header.StdId == PDP_ABAC_Get_Nonce.getID()) {
		Attribute tmpAttribute;
		PDP_ABAC_Get_Nonce.Merge(RxCan1Data);
		tmpAttribute = frameToAttribute(PDP_ABAC_Get_Nonce.getData());
		if(tmpAttribute == resourceType_parameters){
			oldNonce = newNonce;
			sendNonce(tmpAttribute);
		}
	}
	if (RxCan1Header.StdId == PDP_ABAC_Unlock_ResourceMsg.getID()) {
		Attribute tmpAttribute;
		uint16_t key;
		tmpAttribute = frameToAttribute(PDP_ABAC_Get_Nonce.getData());
		PDP_ABAC_Unlock_ResourceMsg.Merge(RxCan1Data);
		pullPDP_ABAC_Unlock_ResourceMsg();
		key = PDP_ABAC_Unlock_ResourceMsg_ABAC_Key.getRawValue();
		if((key == (oldNonce ^ KEY_ECU)) && tmpAttribute == resourceType_parameters){
			timerStart = true;
			ECU2_ABAC_ECU_Resp_ABAC_Attribute_ID.setValues(tmpAttribute.getID());
			ECU2_ABAC_ECU_Resp_ABAC_Attribute_Value.setValues(tmpAttribute.getValue());
			ECU2_ABAC_ECU_Resp_ABAC_ResourceResp.setValues(1);
			pushECU2_ABAC_ECU_Resp();
			send(ECU2_ABAC_ECU_Resp,hcan1);
			oldNonce = newNonce;
		}
		else {
			timerStart = false;
			ECU2_ABAC_ECU_Resp_ABAC_Attribute_ID.setValues(tmpAttribute.getID());
			ECU2_ABAC_ECU_Resp_ABAC_Attribute_Value.setValues(tmpAttribute.getValue());
			ECU2_ABAC_ECU_Resp_ABAC_ResourceResp.setValues(0);
			pushECU2_ABAC_ECU_Resp();
			send(ECU2_ABAC_ECU_Resp,hcan1);
		}
	}

}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan) {
	uint8_t Test = 0;
	if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO1, &RxCan2Header, RxCan2Data)
			!= HAL_OK) {
		/* Reception Error */
		Error_Handler();
	}

	/* Display LEDx */
}

bool send(CMessage<uint8_t> pMsgObj_,CAN_HandleTypeDef pChannel_){
	CAN_TxHeaderTypeDef TxCan1Header;
	uint32_t TxCan1Mailbox;
	TxCan1Header.RTR = CAN_RTR_DATA;
	TxCan1Header.IDE = CAN_ID_STD;
	TxCan1Header.TransmitGlobalTime = DISABLE;
	TxCan1Header.StdId = pMsgObj_.getID();
	TxCan1Header.DLC = pMsgObj_.getDLC();
	if (HAL_CAN_AddTxMessage(&pChannel_, &TxCan1Header, pMsgObj_.getData(), &TxCan1Mailbox) != HAL_OK)
	{
	  /* Transmission request Error */
		return false;
	}
	return true;
}

bool send(CMessage<uint16_t> pMsgObj_,CAN_HandleTypeDef pChannel_){
	CAN_TxHeaderTypeDef TxCan1Header;
	uint32_t TxCan1Mailbox;
	TxCan1Header.RTR = CAN_RTR_DATA;
	TxCan1Header.IDE = CAN_ID_STD;
	TxCan1Header.TransmitGlobalTime = DISABLE;
	TxCan1Header.StdId = pMsgObj_.getID();
	TxCan1Header.DLC = pMsgObj_.getDLC();
	if (HAL_CAN_AddTxMessage(&pChannel_, &TxCan1Header, pMsgObj_.getData(), &TxCan1Mailbox) != HAL_OK)
	{
	  /* Transmission request Error */
		return false;
	}
	return true;
}

bool send(CMessage<uint32_t> pMsgObj_,CAN_HandleTypeDef pChannel_){
	CAN_TxHeaderTypeDef TxCan1Header;
	uint32_t TxCan1Mailbox;
	TxCan1Header.RTR = CAN_RTR_DATA;
	TxCan1Header.IDE = CAN_ID_STD;
	TxCan1Header.TransmitGlobalTime = DISABLE;
	TxCan1Header.StdId = pMsgObj_.getID();
	TxCan1Header.DLC = pMsgObj_.getDLC();
	if (HAL_CAN_AddTxMessage(&pChannel_, &TxCan1Header, pMsgObj_.getData(), &TxCan1Mailbox) != HAL_OK)
	{
	  /* Transmission request Error */
		return false;
	}
	return true;
}

bool send(CMessage<uint64_t> pMsgObj_,CAN_HandleTypeDef pChannel_){
	CAN_TxHeaderTypeDef TxCan1Header;
	uint32_t TxCan1Mailbox;
	TxCan1Header.RTR = CAN_RTR_DATA;
	TxCan1Header.IDE = CAN_ID_STD;
	TxCan1Header.TransmitGlobalTime = DISABLE;
	TxCan1Header.StdId = pMsgObj_.getID();
	TxCan1Header.DLC = pMsgObj_.getDLC();
	if (HAL_CAN_AddTxMessage(&pChannel_, &TxCan1Header, pMsgObj_.getData(), &TxCan1Mailbox) != HAL_OK)
	{
	  /* Transmission request Error */
		return false;
	}
	return true;
}

bool send(CAN_TxHeaderTypeDef pHeader_,uint8_t *pData_, CAN_HandleTypeDef pChannel_){
	CAN_TxHeaderTypeDef TxCan1Header;
	uint32_t TxCan1Mailbox;
	TxCan1Header.RTR = CAN_RTR_DATA;
	TxCan1Header.IDE = CAN_ID_STD;
	TxCan1Header.TransmitGlobalTime = DISABLE;
	TxCan1Header.StdId = pHeader_.StdId;
	TxCan1Header.DLC = pHeader_.DLC;
	if (HAL_CAN_AddTxMessage(&pChannel_, &TxCan1Header, pData_, &TxCan1Mailbox) != HAL_OK)
	{
	  /* Transmission request Error */
		return false;
	}
	return true;
}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_Thread_Main */
/**
  * @brief  Function implementing the Thread_Main.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_Thread_Main */
void Thread_Main(void const * argument)
{

  /* USER CODE BEGIN 5 */
	CAN_TxHeaderTypeDef TxCan1Header;
	uint8_t TxCan1Data[8];
	uint32_t TxCan1Mailbox;

	TxCan1Header.StdId = 0x325;
	TxCan1Header.RTR = CAN_RTR_DATA;
	TxCan1Header.IDE = CAN_ID_STD;
	TxCan1Header.DLC = 1;
	TxCan1Header.TransmitGlobalTime = DISABLE;

	TxCan1Data[0] = 0xFF;

	/* Infinite loop */
	for (;;) {
		if(timerStart == true)
		{
			TxCan1Data[0]++;
		}
        if (HAL_CAN_AddTxMessage(&hcan1, &TxCan1Header, TxCan1Data, &TxCan1Mailbox) != HAL_OK)
        {
          /* Transmission request Error */
          Error_Handler();
        }
		osDelay(100);
	}
  /* USER CODE END 5 */ 
}

/* USER CODE BEGIN Header_Thread_Nonce_Gen */
/**
  * @brief  Function implementing the Thread_Nonce_Gen thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Thread_Nonce_Gen */
void Thread_Nonce_Gen(void const * argument)
{

  /* USER CODE BEGIN 5 */
	/* Infinite loop */
	for (;;) {
		newNonce++;
		osDelay(1);
	}
  /* USER CODE END 5 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
