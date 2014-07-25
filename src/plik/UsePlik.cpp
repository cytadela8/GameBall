#include "UsePlik.h"


template <class nazwe>
void UsePlik<nazwe>::DodajInt()
{
	dane[ildan]=new dananorm<int>(ildan);
	ildan++;
}

template <class nazwe>
void UsePlik<nazwe>::SzybkiZapis()
{
	fstream * plik;
	plik=new fstream(sciezka.c_str(),ios::app);
	for(int i=0;i<ildan;i++)
	(*dane[i]).SzybkiZapis(*plik,i);
	(*plik).close();
}
/*template <class nazwe>
const string UsePlik<nazwe>::  AktWartoscString(short int wyborek,short int element) const
{
	return (*dane[wyborek]).AktWartoscString(element);
}*/

template <class nazwe>
void UsePlik<nazwe>::UstWartoscString(short int wyborek,short int element,string tymek)
{
	(*dane[wyborek])[element]=tymek;
}

