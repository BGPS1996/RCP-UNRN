#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

#include "matrix_Ady.h"
#include "matrix_Ady.cpp"

#include "modes.h"


template<class T>
class grafo
{
private:
	int vertices;
	int aristas;	// en donde se crea la matriz, debo retornar segun el modo la cantidad de arcos

	MODE currentMode; // MODO dirigido o no
	adyacente<T> matrix_ADY; 

public:
	grafo();
	grafo(MODE, int);
	grafo(int);
	~grafo();

	void setVertices(int v) : vertices(v) { }
	void setMode(MODE op) : currentMode(op) { }

	int getVertices() const { return matrix_ADY.getRows(); }
	MODE getMode() const { return currentMode; }

	void showRepresentation();
	
};

#endif

/*
La idea es hacer ahora un template para la matriz incidencia,
luego hacer para cuando el grafo esta en modo dirigido.

luego implementar BFS y DFS.

Para tener la posibilidad de usar el template en cualquier circustancia
*/