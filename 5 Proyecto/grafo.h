#ifndef GRAFO_H
#define GRAFO_H

/**
 * @file grafo.h 
 * @author BGPS
 * @brief Clase Grafo combina la implementación de `matrix_Ady` y `node`, además añade nuevas funcionalidades como BFS, DFS, y el algoritmo de Floyd-Warshall para caminos mínimos.
 */

#include <iostream>
#include <limits>
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
template<class T, class U>
class grafo
{
private:
	int vertices;       			///< Cantidad de nodos cargados en el grafo.
	int aristas;        			///< Cantidad de arcos en el grafo.
	flow<float> capacidad;        	///< Capacidad de la red de flujo.
	MODE currentMode;   			///< Configuración del grafo: dirigido o no dirigido.
	TYPE currentType;				///< Configuracion de grafo: Flujo o Petri.
	adyacente<T, U> matrix_ADY;  	///< Matriz de adyacencia que representa el grafo.
		
	/**
	 * @brief Función auxiliar para realizar DFS recursivo.
	 * @param[in] node Nodo actual en el recorrido DFS.
	 * @param[in] visited Vector que indica si un nodo ha sido visitado.
	 */
	void DFSUtil(int node, vector<bool>& visited);

	/**
	 * @brief Función auxiliar para calcular la capacidad de flujo.
	 * @return Retorna la capacidad.
	 */
	float configCapacidad();

public:

	/**
	 * @brief Constructor por defecto.
	 * Inicializa los atributos en cero y configura el grafo como no dirigido.
	 */
	grafo();

	/**
	 * @brief Constructor con configuración del grafo.
	 * @param[in] mode Configuración del grafo (dirigido o no dirigido).
	 * @param[in] vertices Número de nodos en el grafo.
	 */
	grafo(MODE mode, int vertices);

	/**
	 * @brief Constructor con configuraciónes del grafo.
	 * @param[in] mode Configuración del grafo (dirigido o no dirigido).
	 * @param[in] type Configuración del grafo (Petri, Flujo o Defecto).
	 * @param[in] vertices Número de nodos en el grafo.
	 */
	grafo(MODE mode, int vertices, TYPE type);

	/**
	 * @brief Constructor con la cantidad de nodos.
	 * Configura el grafo como no dirigido por defecto.
	 * @param[in] vertices Número de nodos en el grafo.
	 */
	grafo(int vertices);

	/**
	 * @brief Constructor con la cantidad de nodos.
	 * Configura el grafo como no dirigido por defecto.
	 * @param[in] vertices Número de nodos en el grafo.
	 * @param[in] type Configuración del grafo (Petri, Flujo o Defecto).
	 */
	grafo(int vertices, TYPE type);

	/**
	 * @brief Destructor del grafo.
	 */
	~grafo();

	/**
	 * @brief Establece la cantidad de vértices en el grafo.
	 * @param[in] v Número de vértices.
	 */
	void setVertices(int v) { vertices = v; }

	/**
	 * @brief Establece el modo del grafo (dirigido o no dirigido).
	 * @param[in] mode Modo del grafo.
	 */
	void setMode(MODE mode) { currentMode = mode; }

	/**
	 * @brief Establece el tipo del grafo.
	 * @param[in] type TYPE del grafo.
	 */
	void setType(TYPE type) { currentType = type; }

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
	 * @brief Devuelve el modo de configuración del grafo.
	 * @return Type del grafo.
	 */
	TYPE getType() const { return currentType; }

	/**
	 * @brief Obtiene los vecinos de un nodo dado.
	 * @param[in] node Índice del nodo seleccionado.
	 * @return Vector con los nodos vecinos del nodo seleccionado.
	 */
	vector<int> getVecindario(int node);

	/**
	 * @brief Devuelve la matriz de adyasencia.
	 * @return Matriz de Adyasencia.
	 */
	adyacente<T, U>& getMatrix() {return matrix_ADY; }
	
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
	 * @param[in] startNode Índice del nodo desde el cual comenzar el recorrido.
	 */
	vector<bool> BFS(int startNode);

