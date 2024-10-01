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
    string destination;  
    T weight;            
    edge(string dest, T w) : destination(dest), weight(w) { }
};


template<class T>
class node
{
private:
    string name;
    T data;
    tuple<unsigned long, unsigned long> location;

    vector<edge<T>> edges;

public:
    node(): name("NN"), data(T(0)), location(0, 0) { }
    node(string name, T data, tuple<unsigned long, unsigned long> loc): name(name), data(data), location(loc) { }
    ~node();
    tuple<unsigned long, unsigned long> getLocation() const { return location; }
    T getData() const { return data; }
    void addEdge(string, T);
    void setLocation(tuple<unsigned long, unsigned long>);

    friend ostream& operator<<(ostream& os, const node<T>& n) {
        os << "Node Name: " << n.name << ", Data: " << n.data 
           << ", Location: (" << get<0>(n.location) << ", " << get<1>(n.location) << ")";
        
        os << ", Edges: [";
        for (const auto& e : n.edges) {
            os << " {Dest: " << e.destination << ", Weight: " << e.weight << "} ";
        }
        os << "]";
        
        return os;
    }

};

#endif
