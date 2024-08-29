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
	if( f <= 0 || c <= 0)
		throw invalid_argument("ERROR 1: La dimension de la fila o columna son invalidas");

	this->rows = f;
	this->cols = c;
	this->array = new T*[rows]{};
	
	// Manejador de excepsiones por si hay un error en el guardado en la memoria
	try{
		for (int i = 0; i < this->rows; ++i)
		{
			array[i] = new T[cols]{};
		}
	}catch(const bad_alloc& e){
        for (int i = 0; i < this->rows; ++i)
        {
            delete[] this->array[i];
        }
        delete[] this->array;
        //throw; // En caso de utilizar un catch externo a mi constructor
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
	
	try{
		this->array = new T[rows];
	
		for (int i = 0; i < rows; ++i)
		{
			this->array[i] = new T*[cols];
			for (int i = 0; i < cols; ++i)
			{
				this->array[i][j] = other.array[i][j];
			}
		}
	}catch(const bad_alloc& e){
        for (int i = 0; i < this->rows; ++i)
        {
            delete[] this->array[i];
        }
        delete[] this->array;
        //throw; // En caso de utilizar un catch externo a mi constructor		
	}
}

template<class T>
int matrix<T>::FgetRows(ifstream &file)
{
	if(file == NULL)
		throw runtime_error("ERROR 2: Archivo vacio");
	else{
		fseek(file, 0, SEEK_SET);
		fscanf(file, "%d", &(this->rows));

		return this->rows;
	}
}
template<class T>
int matrix<T>::FgetCols(ifstream &file)
{
	if(file == NULL)
		throw runtime_error("ERROR 2: Archivo vacio");
	else{
		fseek(file, 0, SEEK_SET);
		fscanf(file, "%*d %d", &(this->cols));

		return this->cols;
	}	
}

template <class T>
void matrix<T>::FloadMatrix(ifstream& file)
{
	if(!(file.is_open()))
		throw runtime_error("ERROR 4: No se pudo abrir el archivo");

    fseek(file, 0, SEEK_SET);   // puntero al inicio.
    fscanf(file, "%*d %*d");    // Ignoro fila y columnas.

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fscanf(file, "%T", &(this->array[i][j]));	
}
template <class T>
void matrix<T>::showMatrix()
{
    for (int i = 0; i < (this->rows); i++)
    {
        cout<< "[";
        for (int j = 0; j < (this->cols); j++)
        	cout << this->array[i][j] << " ";
        cout << "]" << endl;
    }	
}
template<class T>
void matrix<T>::scalarProduct(T scalar)
{
	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < this->cols; ++j)
		{
			this->array[i][j] *= scalar;
		}
	}
}


