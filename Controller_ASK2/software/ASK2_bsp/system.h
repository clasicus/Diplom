/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'cpu_ASK2'
 * SOPC Builder design path: D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/cpu_ASK2.sopcinfo
 *
 * Generated: Tue May 22 15:09:43 EEST 2018
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x4820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "small"
#define ALT_CPU_DATA_ADDR_WIDTH 0xf
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x2020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INST_ADDR_WIDTH 0xf
#define ALT_CPU_NAME "nios2_qsys_0"
#define ALT_CPU_RESET_ADDR 0x2000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x4820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "small"
#define NIOS2_DATA_ADDR_WIDTH 0xf
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x2020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INST_ADDR_WIDTH 0xf
#define NIOS2_RESET_ADDR 0x2000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_NIOS2_QSYS


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone III"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x50e8
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x50e8
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x50e8
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "cpu_ASK2"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x50e8
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x2000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "cpu_ASK2_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 8096
#define ONCHIP_MEMORY2_0_SPAN 8096
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * pio_A1_A0 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_A1_A0 altera_avalon_pio
#define PIO_A1_A0_BASE 0x5050
#define PIO_A1_A0_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_A1_A0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_A1_A0_CAPTURE 0
#define PIO_A1_A0_DATA_WIDTH 2
#define PIO_A1_A0_DO_TEST_BENCH_WIRING 0
#define PIO_A1_A0_DRIVEN_SIM_VALUE 0
#define PIO_A1_A0_EDGE_TYPE "NONE"
#define PIO_A1_A0_FREQ 50000000
#define PIO_A1_A0_HAS_IN 0
#define PIO_A1_A0_HAS_OUT 1
#define PIO_A1_A0_HAS_TRI 0
#define PIO_A1_A0_IRQ -1
#define PIO_A1_A0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_A1_A0_IRQ_TYPE "NONE"
#define PIO_A1_A0_NAME "/dev/pio_A1_A0"
#define PIO_A1_A0_RESET_VALUE 0
#define PIO_A1_A0_SPAN 16
#define PIO_A1_A0_TYPE "altera_avalon_pio"


/*
 * pio_I_max configuration
 *
 */

#define ALT_MODULE_CLASS_pio_I_max altera_avalon_pio
#define PIO_I_MAX_BASE 0x5020
#define PIO_I_MAX_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_I_MAX_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_I_MAX_CAPTURE 0
#define PIO_I_MAX_DATA_WIDTH 16
#define PIO_I_MAX_DO_TEST_BENCH_WIRING 0
#define PIO_I_MAX_DRIVEN_SIM_VALUE 0
#define PIO_I_MAX_EDGE_TYPE "NONE"
#define PIO_I_MAX_FREQ 50000000
#define PIO_I_MAX_HAS_IN 0
#define PIO_I_MAX_HAS_OUT 1
#define PIO_I_MAX_HAS_TRI 0
#define PIO_I_MAX_IRQ -1
#define PIO_I_MAX_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_I_MAX_IRQ_TYPE "NONE"
#define PIO_I_MAX_NAME "/dev/pio_I_max"
#define PIO_I_MAX_RESET_VALUE 0
#define PIO_I_MAX_SPAN 16
#define PIO_I_MAX_TYPE "altera_avalon_pio"


/*
 * pio_LED2_LED1 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_LED2_LED1 altera_avalon_pio
#define PIO_LED2_LED1_BASE 0x5000
#define PIO_LED2_LED1_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_LED2_LED1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_LED2_LED1_CAPTURE 0
#define PIO_LED2_LED1_DATA_WIDTH 2
#define PIO_LED2_LED1_DO_TEST_BENCH_WIRING 0
#define PIO_LED2_LED1_DRIVEN_SIM_VALUE 0
#define PIO_LED2_LED1_EDGE_TYPE "NONE"
#define PIO_LED2_LED1_FREQ 50000000
#define PIO_LED2_LED1_HAS_IN 0
#define PIO_LED2_LED1_HAS_OUT 1
#define PIO_LED2_LED1_HAS_TRI 0
#define PIO_LED2_LED1_IRQ -1
#define PIO_LED2_LED1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_LED2_LED1_IRQ_TYPE "NONE"
#define PIO_LED2_LED1_NAME "/dev/pio_LED2_LED1"
#define PIO_LED2_LED1_RESET_VALUE 0
#define PIO_LED2_LED1_SPAN 16
#define PIO_LED2_LED1_TYPE "altera_avalon_pio"


/*
 * pio_PWM_IN configuration
 *
 */

