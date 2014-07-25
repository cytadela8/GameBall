#include "screen_p.h"

screen_p::screen_p()
{
	//ctor
}

screen_p::~screen_p()
{
	//dtor
}

SBI screen_p::LoadAndDraw(sf::RenderWindow &App)
{
	if (!loaded)
	{
		Load();
		loaded=true;
	}


	return Draw(App);
}
SBI screen_p::EventProc(sf::Event event)
{
	return SBI();
}
void screen_p::Init(void * wskaz)
{
	;
}
