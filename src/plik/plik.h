#ifndef PLIK_H_INCLUDED
#define PLIK_H_INCLUDED
#include <fstream>
#include <vector>
#include "plik/dana.h"
#include "plik/tlumacze/lista.h"
#include "plik/UsePlik.h"
/*class Bloki_tab
{
	public:
	Bloki_tab() {zmian=false;}
	void Generuj(short int &wiel) {tab=new Bloki[wiel];}
	~Bloki_tab() {delete tab;}
	Bloki& operator[] (int indexes) {return *(tab+indexes);}
	Bloki& operator[] (int indexes) const {return *(tab+indexes);}
	void UstFalseZmiana() {zmian=false;}
	bool& AktZmian() {return zmian;}
	private:
	Bloki* tab;
	bool zmian;
};*/

/*class danamapa:public dana
{
	public:
	danamapa(short int numek):dana(numek){tab=0;}
	~danamapa(){;}
	Entitie* DostepDoEntity(short int wyborek) {return &(Entities[wyborek]);wielx=0;wiely=0;}
	Bloki_tab* DostepDoTablicy(){return tab;}
	short int AktWielX(){return wielx;}
	short int AktWielY(){return wiely;}
	void zapisz(fstream &plik);
	int zaladuj(fstream &plik);
	Bloki_tab& operator [] (int indexes) {return *(tab+indexes);}
	private:
	Bloki_tab *tab;
	short int wielx;
	short int wiely;
	vector <Entitie> Entities;
};
int danamapa::zaladuj(fstream &plik)
{
	zmian=false;
	delete tab;
	wielx=0;
	wiely=0;
	plik >> wielx;
	plik >> wiely;
	tab=new Bloki_tab[wielx];
	for (int i=0;i<wielx;i++)
	{
		(*(tab+i)).Generuj(wiely);
		for (int j=0;j<wiely;j++)
		{
			(*(tab+i))[j]=(Bloki)plik.get();
		}
		(*(tab+i)).UstFalseZmiana();
	}

	short int tym=0;
	plik >> tym;
	Entities.resize(tym);
	for (int i=0;i<tym;i++)
	{

	}
	return 0;
}
void danamapa::zapisz(fstream &plik)
{
	zmian=false;
	plik <<wielx << " " << wiely << " ";
	for (int i=0;i<wielx;i++)
	for (int j=0;j<wiely;j++)
	{
		plik << (*(tab+i))[j] << " ";
	}
	plik << Entities.size() << " ";
	for (int i=0;i<Entities.size();i++)
	{

	}
}
*/

#endif // PLIK_H_INCLUDED
