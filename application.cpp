#include <cstdint>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>

using namespace platform;

template <typename Port_Pin>
struct Foo {
    Port_Pin reg;
};

template <typename Port_Pin>
Foo<Port_Pin> make_foo(Port_Pin reg) { return {reg}; }

auto foo = make_foo(PORTA_PCR0);

int main(void)
{
    foo.reg.LK();
}
