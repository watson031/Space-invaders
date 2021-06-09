#pragma once
#include "Direction.h"
#include "ObjetDeJeu.h"
/*
	Cette classe repr�sente le vaisseau de base qui sera pilot�
	par le joueur.
*/
class Vaisseau : public ObjetDeJeu {
protected:
	char apparence; // Sert � contenir l'apparence du vaisseau de base
	Coord limiteGauche; // Sert � contenir la limite de d�placement de gauche du vaisseau 
	Coord limiteDroite; // Sert � contenir la limite de d�placement de droite du vaisseau
	
	void effacer() override;
	void afficher() override;
public:
	//Constructeur servant � initialiser un vaisseau et l'afficher � l'�cran.
	Vaisseau(char apparenceVaisseau, Coord c, Coord limiteGauche, Coord limiteDroite);
	/*
		M�thode qui sert � d�placer en m�moire et sur l'�cran le vaisseau.
		Celle-ci peut �tre red�finie par une classe d�riv�e au besoin 
		s'il y a lieu.
	*/
	virtual void deplacer(Direction direction);
};