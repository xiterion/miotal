#include <miotal/platforms/ARM/Cortex/M4/NXP/K2x/port.hpp>
#include <miotal/platforms/ARM/Cortex/M4/NXP/K2x/sim.hpp>
#include <miotal/platforms/ARM/Cortex/M4/NXP/K2x/wdog.hpp>

int main(void) {
    {
        using namespace platform::sim;
        SIM_SCGC5.enable_clock(SIM_SCGC5.PORTA,
                               SIM_SCGC5.PORTB,
                               SIM_SCGC5.PORTC,
                               SIM_SCGC5.PORTD,
                               SIM_SCGC5.PORTE);
    }
    while(1) {}
}
