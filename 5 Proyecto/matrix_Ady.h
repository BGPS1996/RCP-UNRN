#ifndef MATRIX_ADY_H
#define MATRIX_ADY_H

#include <iostream>
#include "..\3 Proyecto\Inciso 2\C3-matrix.h"
#include "..\3 Proyecto\Inciso 2\C3-matrix.cpp"

#include "nodes.h"
#include "nodes.cpp"

template<class T>
class adyacente: public matrix
{
private:
	int nodes_cant;
	int nodes_cont;
	matrix<T> matrix_ADY;
public:
	adyacente(int nodes): matrix_ADY(nodes, nodes), nodes_cant(nodes), nodes_cont(0) { }
	~adyacente() { }

	int getRows() const { return matrix::getRows(); }
	int getCols() const { return matrix::getCols(); }

	void showMatrix() { matrix::showMatrix(); }

	bool existeNodo();
	void addNodo(nodes<T>);
	
};

#endif //MATRIX_ADY_H