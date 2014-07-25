#ifndef DANANORM_H
#define DANANORM_H
#include "plik/dana.h"
template < class typ >
class dananorm:public dana
{
	public:
	dananorm(short int numek);
	~dananorm();
	int zaladuj(fstream &plik);
	void zapisz(fstream &plik);
	operator typ() const;
	void operator = (typ wyborek);
	private:
	typ info;
};
template < class typ >
dananorm<typ>::dananorm(short int numek):dana(numek)
{

}
template < class typ >
dananorm<typ>::~dananorm()
{
	//dtor
}

template < class typ >
int dananorm <typ>::zaladuj(fstream &plik)
{
	zmian=false;
	if(plik>>info)
	return 0;
	else
	return 1;
}
template < class typ >
void dananorm <typ>::zapisz(fstream &plik)
{
	zmian=false;
	plik<<info<<" ";
}

template < class typ >
dananorm <typ>::operator typ() const
{
	return info;
}

template < class typ >
void dananorm <typ>::operator = (typ wyborek)
{
	info=wyborek;
	zmian=true;
}

#endif // DANANORM_H
