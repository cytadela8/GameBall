#ifndef OPCJA_H
#define OPCJA_H
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
using namespace std;
short int const WspolczynnikCienia=50;
class opcja
{
public:
	opcja(sf::Font & fontek,string tekstek,short const pozek,short const pozxek=0,bool srodek=true);
	//opcja(string tekstek,string wymiar2tekstek[],short int wymiar2ek,unsigned short const pozek);
	~opcja();
	//void zaznacz() {wybr=true;}
	//void odznacz() {wybr=false;}
	void SetBlok(bool blokD)
	{
		blok=blokD;
	}
	int AktLiczba() const
	{
		return dopisekliczba;
	}
	string AktTekst() const
	{
		return tekst;
	}
	string AktString() const
	{
		return dopisekstring;
	}
	short int AktSzerokoscTekst()const;
	void UstLiczbe(long int liczbaek)
	{
		dopisekliczba=liczbaek;
		uptekst();
	}
	void AktySpecDopisek(const sf::Font & czcionka=sf::Font::GetDefaultFont());
	void SetSpecDopiskFont(const sf::Font & czcionka);
	//void EdycjaUserLiczby() {EdycjaUserLiczby(-2147483646,2147483646);}
	void EdycjaUserLiczby(long int min,long int max,sf::Key::Code klaw);
	void EdycjaUserStringa(sf::Key::Code klaw,bool shift, int min=0, int max=20);
	void UstString(string stringek);
	void ZmianPoz(short int pozek);
	void UstTekst(string tekstek);
	void rysuj(sf::RenderWindow &App,bool wybre,int pozek);
	void rysuj(sf::RenderWindow &App,bool wybre);
	void rysuj(sf::RenderWindow &App,bool wybre,short int korekta);
private:
	int poz;
	int pozx;
	void uptekst();
	bool wybr;
	bool blok;
	bool srod;
	string tekst;
	long int dopisekliczba;
	string dopisekstring;
	sf::String TEKST;
	sf::String *dopisek_spec;
};

#endif // OPCJA_H
