#include <iostream>
#include <tuple>
#include "node.h"
#include "node.cpp"


using namespace std;
int main(int argc, char const *argv[])
{
	node<int> a("A", 1, make_tuple(0, 0));
	a.addEdge("B", 5);  // Arco de A a B con peso 5
	a.addEdge("C", 10); // Arco de A a C con peso 10

cout << a << endl;
	return 0;
}
