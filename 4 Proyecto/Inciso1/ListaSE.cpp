#include <iostream>
#include <cstdlib>
#include "ListaSE.h"

using namespace std;

template <class T>
Lista<T>::Lista()
{
    dim = 0;
    inicio = NULL;
}

template <class T>
Lista<T>::~Lista()
{

}

template <class T>
struct Lista<T>::Nodo* Lista<T>::crearNodo(T x)
{
	struct Nodo *nodo = new(struct Nodo);
    nodo->dato = x;
    nodo->sig = NULL;
    return nodo;
}

template <class T>
void Lista<T>::InsertarPrimero(T x)
{
	struct Nodo *nuevo;
	nuevo = crearNodo(x);

	nuevo->sig = this->inicio;
	
    inicio = nuevo;
	(dim++);
}

template <class T>
void Lista<T>::InsertarUltimo(T x)
{
	struct Nodo *aux, *nuevo;
	nuevo = crearNodo(x);
	aux = inicio;

	if(LongitudLista() == 0)
    {
        nuevo->sig = inicio;
        inicio = nuevo;
        dim++;
    }

	while(aux->sig != NULL)
		aux = aux->sig;

    aux->sig = nuevo;
	dim++;
}

template <class T>
void Lista<T>::ImprimirLista()
{
    struct Nodo *aux;
    aux = inicio;

    if(!EstaVacia())
    {
        while(aux != NULL)
        {
            cout << aux->dato;
            aux = aux->sig;
            cout <<" ----------------- "<<endl;
        }
    }


}

template <class T>
bool Lista<T>::EstaVacia()
{
    return (dim == 0);
}

template <class T>
void Lista<T>::VaciarLista()
{
    struct Nodo *act;

    while(!EstaVacia())
    {
        act = inicio;
        inicio = inicio->sig;
        delete act;
        dim--;
    }

}
template <class T>
void Lista<T>::SuprimirDato(T x)
{
    struct Nodo *act, *ant = nullptr;
    act = inicio;

    if (!EstaVacia())
    {
        if (act->dato == x)
        {
            inicio = act->sig;
            delete act;       
            dim--;            
            return;           
        }

        // Para otros elementos
        while (act != nullptr && act->dato != x)
        {
            ant = act;
            act = act->sig;
        }

        if (act != nullptr)
        {
            ant->sig = act->sig;
            delete act;         
            dim--;              
        }
    }
}


template <class T>
T Lista<T>::SuprimirDatoPosicion(int pos)
{
    struct Nodo *ant,*act;
    

    if(!(EstaVacia()))
    {
        act = inicio;
        if(pos == 0)
        {
            inicio = act->sig;
            T dato = act->dato;
            delete act;
            dim--;
            return dato;
        }else{

            if(pos == LongitudLista()-1)
            {
                while(act->sig != NULL)
                {
                    ant = act;
                    act = act->sig;
                }

                ant->sig = act->sig;
                T dato = act->dato;
                delete act;
                dim--;
                return dato;
            }

            if(pos > 0 and pos < LongitudLista()-1)
            {
                int indice = 0;
                while(pos != indice)
                {
                    ant = act;
                    act = act->sig;
                    indice++;
                }

                if(indice == pos)
                {
                    ant->sig = act->sig;
                    T dato = act->dato;
                    delete act;
                    dim--;
                    return dato;
                }
            }
        }
    }
}

template <class T>
int Lista<T>::LongitudLista()
{
    return dim;
}

template <class T>
T Lista<T>::DevolverDatoPosicion(int pos)
{
    if (EstaVacia()) {
        throw out_of_range("La lista está vacía.");
    }

    if (pos < 0 || pos >= LongitudLista()) {
        throw out_of_range("Posición fuera de rango.");

    }

    struct Nodo *aux = inicio;

    if (pos == 0) {
        return aux->dato;
    }

    if (pos == LongitudLista() - 1) {
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        return aux->dato;
    }

    int indice = 0;
    while (indice != pos) {
        aux = aux->sig;
        indice++;
    }
    
    return aux->dato;
}


template <class T>
bool Lista<T>::ExisteDato(T x)
{
    struct Nodo *aux;
	aux = inicio;
	int i = 0;

	if(!EstaVacia())
	{
	    while( i <= LongitudLista()-1)
        {
            if(x == DevolverDatoPosicion(i))
                return true;
            i++;
        }
        return false;
	}
	return false;
}

template <class T>
void Lista<T>::SuprimirDatosTodos(T x)
{
	while(ExisteDato(x))
		SuprimirDato(x);
}

template <class T>
void Lista<T>::InsertarDatoPosicion(T x, int pos)
{
    struct Nodo *act,*ant;
    
    if(EstaVacia())
    {
        InsertarPrimero(x);
    }else
    {
        if(pos <= 0)
            InsertarPrimero(x);

        if( pos == LongitudLista()-1 or pos > LongitudLista()-1 )
            InsertarUltimo(x);
        else{
            
            act = inicio;
            int indice = 0;
            
            while(indice != pos)
            {
                ant = act;
                act = act->sig;
                indice++;
            }

            if(indice == pos)
            {
                struct Nodo *nuevo;
                nuevo = crearNodo(x);

                nuevo->sig = ant->sig;
                ant->sig = nuevo;
                dim++;
            }
        }
    }
}