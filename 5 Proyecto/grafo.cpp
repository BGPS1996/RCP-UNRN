#include "grafo.h"

template<class T, class U>
grafo<T, U>::grafo()
    : matrix_ADY(0)
{
    this->vertices = 0;
    this->aristas = 0;
    this->capacidad = 0;
    this->currentMode = mode_NO_DIRIGIDO;
    this->currentType = type_NONE;
}

template<class T, class U>
grafo<T, U>::grafo(MODE op, int _vertice)
    : matrix_ADY(_vertice)
{
    this->vertices = _vertice;
    this->aristas = 0;
    this->currentMode = op;
    this->currentType = type_NONE;

    if (_vertice > 0) {

        switch(this->currentType)
        {
            case type_NONE:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;
                    cin >> aux;
                    this->matrix_ADY.addNodo(aux, currentMode);
                }
                break;
            case type_FLOW:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;

                    cin >> aux;

                    if (i == 0) {
                        aux.setEspecialization(szt_SOURCE);
                        // añadir capacidad.
                    } else if (i == _vertice - 1) {
                        aux.setEspecialization(szt_TARGET);
                    }

                    this->matrix_ADY.addNodo(aux, currentMode);

                    this->capacidad = configCapacidad();
                }
                break;
            case type_PETRI:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;
                    cin >> aux;
                    this->matrix_ADY.addNodo(aux, currentMode);
                }            
                break;
        }

    } else {
        throw invalid_argument("Cantidad de Vertices no valido.");
    }
}

template<class T, class U>
grafo<T, U>::grafo(MODE op, int _vertice, TYPE ty)
    : matrix_ADY(_vertice)
{
    this->vertices = _vertice;
    this->aristas = 0;
    this->currentMode = op;
    this->currentType = ty;

    if (_vertice > 0) {

        switch(this->currentType)
        {
            case type_NONE:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;
                    cin >> aux;
                    this->matrix_ADY.addNodo(aux, currentMode);
                }
                break;
            case type_FLOW:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;

                    cin >> aux;

                    if (i == 0) {
                        aux.setEspecialization(szt_SOURCE);
                    } else if (i == _vertice - 1) {
                        aux.setEspecialization(szt_TARGET);
                    }

                    this->matrix_ADY.addNodo(aux, currentMode);
                    this->capacidad = configCapacidad();
                }
                break;
            case type_PETRI:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;
                    cin >> aux;
                    this->matrix_ADY.addNodo(aux, currentMode);
                }            
                break;
        }
    } else {
        throw invalid_argument("Cantidad de Vertices no valido.");
    }
}

template<class T, class U>
grafo<T, U>::grafo(int _vertice)
    : matrix_ADY(_vertice)
{
    this->vertices = _vertice;
    this->aristas = 0;
    this->currentMode = mode_NO_DIRIGIDO;
    this->currentType = type_NONE;

    if (_vertice > 0) {

        switch(this->currentType)
        {
            case type_NONE:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;
                    cin >> aux;
                    this->matrix_ADY.addNodo(aux, currentMode);
                }
                break;
            case type_FLOW:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;

                    cin >> aux;

                    if (i == 0) {
                        aux.setEspecialization(szt_SOURCE);
                    } else if (i == _vertice - 1) {
                        aux.setEspecialization(szt_TARGET);
                    }

                    this->matrix_ADY.addNodo(aux, currentMode);
                    this->capacidad = configCapacidad();
                }
                break;
            case type_PETRI:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;
                    cin >> aux;
                    this->matrix_ADY.addNodo(aux, currentMode);
                }            
                break;
        }
    } else {
        throw invalid_argument("Cantidad de Vertices no valido.");
    }
}

