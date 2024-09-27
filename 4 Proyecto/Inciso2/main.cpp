#include <iostream>
#include <vector>
#include <algorithm>

#include "../Inciso1/ListaSE.h"
#include "../Inciso1/ListaSE.cpp"

#include "../Inciso1/objeto.h"

using namespace std;

#define capacidadMaxima 20

int mochilaTopDown(Lista<objeto> &mochila, int i, int W, vector<vector<int>> &memo);
void listadoOBJ(Lista<objeto> *mochila);

int main(int argc, char const *argv[])
{
    Lista<objeto> mochila;
    listadoOBJ(&mochila);

    int n = mochila.LongitudLista();
    vector<vector<int>> memo(n + 1, vector<int>(capacidadMaxima + 1, -1));
    int resultado = mochilaTopDown(mochila, n, capacidadMaxima, memo);

    return 0;
}

void listadoOBJ(Lista<objeto> *mochila)
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
}


int mochilaTopDown(Lista<objeto> &mochila, int i, int W, vector<vector<int>> &memo) {
    if (i == 0 || W == 0) {
        return 0;
    }
    if (memo[i][W] != -1) {
        return memo[i][W];
    }
    
    objeto currentObj = mochila.DevolverDatoPosicion(i - 1);
    if (currentObj.getWeight() > W) {
        memo[i][W] = mochilaTopDown(mochila, i - 1, W, memo);
    } else {
        memo[i][W] = max(currentObj.getValor() + mochilaTopDown(mochila, i - 1, W - currentObj.getWeight(), memo),
                         mochilaTopDown(mochila, i - 1, W, memo));
    }

    return memo[i][W];
}

