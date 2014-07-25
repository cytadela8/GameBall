#ifndef MENU_C_H_INCLUDED
#define MENU_C_H_INCLUDED

#include<grafika/menu/opcja.h>
#include<grafika/menu/menu.h>

class menu_przewijane:public menu
{
	public:
	menu_przewijane(sf::Font & fontek,string const tab[],unsigned short int ilopek,unsigned short int poczpoz,string const & tytol):menu(fontek,tab,ilopek,poczpoz,tytol){;}
	void UstOpcjeMysz(short int mysz) {;}
	int rysuj(sf::RenderWindow & App) const;
};


#endif // MENU_C_H_INCLUDED
