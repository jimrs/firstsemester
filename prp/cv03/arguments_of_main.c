//parametry programu
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 2)	//pocitam nazev programu - jeden argument
	{
		printf("Error!\n");
	}

	printf("program: %s\n", argv[0]); //vypise nazev programu, 1 prvni argument, 2 druhy etc
	printf("prvni argument: %s\n", argv[1]);

	//int c = atoi(argv[1]);	// prevede string do int
	//printf("int arg1: %d\n", c);

	return 0;
}

//argc urcuje pocet argumentu, delka pole argv je argc, kazdy parametr je ulozen jako string v argv
//lze i **argv
