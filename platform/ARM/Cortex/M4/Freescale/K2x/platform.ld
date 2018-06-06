OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

MEMORY {
	ROM (rx)  : ORIGIN = 0x00000000, LENGTH = 512k
	RAM (rwx) : ORIGIN = 0x1FFF0000, LENGTH = 128k
}

C_STACK_SIZE = 2000;
IRQ_STACK_SIZE = 0;
FIQ_STACK_SIZE = 0;
SVC_STACK_SIZE = 0;
ABT_STACK_SIZE = 0;
UND_STACK_SIZE = 0;

HEAP_SIZE = 1000;

SECTIONS {
	.text : {
		KEEP (*(.isr_vector))
		. = ALIGN (4);
		*(.text .text.* .gnu.linkonce.t.*)
		*(.plt)
		*(.gnu.warning)
		. = ALIGN (4);

		*(.rodata .rodata.* .gnu.linkonce.r.*)
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP (*(.preinit_array))
        PROVIDE_HIDDEN (__preinit_array_end = .);
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array))
        PROVIDE_HIDDEN (__init_array_end = .);
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP (*(SORT(.fini_array.*)))
        KEEP (*(.fini_array))
        PROVIDE_HIDDEN (__fini_array_end = .);
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
        _edata_load = LOADADDR (.data) + SIZEOF (.data);
	} >RAM AT>ROM

	.bss : {
		__bss_start = .;
		*(.shbss)
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON)
		. = ALIGN (4);
		__bss_end = .;
	} >RAM

    .heap : {
        . = ALIGN (4);
        __heap_start = .;
        . += HEAP_SIZE;
        . = ALIGN (4);
        __heap_end = .;
    } >RAM


	.stack (ORIGIN(RAM) + LENGTH(RAM) - C_STACK_SIZE): {
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
