#include <stdio.h>

int isInBuf(const char *buf, char c, int size)
{
	
}

void _printComb(int size, const char *in, char *buf, int pos)
{
	const char *c;

	//bez opakovani
	//if (!isInBuf(buf, *c, pos) // tak pokracovat dal

	if (pos == size) {
		printf("%s\n", buf);
		return ;
	}

	for (c = in; *c != 0; c++) {
		if (!isInBuf(buf, *c, pos) {
			buf[pos] = *c;
			if (pos == size -1) {
				printf("%s\n", buf);
			} else {
				_printComb(size, in, buf, pos+1);
			}
		}
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
