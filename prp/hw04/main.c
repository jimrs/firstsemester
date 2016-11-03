#include <stdio.h>
#include <stdlib.h>

/* The main program */
int main(int argc, char *argv[])
{
  int user_input;
  int success = 1;
  
  while (success == 1) {
	if (scanf("%d", &user_input) != 1) {
		fprintf(stderr, "Error: Chybny vstup!\n");
  		return 100;
	}
  	if (user_input == 0) {
  		break;
  	}
  	else if (user_input < 0) {
  		fprintf(stderr, "Error: Chybny vstup!\n");
  		return 100;
  	}
  	else {
  		printf("Prvociselny rozklad cisla %d je:\n", user_input);
  		printf("%d\n", user_input);
  	}
  }
  
  return 0;
}

