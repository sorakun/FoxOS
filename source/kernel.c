
#include <kernel.h>
#include <terminal.h>
#include <os_menu.h>
void kernel_main()
{
  terminal_initialize();
  //terminal_writestring("Fox Operating System");
  drawMenu();
  for(;;);
}