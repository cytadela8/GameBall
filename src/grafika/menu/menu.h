#ifndef MENU_H
#define MENU_H
#include<head.h>
#include<grafika/menu/opcja.h>

class menu
{
public:
	menu(sf::Font & fontek,string const tab[],unsigned short int ilopek,short int poczpoz,string const & tytol,short int pozxek=0);
	~menu();
	short int GetPozX();
	virtual int rysuj(sf::RenderWindow & App) const;
	virtual int rysuj(sf::RenderWindow & App,short int przesow) const;
	opcja& operator [] (int indeks);
	unsigned short int AktOpcja() const;
	virtual void UstOpcjeMysz(short int myszx,short int myszy);
	void AktualizujPoz();

	//void OpcjaBlokuj(short int wyborek) {(*wskaz[wyborek]).blokuj();}
	//void OpcjaOdblokuj(short int wyborek) {(*wskaz[wyborek]).odblokuj();}
	void OpcjaUstString(short int wyborek,string stringek);
	int OpcjaAktLiczba(short int wyborek)const;
	string OpcjaAktString(short int wyborek)const;
	void UstOpcje(short int wyborek);
protected:
	short int wybor,ilop,poczpoz,pozx;
	opcja * wskaz[21];
	opcja * tytol;
};

#endif // MENU_H
