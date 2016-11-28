#include <stdio.h>
#include <string.h>

void printComb(const char *in)
{
	// nejde realizovat bez rekurze
	
	//for (int i = 0; i < strlen(in); i++) {
	//	printf("%c", in[0]);
	//}
	//printf("\n"); presne toto nejde
}


int main() 
{
	printComb("a");
	printComb("ab");
	printComb("abc");

	return 0;
}
