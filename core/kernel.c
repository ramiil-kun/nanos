/* 
	Original code by Tommy@OSDev.net
	Nikita Lindamnn, 2015
*/

#include "keyboard.c"
#include "time.c"
#include "console.c"


extern void reboot(); // It's true way to call asm-defined fx's from c code:)
extern int himem(); // It's true way to call asm-defined fx's from c code:)

char* strcat(char *dest, const char *src)
{
	int i;
	int destLength = lengthStr(dest);
	for (i = 0; src[i] != '\0'; i++)
		dest[destLength+i] = src[i];
	dest[destLength+i] = '\0';
	return dest;
}

char* itoa(int inpInt){
	static char buf[32] = {0};
	int i;
	for(i=30; inpInt && i ; --i, inpInt /= 10)
		buf[i] = "0123456789"[inpInt % 10];
	return &buf[i+1];
}


void kmain (void)
{
	initConsole();
	printStr("NanoS v0.0.1 Running", 0x0F);
	for (int i=0; i<5; i++)
	{
		printStr(".", 0x0F);
		delay(10);
	}
	
	printStr("\nPress ESC and any key to reboot\n", 0x0F);
	printStr(strcat("abcd", itoa(12345)), 0x0F);
	
	
	char currentKey = 0;
	do
	{
		int oldCursorPosition = getCursorOffset();
		curLine = 3;
		curCharacter = 25;
		//printStr("xx", 0xF0);
		//printStr(strcat("CurPos: ",itoa(oldCursorPosition)), 0xF0);
		//printStr("xx", 0xF0);
		printStr("xxxxxxxabcda", 0x0F);
		setCursorOffset(oldCursorPosition);

		currentKey = getScancode();
		printStr(&scode[2+currentKey*2], 0x0F);
		delayUB(15, currentKey);
	}
	while(0x01 != currentKey);
	
	printStr("System will restart in 5 seconds\n", 0x0E);
	delay(5000);

	reboot();
}
