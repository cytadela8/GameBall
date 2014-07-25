#ifndef ZAMYKANIE_SCREEN_H
#define ZAMYKANIE_SCREEN_H


#include "screen_c/screen_p.h"

class zamykanie_screen : public screen_p
{
	public:
		zamykanie_screen();
		virtual ~zamykanie_screen();
		int Load();
		int UnLoad();
		SBI Draw(sf::RenderWindow & App);
		SBI Work();
		SBI Animate(sf::RenderWindow & App);
		SBI EventProc(sf::Event event);
	protected:
	private:
};

#endif // ZAMYKANIE_SCREEN_H
