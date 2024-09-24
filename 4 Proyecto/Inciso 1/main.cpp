#include <iostream>

#include "ListaSE.h"
#include "ListaSE.cpp"
#include "objeto.h"

using namespace std;



#define capacidadMaxima 20

int mochila_definicion(Lista<objeto> &mochila, int i, int W, Lista<objeto> &solucion);

int listadoOBJ(Lista<objeto> *);

int main(int argc, char const *argv[])
{
    Lista<objeto> mochila;
    Lista<objeto> solucion;
    int n = listadoOBJ(&mochila);


    int resultado = mochila_definicion(mochila, n, capacidadMaxima, solucion);

    cout << "El valor maximo que se puede obtener es: " << resultado << endl;




    solucion.ImprimirLista();
    return 0;
}

int listadoOBJ(Lista<objeto> *mochila)
{
    objeto automovil(200, 10);
    objeto lentes(2.1, 10);
    objeto netbook(5, 10);
    objeto termo(12, 9);
    objeto audiculares(0.5, 8);
    objeto carpeta(3, 6);
    objeto cartuchera(0.7, 3);
    objeto mate(0.2, 2);
    objeto taza(0.3, 1);

    mochila->InsertarPrimero(automovil);
    mochila->InsertarPrimero(lentes);
    mochila->InsertarPrimero(netbook);
    mochila->InsertarPrimero(termo);
    mochila->InsertarPrimero(audiculares);
    mochila->InsertarPrimero(carpeta);
    mochila->InsertarPrimero(cartuchera);
    mochila->InsertarPrimero(mate);
    mochila->InsertarPrimero(taza);    

    return mochila->LongitudLista();
}

#include <iostream>
#include <algorithm>
using namespace std;

int mochila_definicion(Lista<objeto> &mochila, int i, int W, Lista<objeto> &Solucion) {
    if (i == 0 || W == 0) {
        return 0;
    }

    objeto currentObj = mochila.DevolverDatoPosicion(i - 1);
    if((Solucion.ExisteDato(currentObj)))
        return 0;

    if (currentObj.getWeight() > W) {
        return mochila_definicion(mochila, i - 1, W, Solucion);
    } else {
        
        int incluir = currentObj.getValor() + mochila_definicion(mochila, i - 1, W - currentObj.getWeight(), Solucion);
        int excluir = mochila_definicion(mochila, i - 1, W, Solucion);
        
        if (incluir > excluir) {
            Solucion.InsertarPrimero(currentObj);

            if(!(Solucion.ExisteDato(currentObj)))
                mochila.SuprimirDato(currentObj);
            return incluir;
        } else {
            return excluir;
        }
    }
}
