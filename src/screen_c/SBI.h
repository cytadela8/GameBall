#ifndef SBI_H
#define SBI_H

enum PPrzeslony{Brak=0,Interakcji=1,Animacji=2,Szara=3,Tlo=4};

class SBI //Screen Back Info
{
	public:
	SBI(bool dzamknac=false,int dOtworzyc=0,PPrzeslony dprzeslona=Brak,void * dwskaz=0,int celinitd=0);
	~SBI();
	bool zamknac;
	int Otworzyc;
	PPrzeslony przeslona;
	void * wskaz;
	int celinit;
};

#endif // SBI_H
