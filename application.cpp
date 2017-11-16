#include <cstdint>

#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>

int main(void)
{
    platform::port::PORTA_ISFR.clear(1,2,3);
}
