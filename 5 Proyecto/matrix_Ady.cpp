#include "matrix_ADY.h"

template<class T>
bool adyacente<T>::existeNodo(node<T> Nodo)
{
	if(nodes_cont == 0)
		return false;
	T dato = Nodo.getData();
	for (int i = 0; i < this->nodes_cant; ++i)
	{
		for (int j = 0; j < this->nodes_cant; ++j)
		{
			if(this->matrix_ADY[i][j] == dato)
				return true;
		}
	}
	return false;
}

template<class T>
void adyacente<T>::addNodo(node<T> newNodo)
{
    if (this->nodes_cont < this->nodes_cant)
    {
        this->matrix_ADY[this->nodes_cont][this->nodes_cont] = 0; 
        newNodo.setLocation(make_tuple(this->nodes_cont, this->nodes_cont));
        int aux1, aux2;

        const vector<edge<T>>& edges = newNodo.getEdges();

        for (int i = 0; i < edges.size(); ++i)
        {
            aux1 = get<0>(edges[i].destination) - 1;
            aux2 = get<1>(edges[i].destination) - 1;

            if (aux1 < 0 || aux1 >= this->nodes_cant || aux2 < 0 || aux2 >= this->nodes_cant)
            {
                throw invalid_argument("ERROR: Arco erroneo. Índices fuera de rango.");
            }

            this->matrix_ADY[aux1][aux2] = 1;
            this->matrix_ADY[aux2][aux1] = 1;
        }

        (this->nodes_cont++);
    }
    else
    {
        throw overflow_error("ERROR: No se pueden agregar más nodos. Capacidad alcanzada.");
    }
}

