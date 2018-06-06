.section .isr_vector
.align 2

.weakref NMI_handler,_exit
.weakref HardFault_handler,_exit
.weakref MemManage_handler,_exit
.weakref BusFault_handler,_exit
.weakref UsageFault_handler,_exit
.weakref Dummy_handler,_exit
.weakref SVC_handler,_exit
.weakref DebugMon_handler,_exit
.weakref PendSV_handler,_exit
.weakref SysTick_handler,_exit

.weakref DMA_channel_0_complete_handler,_exit
.weakref DMA_channel_1_complete_handler,_exit
.weakref DMA_channel_2_complete_handler,_exit
.weakref DMA_channel_3_complete_handler,_exit
.weakref DMA_channel_4_complete_handler,_exit
.weakref DMA_channel_5_complete_handler,_exit
.weakref DMA_channel_6_complete_handler,_exit
.weakref DMA_channel_7_complete_handler,_exit
.weakref DMA_channel_8_complete_handler,_exit
.weakref DMA_channel_9_complete_handler,_exit
.weakref DMA_channel_10_complete_handler,_exit
.weakref DMA_channel_11_complete_handler,_exit
.weakref DMA_channel_12_complete_handler,_exit
.weakref DMA_channel_13_complete_handler,_exit
.weakref DMA_channel_14_complete_handler,_exit
.weakref DMA_channel_15_complete_handler,_exit
.weakref DMA_error_handler,_exit
.weakref FPU_error_handler,_exit
.weakref Flash_command_complete_handler,_exit
.weakref Flash_read_collision_handler,_exit
.weakref Low_voltage_detect_handler,_exit
.weakref Low_leakage_wakeup_handler,_exit
.weakref Watchdog_handler,_exit
.weakref Random_number_generator_handler,_exit
.weakref SPI0_handler,_exit
.weakref SPI1_handler,_exit
.weakref I2S0_transmit_handler,_exit
.weakref I2S0_receive_handler,_exit
.weakref LPUART0_status_and_error_handler,_exit
.weakref UART0_status_handler,_exit
.weakref UART0_error_handler,_exit
.weakref UART1_status_handler,_exit
.weakref UART1_error_handler,_exit
.weakref UART2_status_handler,_exit
.weakref UART2_error_handler,_exit
.weakref ADC0_handler,_exit
.weakref CMP0_handler,_exit
.weakref CMP1_handler,_exit
.weakref FTM0_handler,_exit
.weakref FTM1_handler,_exit
.weakref FTM2_handler,_exit
.weakref Real_time_clock_alarm_handler,_exit
.weakref Real_time_clock_seconds_handler,_exit
.weakref Programmable_interrupt_timer_channel_0_handler,_exit
.weakref Programmable_interrupt_timer_channel_1_handler,_exit
.weakref Programmable_interrupt_timer_channel_2_handler,_exit
.weakref Programmable_interrupt_timer_channel_3_handler,_exit
.weakref Programmable_delay_block_handler,_exit
.weakref USB_OTG_handler,_exit
.weakref DAC0_handler,_exit
.weakref Master_clock_generation_handler,_exit
.weakref Low_power_timer_handler,_exit
.weakref Pin_detect_port_A_handler,_exit
.weakref Pin_detect_port_B_handler,_exit
.weakref Pin_detect_port_C_handler,_exit
.weakref Pin_detect_port_D_handler,_exit
.weakref Pin_detect_port_E_handler,_exit
.weakref Software_interrupt_handler,_exit
.weakref FTM3_handler,_exit
.weakref DAC1_handler,_exit
.weakref ADC1_handler,_exit

.word __c_stack_top__
.word _start+1
.word NMI_handler+1
.word HardFault_handler+1
.word MemManage_handler+1
.word BusFault_handler+1
.word UsageFault_handler+1
.word Dummy_handler+1
.word Dummy_handler+1
.word Dummy_handler+1
.word Dummy_handler+1
.word SVC_handler+1
.word DebugMon_handler+1
.word Dummy_handler+1
.word PendSV_handler+1
.word SysTick_handler+1

