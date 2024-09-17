#ifndef C2_MATRIX_h
#define C2_MATRIX_h

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

typedef float Type_data;

void createMatrix(Type_data ***, int, int);	// Reserva de memoria para array nxm
void deleteMatrix(Type_data **, int);

int getRows(FILE *);						// Dato en la estructura de representacion de la matriz
int getCols(FILE *);						// Dato en la estructura de representacion de la matriz

void loadMatrix(Type_data **array, FILE *file);
void showMatrix(Type_data **array, int rows, int cols);
void scalarProduct(Type_data **array, Type_data scalar, int rows, int cols);
void add(Type_data **array, Type_data **array1, Type_data **array2, int rows, int cols);
void multiply(Type_data **result, Type_data **array1, Type_data **array2, int rows1, int cols1, int rows2, int cols2);

#endif /* C2_MATRIX_h */

/*

ERROR 1 : No hay memoria disponible para almacenar.
ERROR 2 : Archivo vacio.
ERROR 3: Las dimensiones de las matrices no permiten la multiplicación.
*/