#include <stdio.h>
#include <stdlib.h>

double *newMatrix(int row, int col)
{
	return (double *)malloc(row*col*sizeof(double));
}

void delMatrix(double *mat)
{
	free(mat);
}

double getValue(const double *mat, int col, int r, int c)
{
	//return "mat[r][c]"
	return mat[r*col + c];
}

void setValue(double *mat, int col, int r, int c, double val)
{
	// "mat[r][c] = val"
	mat[r*col + c] = val;  // arr[i] = *(arr + i)
}

double *readMatrix(int *row, int *col)
{
	// *row
	// *col
	// mat[i][j] = (i,j)
	
	// return mat
	double *mat;
	double v;
	
	scanf("%d %d", row, col); // if != 2 tak return null
	
	mat = newMatrix(*row, *col);
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			scanf("%lf", &v); // &v je ekvivalentni k mat + i * *col + j
			// coz je ekvivalentni k &mat[i* *col + j]
			
		}
	}
	
	return v;
}

void printMatrix(const double *mat, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %lf", mat[j*col+i]);
		}
		printf("\n");
	}
}

double *transpose(const double *mat, int row, int col)
{
	double *mat_t;
	
	mat_t = newMatrix(col, row);
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			setValue(mat_t, row, j, i, getValue(mat, col, i, j));
		}
	}
	
	return mat_t;
}



int main()
{
	double **matarr;
	double *mat, *mat_t;
	int row, col;
	int *mat_rows, *mat_cols;
	int alloc; // pocet matic ktere jsem zaalokoval
	int size; //pocet matic ktere jsem nacetl
	
	//matarr = (double **)malloc(sizeof(double *) * 100); vejde se 100 matic
	matarr = (double **)malloc(sizeof(double *) * alloc); //kdyz nevime kolik matic bude
	mat_rows = (int *)malloc(sizeof(int) * alloc);
	mat_cols = (int *)malloc(sizeof(int) * alloc);
	
	for (size = 0; (mat = readMatrix(&row, &col)) != NULL; size++)	//musim dealokovat to, na co pole pointeru ukazuje
	{
		if (size == alloc) {
			alloc *= 2; //zdvojnasobeni pro realloc
			matarr = (double **)realloc(sizeof(double *) * alloc); //kdyz nevime kolik matic bude
			mat_rows = (int *)realloc(sizeof(int) * alloc);
			mat_cols = (int *)realloc(sizeof(int) * alloc);
		}
		
		matarr[size] = mat;
		mat_rows[size] = row;
		mat_cols[size] = col;
		
	}
	//matarr[0] = readMatrix(&col, &row); obecne napsano ve for cyklu tady nahore
	//matarr[1] = readMatrix(&col, &row);
	
	for (int i = 0; i < size; i++)
	{
		printMatrix(matarr[i], mat_rows[i], mat_cols[i]);
		printf("\n");
	}
	
	for (int i = 0; i < size; i++)
		delMatrix(matarr[i]);
	
	free(matarr);
	free(mat_rows);
	free(mat_cols);
	
	//kdyz nejde realloc, jde malloc noveho vetsiho useku a zkopirovat tam predchozi obsah
	//reallocovat na dvojnasobky toho, co mam, je casove vyhodne
	
	mat = readMatrix(&row, &col);
	printMatrix(mat, row, col);
	
	mat_t = transpose(mat, row, col);
	printf("------\n");
	printMatrix(mat_t, col, row);
	
	delMatrix(mat);
	delMatrix(mat_t);
	
	//pole matic - double **matarr;
	// matarr[0] je typu double *
	// tedy matarr[0][1] je druha polozka prvni matice
	
	//scanf("%d %d", &row, &col);
	
	//double *mat; //pointer na pole, alokuje se na halde, klasicka double mat[row][col] se alokuje na stacku
	//mat = (double *)malloc(row*col*sizeof(double));
	
	//for (int i = 0; i < row; i++)
	//{
		//for (int j = 0; j < col; j++)
		//{
			//scanf("%lf", &mat[i*col+j]);	//je ulozeno linearne (jednorozmerne), index(i,j) = i * col + j
		//}
	//}
	
	//for (int i = 0; i < col; i++)
	//{
		//for (int j = 0; j < row; j++)
		//{
			//printf(" %lf", mat[j*col+i]);
		//}
		//printf("\n");
	//}

	return 0;
}
