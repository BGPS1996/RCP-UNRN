// 2.- Implementar en C el algoritmo de backtracking para resolver el problema de saber si un caballo de ajedrez es capaz de 
// viajar entre dos posiciones.



#include <iostream>
//							Objetos
#include "horse.h"

//							Template
#include "C3-matrix.h"
#include "C3-matrix.cpp"

#include "ListaSE.h"
#include "ListaSE.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream file("tablero.txt");
	matrix<bool> tablero;

	tablero.FloadMatrix(file);
	horse caballito(0,1);

	cout << caballito.getPosition();
	cout<<endl;
	tablero.showMatrix();
	return 0;
}

Lista_T Backtracking(Lista_T *l, Lista_T *Soluciones, _criterio acumulador)
{
	if(acumulador >= W)
	{
		return *Soluciones;
	}else{
		struct Nodo *aux = l->lista;
		while(aux != NULL)
		{
			objeto_T cand = aux->obj;
			struct Nodo *siguiente = aux->sig;

			if(cand.peso + acumulador <= W)
			{
				InsertarPrimero(Soluciones, cand);
				acumulador += cand.peso;
			}
			SuprimirDato(l, cand);
			aux = siguiente;
		}
		
		return Backtracking(l, Soluciones, acumulador);
	}
}
