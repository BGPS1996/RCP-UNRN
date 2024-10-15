#include "grafo.h"

template<class T, class U>
grafo<T, U>::grafo() {
    this->vertices = 0;
    this->aristas = 0;
    this->currentMode = mode_NO_DIRIGIDO;
}

template<class T, class U>
grafo<T, U>::grafo(MODE op, int _vertice) {
    this->vertices = _vertice;
    this->aristas = 0;
    this->currentMode = op;

    if (_vertice > 0) {
        node<T, U> aux;
        for (int i = 0; i < _vertice; ++i) {
            cin >> aux;
            this->matrix_ADY.addNodo(aux, currentMode);
        }
    } else {
        throw invalid_argument("Cantidad de Vertices no valido.");
    }
}

template<class T, class U>
grafo<T, U>::grafo(int _vertice) : matrix_ADY(_vertice) {
    this->vertices = _vertice;
    this->aristas = 0;
    this->currentMode = mode_NO_DIRIGIDO;

    if (_vertice > 0) {
        node<T, U> aux;
        for (int i = 0; i < _vertice; ++i) {
            cin >> aux;
            this->matrix_ADY.addNodo(aux, currentMode);
        }
    } else {
        throw invalid_argument("Cantidad de Vertices no valido.");
    }
}

template<class T, class U>
grafo<T, U>::~grafo() {}

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
