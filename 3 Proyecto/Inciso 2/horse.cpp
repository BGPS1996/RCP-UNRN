
#include "horse.h"

void horse::setHorse(coordenada _new)
{
	this->position.setX(_new.getX());
	this->position.setY(_new.getY());
}

void horse::setHorse(int _x, int _y)
{
	this->position.setX(_x);
	this->position.setY(_y);
}

void horse::movHorse(int _row, int _col)
{
	this->setHorse(_row, _col);
}

void horse::movHorse(coordenada aux)
{
	this->setHorse(aux);
}