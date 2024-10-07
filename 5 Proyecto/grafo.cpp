#include "grafo.h"

template<class T>
grafo<T>::grafo()
{
	this->vertices = 0;
	this->aristas = 0;
	this->currentMode = mode_NO_DIRIGIDO;
}

template<class T>
grafo<T>::grafo(MODE op, int _vertice)
{
	this->vertices = _vertice;
	this->aristas = 0;
	this->currentMode = op;

	if( _vertice > 0){
		node<T> aux;
		for (int i = 0; i < _vertice; ++i)
		{
			cin >> aux;
			this->matrix_ADY.addNodo(aux, currentMode);
		}
	}
	else{
		throw invalid_argument("ERROR 1: Cantidad de Vertices no valido.");
	}
}

template<class T>
grafo<T>::grafo(int _vertice): matrix_ADY(_vertice)
{
	this->vertices = _vertice;
	this->aristas = 0;
	this->currentMode = mode_NO_DIRIGIDO;
	
	if( _vertice > 0){
		node<T> aux;
		for (int i = 0; i < _vertice; ++i)
		{
			cin>> aux;
			this->matrix_ADY.addNodo(aux, currentMode);
		}
	}
	else{
		throw invalid_argument("ERROR 1: Cantidad de Vertices no valido.");
	}
}

template<class T>
grafo<T>::~grafo()
{	

}

template<class T>
vector<int> grafo<T>::getVecindario(int node) {
    vector<int> vecindario;
    for (int i = 0; i < this->vertices; ++i) {
        if (i != node && this->matrix_ADY[node][i] == 1) {
            vecindario.push_back(i);
        }
    }
    return vecindario;
}



template <class T>
void grafo<T>::showRepresentation()
{
	switch(this->currentMode)
	{
		case mode_DIRIGIDO:
			cout<< "MODO: DIRIGIDO: "<< endl;
			this->matrix_ADY.showMatrix();
			break;

    	case mode_NO_DIRIGIDO:
    		cout<< "MODO: NO DIRIGIDO: "<< endl;
			this->matrix_ADY.showMatrix();
    		break;
	}

}

template<class T>
vector<int> grafo<T>::getEjesSalientes(int node) {
    vector<int> salientes;
    for (int i = 0; i < this->vertices; ++i) {
        if (this->matrix_ADY[node][i] == 1) {
            salientes.push_back(i);
        }
    }
    return salientes;
}

template<class T>
vector<int> grafo<T>::getEjesEntrantes(int node) {
    vector<int> entrantes;
    for (int i = 0; i < this->vertices; ++i) {
        if (this->matrix_ADY[i][node] == 1) {
            entrantes.push_back(i);
        }
    }
    return entrantes;
}

template<class T>
bool grafo<T>::esConexo() {
    vector<bool> visited(this->vertices, false);
    DFSUtil(0, visited);
    
    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}


template<class T>
void grafo<T>::BFS(int startNode) {
    vector<bool> visited(this->vertices, false);
    queue<int> q;

    // Empezamos por el nodo de inicio
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < this->vertices; ++i) {
            if (this->matrix_ADY.getValue(current, i) == 1 && !visited[i]) { 
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}


template<class T>
void grafo<T>::DFSUtil(int node, vector<bool>& visited)
{
    visited[node] = true; 
    cout << node << " ";

    for (int i = 0; i < this->vertices; ++i) {
        if (this->matrix_ADY.getValue(node, i) == 1 && !visited[i]) { 
            DFSUtil(i, visited);
        }
    }
}



template<class T>
void grafo<T>::DFS(int startNode) {
    vector<bool> visited(this->vertices, false);

    cout << "DFS traversal starting from node " << startNode << ": ";
    DFSUtil(startNode, visited);
    cout << endl;
}
