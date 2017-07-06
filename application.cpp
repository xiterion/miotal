#include "hal/pin.hpp"
#include "port/ARM/Cortex/M4/Freescale/K2x/MK22.hpp"

port::PORTx_PCRn PORTA_PCR0(0x40049000);

int main(void)
{
    PORTA_PCR0.initialize(0, false, 4, true, true, true, false, false, false);
}
