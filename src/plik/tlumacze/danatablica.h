#ifndef DANATABLICA_H
#define DANATABLICA_H
#include "plik/dana.h"
#include "plik/tlumacze/dananorm.h"

template <class typ>
class danatablica:public dana
{
	public:
	danatablica(short int numek);
	~danatablica();
	typ const AktWartosc(short int element) const;
	void UstWartosc (typ tymek,short int element);
	short int const AktWielkoscTab() const;
	dana & operator [] (int indexes) {return *wskaz[indexes];}
	void zapisz(fstream &plik);
	int zaladuj(fstream &plik);
	private:
	dananorm <int> *ilel;
	typ *wskaz[50];
	short int ostzapis_danil;
};
template <class typ>
danatablica<typ>::danatablica(short int numek):dana(numek)
{
	for (int i=0;i<50;i++)
	wskaz[i]=0;
	ilel=new dananorm<int>(0);
	ostzapis_danil=0;
}
template <class typ>
danatablica<typ>::~danatablica()
{
	//dtor
}

template <class typ>
int danatablica <typ>::zaladuj(fstream &plik)
{
	zmian=false;
	(*ilel).zaladuj(plik);
	short int ilelek=(*ilel);
	ostzapis_danil=ilelek;
	for (short int i=0;i<ilelek;i++)
	{
		wskaz[i]=new typ(i+1);
		(*wskaz[i]).zaladuj(plik);
	}
}
template <class typ>
void danatablica<typ>::zapisz(fstream &plik)
{
	zmian=false;
	short int ilelek=(*ilel);
	(*ilel).zapisz(plik);
	for (short int i=0;i<ostzapis_danil;i++)
	{
		(*wskaz[i]).zapisz(plik);
	}
	for (short int i=ostzapis_danil;i<ilelek;i++)
	{
		wskaz[i]=new typ(i+1);
		(*wskaz[i]).zapisz(plik);
	}
	ostzapis_danil=ilelek;
}

template <class typ>
typ const danatablica<typ>::AktWartosc (short int element) const
{
	return (*wskaz[element]);
}
template <class typ>
void danatablica<typ>::UstWartosc (typ tymek,short int element)
{
	(*wskaz[element])=tymek;
	zmian=true;
}
template <class typ>
short int const danatablica<typ>::AktWielkoscTab() const
{
	return (short int)(*ilel);
}

#endif // DANATABLICA_H
