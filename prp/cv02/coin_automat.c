#include <stdio.h>

int main(int argc, char *argv[])
{	
	int coins = 0;
	
	scanf("%d", &coins);
	printf("You entered %d coins into the automat.\n", coins);			//zbytek z 20, pak z 10, pak z 5, pak 2, pak 1
	
	int dvacet = coins / 20;
	int remainder20 = coins % 20;
	
	int deset = remainder20 / 10;
	int remainder10 = remainder20 % 10;
	
	int pet = remainder10 / 10;
	int remainder5 = remainder10 % 10;
	
	int dva = remainder5 / 10;
	int remainder2 = remainder5 % 10;
	
	int jedna = remainder2 / 10;
	int remainder1 = remainder2 % 10;
	
	printf("%d %d %d", dvacet);
	
	
	
	return 0;
}
