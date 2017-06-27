OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(start)

MEMORY {
	ROM (rx)  : ORIGIN = 0x00000000, LENGTH = 1024k
	RAM (rwx) : ORIGIN = 0x1FFF0000, LENGTH = 128k
}

C_STACK_SIZE = 2000;
IRQ_STACK_SIZE = 0;
FIQ_STACK_SIZE = 0;
SVC_STACK_SIZE = 0;
ABT_STACK_SIZE = 0;
UND_STACK_SIZE = 0;

SECTIONS {
	.reset : {
		*(.Interrupt_vector*);
		. = ALIGN (4);
	} >ROM

	.text : {
		CREATE_OBJECT_SYMBOLS
		*(.text .text.* .gnu.linkonce.t.*)
		*(.plt)
		*(.gnu.warning)
		. = ALIGN (4);

		KEEP (*.crtbegin.o(ctors))
		KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
		KEEP (*(SORT(.ctors.*)))
		KEEP (*.crtend.o(.ctors))
		KEEP (*.crtbegin.o(.dtors))
		KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
		KEEP (*(SORT(.dtors.*)))
		KEEP (*crtend.o(.dtors))

		*(.rodata .rodata.* .gnu.linkonce.r.*)

		*(.init)
		*(.fini)
	} >ROM

	.ARM.exidx : {
		__exidx_start = .;
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
		__exidx_end = .;
	} >ROM
	_etext = .;

	.data : {
		__data_load = LOADADDR (.data);
		__data_start = .;
		KEEP(*(.jcr))
		*(.got.plt) *(.got)
		*(.shdata)
		*(.data .data.* .gnu.linkonce.d.*)
		. = ALIGN (4);
		_edata = .;
	} >RAM AT>ROM

	.bss : {
		__bss_start__ = .;
		*(.shbss)
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON)
		. = ALIGN (4);
		__bss_end__ = .;
	} >RAM

	.stack : {
		total_stack_size = C_STACK_SIZE;
		__stack_start__ = ORIGIN(RAM) + LENGTH(RAM) - total_stack_size;
		. = __stack_start__;
/*
		. += IRQ_STACK_SIZE;
		. = ALIGN(4);
		__irq_stack_top__ = .;

		. += FIQ_STACK_SIZE;
		. = ALIGN(4);
		__fiq_stack_top__ = .;

		. += SVC_STACK_SIZE;
		. = ALIGN(4);
		__svc_stack_top__ = .;

		. += ABT_STACK_SIZE;
		. = ALIGN(4);
		__abt_stack_top__ = .;

		. += UND_STACK_SIZE;
		. = ALIGN(4);
		__und_stack_top__ = .;
*/
		. += C_STACK_SIZE;
		. = ALIGN(4);
		__c_stack_top__ = .;

		__stack_end__ = .;
	} >RAM

	_end = .;
	__end = _end;
	PROVIDE(end = .);

	.stab 0 (NOLOAD) : { *(.stab) }
	.stabstr 0 (NOLOAD) : { *.(.stabstr) }
	.debug 0 : { *(.debug) }
	.line  0 : { *(.line) }
}
