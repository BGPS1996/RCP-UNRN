
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define W 100 // KG

typedef struct objeto
{
	int peso;
	int valor;
}objeto_T;

void inicializarObjeto(objeto_T *);

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	objeto_T *termo = (objeto*)malloc(sizeof(objeto_T));
	objeto_T *net = (objeto*)malloc(sizeof(objeto_T));
	objeto_T *carpeta = (objeto*)malloc(sizeof(objeto_T));
	objeto_T *mate = (objeto*)malloc(sizeof(objeto_T));
	objeto_T *cartuchera = (objeto*)malloc(sizeof(objeto_T));

	inicializarObjeto(termo);
	inicializarObjeto(net);
	inicializarObjeto(carpeta);
	inicializarObjeto(mate);
	inicializarObjeto(cartuchera);


	return 0;
}

void inicializarObjeto(objeto_T *obj)
{
	obj->peso  = rand() % W + 1;
	obj->valor = rand() % 100;
}