################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32_ILI9341_Driver/Src/fonts.c \
../Drivers/STM32_ILI9341_Driver/Src/ili9341.c \
../Drivers/STM32_ILI9341_Driver/Src/ili9341_touch.c \
../Drivers/STM32_ILI9341_Driver/Src/stm32f4xx_hal_msp.c 

OBJS += \
./Drivers/STM32_ILI9341_Driver/Src/fonts.o \
./Drivers/STM32_ILI9341_Driver/Src/ili9341.o \
./Drivers/STM32_ILI9341_Driver/Src/ili9341_touch.o \
./Drivers/STM32_ILI9341_Driver/Src/stm32f4xx_hal_msp.o 

C_DEPS += \
./Drivers/STM32_ILI9341_Driver/Src/fonts.d \
./Drivers/STM32_ILI9341_Driver/Src/ili9341.d \
./Drivers/STM32_ILI9341_Driver/Src/ili9341_touch.d \
./Drivers/STM32_ILI9341_Driver/Src/stm32f4xx_hal_msp.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32_ILI9341_Driver/Src/%.o Drivers/STM32_ILI9341_Driver/Src/%.su Drivers/STM32_ILI9341_Driver/Src/%.cyclo: ../Drivers/STM32_ILI9341_Driver/Src/%.c Drivers/STM32_ILI9341_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Inc -I"C:/STM32/External packages/SPI_LCD_Driver/Drivers/CMSIS/Include" -I"C:/STM32/External packages/SPI_LCD_Driver/Drivers/STM32_ILI9341_Driver/Inc" -I"C:/STM32/External packages/SPI_LCD_Driver/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/STM32/External packages/SPI_LCD_Driver/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32_ILI9341_Driver-2f-Src

clean-Drivers-2f-STM32_ILI9341_Driver-2f-Src:
	-$(RM) ./Drivers/STM32_ILI9341_Driver/Src/fonts.cyclo ./Drivers/STM32_ILI9341_Driver/Src/fonts.d ./Drivers/STM32_ILI9341_Driver/Src/fonts.o ./Drivers/STM32_ILI9341_Driver/Src/fonts.su ./Drivers/STM32_ILI9341_Driver/Src/ili9341.cyclo ./Drivers/STM32_ILI9341_Driver/Src/ili9341.d ./Drivers/STM32_ILI9341_Driver/Src/ili9341.o ./Drivers/STM32_ILI9341_Driver/Src/ili9341.su ./Drivers/STM32_ILI9341_Driver/Src/ili9341_touch.cyclo ./Drivers/STM32_ILI9341_Driver/Src/ili9341_touch.d ./Drivers/STM32_ILI9341_Driver/Src/ili9341_touch.o ./Drivers/STM32_ILI9341_Driver/Src/ili9341_touch.su ./Drivers/STM32_ILI9341_Driver/Src/stm32f4xx_hal_msp.cyclo ./Drivers/STM32_ILI9341_Driver/Src/stm32f4xx_hal_msp.d ./Drivers/STM32_ILI9341_Driver/Src/stm32f4xx_hal_msp.o ./Drivers/STM32_ILI9341_Driver/Src/stm32f4xx_hal_msp.su

.PHONY: clean-Drivers-2f-STM32_ILI9341_Driver-2f-Src

