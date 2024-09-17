// 2.- Implementar en C el algoritmo de backtracking para resolver el problema de saber si un caballo de ajedrez es capaz de 
// viajar entre dos posiciones.

#include <iostream>
#include "horse.h"
#include "coord.h"
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

Lista<coordenada> Backtracking(horse _caballito, Lista<coordenada> *Soluciones, matrix<bool> &_tablero, coordenada objetivo)
{
    if (_caballito.getPosition() == objetivo)
    {
        Soluciones->InsertarPrimero(_caballito.getPosition());
        return *Soluciones;
    }

    // Lista de posibles movimientos del caballo.
    coordenada movimientos[8] = {
        coordenada(2, 1), coordenada(2, -1), coordenada(-2, 1), coordenada(-2, -1),
        coordenada(1, 2), coordenada(1, -2), coordenada(-1, 2), coordenada(-1, -2)
    };

    coordenada actual = _caballito.getPosition();
    _tablero[actual.getX()][actual.getY()] = 1;

    for (int i = 0; i < 8; i++)
    {
        coordenada nuevaPosicion = actual + movimientos[i];

        if (nuevaPosicion.getX() >= 0 && nuevaPosicion.getX() < _tablero.size() &&
            nuevaPosicion.getY() >= 0 && nuevaPosicion.getY() < _tablero[0].size() &&
            !_tablero[nuevaPosicion.getX()][nuevaPosicion.getY()])
        {
            _caballito.movHorse(nuevaPosicion);

            *Soluciones = Backtracking(_caballito, Soluciones, _tablero, objetivo);

            if (Soluciones->LongitudLista() > 0)
            {
                Soluciones->InsertarPrimero(actual);
                return *Soluciones;
            }
        }
    }

    _tablero[actual.getX()][actual.getY()] = 0;
    return *Soluciones;
}
