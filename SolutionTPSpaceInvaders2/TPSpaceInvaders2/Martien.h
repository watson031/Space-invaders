#pragma once
#include "Extraterrestre.h"
/*
	Cette classe repr�sente l'�volution de l'extraterrestre qui � la 
	possibilit� de se d�placer de gauche � droite pour tenter d'�viter 
	les tirs du joueur. 
*/
class Martien : public Extraterrestre {
protected:
	bool toggle; // Information servant � controler si l'extraterrestre se d�place � gauche ou � droite 
				//	lors de l'appel de la m�thode void deplacer();
public:
	Martien(Coord coord, char apparence, unsigned short valeurPoints);
	// M�thode qui sert � d�placer en m�moire et � l'�cran un Martien
	virtual void deplacer();
};



