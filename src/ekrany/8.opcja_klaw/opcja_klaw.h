#ifndef OPCJA_KLAW_H
#define OPCJA_KLAW_H


#include "screen_c/screen_p.h"
#include "grafika/menu/opcja.h"
struct keycont
{
	char znak;
	bool rodz;
};
class opcja_klaw : public screen_p
{
	public:
		opcja_klaw(int r,int g,int b,sf::RenderWindow & App);
		virtual ~opcja_klaw();
		int Load();
		int UnLoad();
		SBI Draw(sf::RenderWindow & App);
		SBI Work();
		SBI Animate(sf::RenderWindow & App);
		SBI EventProc(sf::Event event);
		void Init(void * wskaz);
		sf::Key::Code nasf(char znak,bool rodz);
		sf::Key::Code nasf(int kod);
		keycont nacont(sf::Key::Code klaw);

		struct init_form
		{
			init_form(opcja * delem,sf::Font & norm,sf::Font & spec) {elem=delem;czcionnorm=&norm;czcionspec=&spec;}
			opcja * elem;
			sf::Font *czcionnorm;
			sf::Font *czcionspec;
		};
	protected:
	private:
	init_form * dan;
	sf::Clock czas;
	sf::String napis;
	int r;
	int g;
	int b;
};

#endif // OPCJA_KLAW_H
