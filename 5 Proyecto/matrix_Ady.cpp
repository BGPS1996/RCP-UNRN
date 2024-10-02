#include "matrix_Ady.h"

template<class T>
bool adyacente<T>::existeNodo(nodes<T> Nodo)
{
	if(nodes_cont == 0)	// si esta vacio
		return false;
	T dato = Nodo.getData();
	for (int i = 0; i < this->nodes_cant; ++i)
	{
		for (int j = 0; j < this->nodes_cant; ++j)
		{
			if(this->matrix_Ady[i][j] == dato)
				return true;
		}
	}
	return false;
}

template<class T>
void adyacente<T>::addNodo(nodes<T> newNodo)
{
	if(this->nodes_cont < this->nodes_cant)
	{
		this->matrix_Ady[this->nodes_cont][this->nodes_cont] = 0; 
		for (int i = 0; i < newNodo.cant_edge; ++i)
		{
			get<0>(newNodo->edges[i].destination)
			get<1>(newNodo->edges[i].destination)
		}
		
		(this->nodes_cont++);
	}
}