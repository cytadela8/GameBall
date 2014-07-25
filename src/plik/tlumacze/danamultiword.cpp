#include "danamultiword.h"

danamultiword::danamultiword(short int numek):dana(numek)
{
	//
}

danamultiword::~danamultiword()
{
	//
}


int danamultiword ::zaladuj(fstream &plik)
{
	zmian=false;
    string tym;
    string wyn="";
    plik>>tym;
    while (tym!="^^^"&&!plik.eof())
    {
        wyn+=tym;
        wyn+=" ";
        plik>>tym;
    }
    wyn.erase(wyn.size()-1);
    info=wyn;
	return 0;
}


void danamultiword::zapisz(fstream &plik)
{
	plik<<info<<" "<<"^^^"<<" ";
	zmian=false;
}


danamultiword::operator string() const
{
	return info;
}


void danamultiword::operator = (string wyborek)
{
	info=wyborek;
	zmian=true;
}
