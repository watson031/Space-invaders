#include <iostream>
#include "Partie.h"
#include<time.h>
#include"Menu.h"
using namespace std;

int main() {
	srand(time(0));
	//Démare une seule partie, la joue et la supprime immédiatement lorsqu'elle est terminée
	Menu menu;
	menu.afficherMenu();

	return 0;
}