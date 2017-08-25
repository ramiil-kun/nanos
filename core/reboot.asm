;; Original code by Carottop and Nikita Lindamnn, 2015

format elf
use32

public reboot
public inp

section '.text' executable

	reboot:
		int 18h
		ret
	inp:
		in ax, 60h
		ret
	
