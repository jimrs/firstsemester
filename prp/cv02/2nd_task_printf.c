#include <stdio.h>

int main()
{	
	int i = 10;
	fprintf(stdout, "Stdout: %d\n", i);
	fprintf(stderr, "Stderr: %d\n", i);
	
	// ./2nd_task_printf > output.log 2> error.log
	// timto ziskame dva rozdilne soubory, v jednom bude "Stdout 10" v druhem "Stderr 10"

	return 0;
}
