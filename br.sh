fasm core/bootloader.asm core/bootloader.o
fasm core/reboot.asm core/reboot.o
tcc -c core/kernel.c -o core/kernel.o
rm kernel-i386.elf
tcc -nostdlib -Wl,-Ttext,0x100000 core/*.o -o kernel-i386.elf
rm core/*.o
qemu -kernel kernel-i386.elf 
