#pragma once
/*
	Classe qui sert � contenir les coordonn�es x et y des diff�rents type d'objet 
	de jeu du programme.
*/
class Coord {

	int x;
	int y;
public:
	Coord(int x, int y);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
};

