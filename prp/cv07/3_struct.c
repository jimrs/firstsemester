#include <stdio.h>
#include <stdlib.h>

struct a_t
{
	int x;
	int y;
};


int main()
{
	struct a_t st;
	
	printf("&st: %ld &st.x: %ld &st.y: %ld\n", (long)&st, (long)&st.x, (long)&st.y);
}
