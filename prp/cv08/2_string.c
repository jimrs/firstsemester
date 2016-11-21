#include <stdio.h>

int xstrlen(const char *str)
{
	int length = 0;
	
	//lepsi - misto i<100 napsat str[i] != 0

	for (int i = 0; i < 100; i++)
	{
		if (str[i] == '\0')
			break;

		else
			length++;
	}
	
	return length;
}

void xstrcpy(char *destination, const char *source)	//predavani hodnotou
{
	int length = xstrlen(source);

	for (int i = 0; i < length; i++)
	{
		destination[i] = source[i];
	}

	destination[length] = '\0';
}

int main()
{
	//string je pole, kde na konci je nulovy znak 0x0
	//lze dereferencovat, pointerova aritmetika, reference etc.
	//jediny rozdil je v te nule na konci

	char *str = "abc";
	printf("%s\n", str);

	printf("len: %d\n", xstrlen(str));

	char dst[100];
	xstrcpy(dst, str);
	printf("%s\n", dst);
	printf("%d\n", dst[3]);	

	//kdyz malloc pole, musim porad pamatovat na nulu
	//malloc(sizeof(char) * strlen(jinypole) + 1)

	return 0;
}
