rm kernel-i386.elf
/opt/fasm/fasm core/bootloader.asm core/bootloader.o
/opt/fasm/fasm core/reboot.asm core/reboot.o
tcc -c core/kernel.c -o core/kernel.o
tcc -nostdlib -Wl,-Ttext,0x100000 core/*.o -o kernel-i386.elf
rm core/*.o
qemu-system-i386 -kernel kernel-i386.elf 
