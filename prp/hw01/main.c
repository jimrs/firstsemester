#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int firstint;
	int secondint;
	
	scanf("%d %d", &firstint, &secondint);
	
	if ( (firstint < -10000 || firstint > 10000) || (secondint < -10000 || secondint > 10000) )
	{
		printf("Vstup je mimo interval!\n");
		return 0;
	}
	
	printf("Desitkova soustava: %d %d\n", firstint, secondint);
	printf("Sestnactkova soustava: %x %x\n", firstint, secondint);
	
	int sum = firstint + secondint;
	int diff = firstint - secondint;
	int prod = firstint * secondint;
	
	printf("Soucet: %d + %d = %d\n", firstint, secondint, sum);
	printf("Rozdil: %d - %d = %d\n", firstint, secondint, diff);
	printf("Soucin: %d * %d = %d\n", firstint, secondint, prod);
	
	if (secondint == 0)
	{
		printf("Nedefinovany vysledek!\n");
	}
	else
	{
		int div = firstint / secondint;
		printf("Podil: %d / %d = %d\n", firstint, secondint, div);
	}
	
	
	
	float avg = (float)(firstint + secondint) / 2;
	
	printf("Prumer: %.1f\n", avg);
	
	return 0;
}
