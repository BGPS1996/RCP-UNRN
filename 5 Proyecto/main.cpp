#include <iostream>
#include <tuple>

//#include "matrix_Ady.h"
//#include "matrix_Ady.cpp"

#include "grafo.h"
#include "grafo.cpp"

using namespace std;
int main(int argc, char const *argv[])
{
	grafo<int> preba(2);
	preba.showRepresentation();
	cout<<" BFS" <<endl;
	preba.BFS(0);
	cout<<"DFS " <<endl;
	preba.DFS(0);

	return 0;
}