template<class T, class U>
grafo<T, U>::grafo(int _vertice, TYPE ty)
    : matrix_ADY(_vertice)
{
    this->vertices = _vertice;
    this->aristas = 0;
    this->currentMode = mode_NO_DIRIGIDO;
    this->capacidad = 0;
    this->currentType = ty;

    if (_vertice > 0) {
        switch(this->currentType)
        {
            case type_NONE:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;
                    cin >> aux;
                    this->matrix_ADY.addNodo(aux, currentMode);
                }
                break;
            case type_FLOW:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;

                    cin >> aux;

                    if (i == 0) {
                        aux.setEspecialization(szt_SOURCE);
                    } else if (i == _vertice - 1) {
                        aux.setEspecialization(szt_TARGET);
                    }

                    this->matrix_ADY.addNodo(aux, currentMode);
                    this->capacidad = configCapacidad();
                }
                break;
            case type_PETRI:
                for (int i = 0; i < _vertice; ++i) {
                    node<T, U> aux;
                    cin >> aux;
                    this->matrix_ADY.addNodo(aux, currentMode);
                }            
                break;
        }
    }else {
        throw invalid_argument("Cantidad de Vertices no valido.");
    }
}

template<class T, class U>
grafo<T, U>::~grafo() { }

template<class T, class U>
vector<int> grafo<T, U>::getVecindario(int node) {
    vector<int> vecindario;
    for (int i = 0; i < this->vertices; ++i) {
        if (i != node && this->matrix_ADY[node][i] != numeric_limits<U>::max()) {
            vecindario.push_back(i);
        }
    }
    return vecindario;
}

template<class T, class U>
vector<int> grafo<T, U>::getEjesSalientes(int node) {
    vector<int> salientes;
    for (int i = 0; i < this->vertices; ++i) {
        if (this->matrix_ADY[node][i] != numeric_limits<U>::max()) {
            salientes.push_back(i);
        }
    }
    return salientes;
}

template<class T, class U>
vector<int> grafo<T, U>::getEjesEntrantes(int node) {
    vector<int> entrantes;
    for (int i = 0; i < this->vertices; ++i) {
        if (this->matrix_ADY[i][node] != numeric_limits<U>::max()) {
            entrantes.push_back(i);
        }
    }
    return entrantes;
}

template<class T, class U>
bool grafo<T, U>::esConexo() {
    vector<bool> visited(this->vertices, false);
    DFSUtil(0, visited);
    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}

