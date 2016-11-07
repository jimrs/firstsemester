#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int arr[5] = { 1, 2, 3, 4, 5 };
	printf("%ld\n", (long)arr); // vypise adresu ulozenou v pointeru	 	

    //for (int i = -100; i < 100; ++i){	//okolo 2k se zacne pristupovat k pameti, ke ktere nemame pristup tedy segmentation fault
        //printf("%d: %d\n", i, arr[i]);
      //  printf("%d: %d : %ld\n", i, arr[i], (long)(arr+i));	// vypise i adresu pametove bunky
    //}
 
    return 0;
}
