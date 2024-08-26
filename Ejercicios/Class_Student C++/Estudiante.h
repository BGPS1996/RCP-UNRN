#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include "Personas.h"

#include "ListaSE.h"
#include "ListaSE.cpp"


using namespace std;

class Estudiante: public Personas
{
private:
	Lista<string> Approved;
public:
	Estudiante(): Personas() { }
	Estudiante(string name, int edad, int dni ): Personas(name, edad, dni) { }
	~Estudiante() = default;

	void addMateria(string);
	void showMaterias();

	friend ostream& operator<< (ostream& os, const Estudiante& e)
	{
		os << "NOMBRE: "<< e.getNombre() <<endl
			<< "EDAD: "<< e.getEdad() <<endl
			<< "DNI: "<< e.getDNI() <<endl;
		return os;
	}
	friend istream& operator>>(istream& is, Estudiante& e)
	{
	    string nombre;
	    int edad, dni;

	    cout << "Ingrese nombre: ";
	    is >> nombre;
	    e.setNombre(nombre);

	    cout << "Ingrese edad: ";
	    is >> edad;
	    e.setEdad(edad);

	    cout << "Ingrese DNI: ";
	    is >> dni;
	    e.setDNI(dni);

	    return is;
	}
};

#endif
