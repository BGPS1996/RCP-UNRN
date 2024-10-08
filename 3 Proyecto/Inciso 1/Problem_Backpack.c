#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ListaSE.h"

typedef int _criterio;

Lista_T Backtracking(Lista_T *l, Lista_T *Soluciones, _criterio acumulador);	// Retorna una lista de soluciones parciales?
void listadoObjetos(Lista_T*);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    // Crear lista mochila
    Lista_T mochila = crearLista();
    Lista_T solucion = crearLista();
	
	listadoObjetos(&mochila);
    ImprimirLista(mochila);

    printf("Solucion: \n");

    solucion = Backtracking(&mochila, &solucion, 0);

    ImprimirLista(solucion);

    VaciarLista(&mochila);
    VaciarLista(&solucion);

    return 0;
}


void listadoObjetos(Lista_T *mochila)
{
	objeto_T termo, net, carpeta, mate, cartuchera;

    inicializarObjeto(&termo, "Termo");
    inicializarObjeto(&net, "Netbook");
    inicializarObjeto(&carpeta, "Carpeta");
    inicializarObjeto(&mate, "Mate");
    inicializarObjeto(&cartuchera, "Cartu");

    InsertarPrimero(mochila, termo);
    InsertarPrimero(mochila, carpeta);
    InsertarPrimero(mochila, net);
    InsertarPrimero(mochila, mate);
    InsertarPrimero(mochila, cartuchera);
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
