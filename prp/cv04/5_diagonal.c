#include <stdio.h>

int main() {
	
	for (int i = 0; i < 10; i++) {
		
		for (int j = 0; j < 10; j++) {			
			if (i == j) {
				printf("%2d", 10*i+j);
				break;	// nebudou se pak zbytecne tisknout mezery
			}
			else {
				printf("   ");	//3 spaces because " %2d" prints 3 characters
			}	
		}		
		printf("\n");
	}
	return 0;
}
