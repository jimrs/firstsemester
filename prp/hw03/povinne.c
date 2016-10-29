#include <stdio.h>
#include <stdlib.h>

/* The main program */
int main(int argc, char *argv[])
{
  int w;
  int h;
  int roofw;
  int roofh;
  int ploth;
  
  if ( scanf("%d %d", &w, &h) != 2 ) {
    fprintf(stderr, "Error: Chybny vstup!\n");
    return 100;
  }
  else {
    if ( (w < 3 || w > 69) || (h < 3 || h > 69) ) {
        fprintf(stderr, "Error: Vstup mimo interval!\n");
        return 101;
    }
    if (w % 2 == 0) {
        fprintf(stderr, "Error: Sirka neni liche cislo!\n");
        return 102;
    }
  }
  
  roofh = w/2;
  roofw = w;
  
  for (int row = 0; row < roofh; row++) {
  	for (int col = 0; col < roofw; col++) {
  		if (col == roofh + row) {
  			printf("X\n");
  			break;
  		}
  		else if (col == roofh - row) {
  			printf("X");
  		}
  		else {
  			printf(" ");
  		}
  	}
  }
  
  for (int row = 0; row < h; row++) {
  	for (int col = 0; col < w; col++) {
  		if ( (row == 0) || (row == h-1) ) {
  			if (col == w-1) {
  				printf("X\n");
  				break;
  			}
  			else {
  				printf("X");
  			}
  		}
  		else {
  			if (col % (w-1) == 0) {
  				if (col == w-1) {
  					printf("X\n");
  					break;
  				}
  				else {
  					printf("X");
  				}
  			}
  			else {
  				printf(" ");
  			}
  		}	
  	}
  }
  
  
  return 0;
}

