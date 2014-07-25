#ifndef OPCJA_CZAS_H
#define OPCJA_CZAS_H

#include <sstream>

#include "screen_c/screen_p.h"
#include "grafika/menu/opcja.h"
#include "tostring.h"

int getsek(opcja * op);
int getmin(opcja * op);

class opcja_czas : public screen_p
{
	public:
		opcja_czas();
		virtual ~opcja_czas();
		int Load();
		int UnLoad();
		SBI Draw(sf::RenderWindow & App);
		SBI Work();
		SBI Animate(sf::RenderWindow & App);
		SBI EventProc(sf::Event event);
		void Init(void * wskaz);
		struct init_form
		{
			init_form(opcja * delem,int dmin=0,int dmax=0) {elem=delem;max=dmax;min=dmin;}
			int max;
			int min;
			opcja * elem;
		};
	protected:
	private:
	void akt();
	init_form * dan;
	int minut;
	int sekund;
};

#endif // OPCJA_CZAS_H
