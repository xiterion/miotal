#include "hal/pin.hpp"
#include "port/ARM/Cortex/M4/Freescale/K2x/MK22.hpp"

using namespace port;

PORTx_PCRn PORTA_PCR0(0x40049000);

int main(void)
{
    PORTA_PCR0.initialize(Interrupt_Configuration::interrupt_when_logic_0,
                                    Lock_Register::disabled,
                                  Pin_Mux_Control::disabled_analog,
                                   Drive_Strength::low,
                                       Open_Drain::disabled,
                                   Passive_Filter::disabled,
                                        Slew_Rate::fast,
                                    Internal_Pull::disabled,
                                      Pull_Select::down);
}
