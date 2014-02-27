/*
 * Fox Operating System
 * kernel.h
 */

#ifndef FOX_HERNEL_H
#define FOX_HERNEL_H

#define size_t int

typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int; 

#define uint8_t  u8int
#define uint16_t u16int

#include <terminal.h>

void kernel_main();

#endif