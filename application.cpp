#include "hal/pin.hpp"
#include "port/ARM/Cortex/M4/Freescale/K2x/MK22.hpp"

using namespace port;

PORTx_PCRn PORTA_PCR0(0x40049000);

int main(void)
{
    PORTA_PCR0.initialize(
            Interrupt_Configuration::interrupt_when_logic_0,
            Lock_Register::enabled,
            Pin_Mux_Control::disabled_analog,
            Drive_Strength_Enable::low,
            Open_Drain_Enable::disabled,
            Passive_Filter_Enable::disabled,
            Slew_Rate_Enable::fast,
            Pull_Enable::disabled,
            Pull_Select::down);
}
