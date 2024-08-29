#ifndef C3_MATRIX_H
#define C3_MATRIX_H

#include <iostream>
#include <exception>	// Libreria de excepsiones

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
	
	int FgetRows(ifstream &);					// Dato en la estructura de representacion de la matriz
	int FgetCols(ifstream &);					// Dato en la estructura de representacion de la matriz

	int getRows() const { return rows};			// Obtener fila de la matriz
	int getCols() const { return cols};			// Obtener columna de la matriz

	void FloadMatrix(ifstream &);
	void showMatrix();
	void scalarProduct(T);
	

	friend matrix<T> operator+(const matrix<T> &_this, matrix<T> _other);
	friend matrix<T> operator*(const matrix<T> &_this, matrix<T> _other);
	//friend matrix<T> operator=(const matrix<T> &_this, matrix<T> _other);




	//void add(T **array, T **array1, T **array2, int rows, int cols);
	//void multiply(T **result, T **array1, T **array2, int rows1, int cols1, int rows2, int cols2);

	#endif /* C3_MATRIX_h */

	/*

	ERROR 1: Dimension de filas o columnas invalidas.
	ERROR 2: Archivo vacio.
	ERROR 3: Las dimensiones de las matrices no permiten la multiplicación.
	ERROR 4: No se pudo abrir el archivo.
	ERROR 5: Las matrices tienen distintas dimesiones.
	ERROR 6: Las dimensiones de las matrices no son compatibles para la multiplicación.
	*/	
};

#endif