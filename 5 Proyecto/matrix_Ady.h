#ifndef MATRIX_ADY_H
#define MATRIX_ADY_H

#include <iostream>
#include "..\3 Proyecto\Inciso 2\C3-matrix.h"
#include "..\3 Proyecto\Inciso 2\C3-matrix.cpp"

#include "node.h"
#include "node.cpp"

template<class T>
class adyacente
{
private:
	int nodes_cant;
	int nodes_cont;
	matrix<T> matrix_ADY;
public:
	adyacente(int nodes): matrix_ADY(nodes, nodes), nodes_cant(nodes), nodes_cont(0) { }
	~adyacente() { }

	int getRows() const { return matrix_ADY.getRows(); }
	int getCols() const { return matrix_ADY.getCols(); }

	void showMatrix() { 
		cout<< "MATRIZ ADYACENTE:" << endl;
		matrix_ADY.showMatrix(); }

	bool existeNodo(node<T>);
	void addNodo(node<T>);
	
};

#endif //MATRIX_ADY_H