#ifndef DANA_H
#define DANA_H
#include "head.h"
class dana
{
	public:
	dana();
	dana(short int numek);
	virtual ~dana();
	virtual int zaladuj(fstream &plik)=0;
	virtual void zapisz(fstream &plik)=0;
	void SzybkiZapis(fstream &plik,int numek);
	//virtual typ const AktWartosc() {;}
	//virtual typ const AktWartosc(short int element) {;}
	virtual short int const AktWielkoscTab() const {}
	//virtual typ UstWartosc(typ tymek) {;}
	//virtual typ UstWartosc(typ tymek,short int element) {;}
	virtual operator int() const {;}
	virtual void operator = (int wyborek) {;}

	virtual operator string() const {;}
	virtual void operator = (string wyborek) {;}

	virtual dana & operator [] (int indexes) {;}
	private:
	short int num;
	protected:
	bool zmian;
};
#endif // DANA_H
