#include <iostream>

#include "Estudiante.h"

using namespace std;

int main() {
    Estudiante est("Juan Perez", 20, 12345678);
    est.addMateria("Matemáticas");
    est.addMateria("Física");
    est.addMateria("Química");

    cout << est << endl;  // Imprime los datos del estudiante
    //est.showMaterias();   // Imprime la lista de materias aprobadas

    return 0;
}
