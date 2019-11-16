################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FREE_RTOS_Files/croutine.c \
../FREE_RTOS_Files/event_groups.c \
../FREE_RTOS_Files/heap_1.c \
../FREE_RTOS_Files/list.c \
../FREE_RTOS_Files/port.c \
../FREE_RTOS_Files/queue.c \
../FREE_RTOS_Files/stream_buffer.c \
../FREE_RTOS_Files/tasks.c \
../FREE_RTOS_Files/timers.c 

OBJS += \
./FREE_RTOS_Files/croutine.o \
./FREE_RTOS_Files/event_groups.o \
./FREE_RTOS_Files/heap_1.o \
./FREE_RTOS_Files/list.o \
./FREE_RTOS_Files/port.o \
./FREE_RTOS_Files/queue.o \
./FREE_RTOS_Files/stream_buffer.o \
./FREE_RTOS_Files/tasks.o \
./FREE_RTOS_Files/timers.o 

C_DEPS += \
./FREE_RTOS_Files/croutine.d \
./FREE_RTOS_Files/event_groups.d \
./FREE_RTOS_Files/heap_1.d \
./FREE_RTOS_Files/list.d \
./FREE_RTOS_Files/port.d \
./FREE_RTOS_Files/queue.d \
./FREE_RTOS_Files/stream_buffer.d \
./FREE_RTOS_Files/tasks.d \
./FREE_RTOS_Files/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FREE_RTOS_Files/%.o: ../FREE_RTOS_Files/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


