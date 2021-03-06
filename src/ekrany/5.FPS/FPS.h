#ifndef SCHEMAT_H
#define FPS_H


#include "screen_c/screen_p.h"

class FPS : public screen_p
{
	public:
		FPS();
		virtual ~FPS();
		int Load();
		int UnLoad();
		SBI Draw(sf::RenderWindow & App);
		SBI Work();
		SBI Animate(sf::RenderWindow & App);
		SBI EventProc(sf::Event event);
	protected:
	private:
	std::string IntToString(int d);
	sf::Clock zegar;
	sf::String tekst;
	int licz;
};
#endif // FPS_H
