#include "hal/pin.hpp"
#include "port/ARM/Cortex/M4/Freescale/K2x/MK22.hpp"
#include <hal/register.hpp>

int main(void)
{
    bool foo;
    port::PORTA_PCR0.ISF.clear();
}
