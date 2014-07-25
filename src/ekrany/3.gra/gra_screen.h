#ifndef GRA_SCREEN_H
#define GRA_SCREEN_H

#include <iostream>
#include <SFML/Audio.hpp>

#include "screen_c/screen_p.h"
#include "screen_c/KeyComp.h"
#include "entities/kolo.h"
#include "tostring.h"
#include "grafika/tekstura.h"
#include "ekrany/6.gol/Gol.h"
#include "ekrany/2.menu/menu_screen.h"
#include "fizykcont.h"

/*const double PrzyspG=700+1400;
const double PrzyspGKop=300+1400;
const double MaxVGraczKop=75;
const double MaxVGraczNorm=150;
const double MocKop=500;
const double WspolTarciaGracz=1400;
const double WspolTarciaPilka=600;
const double ProgTarcia=150;*/

const fizykcont fizykopty=fizykcont(700+1400,
                                300+1400,
                                75,
                                150,
                                500,
                                1400,
                                600,
                                150);


/*
PrzyspG=dan->fizyk[0];
PrzyspGKop=dan->fizyk[1];
MaxVGraczKop=dan->fizyk[2];
MaxVGraczNorm=dan->fizyk[3];
MocKop=dan->fizyk[4];
WspolTarciaGracz=dan->fizyk[5];
WspolTarciaPilka=dan->fizyk[6];
ProgTarcia=dan->fizyk[7];
*/

class gra_screen : public screen_p
{
public:
	gra_screen(sf::RenderWindow &App,sf::Font & font);
	virtual ~gra_screen();
	int Load();
	int UnLoad();
	void Init(void * wskaz);
	SBI Draw(sf::RenderWindow &App);
	SBI Work();
	SBI Animate(sf::RenderWindow &App);
	SBI EventProc(sf::Event event);

	struct init_form
	{
		init_form(int grspisd[],int czasmaxd,int wynmaxd,fizykcont fizykd,string ag1d,string ag2d)
		{
			grspis=new int[MaxGraczy+1];
			grspis[0]=0;
			for (int i=1; i<=MaxGraczy; i++)
				grspis[i]=grspisd[i];
			fizyk=fizykd;
			czasmax=czasmaxd;
			wynmax=wynmaxd;
			ag1=ag1d;
			ag2=ag2d;
		}
		~init_form()
		{
			delete grspis;
		}
		int *grspis;
		int czasmax;
		int wynmax;
		fizykcont fizyk;
		string ag1;
		string ag2;
	};
protected:
private:
	void Reseter();
	enum Kier {Gora,Dol,Lewo,Prawo,Uderz,Licz};
	sf::String wynik_obl;
	//sf::String wynik_obs;
	sf::String wynik_obp;
	//tekstura trawa_t;
	sf::Shape * lingran;
	sf::Image *pilka;
	sf::Image *slupek;
	sf::Image *gracz1_im;
	sf::Image *gracz2_im;
	sf::Image *gracz;
	sf::Image *boisko_im;
	sf::Sprite boisko_sp;
	sf::SoundBuffer * kops_o;
	sf::Sound kops_p;
	sf::View view;
	kolo *obiekty;
	kolo *pilka_ob;
	kolo *gracze_ob;
	KeyComp **gracze_ev;
	bool * GraczPowLock;
	int obiekty_il;
	int gracz_il;
	bool czy;
	bool pozres;
	int bg;
	int bd;
	int bl;
	int bp;
	int bramka;
	int wynl;
	int wynp;
	sf::Clock Timer_c;
	sf::String Timer_ob1;
	sf::String Techdata;
	//int endtime;
	//int endwyn;
	init_form *dan;
	double PrzyspG;
	double PrzyspGKop;
	double MaxVGraczKop;
	double MaxVGraczNorm;
	double MocKop;
	double WspolTarciaGracz;
	double WspolTarciaPilka;
	double ProgTarcia;
	bool zam;
	double korektatime;
	double osttime;
};
#endif // GRA_SCREEN_H
