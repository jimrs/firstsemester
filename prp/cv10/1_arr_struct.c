#include <stdio.h>
#include <stdlib.h>

struct arr {
	int *arr;	// 8B
	int size;	// 4B
	int alloc;	// 4B
};

typedef struct arr arr_t;

void arrInit(arr_t *arr)
{
	arr->arr = malloc(sizeof(int));
	arr->alloc = 1;
	arr->size = 0;
}

void arrFree(arr_t *arr)
{
	free(arr->arr);
}

void arrExpand(arr_t *arr)
{	
	arr->alloc *= 2;
	arr->arr = realloc(arr->arr, sizeof(int) * arr->alloc);
}

void arrAppend(arr_t *arr, int value)
{
	if (arr->alloc == arr->size)
		arrExpand(arr);
	
	arr->arr[arr->size] = value;
	arr->size++;
}

void arrPrepend(arr_t *arr, int value)
{
	if (arr->alloc == arr->size)
		arrExpand(arr);
		
	for (int i = arr->size; i > 0; i--) {
		arr->arr[i] = arr->arr[i-1];
	}

	arr->arr[0] = value;
	arr->size++;

	// nebo arrInsert(arr, value, 0);
}

void arrInsert(arr_t *arr, int value, int idx)
{
	if (idx < 0 || idx >= arr->size)
		return;

	if (arr->alloc == arr->size)
		arrExpand(arr);
		
	for (int i = arr->size; i > idx; i--) {
		arr->arr[i] = arr->arr[i-1];
	}

	arr->arr[idx] = value;
	arr->size++;
}

void arrDel(arr_t *arr, int idx)
{
	if (idx < 0 || idx >= arr->size)
		return;

	for (int i = idx; i < arr->size; i++) {
		arr->arr[i] = arr->arr[i+1];
	}

	arr->size--;
}

int main()
{
	arr_t arr;

	arrInit(&arr);

	arrAppend(&arr, 2);
	arrAppend(&arr, 4);
	arrAppend(&arr, 5);
	arrAppend(&arr, 7);
	arrPrepend(&arr, 1);
	arrPrepend(&arr, 0);
	arrInsert(&arr, 10, 1);
	arrDel(&arr, 3);
	arrAppend(&arr, 2);

	for (int i = 0; i < arr.size; i++) {
		printf("%d: %d\n", i, arr.arr[i]);
	}

	arrFree(&arr);

	return 0;


	// x -> y je to same jako (*x).y, pouziva se tedy u pointeru na struct
	// x[i] <=> *(x+i)
}
