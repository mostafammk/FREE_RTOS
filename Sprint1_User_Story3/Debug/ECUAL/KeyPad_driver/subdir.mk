################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/KeyPad_driver/keypad.c 

OBJS += \
./ECUAL/KeyPad_driver/keypad.o 

C_DEPS += \
./ECUAL/KeyPad_driver/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/KeyPad_driver/%.o: ../ECUAL/KeyPad_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


