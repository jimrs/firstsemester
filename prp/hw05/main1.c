#include <stdio.h>
#include <stdlib.h>

int *newMatrix(int rows, int cols);
void printMatrix(const int *mat, int rows, int cols);
int get(const int *mat, int cols, int i, int j);
void set(int *mat, int cols, int i, int j, int val);
void delMatrix(int *mat);
int *fillMatrix(int *rows, int *cols);
int *sum(int *mat1, int *mat2, int rows, int cols);
int *sub(int *mat1, int *mat2, int rows, int cols);
int *prod(int *mat1, int *mat2, int rows1, int cols1, int rows2, int cols2);

int error = 0;

int main(int argc, char *argv[])
{
	int *mat1;
	int *mat2;
	int rows1;
	int cols1;
	int rows2;
	int cols2;
	char operand;
	int *result;
	int res_rows;
	int res_cols;
	
	mat1 = fillMatrix(&rows1, &cols1);
	scanf(" %c", &operand);
	mat2 = fillMatrix(&rows2, &cols2);
	
	if (error == 100) {
		fprintf(stderr, "Error: Chybny vstup!\n");
		free(mat1);
		free(mat2);
		return 100;
	}
	
	if (operand == '*') {
			if (cols1 != rows2) {
				fprintf(stderr, "Error: Chybny vstup!\n");
				return 100;
				
			} else {
				result = prod(mat1, mat2, rows1, cols1, rows2, cols2);
				res_rows = rows1;
				res_cols = cols2;
			}
	}
	
	if (operand == '+') {
			if ((rows1 != rows2) || (cols1 != cols2)) {
				fprintf(stderr, "Error: Chybny vstup!\n");
				return 100;
				
			} else {
				result = sum(mat1, mat2, rows1, cols1);
				res_rows = rows1;
				res_cols = cols1;
			}
	}
	
	if (operand == '-') {
			if ((rows1 != rows2) || (cols1 != cols2)) {
				fprintf(stderr, "Error: Chybny vstup!\n");
				return 100;
				
			} else {
				result = sub(mat1, mat2, rows1, cols1);
				res_rows = rows1;
				res_cols = cols1;
			}
	}
	
	printMatrix(result, res_rows, res_cols);
	
	free(mat1);
	free(mat2);
	free(result);
	
	
	return 0;
}

int *newMatrix(int rows, int cols)
{
	return malloc(sizeof(int) * rows * cols);
}

int *fillMatrix(int *rows, int *cols)
{
	int *mat;

	if (scanf("%d %d", rows, cols) != 2)
		return NULL;

	mat = newMatrix(*rows, *cols);

	for (int i = 0; i < *rows; i++) {
		for (int j = 0; j < *cols; j++) {
			if (scanf("%d", &mat[i * *cols + j]) != 1)
				error = 100;
		}
	}

	return mat;
}

void printMatrix(const int *mat, int rows, int cols)
{
	printf("%d %d\n", rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (j == 0)
				printf("%d", get(mat, cols, i, j));
			else
				printf(" %d", get(mat, cols, i, j));
		}
		printf("\n");
	}
}

int get(const int *mat, int cols, int i, int j)
{
	return mat[i * cols + j];
}

void set(int *mat, int cols, int i, int j, int val)
{
	mat[i * cols + j] = val;
}

void delMatrix(int *mat)
{
	if (mat == NULL)
		return;
	free(mat);
	mat = NULL;
}

int *sum(int *mat1, int *mat2, int rows, int cols)
{
	int *result;
	result = newMatrix(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			set(result, cols, i, j, get(mat1, cols, i, j) + get(mat2, cols, i, j));
		}
	}

	return result;
}

int *sub(int *mat1, int *mat2, int rows, int cols)
{
	int *result;
	result = newMatrix(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			set(result, cols, i, j, get(mat1, cols, i, j) - get(mat2, cols, i, j));
		}
	}

	return result;
}

int *prod(int *mat1, int *mat2, int rows1, int cols1, int rows2, int cols2)
{
	int *result;
	result = newMatrix(rows1, cols2);

	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols2; j++) {
			int preres = 0;
			
			for (int k = 0; k < cols1; k++)
				preres += get(mat1, cols1, i, k) * get(mat2, cols2, k, j);

			set(result, cols2, i, j, preres);
		}
	}

	return result;
}

