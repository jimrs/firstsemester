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
	int **matarray;
	int *mat_rows;
	int *mat_cols;
	char *operands;
	//int **matarray_prod;
	//int *matarray_prod_rows;
	//int *matarray_prod_cols;

	int rows;
	int cols;
	int *mat;

	int allocated = 1;
	int size;
	int position = 0;
	int asterisk_row = 0;
	
	matarray = malloc(sizeof(int *) * allocated);
	mat_rows = malloc(sizeof(int) * allocated);
	mat_cols = malloc(sizeof(int) * allocated);
	operands = malloc(sizeof(char) * allocated);
	//matarray_prod = malloc(sizeof(int *) * allocated);
	//matarray_prod_rows = malloc(sizeof(int) * allocated);
	//matarray_prod_cols = malloc(sizeof(int) * allocated);

	for (size = 0; (mat = fillMatrix(&rows, &cols)) != NULL; size++) {
		if (size == allocated) {
			allocated *= 2;

			matarray = realloc(matarray, sizeof(int *) * allocated);
			mat_rows = realloc(mat_rows, sizeof(int) * allocated);
			mat_cols = realloc(mat_cols, sizeof(int) * allocated);
			operands = realloc(operands, sizeof(char) * allocated);
			//matarray_prod = realloc(matarray_prod, sizeof(int *) * allocated);
			//matarray_prod_rows = realloc(matarray_prod_rows, sizeof(int) * allocated);
			//matarray_prod_cols = realloc(matarray_prod_cols, sizeof(int) * allocated);
		}

		matarray[size] = mat;
		mat_rows[size] = rows;
		mat_cols[size] = cols;
		scanf(" %c", &operands[size]); // nacita i po posledni matici!
	}

	if (error == 100) {
		fprintf(stderr, "Error: Chybny vstup!\n");
		return 100;
	}

//	for (int i = 0; i < size; i++) {
//		printMatrix(matarray[i], mat_rows[i], mat_cols[i]);
//
	//	if (i == size-1) // abych nevypisoval posledni chybny byte
	//		break;
	//	else
	//		printf("%c\n", operands[i]);
	//}

	int *prod_result;

	for (int i = 0; i < size-1; i++) { // size-1 kvuli nacitani po posledni matici
		if (operands[i] == '*') {
			if (mat_cols[i] != mat_rows[i+1]) {
				fprintf(stderr, "Error: Chybny vstup!\n");
				return 100;
				
			} else {
				prod_result = prod(matarray[i], matarray[i+1], mat_rows[i], mat_cols[i], mat_rows[i+1], mat_cols[i+1]);
				
				for (int j = asterisk_row; j > -2; j--) {
					delMatrix(matarray[i-j]);
					matarray[i-j] = NULL;
					matarray[i-j] = prod_result;
					mat_rows[i-j] = mat_rows[i];
					mat_cols[i-j] = mat_cols[i+1];
				}
				asterisk_row++;
				free(prod_result);
				prod_result = NULL;
			}
		} else {
			asterisk_row = 0;
		}
	}

	//int *mat_result;
	int **results_allocated = malloc(sizeof(int *) * allocated);
	int mat_result_rows = mat_rows[0];
	int mat_result_cols = mat_cols[0];
	//mat_result = matarray[0];
	//results_allocated[0] = mat_result;
	results_allocated[0] = matarray[0];
	position++;

	for (int i = 0; i < size-1; i++) {
		if (operands[i] == '+' || operands[i] == '-') {
			if ((mat_result_rows != mat_rows[i+1]) || (mat_result_cols != mat_cols[i+1])) {
				fprintf(stderr, "Error: Chybny vstup!\n");
				return 100;
				
			} else if (operands[i] == '+') {
				results_allocated[position] = sum(results_allocated[position-1], matarray[i+1], mat_rows[i+1], mat_cols[i+1]);
				//results_allocated[i+1] = mat_result;

				matarray[i] = results_allocated[position];
				matarray[i+1] = results_allocated[position]; //abych osetril moznost vice + po sobe
				position++;
			} else if (operands[i] == '-') {
				results_allocated[position] = sub(results_allocated[position-1], matarray[i+1], mat_rows[i+1], mat_cols[i+1]);
				//results_allocated[i+1] = mat_result;
				
				delMatrix(matarray[i]);
				delMatrix(matarray[i+1]);
				matarray[i] = NULL;
				matarray[i+1] = NULL;
				matarray[i] = results_allocated[position];
				matarray[i+1] = results_allocated[position]; //abych osetril moznost vice - po sobe
				position++;
			}
		}
	}

	printMatrix(results_allocated[position-1], mat_result_rows, mat_result_cols);

	for (int i = 0; i < position; i++)
		delMatrix(results_allocated[i]);

	for (int i = 0; i < size; i++) {
		//delMatrix(results_allocated[i]);
		delMatrix(matarray[i]);
		//delMatrix(matarray_prod[i]);
	}
	
	free(matarray);
	free(mat_rows);
	free(mat_cols);
	free(operands);
	//free(matarray_prod);
	//free(matarray_prod_rows);
	//free(matarray_prod_cols);
	//free(mat_result);

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

