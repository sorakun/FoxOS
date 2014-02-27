#include <kernel.h>
#include <terminal.h>

uint8_t make_color(enum vga_color fg, enum vga_color bg)
{
  return fg | bg << 4;
}

uint16_t make_vgaentry(char c, uint8_t color)
{
  uint16_t c16 = c;
  uint16_t color16 = color;
  return c16 | color16 << 8;
}

size_t strlen(const char* str)
{
  size_t ret = 0;
  while ( str[ret] != 0 )
    ret++;
  return ret;
}

void terminal_initialize()
{
  terminal_row = 0;
  terminal_column = 0;
  terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
  terminal_buffer = (uint16_t*) 0xB8000;
  size_t y = 0, x = 0;
  for ( y = 0; y < VGA_HEIGHT; y++ )
  {
    for (x = 0; x < VGA_WIDTH; x++ )
    {
      const size_t index = y * VGA_WIDTH + x;
      terminal_buffer[index] = make_vgaentry(' ', terminal_color);
    }
  }
}

void terminal_setcolor(uint8_t color)
{
  terminal_color = color;
}
#include <kernel.h>
#include <terminal.h>

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
  const size_t index = y * VGA_WIDTH + x;
  terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_putchar(char c)
{
  /* Backspace */
  if (c == 0x08 && terminal_column)
  {
    terminal_column--;
    return;
  }
  
  /* Handle a tab by increasing the cursor's X, but only to a point
   * where it is divisible by 8.
   */
  if (c == 0x09)
  {
    terminal_column = (terminal_column+8) & ~(8-1);
    return;
  }
  /* Handle carriage return */
  if (c == '\r')
  {
    terminal_column = 0;
    return;
  }
  
  if (c == '\n')
  {
    terminal_column = 0;
    terminal_row++;
    return;
  }
  
  /* else */
  terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
  if ( ++terminal_column == VGA_WIDTH )
  {
    terminal_column = 0;
    if ( ++terminal_row == VGA_HEIGHT )
    {
      terminal_row = 0;
    }
  }
}

void terminal_writestring(const char* data)
{
  size_t datalen = strlen(data);
  size_t i;
  for ( i = 0; i < datalen; i++ )
    terminal_putchar(data[i]);
}

void terminal_setentryat(size_t x, size_t y)
{
  terminal_column = x;
  terminal_row = y;
}

void terminal_writedec(u32int n)
{
  
}