#ifndef OPCJA_TEKST_H
#define OPCJA_TEKST_H


#include "screen_c/screen_p.h"
#include "grafika/menu/opcja.h"

class opcja_tekst : public screen_p
{
	public:
		opcja_tekst();
		~opcja_tekst();
		int Load();
		int UnLoad();
		SBI Draw(sf::RenderWindow & App);
		SBI Work();
		SBI Animate(sf::RenderWindow & App);
		SBI EventProc(sf::Event event);
		void Init(void * wskaz);
		struct init_form
		{
			init_form(opcja * delem,bool dczyliczba,int dmin=0,int dmax=0) {czyliczba=dczyliczba;elem=delem;max=dmax;min=dmin;}
			bool czyliczba;
			int max;
			int min;
			opcja * elem;
		};
	protected:
	private:
	init_form * dan;
};
#endif // OPCJA_TEKST_H
