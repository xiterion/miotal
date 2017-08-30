#include <cstdint>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>

using namespace platform;

#define porta_pcr0 *(volatile uint32_t*)0x4004'9000

int main(void)
{
#if 1
    PORTA_PCR0.write(
            Interrupt_Configuration::interrupt_when_logic_0,
            Lock_Register::enabled,
            Pin_Mux_Control::alternative_3,
            Drive_Strength::low,
            Open_Drain::disabled,
            Passive_Filter::enabled,
            Slew_Rate::slow,
            Internal_Pull::enabled,
            Pull_Select::down);
#else
    constexpr uint32_t mask  = 0b0000'0000'0000'1111'1000'0111'0111'0111;
    constexpr uint32_t value = 0b0000'0000'0000'1000'1000'0011'0001'0110;
    porta_pcr0 = (porta_pcr0 & ~mask) | value;
#endif
}
