/*  
	Nikita Lindamnn, 2015
*/

void delay(int time)
{
	for(int i = 0; i <= (time+1); i++)
		for(int j = 0; j <= 32768*2; j++)
			{} 
}

int delayUB(int time, char sym)
{
	for(int i = 0; i <= (time+1); i++)
		for(int j = 0; j <= 32768*2; j++)
			{
				if (sym !=getScancode()) return 0;
			} 
	return 1;
}
