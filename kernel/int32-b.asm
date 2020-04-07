[bits 32]

global int32, _int32

struc regs16_t
	.di	resw 1
	.si	resw 1
	.bp	resw 1
	.sp resw 1
	.bx	resw 1
	.dx	resw 1
	.cx	resw 1
	.ax	resw 1
	.gs	resw 1
	.fs	resw 1
	.es	resw 1
	.ds	resw 1
	.ef resw 1
endstruc

%define INT32_BASE                             0x7C00
%define REBASE(x)                              (((x) - reloc) + INT32_BASE)
%define GDTENTRY(x)                            ((x) << 3)
%define CODE32                                 GDTENTRY(1)
%define DATA32                                 GDTENTRY(2)
%define CODE16                                 GDTENTRY(3)
%define DATA16                                 GDTENTRY(4)
%define STACK16                                (INT32_BASE - regs16_t_size)


section .text
	int32: use32
	_int32:
		cli
		pusha
		mov  esi, reloc
		mov  edi, INT32_BASE
		mov  ecx, (int32_end - reloc)
		cld
		rep  movsb
		jmp INT32_BASE
	reloc: use32
		mov  [REBASE(stack32_ptr)], esp
		sidt [REBASE(idt32_ptr)]
		sgdt [REBASE(gdt32_ptr)]
		lgdt [REBASE(gdt16_ptr)]
		lea  esi, [esp+0x24]
		lodsd
		mov  [REBASE(ib)], al
		mov  esi, [esi]
		mov  edi, STACK16
		mov  ecx, regs16_t_size
		mov  esp, edi
		rep  movsb
		jmp  word CODE16:REBASE(p_mode16)
	p_mode16: use16
		mov  ax, DATA16
		mov  ds, ax
		mov  es, ax
		mov  fs, ax
		mov  gs, ax
		mov  ss, ax
		mov  eax, cr0
		and  al,  ~0x01
		mov  cr0, eax
		jmp  word 0x0000:REBASE(r_mode16)
	r_mode16: use16
		xor  ax, ax
		mov  ds, ax
		mov  ss, ax
		lidt [REBASE(idt16_ptr)]
		mov  bx, 0x0870
		call resetpic                          
		popa
		pop  gs
		pop  fs
		pop  es
		pop  ds
		sti
		db 0xCD
	ib: db 0x00
		cli
		xor  sp, sp
		mov  ss, sp
		mov  sp, INT32_BASE
		pushf
		push ds
		push es
		push fs
		push gs
		pusha
		mov  bx, 0x2028
		call resetpic
		mov  eax, cr0
		inc  eax
		mov  cr0, eax
		jmp  dword CODE32:REBASE(p_mode32)
	p_mode32: use32
		mov  ax, DATA32
		mov  ds, ax
		mov  es, ax
		mov  fs, ax
		mov  gs, ax
		mov  ss, ax
		lgdt [REBASE(gdt32_ptr)]
		lidt [REBASE(idt32_ptr)]
		mov  esp, [REBASE(stack32_ptr)]
		mov  esi, STACK16
		lea  edi, [esp+0x28]
		mov  edi, [edi]
		mov  ecx, regs16_t_size
		cld
		rep  movsb
		popa
		sti
		ret

	resetpic:
		push ax
		mov  al, 0x11
		out  0x20, al
		out  0xA0, al
		mov  al, bh
		out  0x21, al
		mov  al, bl
		out  0xA1, al
		mov  al, 0x04
		out  0x21, al
		shr  al, 1
		out  0xA1, al
		shr  al, 1
		out  0x21, al
		out  0xA1, al
		pop  ax
		ret

	stack32_ptr:
		dd 0x00000000

	idt32_ptr:
		dw 0x0000
		dd 0x00000000

	gdt32_ptr:
		dw 0x0000
		dd 0x00000000

	idt16_ptr:
		dw 0x03FF
		dd 0x00000000

	gdt16_base:
		.null:
			dd 0x00000000
			dd 0x00000000

		.code32:
			dw 0xFFFF
			dw 0x0000
			db 0x00
			db 0x9A
			db 0xCF
			db 0x00

		.data32:
			dw 0xFFFF
			dw 0x0000
			db 0x00
			db 0x92
			db 0xCF
			db 0x00

		.code16:
			dw 0xFFFF
			dw 0x0000
			db 0x00
			db 0x9A
			db 0x0F
			db 0x00

		.data16:
			dw 0xFFFF
			dw 0x0000
			db 0x00
			db 0x92
			db 0x0F
			db 0x00

	gdt16_ptr:
		dw gdt16_ptr - gdt16_base - 1
		dd gdt16_base

	int32_end:
