#ifndef COORDENADA_H
#define COORDENADA_H

#include <iostream>
using namespace std;

class coordenada
{
public:
	coordenada() : x(0), y(0) {}
	coordenada(int _x, int _y) : x(_x), y(_y) {}
	~coordenada() {}  
	
	int x;
	int y;

	int getX() const { return x; }
	int getY() const { return y; }

	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }

	friend istream& operator>> (istream& is, coordenada& other)
	{
		is >> other.x >> other.y;
		return is;
	}

	friend ostream& operator<< (ostream& os, const coordenada& other)
	{
		os << " (" << other.x << ", " << other.y << ") ";
		return os;
	}

	coordenada operator+ (const coordenada &other) const
	{
		coordenada aux;
		aux.x = this->x + other.x;
		aux.y = this->y + other.y;
		return aux;
	}

	bool operator== (const coordenada& other) const
	{
		return ((this->x == other.x) && (this->y == other.y));
	}

	bool operator!= (const coordenada& other) const
	{
		return !(*this == other);
	}

	coordenada& operator= (const coordenada& other)
	{
		if (this != &other)
		{
			this->x = other.x;
			this->y = other.y;
		}
		return *this;
	}
};

#endif
