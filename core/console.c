/*  
	Original code by Tommy@OSDev.net
	Nikita Lindamnn, 2015
*/
#define LINES, 25
#define LLENGTH, 80

int cursorOffset;

int lengthStr(char inpStr[])
{
	int i=0;
	while (inpStr[i] != '\0')
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
	cursorOffset = 0;
}

// Simply prints a string from cursor point.
void printStr(char inpStr[], unsigned char strColor)
{
	for (int i=0; i<lengthStr(inpStr); i++) 
	{
		if (inpStr[i] == 0xA) 
		{
			cursorOffset=((cursorOffset/160)+1)*160;
		}
		else if (inpStr[i] == 0x8) 
		{
			*((unsigned char *) 0x000B8000 + cursorOffset) = ' ';
			*((unsigned char *) 0x000B8000 + cursorOffset + 1) = 0x0;
			cursorOffset-=2;
		}
		else if ((inpStr[i] <= 0x20)&&(inpStr[i] >= 0x7F))
		{
			delay(1);
		}
		else
		{
			*((unsigned char *) 0x000B8000 + cursorOffset) = inpStr[i];
			*((unsigned char *) 0x000B8000 + cursorOffset + 1) = strColor;
			cursorOffset+=2;
		}
	}
}