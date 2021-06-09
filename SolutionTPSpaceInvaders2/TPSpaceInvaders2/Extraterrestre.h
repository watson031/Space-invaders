#pragma once
#include "Direction.h"
#include "ObjetDeJeu.h"
/*
	Classe qui repr�sente la base de l'�volution des d'extraterrestres qui tenterons 
	d'envahir la terre.
*/
class Extraterrestre : public ObjetDeJeu {
protected:
	char apparence; // Sert � contenir l'apparence de l'extraterrestre
	unsigned short valeurPoints; // Sert � contenir la valeur en points que l'extraterrestre donne lorsqu'il est d�truit

	//M�thode qui sert � effacer l'extraterrestre � l'�cran. Peut �tre red�fini au besoin dans une classe d�riv�e.
	void effacer() override;
	//M�thode qui sert � afficher l'extraterrestre � l'�cran. Peut �tre red�fini au besoin dans une classe d�riv�e.
	void afficher() override;
public:
	//Constructeur qui sert � initialiser l'extraterrestre construit et l'affiche � l'�cran
	Extraterrestre(Coord coord, char apparence, unsigned short valeurPoints);

	//M�thode qui retourne la valeur en point de l'extraterrestre
	unsigned short getValeurPoints() const;
	//virtual void deplacer(Direction direction);
};