.word DMA_channel_0_complete_handler
.word DMA_channel_1_complete_handler
.word DMA_channel_2_complete_handler
.word DMA_channel_3_complete_handler
.word DMA_channel_4_complete_handler
.word DMA_channel_5_complete_handler
.word DMA_channel_6_complete_handler
.word DMA_channel_7_complete_handler
.word DMA_channel_8_complete_handler
.word DMA_channel_9_complete_handler
.word DMA_channel_10_complete_handler
.word DMA_channel_11_complete_handler
.word DMA_channel_12_complete_handler
.word DMA_channel_13_complete_handler
.word DMA_channel_14_complete_handler
.word DMA_channel_15_complete_handler
.word DMA_error_handler
.word FPU_error_handler
.word Flash_command_complete_handler
.word Flash_read_collision_handler
.word Low_voltage_detect_handler
.word Low_leakage_wakeup_handler
.word Watchdog_handler
.word Random_number_generator_handler
.word Dummy_handler
.word Dummy_handler
.word SPI0_handler
.word SPI1_handler
.word I2S0_transmit_handler
.word I2S0_receive_handler
.word LPUART0_status_and_error_handler
.word UART0_status_handler
.word UART0_error_handler
.word UART1_status_handler
.word UART1_error_handler
.word UART2_status_handler
.word UART2_error_handler
.word Dummy_handler
.word Dummy_handler
.word ADC0_handler
.word CMP0_handler
.word CMP1_handler
.word FTM0_handler
.word FTM1_handler
.word FTM2_handler
.word Dummy_handler
.word Real_time_clock_alarm_handler
.word Real_time_clock_seconds_handler
.word Programmable_interrupt_timer_channel_0_handler
.word Programmable_interrupt_timer_channel_1_handler
.word Programmable_interrupt_timer_channel_2_handler
.word Programmable_interrupt_timer_channel_3_handler
.word Programmable_delay_block_handler
.word USB_OTG_handler
.word Dummy_handler
.word Dummy_handler
.word DAC0_handler
.word Master_clock_generation_handler
.word Low_power_timer_handler
.word Pin_detect_port_A_handler
.word Pin_detect_port_B_handler
.word Pin_detect_port_C_handler
.word Pin_detect_port_D_handler
.word Pin_detect_port_E_handler
.word Software_interrupt_handler
.word Dummy_handler
.word Dummy_handler
.word Dummy_handler
.word Dummy_handler
.word Dummy_handler
.word Dummy_handler
.word FTM3_handler
.word DAC1_handler
.word ADC1_handler

.section .text
.syntax unified
.thumb

.extern low_level_init
.extern main

.extern __bss_start
.extern __bss_end
.extern __data_load
.extern __data_start
.extern _edata
.extern __heap_start
.extern __heap_end

.extern __preinit_array_start
.extern __preinit_array_end
.extern __init_array_start
.extern __init_array_end
.extern __fini_array_start
.extern __fini_array_end

.weak low_level_init

# call with array_start in a1, array_end in a2
# assumes a function signature of void (*f)()
call_function_array:
    cmp a1, a2
    it eq
    bxeq lr
    ldr a3, [a1], #4
    push {a1, a2}
    blx a3
    pop {a1, a2}
    b call_function_array


.global _start
.global _exit

_start:
    ldr v1,=low_level_init
    blx v1

    ldr v1, =__bss_start
    ldr v2, =__bss_end
    mov a1, #0

zero_bss:
    cmp v1, v2
    itt ne
    strne a1, [v1], #4
    bne zero_bss

    ldr v1, =__data_start
    ldr v2, =_edata
    ldr v3, =__data_load
init_data:
    cmp v1, v2
    ittt ne
    ldrne a1, [v3], #4
    strne a1, [v1], #4
    bne init_data

    ldr a1, =__preinit_array_start
    ldr a2, =__preinit_array_end
    bl call_function_array

    ldr a1, =__init_array_start
    ldr a2, =__init_array_end
    bl call_function_array

    ldr v1,=main
    blx v1
    push {a1}

    ldr a1, =__fini_array_start
    ldr a2, =__fini_array_end
    bl call_function_array

    pop {a1}

_exit:
    b.n _exit

# fini
# _exit
