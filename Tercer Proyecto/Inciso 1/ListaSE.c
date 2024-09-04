
#include "ListaSE.h"

Lista_T crearLista()
{
	Lista_T aux;
	aux.dim = 0;
	aux.lista = NULL;
	return aux;
}

void inicializarObjeto(objeto_T *obj)
{
    obj->peso  = rand() % W + 1;
    obj->valor = rand() % 100;
}

struct Nodo *crearNodo(objeto_T _obj)
{
	struct Nodo *aux;

	if(!(aux=(struct Nodo*)malloc(sizeof(struct Nodo))))
	{
        fprintf(stderr, "ERROR 1: Error alocamiento de memoria\n");
		exit(1);
	}

	aux->obj = _obj;
    aux->sig = NULL;
	
    return aux;
}

int InsertarPrimero(Lista_T *l, objeto_T obj)
{
	struct Nodo *nuevo;

	nuevo = crearNodo(obj);

	nuevo->sig = l->lista;

	l->lista = nuevo;
	(l->dim)++;
	return 1;
}

int ImprimirLista(Lista_T l )
{
	struct Nodo *aux;
	aux = l.lista;

	if(EstaVacia(l))
	{
		printf("Vacia\n");
		return 0;
	}
	
    while(!aux)
	{
		printf(" Peso: %d, Valor: %d \n", aux->obj.peso, aux->obj.valor);
		aux = aux->sig;
	}

    return 1;
}

int EstaVacia(Lista_T l)
	{
        return !(l.dim);
    }

int VaciarLista(Lista_T *l)
{
	struct Nodo *act;
	while(!EstaVacia(*l))
	{
		while(LongitudLista(*l) != 0) //mientras longitud sea mayor a cero.
		{
			act = l->lista;
			l->lista = l->lista->sig;
			free(act);
			(l->dim)--;
		}

	}
	if(EstaVacia(*l))
		return 1;
	return (-1);
}

int SuprimirDato(Lista_T *l, objeto_T _obj)
{
	struct Nodo *act, *ant;

	act = l->lista;
	if(!EstaVacia(*l))
	{
		if(act->obj.valor == _obj.valor && act->obj.peso == _obj.peso)
		{
		    if(LongitudLista(*l) > 1)
            {
                l->lista = act->sig;
                free(act);
                (l->dim)--;

                return 1;
            }

            l->lista = NULL;
            free(act);
            (l->dim)--;

		    return 1;
		}
        while(act->obj.valor != _obj.valor && act->obj.peso != _obj.peso)
        {
            ant = act;
            act = act->sig;
        }
		if(act->obj.valor == _obj.valor && act->obj.peso == _obj.peso)
        {
            if(act->sig == NULL)
            {
                ant->sig = NULL;
                free(act);
                (l->dim)--;

                return 1;
            }
            ant->sig = act->sig;
            free(act);
            (l->dim)--;

            return 1;

        }
    }
}

int LongitudLista(Lista_T l)
{
	return (l.dim);
}
