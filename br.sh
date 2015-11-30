tcc -c kernel.c
tcc -nostdlib -Wl,-Ttext,0x100000 bootloader.o kernel.o -o kernel-i386.elf
qemu -kernel kernel-i386.elf 
