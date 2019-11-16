################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/LCD_driver/LCD.c \
../ECUAL/LCD_driver/LCD_PostBuildconfg.c 

OBJS += \
./ECUAL/LCD_driver/LCD.o \
./ECUAL/LCD_driver/LCD_PostBuildconfg.o 

C_DEPS += \
./ECUAL/LCD_driver/LCD.d \
./ECUAL/LCD_driver/LCD_PostBuildconfg.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/LCD_driver/%.o: ../ECUAL/LCD_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


