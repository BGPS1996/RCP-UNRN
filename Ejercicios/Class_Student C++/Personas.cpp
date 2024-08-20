#include "Personas.h"
#include <string>


Personas::~Personas()
{

}

string Personas::getNombre()
{
	return this->nombre;
}


int Personas::getEdad()
{
	return this->edad;
}

int Personas::getDNI()
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