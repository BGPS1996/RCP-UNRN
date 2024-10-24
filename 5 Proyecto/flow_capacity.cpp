#include "flow_capacity.h"

template<class T>
flow<T>::~flow()
{
	
}


template<class T>
T flow<T>::addFlow(T flow)
{
	T aux = this->actual_capacity;
	
	if(flow + aux > total_capacity)
	{
		this->actual_capacity = this->total_capacity;
		return (aux + flow - this->total_capacity);
	}

	this->actual_capacity += flow;

	return 0;
}
