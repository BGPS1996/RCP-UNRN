#include <iostream>
#include <tuple>

#include "matrix_Ady.h"
#include "matrix_Ady.cpp"

using namespace std;
int main(int argc, char const *argv[])
{
	adyacente<int> matrix(5);

	//https://jonathanhigueravelasquez.wordpress.com/representacion-de-los-grafos/
	node<int> a("A", 1, make_tuple(0, 0));
	a.addEdge(make_tuple(1, 2), 5);
	a.addEdge(make_tuple(1, 4), 10);

	node<int> b("B", 1, make_tuple(0, 0));
	b.addEdge(make_tuple(1, 2), 5);
	b.addEdge(make_tuple(2, 5), 10);
	b.addEdge(make_tuple(2, 3), 10);

	node<int> c("C", 1, make_tuple(0, 0));
	c.addEdge(make_tuple(3, 2), 5);
	c.addEdge(make_tuple(3, 4), 10);

	node<int> d("D", 1, make_tuple(0, 0));
	d.addEdge(make_tuple(4, 1), 5);
	d.addEdge(make_tuple(4, 5), 10);

	node<int> e("E", 1, make_tuple(0, 0));
	e.addEdge(make_tuple(5, 2), 5);
	e.addEdge(make_tuple(5, 4), 10);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;


	matrix.addNodo(a);
	matrix.addNodo(b);
	matrix.addNodo(c);
	matrix.addNodo(d);
	matrix.addNodo(e);

	cout << endl;
	matrix.showMatrix();

	return 0;
}
