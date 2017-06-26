#include "hal/pin.hpp"
#include "port/ARM/Cortex/M4/Freescale/K2x/MK22.hpp"

port::PORTx_PCRn PORTA_PCR0(port::internal::PORTA_PCR0);

int main(void)
{
    PORTA_PCR0.DSE.read();
}
