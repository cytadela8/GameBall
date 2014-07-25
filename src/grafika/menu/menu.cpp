#include "menu.h"
#include <iostream>
menu::menu(sf::Font & fontek,string const tab[],unsigned short int ilopek,short int poczpozek,string const & tytolek,short int pozxek)
{
	wybor=0;
	pozx=pozxek;
	ilop=ilopek;
	if (poczpozek==-1)
	poczpoz=0-ilop/2.0*50+30;
	else
	{
	    poczpoz=poczpozek;
        poczpoz+=60;
	}
	//cout << "poczpoz: " << poczpoz << " ";
	for (int i=0;i<20;i++)
	wskaz[i]=0;
	for (unsigned short int i=0,j=poczpoz;i<ilop;i++,j+=50)
	{
		wskaz[i]=new opcja(fontek,tab[i],j,pozx);
	}
	//if (ilop>0) (*wskaz[0]).zaznacz();
	tytol=new opcja(fontek,tytolek,poczpoz-60,pozx);
	// (*tytol).zaznacz();
}
menu::~menu()
{
	delete tytol;
	for (int i=0;i<ilop;i++)
	delete wskaz[i];
}
short int menu::GetPozX()
	{
		return pozx;
	}
	int menu::rysuj(sf::RenderWindow & App) const
	{
		return rysuj(App,(short int)0);
	}
int menu::rysuj(sf::RenderWindow & App,short int przesow) const
{
	(*tytol).rysuj(App,true,przesow);
	//cout << "narysowalem tytol";
	//int tmp;
	//cin >> tmp;
	for (int i=0;i<ilop;i++)
	{
	    if (wybor==i)
		(*wskaz[i]).rysuj(App,true,przesow);
		else
		(*wskaz[i]).rysuj(App,false,przesow);
	}

	return 0;
}
opcja & menu::operator [] (int indeks)
{
	if (indeks<ilop&&indeks>=0)
	return *wskaz[indeks];
	else
	return *wskaz[ilop-1];
}
unsigned short int menu::AktOpcja() const
{
	return wybor;
}
void menu::UstOpcjeMysz(short int myszx,short int myszy)
{
	short int wyborek=(myszy-poczpoz)/50;
	if (wyborek>=0&&wyborek<ilop&&0/2-((*wskaz[wyborek]).AktSzerokoscTekst())/2<myszx-pozx&&0/2+((*wskaz[wyborek]).AktSzerokoscTekst())/2>myszx-pozx)
	{
		wybor=wyborek;
	}
}
void menu::AktualizujPoz()
{
    unsigned short int tympoczpoz=0/2-ilop/2*50+30; //+30, bo tytol (tytolwys=60)
    if(tympoczpoz!=poczpoz)
    {
        poczpoz=tympoczpoz;
        (*tytol).ZmianPoz(poczpoz-60);
        for (unsigned short int i=0;i<ilop;i++)
        (*wskaz[i]).ZmianPoz(poczpoz+50*i);
    }
}
void menu::OpcjaUstString(short int wyborek,string stringek)
	{
		(*wskaz[wyborek]).UstString(stringek);
	}
	int menu::OpcjaAktLiczba(short int wyborek)const
	{
		return (*wskaz[wyborek]).AktLiczba();
	}
	string menu::OpcjaAktString(short int wyborek)const
	{
		return (*wskaz[wyborek]).AktString();
	}
	void menu::UstOpcje(short int wyborek)
	{
		//cout << " akt: " <<  wybor << " dan: " << wyborek;
		if(ilop>0)
		{
			if (wyborek<0)
				wyborek=ilop-1;
			if (wyborek>ilop-1)
				wyborek=0;

			wybor=wyborek;

		}
		//cout << " now: " << wybor;
	}
