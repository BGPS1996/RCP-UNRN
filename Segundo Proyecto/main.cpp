#include <iostream>
#include "C3-matrix.h"
#include "C3-matrix.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    matrix<int> matriz1;  // Cambiado: eliminado paréntesis
    matrix<int> matriz2;  // Cambiado: eliminado paréntesis

    ifstream file1("matriz.txt");
    ifstream file2("matriz2.txt");

    matriz1.FgetRows(file1);
    matriz2.FgetRows(file2);

    matriz1.FgetCols(file1);
    matriz2.FgetCols(file2);

    cout << matriz1.getRows() <<" "<< matriz1.getCols();


    matriz1.showMatrix();
    return 0;
}
