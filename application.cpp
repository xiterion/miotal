#include "hal/pin.hpp"
#include "port/ARM/Cortex/M4/Freescale/K2x/MK22.hpp"

int main(void)
{
    volatile std::uint32_t foo;
    port::PORTA_PCR0.write(port::PORTA_PCR0.initializer(
                3, false, 1, false, true, false, false, true, false));
}
