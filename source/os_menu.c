 
#include <kernel.h>
#include <terminal.h>
#include <os_menu.h>

void drawMenu()
{
  uint8_t tcolor = make_color(COLOR_RED, COLOR_RED);
  unsigned short i = 0, j= 0;
  for(; i <= 2; i++)
    for(j = 0; j <= VGA_WIDTH; j++)
      terminal_putentryat(' ', tcolor, j-1, i);
    
  terminal_setentryat(1, 1);
  terminal_setcolor(make_color(COLOR_WHITE, COLOR_RED));
  terminal_writestring("  [[ Fox Operating System ]]  "); 
  
  tcolor = make_color(COLOR_RED, COLOR_RED);
  for(j = 0; j <= VGA_WIDTH; j++)
    terminal_putentryat(' ', tcolor, j, VGA_HEIGHT-1);
    
  terminal_setentryat(50, VGA_HEIGHT-1);
  terminal_setcolor(make_color(COLOR_WHITE, COLOR_RED));
  terminal_writestring("Written by Chouri Soulaymen");   
  
  terminal_setcolor(make_color(COLOR_WHITE, COLOR_BLACK));
  
  terminal_setentryat(0, 5);
  terminal_writestring("   * * * * * * * * *          * * * * * * *          * *          * *\n");
  terminal_writestring("   * * * * * * * * *         * * * * * * * *          * *        * * \n");
  terminal_writestring("   * *                      * *           * *          * *      * *\n");
  terminal_writestring("   * *                      * *           * *           * *    * *\n");
  terminal_writestring("   * * * * * * *            * *           * *            * *  * *\n");
  terminal_writestring("   * * * * * * *            * *           * *             * ** *\n");
  terminal_writestring("   * *                      * *           * *             * ** * \n");
  terminal_writestring("   * *                      * *           * *            * *  * *\n");
  terminal_writestring("   * *                      * *           * *           * *    * *\n");
  terminal_writestring("   * *                      * *           * *          * *      * * \n");
  terminal_writestring("   * *                       * * * * * * * *          * *        * *\n");
  terminal_writestring("   * *                         * * * * * *           * *          * *\n");  
  
}

