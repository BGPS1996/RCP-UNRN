#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
using namespace std;

class objeto
{
    float weight;
    int valor;

public:
    objeto() : weight(0), valor(0) { }
    objeto(float w, int v): weight(w), valor(v) { }
    ~objeto();

    float getWeight() const { return weight; }
    int getValor() const { return valor; }


    void setWeight(float w);
    void setValor(int v);

    friend ostream& operator<<(ostream& os, const objeto& o)
    {
        os << "Peso: " << o.weight << endl
           << "Valor: " << o.valor << endl;
        return os;
    }

    friend istream& operator>>(istream& is, objeto& o)
    {
        cout << "Ingrese Peso: ";
        is >> o.weight;
        cout << "Ingrese Valor: ";
        is >> o.valor;
        return is;
    }

    objeto& operator=(const objeto& other) {
        if (this != &other) { 
            this->weight = other.weight;
            this->valor = other.valor;
        }
        return *this;
    }

    
    friend bool operator==(const objeto& lhs, const objeto& rhs)
    {
        return (lhs.weight == rhs.weight) && (lhs.valor == rhs.valor);
    }

    friend bool operator!=(const objeto& lhs, const objeto& rhs)
    {
        return !(lhs == rhs);
    }
};
#endif
