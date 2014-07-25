#include "plik/dana.h"

dana::dana()
{
	num=0;
	zmian=false;
}

dana::dana(short int numek)
{
	num=numek;
	zmian=false;
}
dana::~dana()
{
	;
}

void dana::SzybkiZapis(fstream &plik,int numek)
{
	if(zmian)
	{
		plik <<numek<< " ";
		zapisz(plik);
	}
}
