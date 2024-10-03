#include "grafo.h"

template<class T>
grafo<T>::grafo()
{
	this->vertices = 0;
	this->aristas = 0;
	this->currentMode = mode_NO_DIRIGIDO;
}

template<class T>
grafo<T>::grafo(MODE op, int _vertice)
{
	this->vertices = _vertice;
	this->aristas = 0;
	this->currentMode = op;

	if( _vertice > 0){
		node<T> aux;
		for (int i = 0; i < _vertice; ++i)
		{
			cin>> aux;
			this->matrix_ADY.addNodo(aux, currentMode);
		}
	}
	else{
		throw invalid_argument("ERROR 1: Cantidad de Vertices no valido.");
	}
}

template<class T>
grafo<T>::grafo(int _vertice)
{
	this->vertices = _vertice;
	this->aristas = 0;
	this->currentMode = mode_NO_DIRIGIDO;
	
	if( _vertice > 0){
		node<T> aux;
		for (int i = 0; i < _vertice; ++i)
		{
			cin>> aux;
			this->matrix_ADY.addNodo(aux, currentMode);
		}
	}
	else{
		throw invalid_argument("ERROR 1: Cantidad de Vertices no valido.");
	}
}

template<class T>
grafo<T>::~grafo()
{

}

template <class T>
void grafo<T>::showRepresentation()
{
	switch(this->currentMode)
	{
		case mode_DIRIGIDO:
			cout<< "MODO: DIRIGIDO: "<< endl;
			this->matrix_ADY.showMatrix();
			break;

    	case mode_NO_DIRIGIDO:
    		cout<< "MODO: NO DIRIGIDO: "<< endl;
			this->matrix_ADY.showMatrix();
    		break;
	}

}