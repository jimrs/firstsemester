#include <stdio.h>

int main() {
	
	for (int i = 0; i < 100; i++) {
		printf(" %2d", i);
		
		if (i % 10 == 9) {
			printf("\n");
		}
	}
	return 0;
}
