#include <stdint.h>
#include <stdlib.h>

extern "C" {

extern void low_level_init();
extern void _start();
extern int main();

extern void NMI_Handler();
extern void HardFault_Handler();
extern void MemManage_Handler();
extern void BusFault_Handler();
extern void UsageFault_Handler();
extern void SVC_Handler();
extern void DebugMon_Handler();
extern void PendSV_Handler();
extern void SysTick_Handler();

void start()
{
    low_level_init(); // call user-defined low level initialization
    _start(); // Defer to GCCs internal startup mechanism
}

typedef void( *intfunc )();
extern uintptr_t __c_stack_top__;

__attribute__((section(".Interrupt_vector"), used)) const intfunc __vector_table[] =
{
    reinterpret_cast<intfunc>(&__c_stack_top__),
    start,

    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler

};

__attribute__((weak)) void low_level_init() {}

__attribute__((weak)) [[noreturn]] void NMI_Handler()        { while (1); }
__attribute__((weak)) [[noreturn]] void HardFault_Handler()  { while (1); }
__attribute__((weak)) [[noreturn]] void MemManage_Handler()  { while (1); }
__attribute__((weak)) [[noreturn]] void BusFault_Handler()   { while (1); }
__attribute__((weak)) [[noreturn]] void UsageFault_Handler() { while (1); }
__attribute__((weak)) [[noreturn]] void SVC_Handler()        { while (1); }
__attribute__((weak)) [[noreturn]] void DebugMon_Handler()   { while (1); }
__attribute__((weak)) [[noreturn]] void PendSV_Handler()     { while (1); }
__attribute__((weak)) [[noreturn]] void SysTick_Handler()    { while (1); }

}
