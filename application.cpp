#include <cstdint>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>

struct A {
    const int val;
    constexpr A(int val) : val{val} {}
};

struct B : public A {
    using A::A;
};

struct C {
    B& b;
};

B foo{0x12345678};
C bar{foo};

int main(void)
{
    volatile int baz;
    baz = foo.val;
}
