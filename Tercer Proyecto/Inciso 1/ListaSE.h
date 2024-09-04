
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>


#define W 100 // Kg

// Prototipos de objetos
typedef struct objeto
{
	int peso;
	int valor;
}objeto_T;

struct Nodo
{
	objeto_T obj;
	struct Nodo *sig;
};

typedef struct
{
	int dim;
	struct Nodo *lista;
}Lista_T;

Lista_T crearLista();
int InsertarPrimero(Lista_T *, objeto_T);
struct Nodo *crearNodo(objeto_T);
int ImprimirLista(Lista_T);
int EstaVacia(Lista_T);
int VaciarLista(Lista_T *);
int SuprimirDato(Lista_T *, objeto_T);
int LongitudLista(Lista_T);

void inicializarObjeto(objeto_T *);

#endif