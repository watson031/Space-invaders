#include "Partie.h"
#include "Vaisseau.h"
#include "Extraterrestre.h"
#include "UIKit.h"
#include <iostream>
#include <conio.h>
#include"Laser.h"
#include<time.h>
#include"Martien.h"
#include"ExtraMartien.h"

void Partie::debuter(Niveau niveau)
{
	UIKit::curseurVisible(false);
	UIKit::setDimensionFenetre(0, 0, 70, 30);
	UIKit::cadre(0, 0, 60, 23, 9);
	bool partieTermine = false;

	//Faire apparaitre le vaisseau
	Coord coordonneesDepartVaisseau(30, 20);
	Coord limiteMouvementGauche(10, 20);
	Coord limiteMouvementDroite(50, 20);
	UIKit::color(12);
	char apparenceDuVaisseau = 'A';
	Vaisseau vaisseau(apparenceDuVaisseau, coordonneesDepartVaisseau, limiteMouvementGauche, limiteMouvementDroite);
	unsigned short nbreLasers = 0;
	Laser* laserVaisseau[150];

	unsigned short nbreLasersMartiens = 0;
	Laser* laserMartiens[100];

	unsigned int nbreEnnemis = 0;
	Martien* vaisseauxEnnemis[150];

	const unsigned short  MIN_COORD_Y = 3, MAX_COORD_Y = 10;
	const unsigned short MIN_COORD_X = 11, MAX_COORD_X = 48;
	unsigned int valeurPoint = 10;
	unsigned int valeurPointsEM = 0;

	unsigned short points = 0;
	unsigned short vie = 5;
	unsigned short difficulty;// difficulté du jeu: plus le chiffre est bas plus la partie est compliquée. Ex: (hard=30,normal=40,facile=50)
	unsigned short difficultyGenererAlliensM;
	unsigned short difficultyGenererAlliensO;
	unsigned short faireTirerEnnemis;

	switch (niveau)
	{
	case Niveau::Easy:
		difficulty = 60;
		difficultyGenererAlliensM = 1;
		difficultyGenererAlliensO = 0;
		faireTirerEnnemis = 2;
		break;
	case Niveau::Normal:
		difficulty = 50;
		difficultyGenererAlliensM = 2;
		difficultyGenererAlliensO = 1;
		faireTirerEnnemis = 4;
		break;
	case Niveau::Hard:
		difficulty = 45;
		difficultyGenererAlliensM = 3;
		difficultyGenererAlliensO = 4;
		faireTirerEnnemis = 5;
		break;
	}
	
	do {

		UIKit::gotoXY(1, 1);
		cout << "             ";
		UIKit::gotoXY(1, 1);
		cout << "NBLasers : " << nbreLasers;

		UIKit::gotoXY(48, 1);
		cout << "SCORE: " << points;

		UIKit::gotoXY(27, 1);
		cout << "LIVES: " << vie;

		UIKit::gotoXY(1, 22);
		cout << "NB MARTIANS: " << nbreEnnemis;


		//Récupérer la touche appuyée par l'utilisateur	//
		//Effectuer action en fonction de la touche appuyé par l'utilisateur
		//Ici on peut soit déplacer le vaiseau à gauche ou à droite, soit tirer un laser
		UIKit::color(12);
		if (GetAsyncKeyState(VK_LEFT)) {
			vaisseau.deplacer(Direction::GAUCHE);
		}

		else if (GetAsyncKeyState(VK_RIGHT)) {
			vaisseau.deplacer(Direction::DROITE);
		}

		if (GetAsyncKeyState(VK_SPACE)) {

			laserVaisseau[nbreLasers] = new Laser(vaisseau.getCoord(), TypeLaser::JOUEUR);
			nbreLasers++;
			UIKit::color(12);
		}

		UIKit::color(15);
		//Déplacer les lasers du vaisseau et des extraterrestres
		for (int i = 0; i < nbreLasers; i++) {
			laserVaisseau[i]->deplacer();
		}
		UIKit::color(15);
		for (int i = 0; i < nbreLasers; i++) {
			if (laserVaisseau[i]->isActif() == false) {
				delete laserVaisseau[i];
				laserVaisseau[i] = laserVaisseau[nbreLasers - 1];
				nbreLasers--;
				i--;

			}

		}
		UIKit::color(15);
		//Déplacer les extraterrestres	


		int genererAlliens = rand() % difficulty;
		UIKit::color(9);
		if (genererAlliens < difficultyGenererAlliensM) {
			unsigned short randomCoordX = rand();
			unsigned short randomCoordY = rand();
			unsigned short randExtraterrestreX = (randomCoordX % (MAX_COORD_X - MIN_COORD_X + 1)) + MIN_COORD_X;
			unsigned short randExtraterrestreY = (randomCoordY % (MAX_COORD_Y - MIN_COORD_Y + 1)) + MIN_COORD_Y;
			char apparenceDuExtraterrestre = 'M';
			UIKit::color(9);
			Coord vaisseauxExtra(randExtraterrestreX, randExtraterrestreY);

			nbreEnnemis++;
			vaisseauxEnnemis[nbreEnnemis - 1] = new Martien(vaisseauxExtra, apparenceDuExtraterrestre, valeurPoint);
			UIKit::color(9);
		}
		/*else if (genererAlliens < difficultyGenererAlliensO) {
			unsigned short randomCoordX = rand();
			unsigned short randomCoordY = rand();
			unsigned short randExtraterrestreX = (randomCoordX % (MAX_COORD_X - MIN_COORD_X + 1)) + MIN_COORD_X;
			unsigned short randExtraterrestreY = (randomCoordY % (MAX_COORD_Y - MIN_COORD_Y + 1)) + MIN_COORD_Y;
			char apparenceDuExtraterrestre = 'O';

			Coord vaisseauxExtra(randExtraterrestreX, randExtraterrestreY);

			nbreEnnemis++;
			vaisseauxEnnemis[nbreEnnemis - 1] = new Martien(vaisseauxExtra, apparenceDuExtraterrestre, valeurPoint);

		}*/
		UIKit::color(9);
		for (int i = 0; i < nbreEnnemis; i++) {
			vaisseauxEnnemis[i]->deplacer();
			UIKit::color(9);

		}
		UIKit::color(9);
		for (int i = 0; i < nbreEnnemis; i++) {
			if (vaisseauxEnnemis[i]->isActif() == false) {
				delete vaisseauxEnnemis[i];
				vaisseauxEnnemis[i] = vaisseauxEnnemis[nbreEnnemis - 1];
				nbreEnnemis--;
				i--;
			}
			UIKit::color(13);
		}

		//Faire tirer les extraterrestres	

		for (int i = 0; i < nbreEnnemis; i++) {
			if (rand() % 100 < faireTirerEnnemis) {
				laserMartiens[nbreLasersMartiens] = new Laser(vaisseauxEnnemis[i]->getCoord(), TypeLaser::EXTRATERRESTRE);
				nbreLasersMartiens++;
			}

		}

		for (int i = 0; i < nbreLasersMartiens; i++) {
			laserMartiens[i]->deplacer();
		}

		for (int i = 0; i < nbreLasersMartiens; i++) {
			if (laserMartiens[i]->isActif() == false) {
				delete laserMartiens[i];
				laserMartiens[i] = laserMartiens[nbreLasersMartiens - 1];
				nbreLasersMartiens--;
				i--;

			}

		}

		//Vérifier collision entre laser et joueur ou ennemis
		for (int i = 0; i < nbreEnnemis; i++) {

			for (int j = 0; j < nbreLasers; j++) {
				bool tuerEnnemis = laserVaisseau[j]->detecterCollision(*vaisseauxEnnemis[i]);

				if (tuerEnnemis == true) {
					vaisseauxEnnemis[i]->detruire();
					laserVaisseau[j]->detruire();
					points += vaisseauxEnnemis[i]->getValeurPoints();
				}
			}
		}

		//for (int i = 0; i < nbreEnnemis; i++) {

		for (int j = 0; j < nbreLasersMartiens; j++) {
			bool tuerMonVaisseau = laserMartiens[j]->detecterCollision(vaisseau);
			if (tuerMonVaisseau == true) {
				vaisseau.detruire();
				laserMartiens[j]->detruire();
				vie--;

			}
		}
		
		//}

		//Faire apparaitre nouveau extraterrestre
		int genererAlliens2 = rand() % difficulty;

		if (genererAlliens < difficultyGenererAlliensO) {
			unsigned short randomCoordX = rand();
			unsigned short randomCoordY = rand();
			unsigned short randExtraterrestreX = (randomCoordX % (MAX_COORD_X - MIN_COORD_X + 1)) + MIN_COORD_X;
			unsigned short randExtraterrestreY = (randomCoordY % (MAX_COORD_Y - MIN_COORD_Y + 1)) + MIN_COORD_Y;
			char apparenceDuExtraterrestre = 'O';

			Coord vaisseauxExtra(randExtraterrestreX, randExtraterrestreY);
			valeurPointsEM = 15;


			nbreEnnemis++;
			vaisseauxEnnemis[nbreEnnemis - 1] = new ExtraMartien(vaisseauxExtra, apparenceDuExtraterrestre, valeurPointsEM);
		}



		//Mettre à jour le score affiché		
		UIKit::gotoXY(48, 1);
		cout << "SCORE: " << points+ valeurPointsEM;


		UIKit::gotoXY(27, 1);
		cout << "LIVES: " << vie;

		//Vérifier si on gagne (si le nombre d'extraterrestre est rendu à 0 )
		
		if (nbreEnnemis == 0 && points > 20) {
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "victoire!   vous avez reussi a les exterminer"<<endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << "Score :" << points * 2 << endl;
			cout << endl;
			
			Sleep(5000);
			system("pause");
			partieTermine = true;
			
		}

		//Vérifier si on perd si le nombre d'extra terrestre est à 15+ ou 
		if (nbreEnnemis > 15 || vie == 0) {
			system("cls");
			cout << "-----------------------------------------------" << endl;
			cout << "Defaite!   vous avez ete vaincu " << endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << "Score :" << (points+valeurPointsEM) / 2 << endl;
			cout << endl;
			Sleep(5000);
			system("pause");
			partieTermine = true; 
			
		}
		
		Sleep(50);
	} while (partieTermine == false);
	system("cls");

}

