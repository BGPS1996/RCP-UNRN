
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ListaSE.h"

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	Lista_T mochila = crearLista();

	// Declaracion de objetos
	objeto_T termo;
	objeto_T net;
	objeto_T carpeta;
	objeto_T mate;
	objeto_T cartuchera;

	InsertarPrimero(&mochila, termo);
	InsertarPrimero(&mochila, carpeta);
	InsertarPrimero(&mochila, net);
	InsertarPrimero(&mochila, mate);
	InsertarPrimero(&mochila, cartuchera);
	
	ImprimirLista(mochila);

	return 0;
}
