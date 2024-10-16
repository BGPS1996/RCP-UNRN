#include "node.h"

template<class T, class U>
node<T, U>::~node()
{
    
}

template<class T, class U>
void node<T, U>::setLocation(tuple<unsigned long, unsigned long> _location)
{
    this->location = _location;
}

template<class T, class U>
void node<T, U>::addEdge(tuple<int, int> dest, U weight)
{
    edges.push_back(edge<T, U>(dest, weight));
}
