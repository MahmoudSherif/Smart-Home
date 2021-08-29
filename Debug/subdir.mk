################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../DIO_prog.c \
../INTERRUPT_prog.c \
../KEYPAD_prog.c \
../LCD_prog.c \
../LDR_prog.c \
../SMARTHOME_APP.c \
../SMARTHOME_prog.c \
../TEMP_SENSOR_prog.c 

OBJS += \
./ADC_prog.o \
./DIO_prog.o \
./INTERRUPT_prog.o \
./KEYPAD_prog.o \
./LCD_prog.o \
./LDR_prog.o \
./SMARTHOME_APP.o \
./SMARTHOME_prog.o \
./TEMP_SENSOR_prog.o 

C_DEPS += \
./ADC_prog.d \
./DIO_prog.d \
./INTERRUPT_prog.d \
./KEYPAD_prog.d \
./LCD_prog.d \
./LDR_prog.d \
./SMARTHOME_APP.d \
./SMARTHOME_prog.d \
./TEMP_SENSOR_prog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


