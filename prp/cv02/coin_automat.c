#include <stdio.h>

int main()
{	
	int coins = 0;
	
	printf("Enter a positive integer representing a number of coins:\n");
	scanf("%d", &coins);
	printf("You entered %d coins into the automat.\n", coins);
	printf("Minimal amount of coins needed is:\n");
	
	for (int divisor = 20; divisor >= 1; divisor = divisor/2)
	{
		int amount = coins / divisor;
		
		if (amount != 0)
		{
			printf("%d: %dx\n", divisor, amount);
		}
		
		coins = coins % divisor;
	}
	
	return 0;
}
