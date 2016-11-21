#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("%d %d %d %d\n", 'a', 'z', 'Z', 'A');

	char c = fgetc(stdin);

	if (c >= 'a' && c <= 'z')
	{
		printf("zadali jste pismeno\n");
	}

	//posun znaku
	//pozor na to, ze Z je 90, ale a je 97 tzn je tam mezera!
	c = c + 5;
	if (c > 'Z')
	{
		c = 'a' - 'Z';	//plus jedna?
	}	

	return 0;
}
