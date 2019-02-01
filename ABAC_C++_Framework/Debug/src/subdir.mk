################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ABAC.cpp \
../src/Attribute.cpp \
../src/src.cpp 

OBJS += \
./src/ABAC.o \
./src/Attribute.o \
./src/src.o 

CPP_DEPS += \
./src/ABAC.d \
./src/Attribute.d \
./src/src.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"J:\Repositories\ABAC_Framework\ABAC_C++_Framework\inc" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


