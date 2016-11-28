#include <stdio.h>

int strlen_recursive(const char *str, int tmp)
{
	//int i; nerekurzivne
	//for (i = 0; str[i] != 0; i++);
	//return i;
	
	if (str[tmp] != 0)
		strlen_recursive(str, tmp+1);
	return tmp;
	//nefunkcni
}

int strlen_recursive2(const char *str, int tmp)
{
	if (str[tmp] == 0)
		return tmp;
	return strlen_recursive(str, tmp+1);
}

int strlen_recursive3(const char *str)
{
	if (*str == 0)
		return 0;
	return 1 + strlen_recursive3(str+1); // str+1 bude poporade "abc", "bc", "c", ""
}

int main()
{
	printf("%d\n", strlen_recursive("abc", 0));

	return 0;
}
