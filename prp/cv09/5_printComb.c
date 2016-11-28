#include <stdio.h>

void _printComb(int size, const char *in, char *buf, int pos)
{
	const char *c;

	if (pos == size) {
		printf("%s\n", buf);
		return ;
	}

	for (c = in; *c != 0; c++) {
		buf[pos] = *c;
		_printComb(size, in, buf, pos+1);
	}
}

void printComb(int size, const char *in)
{
	char buf[size+1];
	buf[size] = 0;
	_printComb(size, in, buf, 0);
}

int main()
{
	printComb(2, "abc");

	return 0;
}
