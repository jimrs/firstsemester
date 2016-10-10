#include <stdio.h>

int main()
{	
	char c = 'a';
	int i = 100,j;
	float x,y = 3.1415;
 
	printf("%c\n",c);
	printf("%i\n",c);
 
	printf("%d\n",i);
	printf("%+5d\n",i);
	printf("%x\n",i);
 
	printf("%f\n",y);
	printf("%10.3f\n",y);		//width a .precision
	printf("\t%-g\n",y);		// tabulátor a %-g
	
	printf("%6d,%4d",86,1040);
	printf("\n");
	printf("%12.5e",3.14159265);
	printf("\r");					//carriage return	(návrat kurzoru na začátek řádky)
	printf("%.4f\n",85.167);
	
	return 0;
}
