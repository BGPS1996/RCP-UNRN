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
    if (f <= 0 || c <= 0)
        throw invalid_argument("ERROR 1: La dimension de la fila o columna son invalidas");

    this->rows = f;
    this->cols = c;
    this->array = new T *[rows]{};

    try
    {
        for (int i = 0; i < this->rows; ++i)
        {
            array[i] = new T[cols]{};
        }
    }
    catch (const bad_alloc &e)
    {
        for (int i = 0; i < this->rows; ++i)
        {
            delete[] this->array[i];
        }
        delete[] this->array;
        throw; // En caso de utilizar un catch externo a mi constructor
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

template <class T>
matrix<T>::matrix(const matrix<T> &other)
{
    this->rows = other.rows;
    this->cols = other.cols;

    try
    {
        this->array = new T *[rows];

        for (int i = 0; i < rows; ++i)
        {
            this->array[i] = new T[cols];
            for (int j = 0; j < cols; ++j)
            {
                this->array[i][j] = other.array[i][j];
            }
        }
    }
    catch (const bad_alloc &e)
    {
        for (int i = 0; i < this->rows; ++i)
        {
            delete[] this->array[i];
        }
        delete[] this->array;
        throw; // En caso de utilizar un catch externo a mi constructor
    }
}

template <class T>
void matrix<T>::FloadMatrix(ifstream &file)
{
    if (!file.is_open())
        throw runtime_error("ERROR 4: No se pudo abrir el archivo");

    int fileRows, fileCols;
    file >> fileRows >> fileCols;

    if (this->array != nullptr)
    {
        for (int i = 0; i < this->rows; ++i)
        {
            delete[] this->array[i];
        }
        delete[] this->array;
    }

    this->rows = fileRows;
    this->cols = fileCols;

    this->array = new T *[rows];
    for (int i = 0; i < rows; ++i)
    {
        this->array[i] = new T[cols];
    }

    // Leer valores del archivo
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            file >> this->array[i][j];
        }
    }
}



template <class T>
void matrix<T>::showMatrix()
{
    for (int i = 0; i < (this->rows); i++)
    {
        cout << "[";
        for (int j = 0; j < (this->cols); j++)
            cout << this->array[i][j] << " ";
        cout << "]" << endl;
    }
}

template <class T>
void matrix<T>::scalarProduct(T scalar)
{
	 if (scalar == 0)
        throw invalid_argument("ERROR 5: escalar igual a cero");

    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->cols; ++j)
            this->array[i][j] *= scalar;
    } 
}

template <class T>
matrix<T> operator*(const matrix<T> &_this, const matrix<T> &_other)
{
    if (_this.cols != _other.rows)
        throw invalid_argument("ERROR 6: Las dimensiones de las matrices no son compatibles para la multiplicación.");

    matrix<T> resultado(_this.rows, _other.cols);
    for (int i = 0; i < _this.rows; ++i)
    {
        for (int j = 0; j < _other.cols; ++j)
        {
            for (int k = 0; k < _this.cols; ++k)
                resultado.array[i][j] += _this.array[i][k] * _other.array[k][j];
        }
    }
    return resultado;
}
