#include "SBI.h"

SBI::SBI(bool dzamknac,int dOtworzyc,PPrzeslony dprzeslona,void * dwskaz,int celinitd)
{
	zamknac=dzamknac;
	Otworzyc=dOtworzyc;
	przeslona=dprzeslona;
	wskaz=dwskaz;
	if (celinitd==0)
	celinit=dOtworzyc;
	else
	celinit=celinitd;
}

SBI::~SBI()
{
	//dtor
}
