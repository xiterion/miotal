#include "hal/pin.hpp"
#include "port/ARM/Cortex/M4/Freescale/K2x/MK22.hpp"
#include <hal/register.hpp>

#define PORTA_PCR3 *(volatile uint32_t *)0x4004B000
#define PORTx_PCRn_IRQC_MASK 0x00F00000u
#define PORTx_PCRn_IRQC_SHIFT 20


int main(void)
{
    std::uint32_t foo;
    port::PORTA_PCR0.ISF.read();
    port::PORTA_PCR0.ISF.clear();
}
