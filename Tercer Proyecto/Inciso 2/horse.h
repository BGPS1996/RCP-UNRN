#ifndef HORSE_H
#define HORSE_H

#include <iostream>
#include "coord.h"
using namespace std;

class horse
{
private:
	
	coordenada position;
	void setHorse(coordenada);
	void setHorse(int, int);
public:
	horse(): position(0, 0) { }
	horse(int _row, int _col): position(_row, _col) { }
	~horse();
	
	movHorse(int _row, int _col); 				// set position
	movHorse(coordenada aux);
	coordenada getPosition()const { return position }
	
};

#endif