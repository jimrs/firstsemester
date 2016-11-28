#include <stdio.h>

int fib(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return fib(n-1) + fib(n-2); // rekurzivni strom volani

	// neefektivni, hodnekrat volam ty same funkce, lepe je for cyklus
}

int main()
{
	printf("%d\n", fib(1));
	printf("%d\n", fib(2));
	printf("%d\n", fib(3));
	printf("%d\n", fib(4));
	printf("%d\n", fib(5));
	//printf("%d\n", fib(10));
	//printf("%d\n", fib(20));
	//printf("%d\n", fib(30));
	//printf("%d\n", fib(45));

	return 0;
}
