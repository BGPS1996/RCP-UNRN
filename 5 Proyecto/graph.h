#ifndef GRAPH_H
#define GRAPH_H

#include "../3 Proyecto/Inciso 2/C3-matrix.h"
#include "../3 Proyecto/Inciso 2/C3-matrix.cpp"

template <class T>
class nodo
{
private:
	string name;
	T ID;
	nodo *vecindario;
	
public:
	nodo();
	~nodo();

	T getID();

	void setID(T);
	void setName(string);
	
};





template <class T>
class graph
{
private:
	int 
	matrix<T> representacion;
public:
	graph();
	~graph();
	
};


#endif