#include <iostream>
#include "grafo.h"
#include "grafo.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
    
	system("cls");
    try {
        
        grafo<int, int> preba(mode_DIRIGIDO, 3, type_FLOW);
		preba.showGrafo();

    } catch (const exception& e) {
        cerr << "Excepción: " << e.what() << endl;
    }

    return 0;
}