#define ALT_MODULE_CLASS_pio_PWM_IN altera_avalon_pio
#define PIO_PWM_IN_BASE 0x5010
#define PIO_PWM_IN_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_PWM_IN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_PWM_IN_CAPTURE 0
#define PIO_PWM_IN_DATA_WIDTH 16
#define PIO_PWM_IN_DO_TEST_BENCH_WIRING 0
#define PIO_PWM_IN_DRIVEN_SIM_VALUE 0
#define PIO_PWM_IN_EDGE_TYPE "NONE"
#define PIO_PWM_IN_FREQ 50000000
#define PIO_PWM_IN_HAS_IN 0
#define PIO_PWM_IN_HAS_OUT 1
#define PIO_PWM_IN_HAS_TRI 0
#define PIO_PWM_IN_IRQ -1
#define PIO_PWM_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_PWM_IN_IRQ_TYPE "NONE"
#define PIO_PWM_IN_NAME "/dev/pio_PWM_IN"
#define PIO_PWM_IN_RESET_VALUE 0
#define PIO_PWM_IN_SPAN 16
#define PIO_PWM_IN_TYPE "altera_avalon_pio"


/*
 * pio_SDO_ADC configuration
 *
 */

#define ALT_MODULE_CLASS_pio_SDO_ADC altera_avalon_pio
#define PIO_SDO_ADC_BASE 0x5030
#define PIO_SDO_ADC_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_SDO_ADC_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_SDO_ADC_CAPTURE 0
#define PIO_SDO_ADC_DATA_WIDTH 16
#define PIO_SDO_ADC_DO_TEST_BENCH_WIRING 0
#define PIO_SDO_ADC_DRIVEN_SIM_VALUE 0
#define PIO_SDO_ADC_EDGE_TYPE "NONE"
#define PIO_SDO_ADC_FREQ 50000000
#define PIO_SDO_ADC_HAS_IN 1
#define PIO_SDO_ADC_HAS_OUT 0
#define PIO_SDO_ADC_HAS_TRI 0
#define PIO_SDO_ADC_IRQ -1
#define PIO_SDO_ADC_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_SDO_ADC_IRQ_TYPE "NONE"
#define PIO_SDO_ADC_NAME "/dev/pio_SDO_ADC"
#define PIO_SDO_ADC_RESET_VALUE 0
#define PIO_SDO_ADC_SPAN 16
#define PIO_SDO_ADC_TYPE "altera_avalon_pio"


/*
 * pio_angle configuration
 *
 */

#define ALT_MODULE_CLASS_pio_angle altera_avalon_pio
#define PIO_ANGLE_BASE 0x50d0
#define PIO_ANGLE_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_ANGLE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_ANGLE_CAPTURE 0
#define PIO_ANGLE_DATA_WIDTH 16
#define PIO_ANGLE_DO_TEST_BENCH_WIRING 0
#define PIO_ANGLE_DRIVEN_SIM_VALUE 0
#define PIO_ANGLE_EDGE_TYPE "NONE"
#define PIO_ANGLE_FREQ 50000000
#define PIO_ANGLE_HAS_IN 0
#define PIO_ANGLE_HAS_OUT 0
#define PIO_ANGLE_HAS_TRI 1
#define PIO_ANGLE_IRQ -1
#define PIO_ANGLE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_ANGLE_IRQ_TYPE "NONE"
#define PIO_ANGLE_NAME "/dev/pio_angle"
#define PIO_ANGLE_RESET_VALUE 0
#define PIO_ANGLE_SPAN 16
#define PIO_ANGLE_TYPE "altera_avalon_pio"


/*
 * pio_keyboard_SW6_SW1 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_keyboard_SW6_SW1 altera_avalon_pio
#define PIO_KEYBOARD_SW6_SW1_BASE 0x5040
#define PIO_KEYBOARD_SW6_SW1_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_KEYBOARD_SW6_SW1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_KEYBOARD_SW6_SW1_CAPTURE 0
#define PIO_KEYBOARD_SW6_SW1_DATA_WIDTH 6
#define PIO_KEYBOARD_SW6_SW1_DO_TEST_BENCH_WIRING 0
#define PIO_KEYBOARD_SW6_SW1_DRIVEN_SIM_VALUE 0
#define PIO_KEYBOARD_SW6_SW1_EDGE_TYPE "NONE"
#define PIO_KEYBOARD_SW6_SW1_FREQ 50000000
#define PIO_KEYBOARD_SW6_SW1_HAS_IN 1
#define PIO_KEYBOARD_SW6_SW1_HAS_OUT 0
#define PIO_KEYBOARD_SW6_SW1_HAS_TRI 0
#define PIO_KEYBOARD_SW6_SW1_IRQ -1
#define PIO_KEYBOARD_SW6_SW1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_KEYBOARD_SW6_SW1_IRQ_TYPE "NONE"
#define PIO_KEYBOARD_SW6_SW1_NAME "/dev/pio_keyboard_SW6_SW1"
#define PIO_KEYBOARD_SW6_SW1_RESET_VALUE 0
#define PIO_KEYBOARD_SW6_SW1_SPAN 16
#define PIO_KEYBOARD_SW6_SW1_TYPE "altera_avalon_pio"


/*
 * pio_lcd_control configuration
 *
 */

