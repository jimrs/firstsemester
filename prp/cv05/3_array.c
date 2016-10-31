#include <stdio.h>
#include <stdlib.h>

void fill_array(int size) {
	int pole[size];
	int cisla;
	
	for (int i = 0; i < size; i++) {
		if (scanf("%d", &cisla) != 1)
			break;
		pole[i] = cisla;
	}
	
	for (int i = 0; i < size; i++) {
		printf("%d\n", pole[i]);
	}
}

void histogram(int size) {
	int cetnost[size];
	
	for (int i = 0; i < size; i++) {
		if (cetnost[i] == array[i])
			cetnost[i] += 1;
	}	//cetnost[cislozescanf] += 1; nacitam cisla a kdyz nactu tak
	
	// serazeni cisel na vstupu
	// kdyz mam histogram, vnoreny for, vypisu tolikrat tu hodnotu, kolikrat je cetnost
}

int main(int argc, char *argv[]) {
	int size;
	
	size = atoi(argv[1]);
	int pole[] = fill_array(size);
	histogram(size);

	return 0;
}


