#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	
	scanf("%d", &size);
	
	int pole[size];
	pole[0] = 0;
	pole[size] = 1;
	printf("Prvni index %d, posledni index %d\n", pole[0], pole[size]);

	return 0;
}
