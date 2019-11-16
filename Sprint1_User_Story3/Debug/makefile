################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mcal/DIO_driver/subdir.mk
-include FREE_RTOS_Files/subdir.mk
-include ECUAL/LED_driver/subdir.mk
-include ECUAL/LCD_driver/subdir.mk
-include ECUAL/KeyPad_driver/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Sprint1_User_Story3.lss \

FLASH_IMAGE += \
Sprint1_User_Story3.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Sprint1_User_Story3.elf secondary-outputs

# Tool invocations
Sprint1_User_Story3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Sprint1_User_Story3.map -mmcu=atmega32 -o "Sprint1_User_Story3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Sprint1_User_Story3.lss: Sprint1_User_Story3.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Sprint1_User_Story3.elf  >"Sprint1_User_Story3.lss"
	@echo 'Finished building: $@'
	@echo ' '

Sprint1_User_Story3.hex: Sprint1_User_Story3.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Sprint1_User_Story3.elf  "Sprint1_User_Story3.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Sprint1_User_Story3.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Sprint1_User_Story3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Sprint1_User_Story3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
