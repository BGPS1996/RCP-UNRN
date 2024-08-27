#include <iostream>

#include "C3-matrix.h"

template <class T>
matrix<T>::matrix()
{
	this->rows = 0;
	this->cols = 0;
	this->array = nullptr;

}

template <class T>
matrix<T>::matrix(int f, int c)
{
	if( f < 0 || c < 0)
	{
		fprintf(stderr, " La dimension de la fila o columna son invalidas\n");
		exit(1);
	}
	this->rows = f;
	this->cols = c;
	
	this->array = new T*[rows];
	for (int i = 0; i < rows; ++i)
	{
		array[i] = new T*[cols]{}; // las {} para evitar la basura
	}

}

template <class T>
matrix<T>::~matrix()
{
	for (int i = 0; i < this->rows; ++i)
	{
		delete[] this->array[i];
	}
	delete[] array;
}

template<class T>
matrix<T>::matrix(const matrix<T> &other)
{
	this->rows = other.rows;
	this->cols = other.cols;

	this->array = new T*[rows];
	for (int i = 0; i < rows; ++i)
	{
		this->array[i] = new T*[cols];
		for (int i = 0; i < cols; ++i)
		{
			this->array[i][j] = other.array[i][j];
		}
	}
}

template<class T>
int matrix<T>::FgetRows(FILE *file)
{
	if(file == NULL)
	{
		fprintf(stderr, " Archivo vacio\n");
		exit(2);
	}else{
		fseek(file, 0, SEET_SET);
		fscanf(file, "%d", &(this->rows));

		return this->rows;
	}
}
template<class T>
int matrix<T>::FgetCols(FILE *file)
{
	if(file == NULL)
	{
		fprintf(stderr, " Archivo vacio\n");
		exit(2);
	}else{
		fseek(file, 0, SEET_SET);
		fscanf(file, "%*d %d", &(this->cols));

		return this->cols;
	}	
}

template <class T>
void matrix<T>::FloadMatrix(FILE *file)
{
    fseek(file, 0, SEEK_SET);   // puntero al inicio.
    fscanf(file, "%*d %*d");    // Ignoro fila y columnas.

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fscanf(file, "%f", &(this->array[i][j]));	
}
template <class T>
void matrix<T>::showMatrix()
{
    for (int i = 0; i < (this->rows); i++)
    {
        cout<< "["
        for (int j = 0; j < (this->cols); j++)
        	cout << this->array[i][j] << " ";
        cout << "]" << endl;
    }	
}
void scalarProduct(T scalar);


