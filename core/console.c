/*  
	Original code by Tommy@OSDev.net
	Nikita Lindamnn, 2015
*/
#define LINES, 25
#define LLENGTH, 80

int curLine;
int curCharacter;

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
	curLine = 0;
	curCharacter = 0;
}

void setCursorOffset(int offset)
{
	curLine = (offset/2)/80;
	curCharacter = (offset/2)%80;
}

int getCursorOffset()
{
	return 2*((curLine*80)+curCharacter);
}

// Simply prints a string from cursor point.
void printStr(char inpStr[], unsigned char strColor)
{
	for (int i=0; i<lengthStr(inpStr); i++) 
	{
		if (inpStr[i] == 0xA) 
		{
			curLine += 1;
			curCharacter = 0;
		}
		else if (inpStr[i] == 0x8) 
		{
			*((unsigned char *) 0x000B8000 + getCursorOffset()) = ' ';
			*((unsigned char *) 0x000B8000 + getCursorOffset() + 1) = 0x0;
			setCursorOffset(getCursorOffset()-2);
		}
		else if ((inpStr[i] <= 0x20)&&(inpStr[i] >= 0x7F))
		{
			delay(1);
		}
		else
		{
			*((unsigned char *) 0x000B8000 + getCursorOffset()) = inpStr[i];
			*((unsigned char *) 0x000B8000 + getCursorOffset() + 1) = strColor;
			setCursorOffset(getCursorOffset()+2);
		}
	}
}
