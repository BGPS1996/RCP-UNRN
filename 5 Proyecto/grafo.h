#ifndef GRAFO_H
#define GRAFO_H
/**
 * @file grafo.h 
 * @author BGPS
 * @brief Clase Grafo combina la implementación de `matrix_Ady` y `node`, además añade nuevas funcionalidades como BFS, DFS, y el algoritmo de Floyd-Warshall para caminos mínimos.
 */

#include <iostream>
#include <queue>
#include <stack>

#include "matrix_Ady.h"
#include "matrix_Ady.cpp"
#include "modes.h"

/**
 * @class grafo
 * @brief La clase Grafo tiene dos modos: dirigido y no dirigido. Esto afecta la forma en que se representa la matriz de adyacencia.
 * @tparam T Tipo de dato asociado a los arcos del grafo.
 */
template<class T>
class grafo
{
private:
	int vertices;       		///< Cantidad de nodos cargados en el grafo.
	int aristas;        		///< Cantidad de arcos en el grafo.
	MODE currentMode;   		///< Configuración del grafo: dirigido o no dirigido.
	adyacente<T> matrix_ADY;  	///< Matriz de adyacencia que representa el grafo.

public:
	/**
	 * @brief Constructor por defecto.
	 * Inicializa los atributos en cero y configura el grafo como no dirigido.
	 */
	grafo();

	/**
	 * @brief Constructor con configuración del grafo.
	 * @param [in] mode Configuración del grafo (dirigido o no dirigido).
	 * @param [in] vertices Número de nodos en el grafo.
	 */
	grafo(MODE mode, int vertices);

	/**
	 * @brief Constructor con la cantidad de nodos.
	 * Configura el grafo como no dirigido por defecto.
	 * @param [in] vertices Número de nodos en el grafo.
	 */
	grafo(int vertices);

	/**
	 * @brief Destructor del grafo.
	 */
	~grafo();

	/**
	 * @brief Establece la cantidad de vértices en el grafo.
	 * @param [in] v Número de vértices.
	 */
	void setVertices(int v) { vertices = v; }

	/**
	 * @brief Establece el modo del grafo (dirigido o no dirigido).
	 * @param [in] mode Modo del grafo.
	 */
	void setMode(MODE mode) { currentMode = mode; }

	/**
	 * @brief Devuelve la cantidad de vértices del grafo.
	 * @return Número de vértices.
	 */
	int getVertices() const { return matrix_ADY.getRows(); }

	/**
	 * @brief Devuelve el modo de configuración del grafo.
	 * @return Modo del grafo (dirigido o no dirigido).
	 */
	MODE getMode() const { return currentMode; }

	/**
	 * @brief Obtiene los vecinos de un nodo dado.
	 * @param [in] node Índice del nodo seleccionado.
	 * @return Vector con los nodos vecinos del nodo seleccionado.
	 */
	vector<int> getVecindario(int node);

	/**
	 * @brief Verifica si el grafo es conexo.
	 * @return true si el grafo es conexo, false en caso contrario.
	 */
	bool esConexo();

	/**
	 * @brief Muestra la representación del grafo usando la matriz de adyacencia.
	 */
	void showRepresentation();

	/**
	 * @brief Realiza un recorrido BFS (Breadth-First Search) desde un nodo inicial.
	 * @param [in] startNode Índice del nodo desde el cual comenzar el recorrido.
	 */
	void BFS(int startNode);

	/**
	 * @brief Realiza un recorrido DFS (Depth-First Search) desde un nodo inicial.
	 * @param [in] startNode Índice del nodo desde el cual comenzar el recorrido.
	 */
	void DFS(int startNode);

	/**
	 * @brief Función auxiliar para realizar DFS recursivo.
	 * @param [in] node Nodo actual en el recorrido DFS.
	 * @param [in] visited Vector que indica si un nodo ha sido visitado.
	 */
	void DFSUtil(int node, vector<bool>& visited);

	/**
	 * @brief Obtiene los ejes salientes de un nodo dado.
	 * @param [in] node Índice del nodo seleccionado.
	 * @return Vector de índices de nodos a los que el nodo dado está conectado.
	 */
    vector<int> getEjesSalientes(int node);

	/**
	 * @brief Obtiene los ejes entrantes a un nodo dado.
	 * @param [in] node Índice del nodo seleccionado.
	 * @return Vector de índices de nodos que están conectados al nodo dado.
	 */
    vector<int> getEjesEntrantes(int node);
};
#endif
