#include "hal/pin.hpp"
#include "platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp"
#include "platform/ARM/Cortex/M4/Freescale/K2x/pin.hpp"


int main(void)
{
hal::GPIO gpio{platform::PORTA_PCR2};
    gpio.enableOpenDrain();
}
