#!/bin/sh

clear

echo "** Fox Operating System **"
echo "Written by Chouri Soulaymen"

echo "Assembling kernel"
nasm -felf kernel_start.asm -o ks.o

echo "Compiling C kernel"
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./ -c -o kernel.o kernel.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./ -c -o terminal.o terminal.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./ -c -o os_menu.o os_menu.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./ -c -o workspace.o workspace.c

echo "Linking kernel"
ld -T link.ld -o kernel.bin ks.o kernel.o terminal.o os_menu.o workspace.o

echo "Creating ISO"

mkdir -p isodir
mkdir -p isodir/boot
cp kernel.bin isodir/boot/fox.bin
mkdir -p isodir/boot/grub
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o fox.iso isodir 

rm *.o

qemu fox.iso