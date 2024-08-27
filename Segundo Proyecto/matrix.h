#ifndef C3_MATRIX_H
#define C3_MATRIX_H
#include <iostream>

using namespace std;
template <class T>
class matrix
{
private:
	int rows;
	int cols;
	T **array;

public:
	matrix();
	~matrix();
	matrix(const matrix<T>&);					// constructor copia
												// constructor copia, referencia
	
	int FgetRows(FILE *);						// Dato en la estructura de representacion de la matriz
	int FgetCols(FILE *);						// Dato en la estructura de representacion de la matriz

	int getRows() const { return rows};			// Obtener fila de la matriz
	int getCols() const { return cols};			// Obtener columna de la matriz

	void FloadMatrix(FILE *);
	void showMatrix();
	void scalarProduct(T);
	
	//void add(T **array, T **array1, T **array2, int rows, int cols);
	//void multiply(T **result, T **array1, T **array2, int rows1, int cols1, int rows2, int cols2);

	#endif /* C2_MATRIX_h */

	/*

	ERROR 1 : Dimension de filas o columnas invalidas
	ERROR 2 : Archivo vacio.
	ERROR 3: Las dimensiones de las matrices no permiten la multiplicación.
	*/	
};

#endif