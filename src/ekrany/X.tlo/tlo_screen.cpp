#include "tlo_screen.h"

tlo_screen::tlo_screen()
{
	loaded=false;
	//ctor
}

tlo_screen::~tlo_screen()
{
	//dtor
}

int tlo_screen::Load()
{
	if (!loaded)
	{
		loaded=true;
		if (trawa_i.LoadFromFile(files+"tlo.jpg"))
    {
        trawa_t.Load(0,1000,0,1000,trawa_i);
    }
    else
    {
        cout << "Load tlo.jpg error";
    }
	}

	return 0;
}
int tlo_screen::UnLoad()
{

	return 0;
}
SBI tlo_screen::Draw(sf::RenderWindow & App)
{
    App.SetView(App.GetDefaultView());
    trawa_t.Draw(App);
	return SBI();
}
SBI tlo_screen::Animate(sf::RenderWindow & App)
{

	return SBI();
}
SBI tlo_screen::Work()
{

	return SBI();
}
