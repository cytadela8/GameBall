#ifndef FIZYKCONT_H_INCLUDED
#define FIZYKCONT_H_INCLUDED

class fizykcont
{
public:
fizykcont(){}
fizykcont(double PrzyspGd,
double PrzyspGKopd,
double MaxVGraczKopd,
double MaxVGraczNormd,
double MocKopd,
double WspolTarciaGraczd,
double WspolTarciaPilkad,
double ProgTarciad)
{
	PrzyspG=PrzyspGd;
	PrzyspGKop=PrzyspGKopd;
	MaxVGraczKop=MaxVGraczKopd;
	MaxVGraczNorm=MaxVGraczNormd;
	MocKop=MocKopd;
	WspolTarciaGracz=WspolTarciaGraczd;
	WspolTarciaPilka=WspolTarciaPilkad;
	ProgTarcia=ProgTarciad;
}
fizykcont(int PrzyspGd,
int PrzyspGKopd,
int MaxVGraczKopd,
int MaxVGraczNormd,
int MocKopd,
int WspolTarciaGraczd,
int WspolTarciaPilkad,
int ProgTarciad)
{
	PrzyspG=PrzyspGd;
	PrzyspGKop=PrzyspGKopd;
	MaxVGraczKop=MaxVGraczKopd;
	MaxVGraczNorm=MaxVGraczNormd;
	MocKop=MocKopd;
	WspolTarciaGracz=WspolTarciaGraczd;
	WspolTarciaPilka=WspolTarciaPilkad;
	ProgTarcia=ProgTarciad;
}
void Load(int PrzyspGd,
int PrzyspGKopd,
int MaxVGraczKopd,
int MaxVGraczNormd,
int MocKopd,
int WspolTarciaGraczd,
int WspolTarciaPilkad,
int ProgTarciad)
{
	PrzyspG=PrzyspGd;
	PrzyspGKop=PrzyspGKopd;
	MaxVGraczKop=MaxVGraczKopd;
	MaxVGraczNorm=MaxVGraczNormd;
	MocKop=MocKopd;
	WspolTarciaGracz=WspolTarciaGraczd;
	WspolTarciaPilka=WspolTarciaPilkad;
	ProgTarcia=ProgTarciad;
}
double PrzyspG;
	double PrzyspGKop;
	double MaxVGraczKop;
	double MaxVGraczNorm;
	double MocKop;
	double WspolTarciaGracz;
	double WspolTarciaPilka;
	double ProgTarcia;
};

#endif // FIZYKCONT_H_INCLUDED
