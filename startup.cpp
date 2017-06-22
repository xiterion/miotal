#include <stdint.h>
#include <stdlib.h>

extern "C" {

extern int main( void );
extern void NMI_Handler( void );
extern void HardFault_Handler( void );
extern void MemManage_Handler( void );
extern void BusFault_Handler( void );
extern void UsageFault_Handler( void );
extern void SVC_Handler( void );
extern void DebugMon_Handler( void );
extern void PendSV_Handler( void );
extern void SysTick_Handler( void );

[[noreturn]] void start()
{
  main();
  exit(0);
}

typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;
extern uintptr_t __c_stack_top__;

__attribute__((section(".Interrupt_vector"), used)) const intvec_elem __vector_table[] =
{
  { .__ptr = &__c_stack_top__ },
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

__attribute__((weak)) [[noreturn]] void NMI_Handler( void ) { while (1) {} }
__attribute__((weak)) [[noreturn]] void HardFault_Handler( void ) { while (1) {} }
__attribute__((weak)) [[noreturn]] void MemManage_Handler( void ) { while (1) {} }
__attribute__((weak)) [[noreturn]] void BusFault_Handler( void ) { while (1) {} }
__attribute__((weak)) [[noreturn]] void UsageFault_Handler( void ) { while (1) {} }
__attribute__((weak)) [[noreturn]] void SVC_Handler( void ) { while (1) {} }
__attribute__((weak)) [[noreturn]] void DebugMon_Handler( void ) { while (1) {} }
__attribute__((weak)) [[noreturn]] void PendSV_Handler( void ) { while (1) {} }
__attribute__((weak)) [[noreturn]] void SysTick_Handler( void ) { while (1) {} }
__attribute__((weak)) [[noreturn]] void exit( int code ) { while (1) {} }

}
