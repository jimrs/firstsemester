#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	const char *from, *to;
	char c;

	if (argc != 3) 	{
		fprintf(stderr, "error\n");
		return -1;
	}

	from = argv[1];
	to = argv[2];

	while ((c = fgetc(stdin)) != EOF)	//funguje jen kdyz nahrazuju jeden znak!!!
	{
		if (c == *from)
			printf("%c", *to); 
		else
			printf("%c", c);
	}

	printf("\n");

	//jinak
	int i;
	while ((c = fgetc(stdin)) != EOF)
	{
		for (i = 0; from[i] != 0 && from[i] != c; i++);

		if (from[i] == c)
			printf("%c", to[i]);
		else
			printf("%c", c);
	}

	char *table = (char *)malloc(256);
	for (i = 0; i < 256; i++)
		table[i] = i;	//vyplneni ascii tabulky
	for (i = 0; from[i] != 0; i++)
		table[from[i]] = to[i];	//nahradil jsem znaky from znaky to

	while ((c = fgetc(stdin)) != EOF) {
		printf("%c", table[c]);
	}

	free(table);

	return 0;
}
