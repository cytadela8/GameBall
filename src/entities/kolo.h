#ifndef KOLO_H
#define KOLO_H
#include "head.h"
#include <cmath>
#include <iostream>
class kolo
{
public:
    kolo(sf::Sprite spritekx,double vxx,double vyx,int rx,int mx,double maxv, double WspolTarD);
    kolo();
    ~kolo();
    bool Load(sf::Sprite spritekx,double vxx,double vyx,int rx,int mx, double WspolTarD);
    bool ZderzenieAnaliz(double ftime,kolo * obiekt2,int & bg,int & bd,int & bl,int & bp,int & bram);
    void Draw(sf::RenderWindow &App);
    virtual void Animate(double ftime,int & bg,int & bd,int & bl,int & bp,int & bram);
    double GetX();
    double GetY();
    void SetTarcie(double tarcied);
    void SetX(double xe);
    void SetY(double ye);
    void SetPos(double xe, double ye);
    void SetRotation(int rot);
    double GetVX();
    double GetVY();
    void SetVX(double danvx);
    void SetVY(double danvy);
    void SetV(double danvx,double danvy);
    int GetR();
    int GetM();
    void setbram(bool bramkad);
    bool GetStat();
    void setstat(bool statek);
    void PopV(double vmax);
    long double TZderzenia(kolo * o2);
    double TZderzenieScian();
    double PrzeliczZderzenie(kolo * obiekt2,double addpow=0);
    void ZasTarcie(double ftime,double prog=-1);
    //void PopVc();
    //void PopVx();
    //void PopVy();
protected:
    double vx;
    double vy;
private:
    double todod(double dan);
    sf::Sprite spritek;
    int r;
    int m;
    bool bramka;
    bool stat;
    double WspolTar;
    bool ingol;
};

#endif // KOLO_H
