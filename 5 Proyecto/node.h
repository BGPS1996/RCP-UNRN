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
    vector<edge<T>> edges;

public:
    node(): name("NN"), data(T(0)), location(0, 0) { }
    node(string name, T data, tuple<unsigned long, unsigned long> loc): name(name), data(data), location(loc) { }
    ~node();
    
    tuple<unsigned long, unsigned long> getLocation() const { return location; }
    T getData() const { return data; }
    string getName() const { return name; }
    int getCantedge() const { return edges.size(); }
    const vector<edge<T>>& getEdges() const { return edges; }
    
    void addEdge(tuple<int, int> dest, T weight);
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
