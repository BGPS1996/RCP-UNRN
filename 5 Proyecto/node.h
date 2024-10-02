#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

template<class T>
class edge
{
public:
    tuple<int, int> destination;  
    T weight;            
    edge(tuple<int, int> dest, T w) : destination(dest), weight(w) { }
};


template<class T>
class node
{
private:
    string name;
    T data;
    tuple<unsigned long, unsigned long> location;
    int cant_edge;
    vector<edge<T>> edges;

public:
    node(): name("NN"), data(T(0)), location(0, 0), cant_edge(0) { }
    node(string name, T data, tuple<unsigned long, unsigned long> loc): name(name), data(data), location(loc), cant_edge = 0 { }
    ~node();
    tuple<unsigned long, unsigned long> getLocation() const { return location; }
    T getData() const { return data; }
    int getCantedge() const { return cant_edge;}
    void addEdge(string, T);
    void setLocation(tuple<unsigned long, unsigned long>);

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

    
    node<T>& operator=(const node<T>& other) {
        if (this != &other) {
            this->name = other.name;
            this->data = other.data;
            this->location = other.location;
            this->edges = other.edges;
            this->cant_edge = other.cant_edge;
        }
        return *this;
    }

    
    bool operator==(const node<T>& other) const {
        return (this->name == other.name && 
                this->data == other.data && 
                this->location == other.location && 
                this->edges == other.edges);  // Comparación de aristas
    }

};

#endif