template<class T, class U>
void grafo<T, U>::BFS(int startNode) {
    vector<bool> visited(this->vertices, false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < this->vertices; ++i) {
            if (this->matrix_ADY.getValue(current, i) != numeric_limits<U>::max() && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

template<class T, class U>
void grafo<T, U>::DFSUtil(int node, vector<bool>& visited) {
    visited[node] = true;

    for (int i = 0; i < this->vertices; ++i) {
        if (this->matrix_ADY.getValue(node, i) != numeric_limits<U>::max() && !visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

template<class T, class U>
void grafo<T, U>::DFS(int startNode) {
    vector<bool> visited(this->vertices, false);
    DFSUtil(startNode, visited);
}

template<class T, class U>
void grafo<T, U>::floydWarshall(vector<vector<U>>& dist, vector<vector<int>>& next) {
    int n = this->vertices;
    dist.resize(n, vector<U>(n, numeric_limits<U>::max()));
    next.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (this->matrix_ADY[i][j] != numeric_limits<U>::max()) {
                dist[i][j] = this->matrix_ADY[i][j];
                next[i][j] = j;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != numeric_limits<U>::max() &&
                    dist[k][j] != numeric_limits<U>::max() &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

template<class T, class U>
vector<int> grafo<T, U>::getPath(int u, int v, const vector<vector<int>>& next) {
    if (next[u][v] == -1) return {};
    vector<int> path = {u};
    while (u != v) {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}

template<class T, class U>
void grafo<T, U>::showGrafo() {

    vector<node<T, U>>& nodes = matrix_ADY.getNodes();
    int cont = 0;
    cout << endl;
    cout << "Representacion del grafo con flechas:" << endl;

    switch(this->currentMode) {
        case mode_DIRIGIDO:
            cout << "MODO: DIRIGIDO: "<< endl;

            switch(this->currentType)
            {
                case type_FLOW:
                    cout << "TIPO: FLUJO: "<< endl;
                    for (int i = 0; i < vertices; ++i){
                        cout << " " <<nodes[i].getName() << "(" << nodes[i].getData() <<")" ;

                        const vector<edge<T, U>>& edges = nodes[i].getEdges();
                        bool tieneVecinos = false;

                        for (int j = cont; j < edges.size(); ++j) {
                            cont++;
                            const tuple<int, int>& destination = edges[j].getDestination();
                            int destino = get<1>(destination) - 1 ;

                            if (destino >= 0 && destino < vertices) {
                                T valor = nodes[destino].getData();
                            
                                if (valor != 0 && valor != numeric_limits<T>::max() && destino != i) {
                                    tieneVecinos = true;
                                    cout<< "\t ---" << edges[j].getFlow() << "---> " << nodes[destino].getName() << "(" << valor << ") \t"<< endl;
                                }
                            }
                        }
                    
                        if (!tieneVecinos) {
                            cout << "sin vecinos";
                        }
                        cout << endl; 
                    }
                break;

                case type_NONE:
                    cout << "TIPO: Por defecto: "<< endl;
                    for (int i = 0; i < vertices; ++i){
                        cout << " " <<nodes[i].getName() << "(" << nodes[i].getData() <<")" ;

                        const vector<edge<T, U>>& edges = nodes[i].getEdges();
                        bool tieneVecinos = false;

                        for (int j = cont; j < edges.size(); ++j) {
                            cont++;
                            const tuple<int, int>& destination = edges[j].getDestination();
                            int destino = get<1>(destination) - 1 ;

                            if (destino >= 0 && destino < vertices) {
                                T valor = nodes[destino].getData();
                            
                                if (valor != 0 && valor != numeric_limits<T>::max() && destino != i) {
                                    tieneVecinos = true;
                                    cout<< "\t ------> " << nodes[destino].getName() << "(" << valor << ") \t"<< endl;
                                }
                            }
                        }
                    
                        if (!tieneVecinos) {
                            cout << "sin vecinos";
                        }
                        cout << endl; 
                    }
                break;

                case type_PETRI:
                    cout << "TIPO: REDES DE PETRI: "<< endl;
                break;
            }

        case mode_NO_DIRIGIDO:
            
            cout<< "MODO: NO DIRIGIDO: "<< endl;
            switch(this->currentType)
            {
                case type_NONE:
                    cout << "TIPO: Por defecto: "<< endl;
                    for (int i = 0; i < vertices; ++i){
                        cout << " " <<nodes[i].getName() << "(" << nodes[i].getData() <<")" ;

                        const vector<edge<T, U>>& edges = nodes[i].getEdges();
                        bool tieneVecinos = false;

                        for (int j = cont; j < edges.size(); ++j) {
                            cont++;
                            const tuple<int, int>& destination = edges[j].getDestination();
                            int destino = get<1>(destination) - 1 ;

                            if (destino >= 0 && destino < vertices) {
                                T valor = nodes[destino].getData();
                            
                                if (valor != 0 && valor != numeric_limits<T>::max() && destino != i) {
                                    tieneVecinos = true;
                                    cout<< "\t <------> " << nodes[destino].getName() << "(" << valor << ") \t"<< endl;
                                }
                            }
                        }
                    
                        if (!tieneVecinos) {
                            cout << "sin vecinos";
                        }
                        cout << endl; 
                    }
                break;

                case type_PETRI:
                    cout << "TIPO: REDES DE PETRI: "<< endl;
                break;
            }
        break;
    }
}

template <class T, class U>
void grafo<T, U>::showRepresentation()
{
    switch(this->currentMode) {
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

template<class T, class U>
float grafo<T, U>::configCapacidad() {
    vector<node<T, U>>& nodes = matrix_ADY.getNodes();
    const vector<edge<T, U>>& edges = nodes[0].getEdges();
    flow<float> aux(0, 0);

    for (int i = 0; i < edges.size(); ++i) {
        aux += edges[i].getFlow();
    }
    return aux.getCapacityTotal();
}
