#pragma once
#include "Martien.h"
class ExtraMartien :public Martien
{

public:
	ExtraMartien(Coord coord, char apparence, unsigned short valeurPoints);
	void deplacer() override;

};

