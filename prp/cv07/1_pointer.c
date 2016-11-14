#include <stdio.h>
#include <stdlib.h>

int main()
{
	//printf("%ld\n", sizeof(void*));		// vrati 8B, tedy adresa je 64 bitu dlouha
	
	int i = 1;
	long addr = (long)&i;
	
	printf("%d %d %d %d\n", *(char*)addr, *(char*)(addr+1), *(char*)(addr+2), *(char*)(addr+3));	//adresy bunek
	
	i = 500;
	unsigned char *c;
	
	c = (char *)&i;
	
	printf("%d %d %d %d\n", *c, *(c+1), *(c+2), *(c+3));	// 4 bajtovy int vypisuju po 1 bajtovych bunkach (hodnoty 1B bunek
	printf("%d %d %d %d\n", c[0], c[1], c[2], c[3]);
	
	return 0;
}
