#ifndef C3_MATRIX_H
#define C3_MATRIX_H

/**
 * @file C3-matrix.h
 * @author BGPS
 * @brief Clase que representa una matriz genérica y proporciona operaciones básicas.
 *
 * Esta clase permite crear, manipular y realizar operaciones sobre matrices de tipo genérico T.
 * Se pueden realizar operaciones como suma y multiplicación de matrices, así como la carga
 * de matrices desde archivos.
 */

#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

template <class T>
class matrix
{
private:
    int rows;       ///< Cantidad de filas en la matriz.
    int cols;       ///< Cantidad de columnas en la matriz.
    T **array;      ///< Puntero doble que representa la matriz.

public:
    /**
     * @brief Constructor por defecto.
     * Inicializa la matriz sin filas ni columnas.
     */
    matrix();

    /**
     * @brief Constructor con dimensiones especificadas.
     * @param[in] r Número de filas.
     * @param[in] c Número de columnas.
     * @throw std::invalid_argument Si las dimensiones son menores o iguales a cero.
     */
    matrix(int r, int c);

    /**
     * @brief Destructor.
     * Libera la memoria asignada a la matriz.
     */
    ~matrix();

    /**
     * @brief Constructor de copia.
     * @param[in] other Matriz a copiar.
     */
    matrix(const matrix<T> &other);

    /**
     * @brief Obtiene la cantidad de filas en la matriz.
     * @return Número de filas.
     */
    int getRows() const { return rows; }

    /**
     * @brief Obtiene la cantidad de columnas en la matriz.
     * @return Número de columnas.
     */
    int getCols() const { return cols; }

    /**
     * @brief Carga una matriz desde un archivo.
     * @param[in] file Stream de archivo desde el cual cargar la matriz.
     * @throw std::runtime_error Si no se puede abrir el archivo o si el archivo está vacío.
     */
    void FloadMatrix(ifstream &file);

    /**
     * @brief Muestra la matriz en la salida estándar.
     */
    void showMatrix();

    /**
     * @brief Realiza el producto escalar de la matriz por un escalar.
     * @param[in] scalar Escalar por el cual multiplicar la matriz.
     * @throw std::invalid_argument Si el escalar es igual a cero.
     */
    void scalarProduct(T scalar);

    /**
     * @brief Sobrecarga del operador de suma para matrices.
     * @param[in] _this Primera matriz.
     * @param[in] _other Segunda matriz.
     * @return Nueva matriz que resulta de la suma.
     * @throw std::invalid_argument Si las dimensiones de las matrices no son compatibles.
     */
    template <class U>
    friend matrix<U> operator+(const matrix<U> &_this, const matrix<U> &_other);

    /**
     * @brief Sobrecarga del operador de multiplicación para matrices.
     * @param[in] _this Primera matriz.
     * @param[in] _other Segunda matriz.
     * @return Nueva matriz que resulta de la multiplicación.
     * @throw std::invalid_argument Si las dimensiones de las matrices no permiten la multiplicación.
     */
    template <class U>
    friend matrix<U> operator*(const matrix<U> &_this, const matrix<U> &_other);

    // Devuelve un puntero a la fila
    T* operator[](int row) {
        if (row >= 0 && row < rows) {
            return array[row];
        }
        throw out_of_range("Índice fuera de rango");
    }

    // Con este, en la fila, obtengo el elemento del puntero de la fila
    const T* operator[](int row) const {
        if (row >= 0 && row < rows) {
            return array[row];
        }
        throw out_of_range("Índice fuera de rango");
    }
};

#endif
