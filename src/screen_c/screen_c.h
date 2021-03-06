#ifndef SCREEN_C_H_INCLUDED
#define SCREEN_C_H_INCLUDED
#include "head.h"
#include "screen_c/screen_p.h"
#include "ekrany/lista.h"
class eleinfo
{
	public:
	eleinfo();
	eleinfo(int dnum,PPrzeslony dprz=Brak);
	operator int();
	operator PPrzeslony();
	void operator = (int dnum);
	void operator = (PPrzeslony dprz);
	int num;
	PPrzeslony prz;
};
class screen_c
{
public:
    screen_c();
    screen_c(int ilD,screen_p * ekrwskazD [],screen_p *tloD);
    ~screen_c();
    int Load(int ilD,screen_p *ekrwskazD [],screen_p *tloD);
    int Render(sf::RenderWindow &App);
    int Acctive(int num,PPrzeslony przeslona=Brak);
    //int Kill (int num);
    //int KillFront ();
private:
	void SBIproc(SBI sbi,int & i);
	bool loaded;
    int il;
    screen_p ** wskaz;
    screen_p * tlo;
    vector <eleinfo> stos;
    int GTlo;
    int GSzara;
    int GAnimacji;
    int GInterakcji;
};

#endif // SCREEN_C_H_INCLUDED
