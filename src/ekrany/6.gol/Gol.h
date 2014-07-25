#ifndef GOL_H
#define GOL_H

#include <iostream>
#include "screen_c/screen_p.h"
#include <SFML/Audio.hpp>

class Gol_screen : public screen_p
{
	public:
		Gol_screen(sf::RenderWindow & App,sf::Font &font);
		virtual ~Gol_screen();
		int Load();
		int UnLoad();
		void Init(void * wskaz);
		SBI Draw(sf::RenderWindow & App);
		SBI Work();
		SBI Animate(sf::RenderWindow & App);
		SBI EventProc(sf::Event event);
		struct init_form
		{
			init_form(bool Pstroned,string wind="",bool czasd=false) {Pstrone=Pstroned;win=wind;czas=czasd;}
			bool Pstrone;
			string win;
			bool czas;
		};
	protected:
	private:
	sf::SoundBuffer * gol_b;
	sf::SoundBuffer * czas_b;
	sf::Sound gol;
	sf::Sound czas;
	sf::String gol_ob;
	sf::String win_ob;
	int faza;
	int pozx;
	int pozy;
	sf::Clock zegar;
	init_form * dan;
};
#endif // GOL_H
