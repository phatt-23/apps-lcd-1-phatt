################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../button_classes.cpp \
../graph_class.cpp \
../lcd_lib.cpp \
../main.cpp 

CPP_DEPS += \
./button_classes.d \
./graph_class.d \
./lcd_lib.d \
./main.d 

OBJS += \
./button_classes.o \
./graph_class.o \
./lcd_lib.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -std=gnu++14 -DTARGET_NAME=K64F -DCOMPONENT_SD=1 -DDEVICE_RTC=1 -DFSL_RTOS_MBED -DTOOLCHAIN_GCC -DTARGET_LIKE_CORTEX_M4 -DTARGET_Freescale -DTARGET_MCUXpresso_MCUS -DTARGET_KPSDK_CODE -DTOOLCHAIN_GCC_ARM -DFEATURE_PSA=1 -DDEVICE_USTICKER=1 -DDEVICE_PORTIN=1 -DDEVICE_USBDEVICE=1 -DDEVICE_STDIO_MESSAGES=1 -DCOMPONENT_FLASHIAP=1 -DDEVICE_EMAC=1 -DDEVICE_TRNG=1 -DMBED_SPLIT_HEAP -DTARGET_KPSDK_MCUS -DTARGET_MCU_K64F -DDEVICE_PORTOUT=1 -D__MBED__=1 -DTARGET_Freescale_EMAC -DMBED_TICKLESS -DDEVICE_SERIAL=1 -DTARGET_PSA_Target -DDEVICE_PORTINOUT=1 -DDEVICE_LPTICKER=1 -DDEVICE_SERIAL_FC=1 -DTARGET_KSDK2_MCUS -DDEVICE_WATCHDOG=1 -DTARGET_PSA_V7_M -DDEVICE_ANALOGOUT=1 -DDEVICE_SPI_ASYNCH=1 -DDEVICE_ANALOGIN=1 -DDEVICE_I2C=1 -DTARGET_M4 -DDEVICE_SLEEP=1 -D__CORTEX_M4 -D__MBED_CMSIS_RTOS_CM -DDEVICE_FLASH=1 -DTARGET_K64F -DARM_MATH_CM4 -DMBED_BUILD_TIMESTAMP=1645455281.1211684 -DDEVICE_INTERRUPTIN=1 -DTARGET_RELEASE -DTARGET_LIKE_MBED -DTARGET_RTOS_M4_M7 -D__FPU_PRESENT=1 -DDEVICE_SERIAL_ASYNCH=1 -DTARGET_FRDM -DDEVICE_SPI=1 -D__CMSIS_RTOS -DTARGET_MBED_PSA_SRV -DDEVICE_RESET_REASON=1 -DDEVICE_SPISLAVE=1 -DTARGET_CORTEX -DTARGET_CORTEX_M -DDEVICE_PWMOUT=1 -DTARGET_FF_ARDUINO_UNO -DDEVICE_I2CSLAVE=1 -DDEVICE_CRC=1 -DCPU_MK64FN1M0VMD12 -D__NEWLIB__ -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/." -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/cmsis" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/cmsis/CMSIS_5" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/cmsis/CMSIS_5/CMSIS" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/cmsis/CMSIS_5/CMSIS/TARGET_CORTEX_M" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/cmsis/CMSIS_5/CMSIS/TARGET_CORTEX_M/Include" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/cmsis/device" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/cmsis/device/RTE" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/cmsis/device/RTE/include" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/drivers" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/drivers/include" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/drivers/include/drivers" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/drivers/include/drivers/interfaces" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/features" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/features/frameworks" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/hal" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/hal/include" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/hal/include/hal" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/hal/usb" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/hal/usb/include" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/hal/usb/include/usb" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/platform" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/platform/cxxsupport" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/platform/include" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/platform/include/platform" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/platform/include/platform/internal" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/platform/mbed-trace" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/platform/mbed-trace/include" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/platform/mbed-trace/include/mbed-trace" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/platform/source" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/platform/source/minimal-printf" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/rtos" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/rtos/include" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/rtos/include/rtos" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/rtos/include/rtos/internal" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/rtos/source" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/storage" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/storage/blockdevice" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/storage/blockdevice/include" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/storage/blockdevice/include/blockdevice" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/storage/blockdevice/include/blockdevice/internal" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/targets/TARGET_Freescale" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/targets/TARGET_Freescale/TARGET_MCUXpresso_MCUS" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/targets/TARGET_Freescale/TARGET_MCUXpresso_MCUS/TARGET_MCU_K64F" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/targets/TARGET_Freescale/TARGET_MCUXpresso_MCUS/TARGET_MCU_K64F/TARGET_FRDM" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/targets/TARGET_Freescale/TARGET_MCUXpresso_MCUS/TARGET_MCU_K64F/device" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/targets/TARGET_Freescale/TARGET_MCUXpresso_MCUS/TARGET_MCU_K64F/drivers" -I"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed-os/targets/TARGET_Freescale/TARGET_MCUXpresso_MCUS/api" -include"/home/phatt/University/apps/lcd-1-prep/apps-workspace.mcu/lcd/mbed_config.h" -fno-rtti -fmessage-length=0 -fno-exceptions -ffunction-sections -fdata-sections -funsigned-char -fomit-frame-pointer -g3 -gdwarf-4 -Wall -Wextra -c -DMBED_DEBUG -DMBED_TRAP_ERRORS_ENABLED=1 -DMBED_MINIMAL_PRINTF -c -g3 -Wno-unused-parameter -Wno-missing-field-initializers -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./button_classes.d ./button_classes.o ./graph_class.d ./graph_class.o ./lcd_lib.d ./lcd_lib.o ./main.d ./main.o

.PHONY: clean--2e-

