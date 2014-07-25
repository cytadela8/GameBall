#ifndef TLO_SCREEN_H
#define TLO_SCREEN_H

#include <iostream>
#include "screen_c/screen_p.h"
#include "grafika/tekstura.h"


class tlo_screen : public screen_p
{
	public:
		tlo_screen();
		virtual ~tlo_screen();
		int Load();
		int UnLoad();
		SBI Draw(sf::RenderWindow & App);
		SBI Work();
		SBI Animate(sf::RenderWindow & App);
	protected:
	private:
	tekstura trawa_t;
	sf::Image trawa_i;
};

#endif // TLO_SCREEN_H
