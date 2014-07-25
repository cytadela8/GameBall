#ifndef USEPLIK_H
#define USEPLIK_H
#include "head.h"
#include "plik/dana.h"
#include "plik/tlumacze/lista.h"
template <class nazwe>
class UsePlik
{
public:
	UsePlik(ZmianRodz danrodzek[],string sciezek,nazwe ildan=END);
	UsePlik();
	~UsePlik();
	//long int AktWartoscInt(int wyborek) {return (*dane[wyborek]).AktWartoscInt();}
	//void UstWartoscInt(int wyborek,long int wartosc) {(*dane[wyborek]).WczytajInt(wartosc);}
	void INIT(ZmianRodz danrodzek[],string sciezek,nazwe ildan=END);
	void DodajInt();
	void Zapis();
	void SzybkiZapis();
	//string const AktWartoscString(short int wyborek) {return (*dane[wyborek]).AktWartoscString();}
	//string const AktWartoscString(short int wyborek,short int element) const;
	short int const AktWielkoscTablicy(short int wyborek) const
	{
		return (*dane[wyborek]).AktWielkoscTab();
	}
	//void UstWartoscString(short int wyborek,string tymek) {(*dane[wyborek]).UstWartoscString(tymek);}
	void UstWartoscString(short int wyborek,short int element,string tymek);

	dana& operator [] (nazwe indeks);
private:
	ZmianRodz danrodz[100];
	dana * dane[100];
	string sciezka;
	int ildan;
};
template <class nazwe>
UsePlik<nazwe>::UsePlik()
{
	//ctor
}
template <class nazwe>
UsePlik<nazwe>::UsePlik(ZmianRodz danrodzek[],string sciezek,nazwe ildanek)
{
	INIT(danrodzek,sciezek,ildanek);
}

template <class nazwe>
UsePlik<nazwe>::~UsePlik()
{
	Zapis();
}
template <class nazwe>
void UsePlik<nazwe>::INIT(ZmianRodz danrodzek[],string sciezek,nazwe ildanek)
{
	int i;
	sciezka=sciezek;
	fstream *plik;
	ildan=(int)ildanek;
	plik=new fstream(sciezka.c_str(),ios::in);
	bool co=true;
	if(!((*plik).is_open()))
	{
		co=false;
		(*plik).close();
		delete plik;
		plik=new fstream(sciezka.c_str(),ios::out);
	}
	for(i=0; i<ildan; i++)
	{
		danrodz[i]=danrodzek[i];
		switch(danrodz[i])
		{
		case IntD:
			dane[i]=new dananorm<int>(i);
			break;
		case charD:
			dane[i]=new dananorm<char>(i);
			break;
		case StringD:
			dane[i]=new danamultiword(i);
			break;
		case TabStringD:
			dane[i]=new danatablica<danamultiword>(i);
			break;
		}
		if(co)
			(*dane[i]).zaladuj(*plik);
		else
			(*dane[i]).zapisz(*plik);
	}
	short int tym=-1;
	if(co)
		while (!(*plik).eof())
		{
			(*plik)>>tym;
			if(tym>0&&tym<100)
				(*dane[tym]).zaladuj(*plik);
		}
	(*plik).close();
	for(; i<100; i++)
		dane[i]=0;

}
template <class nazwe>
void UsePlik<nazwe>::Zapis()
{
	fstream plik(sciezka.c_str(),ios::out);
	for(int i=0; i<ildan; i++)
		(*dane[i]).zapisz(plik);
	plik.close();
}
template <class nazwe>
dana& UsePlik<nazwe>::operator [] (nazwe indeks)
{
	if((int)indeks>=0&&(int)indeks<ildan)
		return (*dane[(int)indeks]);
	danamultiword zwrot(1);
	zwrot="ERROR!";
	return zwrot;
}
#endif // USEPLIK_H
