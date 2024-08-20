#ifndef PERSONAS_H
#define PERSONAS_H
#include <iostream>

using namespace std;

class Personas
{
private:
	string nombre;
	int edad;
	int DNI;
public:
	Personas(string name, int n, int dni): nombre(name), edad(n), DNI(dni) { }
	Personas() : nombre("NN"), edad(0), DNI(0) { }
	~Personas();
	string getNombre();
	int getEdad();
	int getDNI();

	void setNombre(string);
	void setEdad(int);
	void setDNI(int);

	friend ostream& operator<< (ostream& os, const Personas& p)
	{
		os << "NOMBRE "<< p.nombre <<endl
			<< "EDAD: "<< p.edad <<endl
			<< "DNI: "<< p.DNI <<endl;
		return os;
	}

	friend istream& operator>> (istream& is, Personas& p)
    {
        cout << "Ingrese nombre: ";
        is >> p.nombre;
        cout << "Ingrese edad: ";
        is >> p.edad;
        cout << "Ingrese DNI: ";
        is >> p.DNI;
        return is;
    }
};
#endif