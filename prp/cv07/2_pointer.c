#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *i;
	char *p;
	char **q;
	
	i = (int *)malloc(sizeof(int) * 3);
	i[0] = 10;
	i[1] = 11;
	i[2] = 12;
	
	q = &p;
	p = (char *)i;
	
	printf("p: %ld, &p: %ld, *p: %ld\n"
		"q: %ld, &q: %ld, *q: %ld **q: %ld\n"
		"i: %ld, &i: %ld, *i: %ld\n",
		(long) //dodelat
	
	return 0;
}
