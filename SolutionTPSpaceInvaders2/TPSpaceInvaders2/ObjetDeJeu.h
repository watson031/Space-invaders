#pragma once
#include "Coord.h"
#include "TypeObjetDeJeu.h"

/*
	Classe de base servent � contenir les donn�es membre et m�thodes commune �
	toutes les type d'objets de jeux disponible dans le programme.
*/
class ObjetDeJeu {
protected:
	Coord coord; // l'emplacement sur l'axe des x et y de l'objet de jeu
	bool actif; // si l'objet est actif ou non
	TypeObjetDeJeu type; // le type de l'objet de jeu
	
	/*
		M�thode appel�e pour effacer un objet � l'�cran. M�thode virtuelle 
		pure qui doit �tre red�finie dans une classe d�riv�e.
	*/
	virtual void effacer() = 0;
	/*
		M�thode appel�e pour afficher un objet � l'�cran. M�thode virtuelle
		pure qui doit �tre red�finie dans une classe d�riv�e.
	*/
	virtual void afficher() = 0;
public:
	ObjetDeJeu(Coord coord, TypeObjetDeJeu type);
	virtual ~ObjetDeJeu(); 
	/*
		M�thode qui retourne true si les coordonn�es x et y de l'instance en 
		cours sont �gales au coordonn�es x et y de l'OBJET_DE_JEU, sinon elle 
		retourne false.

		Peut �tre red�finie au besoin dans une classe d�riv�e.
	*/
	virtual bool detecterCollision(const ObjetDeJeu& OBJET_DE_JEU) const;
	//Retourne les coordonn�es de l'instance
	const Coord& getCoord() const;
	//Retourne l'�tat actif ou non de l'instance
	bool isActif() const;
	//M�thode servant � d�truire l'objet en cours. Peut �tre red�finie dans un classe d�riv�e au besoin
	virtual void detruire();
	//Retourne le type de l'objet de jeu
	TypeObjetDeJeu getType() const;
};

