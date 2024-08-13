#include "C2-matrix.h"


int getRows(FILE *file)
{
    if(file == NULL)
    {
        fprintf(stderr, "ERROR 2: Archivo vacio\n");
        exit(2);
    }else
    {
        int rows;
        fseek(file, 0, SEEK_SET);   // SEEK_SET es una macro?
        fscanf(file,"%d", &rows);
        return rows;
    }
}

int getCols(FILE *file)
{
    if(file == NULL)
    {
        fprintf(stderr, "ERROR 2: Archivo vacio\n");
        exit(2);
    }else
    {
        int cols;
        fseek(file, 0, SEEK_SET);       // SEEK_SET es una macro?
        fscanf(file,"%*d %d", &cols);   // %*d ignora el primer dato leido
        return cols;
    }
}

void createMatrix(Type_data ***array, int rows, int cols)
{
    if((*array = (Type_data **)malloc(sizeof(Type_data*)*rows)) == NULL)
        {
            fprintf(stderr, "ERROR\n");    // Añadir mensaje de error por el canal correspondiente.
            exit(1);                       // ERROR 1: No hay suficiente memoria disponible.
        }
    
    for (int i = 0; i < rows; i++) 
    {
        (*array)[i] = (Type_data *)malloc(cols * sizeof(Type_data));
        if ((*array)[i] == NULL)
        {
            fprintf(stderr, "ERROR\n");    // Añadir mensaje de error por el canal correspondiente.
            exit(1);                       // ERROR 1: No hay suficiente memoria disponible.
        }
    }   
}

void deleteMatrix(Type_data **array, int rows)
{
    for (int i = 0; i < rows; i++)
        free(array[i]);
    free(array);
}

void loadMatrix(Type_data **array, FILE *file)
{
    int rows = getRows(file);
    int cols = getCols(file);

    fseek(file, 0, SEEK_SET);   // puntero al inicio.
    fscanf(file, "%*d %*d");    // Ignoro fila y columnas.

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fscanf(file, "%f", &array[i][j]);
}

void showMatrix(Type_data **array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        printf("[ ");
        for (int j = 0; j < cols; j++)
            printf("%f ", array[i][j]);
        printf("]\n");
    }
}

void scalarProduct(Type_data **array, Type_data scalar, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            array[i][j] = scalar*array[i][j];
}

// Asumo que el usuario tiene conocimiento de las dimensiones de las matrices
void add(Type_data **array, Type_data **array1, Type_data **array2, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            array[i][j] = array1[i][j]+array2[i][j];
}

void multiply(Type_data **result, Type_data **array1, Type_data **array2, int rows1, int cols1, int rows2, int cols2)
 {
    // Verifica si la multiplicación es posible
    if (cols1 != rows2) {
        fprintf(stderr, "ERROR 3: Las dimensiones de las matrices no permiten la multiplicación.\n");
        exit(3);
    }

    // Inicializa la matriz resultado con ceros
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    // Multiplica las matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            Type_data suma = 0;
            for (int k = 0; k < cols1; k++) {  // Utiliza 'k' para el índice de la suma
                suma += array1[i][k] * array2[k][j];
            }
            result[i][j] = suma;
        }
    }
}

