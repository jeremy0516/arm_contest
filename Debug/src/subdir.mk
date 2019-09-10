################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/7seg.c \
../src/delay.c \
../src/hc_sr04.c \
../src/helper.c \
../src/horn.c \
../src/initializer.c \
../src/main.c \
../src/motion.c \
../src/servo.c \
../src/stm32f7xx_hal_msp.c \
../src/stm32f7xx_it.c \
../src/syscalls.c \
../src/system_stm32f7xx.c \
../src/timer.c 

OBJS += \
./src/7seg.o \
./src/delay.o \
./src/hc_sr04.o \
./src/helper.o \
./src/horn.o \
./src/initializer.o \
./src/main.o \
./src/motion.o \
./src/servo.o \
./src/stm32f7xx_hal_msp.o \
./src/stm32f7xx_it.o \
./src/syscalls.o \
./src/system_stm32f7xx.o \
./src/timer.o 

C_DEPS += \
./src/7seg.d \
./src/delay.d \
./src/hc_sr04.d \
./src/helper.d \
./src/horn.d \
./src/initializer.d \
./src/main.d \
./src/motion.d \
./src/servo.d \
./src/stm32f7xx_hal_msp.d \
./src/stm32f7xx_it.d \
./src/syscalls.d \
./src/system_stm32f7xx.d \
./src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ampire480272" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/n25q512a" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/s5k5cag" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/mfxstm32l152" -I"C:/Users/jeremy/workspace/pure/CMSIS/device" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/n25q128a" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ts3510" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/st7735" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/rk043fn48h" -I"C:/Users/jeremy/workspace/pure/HAL_Driver/Inc/Legacy" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ov9655" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/otm8009a" -I"C:/Users/jeremy/workspace/pure/Utilities/STM32746G-Discovery" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/Common" -I"C:/Users/jeremy/workspace/pure/HAL_Driver/Inc" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/stmpe811" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/wm8994" -I"C:/Users/jeremy/workspace/pure/Utilities/Fonts" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ft5336" -I"C:/Users/jeremy/workspace/pure/inc" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ft6x06" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/exc7200" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/st7789h2" -I"C:/Users/jeremy/workspace/pure/Utilities/Log" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/adv7533" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/ampire640480" -I"C:/Users/jeremy/workspace/pure/CMSIS/core" -I"C:/Users/jeremy/workspace/pure/Utilities/Components/mx25l512" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


