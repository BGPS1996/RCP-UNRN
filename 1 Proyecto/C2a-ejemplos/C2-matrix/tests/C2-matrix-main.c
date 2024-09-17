#include "../constants.h"
#include "../C2-matrix.h"

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x[DIM][DIM];
    int y[DIM][DIM];
    int z[DIM][DIM];

    loadMatrix (x);
    loadMatrix (y);

    printf("\n");

    showMatrix (x);
    scalarProduct (2, x);
    showMatrix (x);
    add (z, x, y);
    showMatrix (z);
    multiply (z, y, y);
    showMatrix (z);

    return 0;
}
