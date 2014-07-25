#ifndef INTRO_SCREEN_H
#define INTRO_SCREEN_H

#include "screen_c/screen_p.h"
#include "version.h"

class intro_screen : public screen_p
{
	public:
		intro_screen(sf::RenderWindow & App);
		virtual ~intro_screen();
		int Load();
		int UnLoad();
		SBI Draw(sf::RenderWindow &App);
		SBI Work();
		SBI Animate(sf::RenderWindow &App);
	protected:
	private:
	sf::Image *logo_i;
	sf::Sprite logo_s;
	sf::String wersja;
	sf::Clock zegar;
	int faza;
};

#endif // INTRO_SCREEN_H