#define ALT_MODULE_CLASS_pio_lcd_control altera_avalon_pio
#define PIO_LCD_CONTROL_BASE 0x50b0
#define PIO_LCD_CONTROL_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_LCD_CONTROL_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_LCD_CONTROL_CAPTURE 0
#define PIO_LCD_CONTROL_DATA_WIDTH 3
#define PIO_LCD_CONTROL_DO_TEST_BENCH_WIRING 0
#define PIO_LCD_CONTROL_DRIVEN_SIM_VALUE 0
#define PIO_LCD_CONTROL_EDGE_TYPE "NONE"
#define PIO_LCD_CONTROL_FREQ 50000000
#define PIO_LCD_CONTROL_HAS_IN 0
#define PIO_LCD_CONTROL_HAS_OUT 1
#define PIO_LCD_CONTROL_HAS_TRI 0
#define PIO_LCD_CONTROL_IRQ -1
#define PIO_LCD_CONTROL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_LCD_CONTROL_IRQ_TYPE "NONE"
#define PIO_LCD_CONTROL_NAME "/dev/pio_lcd_control"
#define PIO_LCD_CONTROL_RESET_VALUE 0
#define PIO_LCD_CONTROL_SPAN 16
#define PIO_LCD_CONTROL_TYPE "altera_avalon_pio"


/*
 * pio_lcd_data configuration
 *
 */

#define ALT_MODULE_CLASS_pio_lcd_data altera_avalon_pio
#define PIO_LCD_DATA_BASE 0x50c0
#define PIO_LCD_DATA_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_LCD_DATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_LCD_DATA_CAPTURE 0
#define PIO_LCD_DATA_DATA_WIDTH 8
#define PIO_LCD_DATA_DO_TEST_BENCH_WIRING 0
#define PIO_LCD_DATA_DRIVEN_SIM_VALUE 0
#define PIO_LCD_DATA_EDGE_TYPE "NONE"
#define PIO_LCD_DATA_FREQ 50000000
#define PIO_LCD_DATA_HAS_IN 0
#define PIO_LCD_DATA_HAS_OUT 0
#define PIO_LCD_DATA_HAS_TRI 1
#define PIO_LCD_DATA_IRQ -1
#define PIO_LCD_DATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_LCD_DATA_IRQ_TYPE "NONE"
#define PIO_LCD_DATA_NAME "/dev/pio_lcd_data"
#define PIO_LCD_DATA_RESET_VALUE 0
#define PIO_LCD_DATA_SPAN 16
#define PIO_LCD_DATA_TYPE "altera_avalon_pio"


/*
 * pio_res_nCS configuration
 *
 */

#define ALT_MODULE_CLASS_pio_res_nCS altera_avalon_pio
#define PIO_RES_NCS_BASE 0x5060
#define PIO_RES_NCS_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_RES_NCS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_RES_NCS_CAPTURE 0
#define PIO_RES_NCS_DATA_WIDTH 1
#define PIO_RES_NCS_DO_TEST_BENCH_WIRING 0
#define PIO_RES_NCS_DRIVEN_SIM_VALUE 0
#define PIO_RES_NCS_EDGE_TYPE "NONE"
#define PIO_RES_NCS_FREQ 50000000
#define PIO_RES_NCS_HAS_IN 0
#define PIO_RES_NCS_HAS_OUT 1
#define PIO_RES_NCS_HAS_TRI 0
#define PIO_RES_NCS_IRQ -1
#define PIO_RES_NCS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_RES_NCS_IRQ_TYPE "NONE"
#define PIO_RES_NCS_NAME "/dev/pio_res_nCS"
#define PIO_RES_NCS_RESET_VALUE 0
#define PIO_RES_NCS_SPAN 16
#define PIO_RES_NCS_TYPE "altera_avalon_pio"


/*
 * pio_res_nRd configuration
 *
 */

