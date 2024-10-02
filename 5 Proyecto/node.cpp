#include "node.h"

template<class T>
node<T>::~node()
{

}

template<class T>
void node<T>::setLocation(tuple<unsigned long, unsigned long> _location)
{
	this->location = _location;
}
template<class T>
void node<T>::addEdge(string dest, T weight){
        edges.push_back(edge<T>(dest, weight));
        this->cant_edge++;
}