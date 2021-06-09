#pragma once
#include "ObjetDeJeu.h"
#include "TypeLaser.h"
/*
	Classe servant � repr�senter tout type de laser pouvant �tre utilis� dans le jeu (Joueur ou Extraterrestre).
*/
class Laser : public ObjetDeJeu {

protected:
	TypeLaser typeLaser; // Repr�sente le type de laser

	void afficher() override;
	void effacer() override;
public:
	Laser(Coord c, TypeLaser typeLaser);
	/*
		M�thode qui sert � d�placer en m�moire et � l'�cran un laser selon son type.
	*/
	virtual void deplacer();
	/*
		Retourne le type de laser.
	*/
	TypeLaser getTypeLaser() const;
	/*
		Redfinition de la m�thode d�truire de ObjetDeJeu.
	*/
	void detruire() override;
};