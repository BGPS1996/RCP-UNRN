#ifndef MATRIX_ADY_H
#define MATRIX_ADY_H

/**
 * @file matrix_Ady.h 
 * @autor BGPS
 * @brief Este archivo desarrolla la implementacion de la representacion de un grafo en su forma matrix adyacente.
*/
#include <iostream>
#include <exception> // Libreria de excepciones
#include "..\3 Proyecto\Inciso 2\C3-matrix.h"
#include "..\3 Proyecto\Inciso 2\C3-matrix.cpp"

#include "node.h"
#include "node.cpp"

#include "modes.h"

/**
 * @brief Clase que representa la matriz adyacente junto a distintos metodos, que aportan informacion del grafo.
 * @tparam T Tipo de dato.
 * 
*/
template<class T, class U>
class adyacente
{
private:
	int nodes_cant;											///< Cantidad de Nodos en la matriz.
	int nodes_cont;											///< Cantidad de Nodos cargados.
	vector<node<T, U>> nodes;									///< Lista de Nodos.
	matrix<T> matrix_ADY;									///< Matriz adyacente.

public:

	/**
	 * @brief Constructor de la clase
	 * @param[in] nodes Cantidad de nodos de la matriz.
	 * 
	 * Por defectos se setea nodes_cont igual a cero, y nodes_cant igual a nodes (input).
	*/
	adyacente(int nodes): matrix_ADY(nodes, nodes), nodes_cant(nodes), nodes_cont(0) { }
	~adyacente() { }

	/**
	 * @brief Getter Rows
	 * Usa el metodo de clase Matrix para obtener la cantidad de filas.
	 * @return constante.
	*/

	int getRows() const { return matrix_ADY.getRows(); }

	/**
	 * @brief Getter Cols
	 * Usa el metodo de clase Matrix para obtener la cantidad de columnas.
	 * @return constante.
	*/
	int getCols() const { return matrix_ADY.getCols(); }

	/**
	 * @brief Getter dato en matriz (i, j).
	 * Usa la sobrecarga del operador de la clase Matrix para obtener el valor.
	 * @param[in] row fila seleccionada de la matriz.
	 * @param[in] col columna seleccionada de la matriz.
	 * @return tipo da T.
	*/
	T getValue(int row, int col) const { return this->matrix_ADY[row][col]; }

	/**
	 * @brief Getter para acceder a la lista de nodos en el grafo.
	 * @return Referencia a un vector de nodos.
	 */
	vector<node<T, U>>& getNodes() { return nodes; }


	/**
	 * @brief Mostrar
	 * Usa el metodo de clase Matrix para obtener la cantidad de filas.
	*/
	void showMatrix() { 
		cout<< "MATRIZ ADYACENTE:" << endl;
		matrix_ADY.showMatrix(); }

	/**
	 * @brief Funcion que retoral verdadero o falso si el nodo se encuentra cargado en la matriz. 
	 * 
	 * @param[in] nodo Nodo que se busca en la matriz adyacente.
	*/
	bool existeNodo(node<T, U> nodo);

	/**
	 * @brief Añadir Nodo
	 * Añade el nodo a la matriz adyacente, si nodo_cont es diferente a nodo_cant.
	 * @param[in] nodo Nodo para añadir en la matriz.
	 * @param[in] op Modo que se inserta el nodo, Direccional o Bidireccional.
	*/
	void addNodo(node<T, U> nodo, MODE op);


	/**
	 * @brief Sobrecarga de operador[]
	 * Destinado a obtener el fila del vector.
	*/
	vector<T>& operator[](int index) {
        return matrix_ADY[index];
    }
};

/************************************** ERRORES *******************************************/
/* ERROR 1: Arco erroneo. Índices fuera de rango.										  */
/* ERROR 2: No se pueden agregar más nodos. Capacidad alcanzada.						  */
/************************************** ERRORES *******************************************/

#endif //MATRIX_ADY_H