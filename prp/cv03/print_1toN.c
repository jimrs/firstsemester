#include <stdio.h>

int main()
{
	int n = 1;
	scanf("%d", &n);
	
	long product = 1;
	int i = 1;
	while (i < n+1)
	{
		if ( (i%2) == 0 )
		{
			printf("%d\n", i);
			product = product * i;
			i++;
		}
		else
		{
			i++;
		}
	}
	
	printf("%ld\n", product);
	return 0;
}
