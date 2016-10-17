#include <stdio.h>

int main()
{
	for (int i = 0; i < 100; i++)
	{
		printf("%d", i);
		if (i == 10)
		{
			break;
		}
	}
	
	int i = 0;
	while (i < 100)
	{
		printf("%d", i+1);
		if (i == 9)
		{
			break;
		}
	}
	
	do
	{
		printf("%d", i+1);
		if (i == 9)
		{
			break;
		}
	} while (i <= 100); 

	return 0;
}
