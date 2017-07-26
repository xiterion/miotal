#include "hal/pin.hpp"
#include "platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp"

#include <initializer_list>

using namespace platform;

int main(void)
{
    PORTA_GPCLR.write({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
            Lock_Register::enabled,
            Pin_Mux_Control::alternative_1_GPIO,
            Drive_Strength::high,
            Open_Drain::disabled,
            Passive_Filter::disabled,
            Slew_Rate::fast,
            Internal_Pull::enabled,
            Pull_Select::down);
}
