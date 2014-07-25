#include "grafika/menu/menu_c.h"
int menu_przewijane::rysuj(sf::RenderWindow & App) const
{
	(*tytol).rysuj(App,true);
	int i=wybor;
	if(i>ilop-5)
	i=ilop-5;
	i-=4;
	if(i<0)
	i=0;
	int zmniej_wys=i*50;
	for (;i<ilop;i++)
	{
		(*wskaz[i]).rysuj(App,poczpoz+50*i-zmniej_wys);
	}
	return 0;
}
