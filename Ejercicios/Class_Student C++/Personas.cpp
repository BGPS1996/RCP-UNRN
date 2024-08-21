#include "Personas.h"
#include <string>


Personas::~Personas()
{

}

string Personas::getNombre() const
{
	return this->nombre;
}


int Personas::getEdad() const
{
	return this->edad;
}

int Personas::getDNI() const
{
	return this->DNI;
}

void Personas::setNombre(string name)
{
	this->nombre = name;
}

void Personas::setEdad(int n)
{
	this->edad = n;
}

void Personas::setDNI(int d)
{
	this->DNI = d;
}