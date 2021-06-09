#include "Menu.h"
#include"Niveau.h"
#include<iostream>
#include <conio.h>
#include"Partie.h"


void Menu::afficherMenu()
{
	UIKit::setDimensionFenetre(0, 60, 100, 20);
	char choixUtilisateur;

	do {
		
		system("cls");
		UIKit::setDimensionFenetre(0, 60, 100, 20);
		UIKit::color(9);
		UIKit::gotoXY(43, 5);
		std::cout << "BIENVENUE DANS LE JEUX SPACE INVADERS" << std::endl;
		UIKit::color(10);
		UIKit::gotoXY(38, 7);
		std::cout << "Veuillez faire un choix pour debuter une partie : " << std::endl;
		UIKit::gotoXY(48, 8);
		std::cout << " (F) Choix de jeux facile" << std::endl;
		UIKit::gotoXY(48, 9);
		std::cout << " (M) Choix de jeux moyen" << std::endl;
		UIKit::gotoXY(48, 10);
		std::cout << " (D) Choix de jeux difficile" << std::endl;
		UIKit::gotoXY(48, 11);
		std::cout << " (Q) Quitter" << std::endl;
		UIKit::gotoXY(50, 13);
		std::cout << "Quel est votre choix : ";

		choixUtilisateur = toupper(_getch());
		Partie* partie = new Partie();

		system("cls");
		if (choixUtilisateur != 'Q') {
			switch (choixUtilisateur) {
			case 'F':
				partie->debuter(Niveau::Easy);
				
				break;
			case 'M':
				partie->debuter(Niveau::Normal);
				
				break;
			case 'D':
				partie->debuter(Niveau::Hard);

				break;
			}
			delete partie;
		}

		//system("pause");
		
	} while (choixUtilisateur != 'Q');
}

