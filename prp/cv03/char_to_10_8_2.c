#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char user_input = getchar();

  printf("%d\n", user_input);
  printf("0x%x\n", user_input);

  int dec = user_input;

  for (int i = 31; i >= 0; i--) {
    int asd = dec >> i;
    printf("%d\n", asd);
    if (asd & 1) {
      printf("\n");
    }
    else {
      printf("\n");
    }
  }


  return 0;
}
