################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mcal/DIO_driver/DIO.c \
../mcal/DIO_driver/DIO_cnfg.c 

OBJS += \
./mcal/DIO_driver/DIO.o \
./mcal/DIO_driver/DIO_cnfg.o 

C_DEPS += \
./mcal/DIO_driver/DIO.d \
./mcal/DIO_driver/DIO_cnfg.d 


# Each subdirectory must supply rules for building sources it contributes
mcal/DIO_driver/%.o: ../mcal/DIO_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


