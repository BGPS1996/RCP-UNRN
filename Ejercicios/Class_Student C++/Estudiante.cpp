#include "Estudiante.h"

using namespace std;

void Estudiante::addMateria(string _materia)
{
	this->Approved.InsertarUltimo(_materia);
}

void Estudiante::showMaterias()
{
	cout<<"Materias aprobadas: "<<endl;
	Approved.ImprimirLista();
}