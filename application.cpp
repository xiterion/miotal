#include "hal/pin.hpp"
#include "port/ARM/Cortex/M4/Freescale/K2x/MK22.hpp"

int main(void)
{
    std::uint32_t foo;
    PORTA_PCR0.LK.clear();
}
