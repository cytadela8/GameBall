#include "tekstura.h"

tekstura::tekstura()
{
	//ctor
}
tekstura::tekstura(int gd, int dd, int ld, int pd,sf::Image & imaged)
{
	Load(gd,dd,ld,pd,imaged);
}

tekstura::~tekstura()
{
	//dtor
}
void tekstura::Load(int gd, int dd, int ld, int pd,sf::Image & imaged)
{
	g=gd;
	d=dd;
	l=ld;
	p=pd;
	wys=imaged.GetHeight();
	szer=imaged.GetWidth();
	sprit.SetImage(imaged);
}
void tekstura::Draw(sf::RenderWindow & App)
{
	int tszer;
	int twys;
	for (int x=l;x<p;x+=szer)
	for (int y=g;y<d;y+=wys)
	{
		sprit.SetPosition(x,y);
		if (x+szer>p)
		tszer=p-x;
		else
		tszer=szer;
		if (y+wys>d)
		twys=d-y;
		else
		twys=wys;
		sprit.SetSubRect(sf::IntRect(0,0,tszer,twys));
		App.Draw(sprit);
	}
}
