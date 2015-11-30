format elf
use32

public reboot as 'reboot'
section '.text' executable

        reboot:
	int 18h