	/**
	 * @brief Realiza un recorrido DFS (Depth-First Search) desde un nodo inicial.
	 * @param[in] startNode Índice del nodo desde el cual comenzar el recorrido.
	 */
	void DFS(int startNode);

	/**
	 * @brief Obtiene los ejes salientes de un nodo dado.
	 * @param[in] node Índice del nodo seleccionado.
	 * @return Vector de índices de nodos a los que el nodo dado está conectado.
	 */
    vector<int> getEjesSalientes(int node);

	/**
	 * @brief Obtiene los ejes entrantes a un nodo dado.
	 * @param[in] node Índice del nodo seleccionado.
	 * @return Vector de índices de nodos que están conectados al nodo dado.
	 */
    vector<int> getEjesEntrantes(int node);

    /**
	 * @brief Implementa el algoritmo de Floyd-Warshall para calcular los caminos mínimos entre todos los pares de nodos.
	 * 
	 * Esta función calcula la matriz de distancias mínimas entre todos los pares de nodos en el grafo y también construye una matriz 
	 * que permite reconstruir el camino mínimo entre cualquier par de nodos. 
	 * Si hay ciclos negativos en el grafo, la función puede no comportarse como se espera.
	 * 
	 * @param[out] dist Matriz que será llenada con las distancias mínimas entre todos los nodos. Inicialmente debe tener el mismo tamaño que el número de nodos.
	 * @param[out] next Matriz que será llenada con los nodos precedentes para cada par de nodos, lo que permite reconstruir el camino mínimo.
	 * En caso de que no exista un camino entre dos nodos, el valor correspondiente en `next` debe ser -1.
	*/
	void floydWarshall(vector<vector<U>>& dist, vector<vector<int>>& next);

	/**
	 * @brief Reconstruye el camino mínimo entre dos nodos dado el resultado del algoritmo de Floyd-Warshall.
	 * 
	 * Esta función utiliza la matriz `next`, generada por el algoritmo de Floyd-Warshall, para reconstruir el camino mínimo entre 
	 * dos nodos específicos.
	 * 
	 * @param[in] u Nodo de origen.
	 * @param[in] v Nodo de destino.
	 * @param[in] next Matriz que contiene los nodos precedentes para cada par de nodos, generada por el algoritmo de Floyd-Warshall.
	 * @return Un vector de enteros que representa el camino mínimo desde el nodo `u` hasta el nodo `v`. Si no hay camino, se devuelve un vector vacío.
	 */
	vector<int> getPath(int u, int v, const vector<vector<int>>& next);
	
	/**
	 * @brief Muestra por pantalla los nodos utilizando los arcos para visualizar las conexiones de los nodos.
	 * utiliza configuracion que trae el grafo, para mostrar su reprensentacion.
	 * No se encuentra implementado para Modo Redes de Petri.
	*/
	void showGrafo();

    /**
     * @brief Encuentra el corte minimo en una red de flujo a partir de un nodo de origen.
     * 
     * Esta funcion utiliza un recorrido BFS modificado para encontrar todos los nodos alcanzables 
     * desde el nodo de origen en el grafo residual, donde solo se consideran arcos con capacidad residual positiva.
     * Luego, identifica los arcos que cruzan de los nodos alcanzables a los no alcanzables, los cuales forman 
     * el corte mínimo.
     * 
     * @param[in] s indice del nodo de origen.
     * @return Un vector de pares de enteros, donde cada par representa un arco en el corte mínimo, desde el conjunto alcanzable (S) al no alcanzable (T).
     */
	vector<pair<int, int>> findMinCut(int s);
    
    /**
     * @brief Calcula el valor del corte mínimo en una red de flujo.
     * 
     * Esta función calcula la suma de las capacidades de los arcos en el corte minimo, lo cual representa 
     * el valor total del flujo máximo posible en la red de flujo desde el nodo de origen.
     * 
     * @param[in] s indice del nodo de origen.
     * @return El valor del corte minimo, de tipo U.
     */
	U minCutValue(int s);
};

#endif
