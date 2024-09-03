#include <iostream>
#include "C3-matrix.h"
#include "C3-matrix.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    matrix<int> matriz1;
    matrix<int> matriz2;

    ifstream file1("matriz.txt");
    ifstream file2("matriz2.txt");

    matriz1.FloadMatrix(file1);
    matriz2.FloadMatrix(file2);

    //cout << matriz1.getRows() <<" "<< matriz1.getCols();

    cout<<" Primer matriz"<<endl;
    matriz1.showMatrix();

    cout<<" Segunda matriz"<<endl;
    matriz2.showMatrix();

    return 0;
}
