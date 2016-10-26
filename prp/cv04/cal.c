#include <stdio.h>
#include <stdlib.h>

int main() {
	static char *day_of_week[] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su" };
	
	for (int i = 0; i < 7; i++) {
		printf("%s ", day_of_week[i]);
	}
	printf("\n");
	
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%2d ", j+1);
		}
		printf("\n");
	}
	
	return 0;
}
