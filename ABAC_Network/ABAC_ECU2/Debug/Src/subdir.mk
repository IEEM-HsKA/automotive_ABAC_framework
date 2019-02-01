################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/freertos.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_hal_timebase_TIM.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c 

CPP_SRCS += \
../Src/ABAC_Com_20181007_dbc.cpp \
../Src/Attribute.cpp \
../Src/main.cpp 

OBJS += \
./Src/ABAC_Com_20181007_dbc.o \
./Src/Attribute.o \
./Src/freertos.o \
./Src/main.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_hal_timebase_TIM.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/freertos.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_hal_timebase_TIM.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d 

CPP_DEPS += \
./Src/ABAC_Com_20181007_dbc.d \
./Src/Attribute.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F446xx -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Inc" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Drivers/STM32F4xx_HAL_Driver/Inc" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Middlewares/Third_Party/FreeRTOS/Source/include" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Drivers/CMSIS/Include"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F446xx -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Inc" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Drivers/STM32F4xx_HAL_Driver/Inc" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Middlewares/Third_Party/FreeRTOS/Source/include" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"J:/Repositories/ABAC_Framework/ABAC_Network/ABAC_ECU2/Drivers/CMSIS/Include"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


