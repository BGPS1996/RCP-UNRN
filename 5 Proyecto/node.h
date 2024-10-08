#ifndef NODE_H
#define NODE_H

/**
 * @file nodo.h 
 * @autor BGPS
 * @brief Este archivo desarrolla la implementacion de los `nodos` y de los `arcos`.
*/


#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

/**
 @brief Clase que representa un arco en un grafo.
 * @tparam T Tipo de dato.
 * 
*/
template<class T>
class edge
{
public:
    tuple<int, int> destination;                    ///< Tupla representando < Origen Nodo, Destino Nodo>
    T weight;                                       ///< Peso o costo del Arco.
    /**
    @brief Constructor por defecto.
    *
    * @param[in] dest Tupla de enteros para representar la posicion.
    * @param[in] w Costo o Peso del arco.
    */ 
    edge(tuple<int, int> dest, T w) : destination(dest), weight(w) { }

    /**
     * @brief Getter del peso o costo del arco.
     * @return El peso o Costo.
    */ 
    T getWeight() const { return weight;}
};

/**
 * @brief Esta clase representa al nodo de un grafo
 * 
 */

template<class T>
class node
{
private:
    string name;                                    ///< Nombre, es opcional.
    T data;                                         ///< Dato representativo.
    tuple<unsigned long, unsigned long> location;   ///< Representa la tupla. (Posicion i, Posicion j)
    vector<edge<T>> edges;                          ///< Los arcos que conectar al nodo. 

public:
    
    /**
     * @brief Constructores con sus variantes.
     * La funcion por defecto le asigna al nodo nombre "NN", y locacion en la matriz en (0, 0).
    */ 
    node(): name("NN"), data(T(0)), location(0, 0) { }
    
    /**
     * @brief Constructor con entradas.
     * @param[in] name Asignacion de nombre al nodo
     * @param[in] data  Dato representativo.
     * @param[in] loc Representa la ubicacion en la matriz adyacente.
    */
    node(string name, T data, tuple<unsigned long, unsigned long> loc): name(name), data(data), location(loc) { }
    
    ~node();

    /**
     * @brief Getter locacion 
     * Por defecto se encuentra ubicaco en la posicion (0, 0).
     * @return Devuelve la ubicion en la matriz de adyacencia. 
    */
    tuple<unsigned long, unsigned long> getLocation() const { return location; }
    
    /**
     * @brief Getter dato
     * Devuelve el valor que se guardo en el nodo.
     * @return Retorna el valor del nodo.
    */
    T getData() const { return data; }
    
    /**
     * @brief Getter Nombre
     * Por defecto el nombre del nodo es "NN".
     * @return Retorna el nombre del nodo.
    */
    string getName() const { return name; }
    
    /**
     * @brief Getter cantidad de arcos que enlazan al Nodo.
     * @return Retorna un entero. 
    */
    int getCantedge() const { return edges.size(); }
    
    /**
     * @brief Getter de Lista de arcos.
     * Devuelve la lista de los arcos conectado al Nodo.
    */
    const vector<edge<T>>& getEdges() const { return edges; }
    
    /**
     * @brief Añadir arco al Nodo
     * @param[in] dest Tupla que representa la coneccion < Nodo origen, Nodo Destino> .
     * @param[in] weigth Peso o costo asignado a dicho arco.
    */
    void addEdge(tuple<int, int> dest, T weight);
    
    /**
     * @brief Setter ubicacion en la funcion adyacente.
     * @param[in] loc Redefine la locacion del Nodo.
    */
    void setLocation(tuple<unsigned long, unsigned long> loc);


    friend ostream& operator<<(ostream& os, const node<T>& n) {
        os << "Node Name: " << n.name << ", Data: " << n.data 
           << ", Location: (" << get<0>(n.location) << ", " << get<1>(n.location) << ")";
        
        os << ", Edges: [";
        for (const auto& e : n.edges) {
            os << " {Dest: (" << get<0>(e.destination) << ", " << get<1>(e.destination) << "), Weight: " << e.weight << "} ";
        }
        os << "]";
        
        return os;
    }

    friend istream& operator>>(istream& is, node<T>& n) {
        cout << "Enter node name: ";
        is >> n.name;

        cout << "Enter node data: ";
        is >> n.data;

        unsigned long x, y;
        cout << "Enter node location (x y): ";
        is >> x >> y;
        n.location = make_tuple(x, y);

        int numEdges;
        cout << "Enter number of edges: ";
        is >> numEdges;

        for (int i = 0; i < numEdges; ++i) {
            int destX, destY;
            T weight;
            cout << "Enter edge destination (x y) and weight: ";
            is >> destX >> destY >> weight;

            n.addEdge(make_tuple(destX, destY), weight);
        }
        return is;
    }

    node<T>& operator=(const node<T>& other) {
        if (this != &other) {
            this->name = other.name;
            this->data = other.data;
            this->location = other.location;
            this->edges = other.edges;
        }
        return *this;
    }

    bool operator==(const node<T>& other) const {
        return (this->name == other.name && 
                this->data == other.data && 
                this->location == other.location && 
                this->edges == other.edges);
    }
};

#endif
