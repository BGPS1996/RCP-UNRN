#include <stdio.h>
#include <stdlib.h>
#include "C2-matrix.h"

int main(int argc, char const *argv[])
{
	FILE *arch, *arch2;

	Type_data **matrix, **matrix2;

	if((arch = fopen("matriz.txt", "r")) == NULL)
	{
		fprintf(stderr, "ERROR 2: Archivo vacio");
		exit(2);
	}

	if((arch2 = fopen("matriz2.txt", "r")) == NULL)
	{
		fprintf(stderr, "ERROR 2: Archivo vacio");
		exit(2);
	}

	int rows = getRows(arch);
	int cols = getCols(arch);

	int rows2 = getRows(arch2);
	int cols2 = getCols(arch2);
	createMatrix(&matrix, rows, cols);
	createMatrix(&matrix2, rows2, cols2);

	loadMatrix(matrix, arch);
	loadMatrix(matrix2, arch2);
	fclose(arch);
	fclose(arch2);
	showMatrix(matrix, rows, cols);
	printf("\n");
	showMatrix(matrix2, rows2, cols2);

	
	deleteMatrix(matrix, rows);
	



	return 0;
}
