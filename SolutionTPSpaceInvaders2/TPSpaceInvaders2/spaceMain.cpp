#include <iostream>
#include "Partie.h"
#include<time.h>
#include"Menu.h"
using namespace std;

int main() {
	srand(time(0));
	//D�mare une seule partie, la joue et la supprime imm�diatement lorsqu'elle est termin�e
	Menu menu;
	menu.afficherMenu();

	return 0;
}