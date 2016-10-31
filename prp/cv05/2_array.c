#include <stdio.h>
#include <stdlib.h>

void fill_array(int size) {
	int pole[size];
	
	for (int i = 0; i < size; i++) {
		pole[i] = i;
	}
	
	for (int i = 0; i < size; i++) {
		printf("%d\n", pole[i]);
	}
}

int main(int argc, char *argv[]) {
	int size;
	
	size = atoi(argv[1]);
	fill_array(size);

	return 0;
}


