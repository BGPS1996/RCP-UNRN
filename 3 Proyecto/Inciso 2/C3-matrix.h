#ifndef C3_MATRIX_H
#define C3_MATRIX_H

#include <iostream>
#include <fstream>
#include <exception> // Libreria de excepciones


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
    matrix(int, int);
    ~matrix();
    matrix(const matrix<T> &); // constructor copia

    int getRows() const { return rows; } // Obtener fila de la matriz
    int getCols() const { return cols; } // Obtener columna de la matriz

    void FloadMatrix(ifstream &);
    void showMatrix();
    void scalarProduct(T);

    template <class U>
    friend matrix<U> operator+(const matrix<U> &_this, const matrix<U> &_other);
    template <class U>
    friend matrix<U> operator*(const matrix<U> &_this, const matrix<U> &_other);
    
    // Devuelve un puntero de la fila
    T* operator[](int row) {
        if (row >= 0 && row < rows) {
            return array[row];
        }
        throw out_of_range("Índice fuera de rango");
    }

    // con este, en la fila, obtengo el elemento del puntero de la fila
    const T* operator[](int row) const {
        if (row >= 0 && row < rows) {
            return array[row];
        }
        throw out_of_range("Índice fuera de rango");
    }

    /************************************** ERRORES *******************************************/
    /* ERROR 1: Dimension de filas o columnas invalidas.                                      */
    /* ERROR 2: Archivo vacio.                                                                */
    /* ERROR 3: Las dimensiones de las matrices no permiten la multiplicación.                */
    /* ERROR 4: No se pudo abrir el archivo.                                                  */
    /* ERROR 5: escalar igual a  cero.				   	                                      */
    /* ERROR 6: Las dimensiones de las matrices no son compatibles para la multiplicación.    */
    /************************************** ERRORES *******************************************/
};

#endif
