/*  
	Original code by Tommy@OSDev.net
	Nikita Lindamnn, 2015
*/
#define LINES, 25
#define LLENGTH, 80

int cursorOffset = 0;

int getCursorLine()
{
	return (cursorOffset/160);
}

int getCursorPos()
{
	return (cursorOffset-(160*getCursorLine()))/2;
}

void setCursor(int line, int pos)
{
	cursorOffset = ((80*line)+pos)*2;
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

// Simply prints a string from cursor point.
void printStr(char inpStr[], unsigned char strColor)
{
	for (int i=0; i<lengthStr(inpStr); i++) 
	{
		*((unsigned char *) 0xB8000 + cursorOffset + i*2) = inpStr[i];
		*((unsigned char *) 0xB8000 + 1 + cursorOffset + i*2) = strColor;
	}
}

// Prints a string from cursor point, with line break at end of string.
void writeLn(char inpStr[], unsigned char strColor)
{
	printStr(inpStr, strColor);
	setCursor(getCursorLine()+1, 0);
}

// Prints a string from cursor point, without line break at end of string.
void write(char inpStr[], unsigned char strColor)
{
	printStr(inpStr, strColor);
	setCursor(getCursorLine(), getCursorPos()+lengthStr(inpStr));
}