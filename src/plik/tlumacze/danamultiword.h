#ifndef DANAMULTIWORD_H
#define DANAMULTIWORD_H
#include "plik/dana.h"

class danamultiword:public dana
{
    public:
    danamultiword(short int numek);
    ~danamultiword();
    int zaladuj(fstream &plik);
	void zapisz(fstream &plik);

	//void UstString(string tymek){info=tymek;zmian=true;}
	//string const AktWartoscString() {return info;}
	operator string() const;
	void operator = (string wyborek);
    private:
    string info;
};

#endif // DANAMULTIWORD_H
