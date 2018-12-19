#include <algorithm>
#include <stdint.h>
#include <stdlib.h>
#include <cstring>

#include <miotal/ARM/Cortex/M4/NXP/K2x/wdog.hpp>

extern "C" {

extern void low_level_init();
extern int main();

extern void NMI_handler();
extern void HardFault_handler();
extern void MemManage_handler();
extern void BusFault_handler();
extern void UsageFault_handler();
extern void SVC_handler();
extern void DebugMon_handler();
extern void PendSV_handler();
extern void SysTick_handler();

extern void DMA_channel_0_complete_handler();
extern void DMA_channel_1_complete_handler();
extern void DMA_channel_2_complete_handler();
extern void DMA_channel_3_complete_handler();
extern void DMA_channel_4_complete_handler();
extern void DMA_channel_5_complete_handler();
extern void DMA_channel_6_complete_handler();
extern void DMA_channel_7_complete_handler();
extern void DMA_channel_8_complete_handler();
extern void DMA_channel_9_complete_handler();
extern void DMA_channel_10_complete_handler();
extern void DMA_channel_11_complete_handler();
extern void DMA_channel_12_complete_handler();
extern void DMA_channel_13_complete_handler();
extern void DMA_channel_14_complete_handler();
extern void DMA_channel_15_complete_handler();
extern void DMA_error_handler();
extern void FPU_error_handler();
extern void Flash_command_complete_handler();
extern void Flash_read_collision_handler();
extern void Low_voltage_detect_handler();
extern void Low_leakage_wakeup_handler();
extern void Watchdog_handler();
extern void Random_number_generator_handler();
extern void SPI0_handler();
extern void SPI1_handler();
extern void I2S0_transmit_handler();
extern void I2S0_receive_handler();
extern void LPUART0_status_and_error_handler();
extern void UART0_status_handler();
extern void UART0_error_handler();
extern void UART1_status_handler();
extern void UART1_error_handler();
extern void UART2_status_handler();
extern void UART2_error_handler();
extern void ADC0_handler();
extern void CMP0_handler();
extern void CMP1_handler();
extern void FTM0_handler();
extern void FTM1_handler();
extern void FTM2_handler();
extern void Real_time_clock_alarm_handler();
extern void Real_time_clock_seconds_handler();
extern void Programmable_interrupt_timer_channel_0_handler();
extern void Programmable_interrupt_timer_channel_1_handler();
extern void Programmable_interrupt_timer_channel_2_handler();
extern void Programmable_interrupt_timer_channel_3_handler();
extern void Programmable_delay_block_handler();
extern void USB_OTG_handler();
extern void DAC0_handler();
extern void Master_clock_generation_handler();
extern void Low_power_timer_handler();
extern void Pin_detect_port_A_handler();
extern void Pin_detect_port_B_handler();
extern void Pin_detect_port_C_handler();
extern void Pin_detect_port_D_handler();
extern void Pin_detect_port_E_handler();
extern void Software_interrupt_handler();
extern void FTM3_handler();
extern void DAC1_handler();
extern void ADC1_handler();

[[noreturn]] void _exit(int) { while (1); }

extern uintptr_t __bss_start__;
extern uintptr_t __bss_end__;

extern uintptr_t __data_load;
extern uintptr_t _edata_load;
extern uintptr_t __data_start;

extern uintptr_t __heap_start;
extern uintptr_t __heap_end;

extern void (*__preinit_array_start [] ) ();
extern void (*__preinit_array_end [] ) ();
extern void (*__init_array_start []) ();
extern void (*__init_array_end []) ();
extern void (*__fini_array_start []) ();
extern void (*__fini_array_end []) ();

[[noreturn]] void _start()
{
    // First, call the user defined initialization.  This can't really
    // go in the GCC defined init section because the compiler sets
    // up the runtime first, and by that time the window of opportunity
    // to perform activities like turn off the watchdog timer within
    // a certain number of cycles of startup has expired.  This ensures
    // the user has the ability to perform low level actions on the
    // hardware prior to any potentially heavy-weight startup actions.
    low_level_init();

    std::fill(&__bss_start__, &__bss_end__, 0);
    std::copy(&__data_load, &_edata_load, &__data_start);
    std::fill(&__heap_start, &__heap_end, 0x55555555);
    std::for_each(__preinit_array_start, __preinit_array_end, [](auto& f){ f(); });
    std::for_each(__init_array_start, __init_array_end, [](auto& f){ f(); });
    auto ret = main();
    std::for_each(__fini_array_start, __fini_array_end, [](auto& f){ f(); });
    _exit(ret);
}

__attribute__((weak)) void low_level_init() {
    using namespace platform::wdog;
    WDOG_UNLOCK.unlock();
    WDOG_STCTRLH.write(WDOG_STCTRLH.disable_watchdog);
}

namespace { __attribute__((alias("_exit"))) void Dummy_handler(); }
__attribute__((weak, alias("_exit"))) void NMI_handler();
__attribute__((weak, alias("_exit"))) void HardFault_handler();
__attribute__((weak, alias("_exit"))) void MemManage_handler();
__attribute__((weak, alias("_exit"))) void BusFault_handler();
__attribute__((weak, alias("_exit"))) void UsageFault_handler();
__attribute__((weak, alias("_exit"))) void SVC_handler();
__attribute__((weak, alias("_exit"))) void DebugMon_handler();
__attribute__((weak, alias("_exit"))) void PendSV_handler();
__attribute__((weak, alias("_exit"))) void SysTick_handler();

__attribute__((weak, alias("_exit"))) void DMA_channel_0_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_1_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_2_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_3_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_4_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_5_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_6_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_7_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_8_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_9_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_10_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_11_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_12_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_13_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_14_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_channel_15_complete_handler();
__attribute__((weak, alias("_exit"))) void DMA_error_handler();
__attribute__((weak, alias("_exit"))) void FPU_error_handler();
__attribute__((weak, alias("_exit"))) void Flash_command_complete_handler();
__attribute__((weak, alias("_exit"))) void Flash_read_collision_handler();
__attribute__((weak, alias("_exit"))) void Low_voltage_detect_handler();
__attribute__((weak, alias("_exit"))) void Low_leakage_wakeup_handler();
__attribute__((weak, alias("_exit"))) void Watchdog_handler();
__attribute__((weak, alias("_exit"))) void Random_number_generator_handler();
__attribute__((weak, alias("_exit"))) void SPI0_handler();
__attribute__((weak, alias("_exit"))) void SPI1_handler();
__attribute__((weak, alias("_exit"))) void I2S0_transmit_handler();
__attribute__((weak, alias("_exit"))) void I2S0_receive_handler();
__attribute__((weak, alias("_exit"))) void LPUART0_status_and_error_handler();
__attribute__((weak, alias("_exit"))) void UART0_status_handler();
__attribute__((weak, alias("_exit"))) void UART0_error_handler();
__attribute__((weak, alias("_exit"))) void UART1_status_handler();
__attribute__((weak, alias("_exit"))) void UART1_error_handler();
__attribute__((weak, alias("_exit"))) void UART2_status_handler();
__attribute__((weak, alias("_exit"))) void UART2_error_handler();
__attribute__((weak, alias("_exit"))) void ADC0_handler();
__attribute__((weak, alias("_exit"))) void CMP0_handler();
__attribute__((weak, alias("_exit"))) void CMP1_handler();
__attribute__((weak, alias("_exit"))) void FTM0_handler();
__attribute__((weak, alias("_exit"))) void FTM1_handler();
__attribute__((weak, alias("_exit"))) void FTM2_handler();
__attribute__((weak, alias("_exit"))) void Real_time_clock_alarm_handler();
__attribute__((weak, alias("_exit"))) void Real_time_clock_seconds_handler();
__attribute__((weak, alias("_exit"))) void Programmable_interrupt_timer_channel_0_handler();
__attribute__((weak, alias("_exit"))) void Programmable_interrupt_timer_channel_1_handler();
__attribute__((weak, alias("_exit"))) void Programmable_interrupt_timer_channel_2_handler();
__attribute__((weak, alias("_exit"))) void Programmable_interrupt_timer_channel_3_handler();
__attribute__((weak, alias("_exit"))) void Programmable_delay_block_handler();
__attribute__((weak, alias("_exit"))) void USB_OTG_handler();
__attribute__((weak, alias("_exit"))) void DAC0_handler();
__attribute__((weak, alias("_exit"))) void Master_clock_generation_handler();
__attribute__((weak, alias("_exit"))) void Low_power_timer_handler();
__attribute__((weak, alias("_exit"))) void Pin_detect_port_A_handler();
__attribute__((weak, alias("_exit"))) void Pin_detect_port_B_handler();
__attribute__((weak, alias("_exit"))) void Pin_detect_port_C_handler();
__attribute__((weak, alias("_exit"))) void Pin_detect_port_D_handler();
__attribute__((weak, alias("_exit"))) void Pin_detect_port_E_handler();
__attribute__((weak, alias("_exit"))) void Software_interrupt_handler();
__attribute__((weak, alias("_exit"))) void FTM3_handler();
__attribute__((weak, alias("_exit"))) void DAC1_handler();
__attribute__((weak, alias("_exit"))) void ADC1_handler();

typedef void( *intfunc )();
extern uintptr_t __c_stack_top__;

__attribute__((section(".isr_vector"), used)) const intfunc __vector_table[] =
{
    reinterpret_cast<intfunc>(&__c_stack_top__),
    _start,

    NMI_handler,
    HardFault_handler,
    MemManage_handler,
    BusFault_handler,
    UsageFault_handler,
    Dummy_handler,
    Dummy_handler,
    Dummy_handler,
    Dummy_handler,
    SVC_handler,
    DebugMon_handler,
    Dummy_handler,
    PendSV_handler,
    SysTick_handler,

    DMA_channel_0_complete_handler,
    DMA_channel_1_complete_handler,
    DMA_channel_2_complete_handler,
    DMA_channel_3_complete_handler,
    DMA_channel_4_complete_handler,
    DMA_channel_5_complete_handler,
    DMA_channel_6_complete_handler,
    DMA_channel_7_complete_handler,
    DMA_channel_8_complete_handler,
    DMA_channel_9_complete_handler,
    DMA_channel_10_complete_handler,
    DMA_channel_11_complete_handler,
    DMA_channel_12_complete_handler,
    DMA_channel_13_complete_handler,
    DMA_channel_14_complete_handler,
    DMA_channel_15_complete_handler,
    DMA_error_handler,
    FPU_error_handler,
    Flash_command_complete_handler,
    Flash_read_collision_handler,
    Low_voltage_detect_handler,
    Low_leakage_wakeup_handler,
    Watchdog_handler,
    Random_number_generator_handler,
    Dummy_handler,
    Dummy_handler,
    SPI0_handler,
    SPI1_handler,
    I2S0_transmit_handler,
    I2S0_receive_handler,
    LPUART0_status_and_error_handler,
    UART0_status_handler,
    UART0_error_handler,
    UART1_status_handler,
    UART1_error_handler,
    UART2_status_handler,
    UART2_error_handler,
    Dummy_handler,
    Dummy_handler,
    ADC0_handler,
    CMP0_handler,
    CMP1_handler,
    FTM0_handler,
    FTM1_handler,
    FTM2_handler,
    Dummy_handler,
    Real_time_clock_alarm_handler,
    Real_time_clock_seconds_handler,
    Programmable_interrupt_timer_channel_0_handler,
    Programmable_interrupt_timer_channel_1_handler,
    Programmable_interrupt_timer_channel_2_handler,
    Programmable_interrupt_timer_channel_3_handler,
    Programmable_delay_block_handler,
    USB_OTG_handler,
    Dummy_handler,
    Dummy_handler,
    DAC0_handler,
    Master_clock_generation_handler,
    Low_power_timer_handler,
    Pin_detect_port_A_handler,
    Pin_detect_port_B_handler,
    Pin_detect_port_C_handler,
    Pin_detect_port_D_handler,
    Pin_detect_port_E_handler,
    Software_interrupt_handler,
    Dummy_handler,
    Dummy_handler,
    Dummy_handler,
    Dummy_handler,
    Dummy_handler,
    Dummy_handler,
    FTM3_handler,
    DAC1_handler,
    ADC1_handler
};

} // extern "C"
