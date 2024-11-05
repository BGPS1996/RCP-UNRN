#include "flow_capacity.h"

template<class T>
flow<T>::~flow()
{
	
}


template<class T>
T flow<T>::addFlow(T flow) {
    if (flow < 0) {
        throw invalid_argument("El flujo a aniadir no puede ser negativo.");
    }

    T aux = this->actual_capacity;

    if (flow + aux > total_capacity) {
        this->actual_capacity = this->total_capacity;
        throw overflow_error("El flujo aniadido excede la capacidad total.");
    }

    this->actual_capacity += flow;
    return 0;
}