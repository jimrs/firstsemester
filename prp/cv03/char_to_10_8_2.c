#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char user_input = getchar();

  printf("%d\n", user_input);
  printf("0x%x\n", user_input);

  int dec = user_input;

  for (int i = 31; i >= 0; i--) {
    int tmp = dec >> i;
    int leading_zeros = 1;
    char binary[33];
    if (tmp & 1) {
      strcat("1", binary);
      leading_zeros = 0;
    }
    else if (!leading_zeros) {
      strcat("0", binary);
    }
  }


  return 0;
}
