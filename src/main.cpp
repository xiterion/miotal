//import miotal.hal;
//import miotal.platform;
#include <miotal/ARM/Cortex/M4/NXP/K2x/gpio.hpp>

int main() {
	platform::gpio::GPIOA_PSOR.set(1,2,7,8);
	return 0;
}
