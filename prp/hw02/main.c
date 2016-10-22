#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int user_input;
  int num_count = 0;
  int pos_count = 0;
  int neg_count = 0;
  int even_count = 0;
  int odd_count = 0;
  int max = -10001;
  int min = 10001;
  float average = 0.0;

  while (scanf("%d", &user_input) != -1) {
    
    if ( (user_input < -10000) || (user_input > 10000) ) {
      printf("\nError: Vstup je mimo interval!\n");
      return 100;
    }

    num_count++;

    if (user_input > 0) {
      pos_count++;
    }
    else if (user_input < 0) {
      neg_count++;
    }

    if ( (user_input % 2 == 0) ) {
      even_count++;
    }
    else {
      odd_count++;
    }

    if (user_input > max) {
      max = user_input;
    }
    if (user_input < min) {
      min = user_input;
    }

    average += (user_input - average) / num_count; 
    
    if (num_count > 1) {
      printf(", %d", user_input);
    }
    else {
      printf("%d", user_input);
    }
  }

  printf("\nPocet cisel: %d\n", num_count);
  printf("Pocet kladnych: %d\n", pos_count);
  printf("Pocet zapornych: %d\n", neg_count);
  printf("Procento kladnych: %.2f\n", (pos_count/(float)num_count)*100);
  printf("Procento zapornych: %.2f\n", (neg_count/(float)num_count)*100);
  printf("Pocet sudych: %d\n", even_count);
  printf("Pocet lichych: %d\n", odd_count);
  printf("Procento sudych: %.2f\n", (even_count/(float)num_count)*100);
  printf("Procento lichych: %.2f\n", (odd_count/(float)num_count)*100);
  printf("Prumer: %.2f\n", average);
  printf("Maximum: %d\n", max);
  printf("Minimum: %d\n", min);
  
    
  return 0;
}

