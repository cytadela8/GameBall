#ifndef SCHEMAT_H
#define SCHEMAT_H


#include "screen_c/screen_p.h"

class schemat : public screen_p
{
	public:
		schemat();
		virtual ~schemat();
		int Load();
		int UnLoad();
		SBI Draw(sf::RenderWindow & App);
		SBI Work();
		SBI Animate(sf::RenderWindow & App);
		SBI EventProc(sf::Event event);
	protected:
	private:
};
#endif // SCHEMAT_H
