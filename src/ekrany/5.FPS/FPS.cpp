#include "FPS.h"

FPS::FPS()
{
	licz=0;
	zegar.Reset();
	events=new EventComp;
    (*events).Set(sf::Event::KeyPressed,sf::Key::Escape);
    tekst.SetText("Hello");
    tekst.SetSize(50);
    tekst.SetFont(sf::Font::GetDefaultFont());
}

FPS::~FPS()
{
	//dtor
}
int FPS::Load()
{

	return 0;
}
int FPS::UnLoad()
{

	return 0;
}
SBI FPS::Draw(sf::RenderWindow & App)
{
	App.SetView(App.GetDefaultView());
	App.Draw(tekst);
	return SBI();
}
SBI FPS::Animate(sf::RenderWindow & App)
{
	licz++;
	if (zegar.GetElapsedTime()>=1)
	{
		int FPS=licz/zegar.GetElapsedTime();
		tekst.SetText("FPS: "+IntToString(FPS));
		licz=0;
		zegar.Reset();
	}
	return SBI();
}
SBI FPS::Work()
{

	return SBI();
}
SBI FPS::EventProc(sf::Event event)
{
	if (*(events)==event)
        return SBI(true);
    return SBI();
}
std::string FPS::IntToString(int d)
{
   std::stringstream ss;
   ss << d;
   return ss.str();
}
