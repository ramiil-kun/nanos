;; Original code by Carottop and Nikita Lindamnn, 2015

format elf
use32

public reboot
public inp
public outp
public himem

section '.text' executable

	reboot:
		int 18h
		ret
	inp:
		;mov bl, 60h
		in ax, 60h
		ret
	outp:
		;mov bl, 60h
		out 60h, ax
		ret
	himem:
		mov ax, 0xE881
		int 15h
		ret
	