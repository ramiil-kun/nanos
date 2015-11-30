/*  Tutorial: A small kernel with Fasm & TCC
    By Tommy.
*/

#include "console.lib"
#include "time.lib"

void kmain (void)
{
    initConsole();
    printStr("Hello, world!", 0x0F);
    serCursor(3, 0);
    printStr("System will halt in 5 seconds", 0x0E);

    delay(5000);

    reboot();
}