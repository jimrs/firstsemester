#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lock.h"

int isInBuffer(const char *buffer, char c, int size);
void _printComb(int size, const char *input, char *buffer, int pos);
void printComb(int size, const char *in);

int main(int argc, char *argv[])
{
	char characters[9];
	char input;
	int size = 0;

	characters[0] = '\0';

	for (size = 0; size < 8; size++) {
		input = getchar();

		if (input == EOF || input == '\n')
			break;
		else if ((input >= '0' && input <= '9') || (input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z'))
			characters[size] = input;
		else {
			fprintf(stderr, "Error: Chybny vstup!\n");
			return 100;
		}
	}

	if (size == 0) {
		fprintf(stderr, "Error: Chybny vstup!\n");
		return 100;
	}

	characters[size] = '\0';

	printComb(size, characters);

	return 0;
}

void printComb(int size, const char *input)
{
	char buffer[size+1];
	buffer[size] = 0;
	_printComb(size, input, buffer, 0);
}

void _printComb(int size, const char *input, char *buffer, int pos)
{
	const char *c;

	if (pos == size) {
		printf("%s\n", buffer);
		return;
	}

	for (c = input; *c != '\0'; c++) {
		if (!isInBuffer(buffer, *c, pos)) {
			buffer[pos] = *c;
			if (pos == size-1)
				printf("%s\n", buffer);
			else
				_printComb(size, input, buffer, pos+1);
		}
	}
}

int isInBuffer(const char *buffer, char c, int size)
{
	for (int i = 0; i < size; i++) {
		if (buffer[i] == c)
			return 1;
	}

	return 0;
}
