#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  int n;
  float leibniz(int n);

  printf("Enter a number n for a number of Leibniz series members: ");
  scanf("%d", &n);

  float pi = 3.141592;
  //float potential = leibniz(n);

  do {
    printf("%.9g\n", leibniz(n));
    if ( (fabs(leibniz(n) - pi)) < 10E-6 ) {
      break;
    }
    n = n + 1;
  } while (n > 0);
  //if ( fabs((potential - pi)) < 10E-6) {
    //printf("aww yiss\n");
  //}

  return 0;
}


float leibniz(int n) {
  float k = 0.0;
  float pi = 0.0;
  int i = 0;

  while (i < n) {
    if (i % 2 == 0)
		{
			pi += 4 / (2 * k + 1);
		}
		else
		{
			pi -= 4 / (2 * k + 1);
		}
    i++;
    k++;
  }

  return pi;
}
