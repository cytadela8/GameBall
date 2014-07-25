#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H


#include "screen_c/screen_p.h"
#include "grafika/menu/menu_c.h"
#include "plik/plik.h"
#include "container.h"
#include "tostring.h"
#include "ekrany/7.opcja_tekst/opcja_tekst.h"
#include "ekrany/8.opcja_klaw/opcja_klaw.h"
#include "ekrany/9.opcja_czas/opcja_czas.h"
#include "ekrany/3.gra/gra_screen.h"
#include "ekrany/3.gra/fizykcont.h"

#include <iostream>

const unsigned int IlMaxGraczy=6;

struct sestingcont
{
	int rx;
	int ry;
	bool fulscreen;
};
enum SpisMenu{Koniec=0,Glowne=1,NowaGra,NowaGra_Gracze,NowaGra_Fizyka,NowaGra_Ustaw_Fizyka,Edytor,Ustawienia,Ustawienia_roz,Ustawienia_klaw,Ilosc};
class menu_screen : public screen_p
{
	public:
		menu_screen(UsePlik<PD> & danek,sf::RenderWindow & App);
		virtual ~menu_screen();
		int Load();
		int UnLoad();
		SBI Draw(sf::RenderWindow &App);
		SBI Work();
		SBI Animate(sf::RenderWindow &App);
		SBI EventProc(sf::Event event);
		void Init(void * wskaz);
		struct init_form
	{
		init_form(bool zakonczonad)
		{
			zakonczona=zakonczonad;
		}
		bool zakonczona;
	};
	protected:
	private:
	init_form * dan;
	SBI Up(sf::Event event);
	SBI Down(sf::Event event);
	SBI Next(sf::Event event);
	SBI Back(sf::Event event);
	menu ** mena;
	SpisMenu MenuNum;
	SpisMenu PrzesowOd;
	short int WspolczynnikPrzesowo;
	short int menuprzesow;
	UsePlik<PD> * dane;
	sf::View view;
	enum eActions{MenuDown,MenuUp,MenuNext1,MenuNext2,MenuNext3,MenuBack1,MenuBack2,eaEND};
	sf::Font font;
	sf::Font klawfont;
	sf::Font klawfont2;
	sf::RenderWindow * Appek;
	sf::String komdolny;
	sf::Clock zegarkom;
	sf::Sprite logo_sp;
	sf::Image *logo_im;
	short int prz;
	int ostmousepozx;
	int ostmousepozy;
	fizykcont * fizyki;
};

#endif // MENU_SCREEN_H
