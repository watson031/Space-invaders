#include "ExtraMartien.h"
#include <random>

ExtraMartien::ExtraMartien(Coord coord, char apparence, unsigned short valeurPoints):Martien(coord,apparence,valeurPoints)
{
	this->toggle = (rand() % 3);
}

void ExtraMartien::deplacer()
{
	this->effacer();
	this->coord.setX(this->coord.getX() + (toggle ? 1 : -1));
	//this->coord.setY(this->coord.getY() + (toggle ? 2 : -2));
	if (this->getCoord().getX() <= 10 || this->getCoord().getX() >= 58) {
		toggle = !toggle;
	}
	this->afficher();
}
