#include <stdio.h>

void printNum(int from, int to)
{
	// jde s cyklem
	
	//for (int i = from; i <= to; i++)
	//	printf("%d\n", i);

	if (from <= to) {
		printf("%d\n", from);

		printNum(from+1, to);
	}
}

void printNumBetter(int from, int to)
{
	printf("%d\n", from);
	if (from < to)
		printNumBetter(from+1, to);
}

void printNumViceVersa(int from, int to)
{
	//for (int i = to; i >= from; i--)
	//	printf("%d\n", i);
	

	printf("%d\n", to);
	if (to > from)
		printNumViceVersa(from, to-1);
}

void printNumViceVersaBetter(int from, int to)
{
	// hezka vlastnost rekurze
	// identicke s printNumBetter, jen print pozdeji az kdyz vylezam z
	// rekurze
	
	if (from < to)
		printNumViceVersaBetter(from+1, to);
	printf("%d\n", from);
}

int main()
{
	printNum(5, 10);
	printNumBetter(5, 10);
	printNumViceVersa(5, 10);
	printNumViceVersaBetter(5, 10);

	return 0;
}
