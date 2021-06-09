//	Version au 15/01/2015
#include "UIKit.h"
#define VERSION_CPP 15012015

#if VERSION_CPP != VERSION_H
#error "rockUtiles: versions diff�rentes"
#endif

//impl�mentation des m�thodes statiques de gestion d'�cran

#include <windows.h>
#include <iostream>
using namespace std;

HANDLE UIKit::handle = GetStdHandle(STD_OUTPUT_HANDLE);
bool UIKit::isPaletteReset = false;

void UIKit::resetPalette() {
	isPaletteReset = true;

	const short value[3] = {0, 128, 255};

	CONSOLE_SCREEN_BUFFER_INFOEX csbiex;
	csbiex.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(handle, &csbiex);

	for(int index=0; index<16; index++) {
		int r=(index & FOREGROUND_RED) >> 2, v=(index & FOREGROUND_GREEN) >> 1, b=(index & FOREGROUND_BLUE);
		if (index & FOREGROUND_INTENSITY) { r <<= 1; v <<= 1; b <<= 1; }
		csbiex.ColorTable[index] = RGB(value[r], value[v], value[b]);
	}

	SetConsoleScreenBufferInfoEx(handle, &csbiex);
}

/**************************
d�finir la couleur d'affichage
***************************/
void UIKit::color(unsigned short laCouleur)
{
	if(!isPaletteReset)
		resetPalette();
    SetConsoleTextAttribute (handle, laCouleur);
}

/*************************
positioner le curseur
**************************
	Positionne le curseur � l'�cran
	Entr�es: x = num�ro de colonne
			 y = num�ro de ligne
*/
void UIKit::gotoXY(int x, int y)
{   
	cout.flush();	//	affiche les caract�res en attente
	COORD coord;   
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}

//  retourne le caract�re se trouvant � la colonne x, ligne y
char UIKit::getCharXY(int x, int y)
{
    CHAR_INFO buffer;
    COORD dwBufferSize = {1, 1};
    COORD dwBufferCoord = {0, 0};
	SMALL_RECT readRegion;

    readRegion.Top = readRegion.Bottom = y;
    readRegion.Left = readRegion.Right = x;

    if (! ReadConsoleOutput(handle, &buffer, dwBufferSize, dwBufferCoord, &readRegion))
    {
        printf("ReadConsoleOutput failed - (%d)\n", GetLastError());
        return 1;
    }

    return buffer.Char.AsciiChar;
}

/*************************
configurer les dimension de la fen�tre
	dimensionner la fenetre
	relatif au settings par d�faut de la console
**************************/
void UIKit::setDimensionFenetre(int x1, int y1, int x2, int y2)
{
	COORD coord,max; 
	coord.X =x2+1;
	coord.Y =y2+1;

	//v�rifier que la taille voulue est possible
	max=GetLargestConsoleWindowSize(handle);
	if(coord.X>max.X)
    {
		coord.X=max.X;
		x2=max.X-1;
	}
	if(coord.Y>max.Y)
    {
		coord.Y=max.Y;
		y2=max.Y-1;
	}
	SetConsoleScreenBufferSize(handle,coord);

	const SMALL_RECT fenetre = {(short)x1, (short)y1, (short)x2, (short)y2};
	SetConsoleWindowInfo(handle, true, &fenetre);
}

/**************************
fonction cadre
***************************/
void UIKit::cadre(int cd,int ld,int cf,int lf, int couleur)
{
    color(couleur);  //d�finir la couleur du cadre
    
	gotoXY(cd,ld);
    cout<<(char)201;  //coin sup�rieur gauche
    for(int i=cd+1;i<cf;i++)
    	 cout<<(char)205; //ligne horizontale du haut
	cout<<(char)187;  //coin sup�rieur droit
    for(int i=ld+1;i<lf;i++)
    {
    	 gotoXY(cd,i);
    	 cout<<(char)186;  //ligne verticale gaughe
    	 gotoXY(cf,i);
    	 cout<<(char)186;  //ligne verticale droite
    }
    gotoXY(cd,lf);
    cout<<(char)200;  //coin inf�rieur gauche
    for(int i=cd+1;i<cf;i++)
    	cout<<(char)205;  //ligne horizontale inf�rieure
    cout<<(char)188;  //coin inf�rieur droit
}

/*
	Retourne la position courante horizontale
	du curseur dans la fen�tre d'affichage
*/
int UIKit::whereX()
{
	cout.flush();
	CONSOLE_SCREEN_BUFFER_INFO tampon;
	GetConsoleScreenBufferInfo(handle, &tampon);
	return tampon.dwCursorPosition.X;
}

/*
	Retourne la position courante verticale
	du curseur dans la fen�tre d'affichage
*/
int UIKit::whereY()
{
	cout.flush();
	CONSOLE_SCREEN_BUFFER_INFO tampon;
	GetConsoleScreenBufferInfo(handle, &tampon);
	return tampon.dwCursorPosition.Y;
}

/*
	Rend le curseur visible ou invisible
	Entr�e: visibilite = le curseur doit �tre invisible (VRAI ou FAUX)
*/
void UIKit::curseurVisible(bool visibilite)
{
	CONSOLE_CURSOR_INFO curseur;
	GetConsoleCursorInfo(handle, &curseur);
	curseur.bVisible = visibilite;
	SetConsoleCursorInfo(handle, &curseur);
}

