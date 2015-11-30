/*  Tutorial: A small kernel with Fasm & TCC
    By Tommy.
*/

#define LINES, 25
#define LLENGTH, 80

int cursorOffset = 0;


void serCursor(int line, int pos)
{
  cursorOffset = ((80*line)+(25*pos))*2;
}

int lengthStr(char inpStr[])
{
  int i=0;
  while (inpStr[i] != 0x00)
  {
    i++;
  }
  return i;
}

void initConsole()
{
  for(int i = 0; i<(25*80*2); i++) 
  {
    *((unsigned char *) 0xB8000 + i) = 0x00;
  }
}

void printStr(char inpStr[], unsigned char strColor)
{
  for (int i=0; i<lengthStr(inpStr); i++) 
  {
    *((unsigned char *) 0xB8000 + cursorOffset + i*2) = inpStr[i];
    *((unsigned char *) 0xB8000 + 1 + cursorOffset + i*2) = strColor;
  }
}

void kmain (void)
{
    initConsole();
    printStr("Hello, world!", 0x0F);
    serCursor(10, 0);
    printStr("Hello, world!", 0x0F);
}