#include "hal/pin.hpp"
#include "port/ARM/Cortex/M4/Freescale/K2x/MK22.hpp"

int main(void)
{
    port::internal::PORTA_PCR1 = 1;
}
