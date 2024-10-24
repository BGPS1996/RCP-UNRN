#ifndef FLOW_CAPACITY_H
#define FLOW_CAPACITY_H
/**
 * @file flow_capacity.h
 * @autor BGPS
 * @brief Clase Flujo, representara el "flujo" posible entre los nodos, esta pensado para estar contenido en la clase `edge`.
 */

#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief Esta clase representa al flujo de objetos.
 * @tparam T Tipo de dato para el contenido del nodo.
 */
template<class T>
class flow
{
public:
	T actual_capacity;	///< Capacidad actual.
	T total_capacity;	///< Capacidad total.
	
	/**
	 * @brief Constructor por defecto.
	 * @return total_capacity(10) y actual_capacity(0).
	 */
	flow() : actual_capacity(0), total_capacity(10) { }

	/**
	 * @brief Constructor con capacidades seleccionadas.
	 * @param[in] Ac Parametro de Capacidad Actual.
	 * @param[in] At Parametro de Capacidad Total.
	 */
	flow(T Ac, T At) : actual_capacity(Ac), total_capacity(At) { }

	/**
	 * @brief Constructor con capacidad total seleccionada.
	 * El atributo Actual capacidad se setea en cero.
	 * @param[in] At Parametro de Capacidad Total.
	 */
	flow(T At) : actual_capacity(0), total_capacity(At) { }

	/**
	 * @brief Destructor por defecto.
	 */
	~flow();
	
	/**
	 * @brief Retorna la capacidad que es posible inyectar.
	 * Retorna un tipo T, que sera la unidad de flujo que se busca inyectar por los arcos.
	 * @return Retorna elemento tipo T.
	 */
	T getResidualCapacity() const { return (total_capacity - actual_capacity); }
	
	/**
	 * @brief Retorna la capacidad total.
	 * Retorna la capacidad total.
	 * @return Capacidad total.
	 */
	T getCapacityTotal() const { return total_capacity; }

	/**
	 * @brief Retorna la capacidad Actual.
	 * Retorna la capacidad actual.
	 * @return Capacidad actual.
	 */
	T getCapacityActual() const { return actual_capacity; }

	/**
	 * @brief Añadir mas flujo.
	 * Se incrementa la cantidad de flujo por el arco, no podra exceder la capacidad todal.
	 * @param[in] flow Flujo a anadir.
	 * @return Retornara la capacidad que posee, una vez añadido. En caso que no se pueda añadir la cantidad indicada, se añadira lo posible y se retornara el excedente.
	 */
	T addFlow(T flow);

	/**
	 * @brief Set la capacidad total del arco.
	 * Cambia la capacidad total del arco.
	 * @param[in] newCapacity Capacidad nueva.
	 */
	void setTotalCapacity(T newCapacity) { total_capacity = newCapacity; }
};

	/**
	 * @brief Sobrecarga del operador << para imprimir la clase flow.
	 * @tparam T Tipo de dato para el contenido del flujo.
	 * @param[in] os Flujo de salida.
	 * @param[in] f Objeto de la clase flow.
	 * @return El flujo de salida modificado.
	 */
	template<class T>
	ostream& operator<<(ostream& os, const flow<T>& f) 
	{
	    os << " (" << f.actual_capacity 
	       << "/ " << f.total_capacity << ") ";
	    return os;
	}

template<class T>
istream& operator>>(istream& is, flow<T>& f) 
{
    T actual, total;
 	
 	cout << " Selecciona Flujo actual: ";

    is >> actual;

    f.actual_capacity = actual;
    return is;
}

#endif // FLOW_CAPACITY_H