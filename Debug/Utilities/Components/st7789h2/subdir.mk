################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/Components/st7789h2/st7789h2.c 

OBJS += \
./Utilities/Components/st7789h2/st7789h2.o 

C_DEPS += \
./Utilities/Components/st7789h2/st7789h2.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/Components/st7789h2/%.o: ../Utilities/Components/st7789h2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ampire480272" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/n25q512a" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/s5k5cag" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/mfxstm32l152" -I"C:/Users/jeremy/workspace/pure/CMSIS/device" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/n25q128a" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ts3510" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/st7735" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/rk043fn48h" -I"C:/Users/jeremy/workspace/pure/HAL_Driver/Inc/Legacy" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ov9655" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/otm8009a" -I"C:/Users/jeremy/workspace/pure/Utilities/STM32746G-Discovery" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/Common" -I"C:/Users/jeremy/workspace/pure/HAL_Driver/Inc" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/stmpe811" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/wm8994" -I"C:/Users/jeremy/workspace/pure/Utilities/Fonts" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ft5336" -I"C:/Users/jeremy/workspace/pure/inc" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ft6x06" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/exc7200" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/st7789h2" -I"C:/Users/jeremy/workspace/pure/Utilities/Log" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/adv7533" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ampire640480" -I"C:/Users/jeremy/workspace/pure/CMSIS/core" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/mx25l512" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


