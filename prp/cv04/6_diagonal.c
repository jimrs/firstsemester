#include <stdio.h>

int main() {
	
	for (int i = 0; i < 10; i++) {
		
		for (int j = 0; j < 10; j++) {			
			if (j == 9-i) {
				printf("%2d", 10*i+j);
				break;	//nemusi se pak tisknout zbytecne mezery
			}
			else {
				printf("   ");
			}	
		}		
		printf("\n");
	}
	return 0;
}