#define ALT_MODULE_CLASS_pio_res_nRd altera_avalon_pio
#define PIO_RES_NRD_BASE 0x5090
#define PIO_RES_NRD_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_RES_NRD_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_RES_NRD_CAPTURE 0
#define PIO_RES_NRD_DATA_WIDTH 1
#define PIO_RES_NRD_DO_TEST_BENCH_WIRING 0
#define PIO_RES_NRD_DRIVEN_SIM_VALUE 0
#define PIO_RES_NRD_EDGE_TYPE "NONE"
#define PIO_RES_NRD_FREQ 50000000
#define PIO_RES_NRD_HAS_IN 0
#define PIO_RES_NRD_HAS_OUT 1
#define PIO_RES_NRD_HAS_TRI 0
#define PIO_RES_NRD_IRQ -1
#define PIO_RES_NRD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_RES_NRD_IRQ_TYPE "NONE"
#define PIO_RES_NRD_NAME "/dev/pio_res_nRd"
#define PIO_RES_NRD_RESET_VALUE 0
#define PIO_RES_NRD_SPAN 16
#define PIO_RES_NRD_TYPE "altera_avalon_pio"


/*
 * pio_res_nSOE configuration
 *
 */

#define ALT_MODULE_CLASS_pio_res_nSOE altera_avalon_pio
#define PIO_RES_NSOE_BASE 0x5070
#define PIO_RES_NSOE_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_RES_NSOE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_RES_NSOE_CAPTURE 0
#define PIO_RES_NSOE_DATA_WIDTH 1
#define PIO_RES_NSOE_DO_TEST_BENCH_WIRING 0
#define PIO_RES_NSOE_DRIVEN_SIM_VALUE 0
#define PIO_RES_NSOE_EDGE_TYPE "NONE"
#define PIO_RES_NSOE_FREQ 50000000
#define PIO_RES_NSOE_HAS_IN 0
#define PIO_RES_NSOE_HAS_OUT 0
#define PIO_RES_NSOE_HAS_TRI 1
#define PIO_RES_NSOE_IRQ -1
#define PIO_RES_NSOE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_RES_NSOE_IRQ_TYPE "NONE"
#define PIO_RES_NSOE_NAME "/dev/pio_res_nSOE"
#define PIO_RES_NSOE_RESET_VALUE 0
#define PIO_RES_NSOE_SPAN 16
#define PIO_RES_NSOE_TYPE "altera_avalon_pio"


/*
 * pio_res_nSample configuration
 *
 */

#define ALT_MODULE_CLASS_pio_res_nSample altera_avalon_pio
#define PIO_RES_NSAMPLE_BASE 0x5080
#define PIO_RES_NSAMPLE_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_RES_NSAMPLE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_RES_NSAMPLE_CAPTURE 0
#define PIO_RES_NSAMPLE_DATA_WIDTH 1
#define PIO_RES_NSAMPLE_DO_TEST_BENCH_WIRING 0
#define PIO_RES_NSAMPLE_DRIVEN_SIM_VALUE 0
#define PIO_RES_NSAMPLE_EDGE_TYPE "NONE"
#define PIO_RES_NSAMPLE_FREQ 50000000
#define PIO_RES_NSAMPLE_HAS_IN 0
#define PIO_RES_NSAMPLE_HAS_OUT 1
#define PIO_RES_NSAMPLE_HAS_TRI 0
#define PIO_RES_NSAMPLE_IRQ -1
#define PIO_RES_NSAMPLE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_RES_NSAMPLE_IRQ_TYPE "NONE"
#define PIO_RES_NSAMPLE_NAME "/dev/pio_res_nSample"
#define PIO_RES_NSAMPLE_RESET_VALUE 0
#define PIO_RES_NSAMPLE_SPAN 16
#define PIO_RES_NSAMPLE_TYPE "altera_avalon_pio"


/*
 * pio_res_nWr configuration
 *
 */

#define ALT_MODULE_CLASS_pio_res_nWr altera_avalon_pio
#define PIO_RES_NWR_BASE 0x50a0
#define PIO_RES_NWR_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_RES_NWR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_RES_NWR_CAPTURE 0
#define PIO_RES_NWR_DATA_WIDTH 1
#define PIO_RES_NWR_DO_TEST_BENCH_WIRING 0
#define PIO_RES_NWR_DRIVEN_SIM_VALUE 0
#define PIO_RES_NWR_EDGE_TYPE "NONE"
#define PIO_RES_NWR_FREQ 50000000
#define PIO_RES_NWR_HAS_IN 0
#define PIO_RES_NWR_HAS_OUT 1
#define PIO_RES_NWR_HAS_TRI 0
#define PIO_RES_NWR_IRQ -1
#define PIO_RES_NWR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_RES_NWR_IRQ_TYPE "NONE"
#define PIO_RES_NWR_NAME "/dev/pio_res_nWr"
#define PIO_RES_NWR_RESET_VALUE 0
#define PIO_RES_NWR_SPAN 16
#define PIO_RES_NWR_TYPE "altera_avalon_pio"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x50e0
#define SYSID_QSYS_0_ID 21
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1526990665
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"

#endif /* __SYSTEM_H_ */
