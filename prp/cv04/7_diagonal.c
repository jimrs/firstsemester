#include <stdio.h>

int main() {
	int dimension = 10;
	scanf("%d", &dimension);
	
	for (int i = 0; i < dimension; i++) {		
		for (int j = 0; j < dimension; j++) {			
			if ( (j+1 == dimension-i) || (j == i) ) {
				printf(" %2d", 10*i+j);
			}
			else {
				printf("   ");
			}	
		}		
		printf("\n");
	}
	return 0;
}
