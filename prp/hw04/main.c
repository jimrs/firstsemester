#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UPPER_LIMIT 1000004

int main(int argc, char *argv[])
{
  long long int user_input;
  short success = 1;
  long long int remainder;
  int iter = -1;
  int power = 1;
  
  // begin sieve of erasthotenes
  int sieve[UPPER_LIMIT] = {0};
  int primes[100004];
  
  for (int i = 2; i < UPPER_LIMIT; i++) {
  	if (sieve[i] == 0) {
  		for (int j = i * 2; j < UPPER_LIMIT; j += i)
  			sieve[j] = 1;
  	}
  }
  
  for (int i = 2; i < UPPER_LIMIT; i++) {
  	if (sieve[i] == 0) {
  		iter++;
  		primes[iter] = i;
  	}	
  }
  //end sieve of erasthotenes
  
   while (success == 1) {
	if (scanf("%lld", &user_input) != 1) {
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
  		printf("Prvociselny rozklad cisla %lld je:\n", user_input);	
  		
  		if (user_input == 1)
  			printf("%lld\n", user_input);
  			
  		remainder = user_input;
  		iter = 0;
  		power = 0;
  		
  		while (remainder != 1) {
  			if ( (remainder % primes[iter]) == 0) {
  			
  				remainder = remainder/primes[iter];
  				power++;
  				if ( (remainder % primes[iter]) == 0) {
  					continue;
  				}
  				else if ( (remainder != 1) && (power != 1) ) {
  					printf("%d^%d x ", primes[iter], power);
  				}
  				else if ( (remainder != 1) && (power = 1) ) {
  					printf("%d x ", primes[iter]);
  				}
  				else if (power != 1) {
  					printf("%d^%d\n", primes[iter], power);
  				}
  				else {
  					printf("%d\n", primes[iter]);
  				}
  				
  			}
  			else {
  				iter++;
  				power = 0;
  			}
  		}
  	}
  }
 
  
  return 0;
}

