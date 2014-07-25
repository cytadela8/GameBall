#include "intro_screen.h"

intro_screen::intro_screen(sf::RenderWindow & App)
{
    faza=0;
	loaded=false;
	logo_s.SetPosition(20,20);
	logo_i=0;
	string wersjak="Wersja ";
	wersjak+=AutoVersion::FULLVERSION_STRING;
	wersjak+=" - ";
	wersjak+=AutoVersion::STATUS;
	wersja.SetText(wersjak);
	wersja.SetSize(30);
	wersja.SetFont(sf::Font::GetDefaultFont());
	wersja.SetPosition(50,450);
	logo_s.SetScale(5,5);
	logo_s.SetPosition(App.GetWidth()/2,App.GetHeight()/2);

	zegar.Reset();
}

intro_screen::~intro_screen()
{

	UnLoad();
}
int intro_screen::Load()
{
	if (loaded==false)
	{
		logo_i=new sf::Image;
		string tmp=files+"C8.png";
		if (!(*logo_i).LoadFromFile(tmp))
			return 1;
		else
		{
			logo_s.SetImage(*logo_i);
			logo_s.Resize(860,500);
			logo_s.SetCenter(logo_s.GetSubRect().GetWidth()/2,logo_s.GetSubRect().GetHeight()/2);
			logo_s.SetScale(5,5);
			loaded=true;
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
int intro_screen::UnLoad()
{
	loaded=false;
	delete logo_i;
	logo_i=0;
	return 0;
}
SBI intro_screen::Draw(sf::RenderWindow &App)
{
	App.SetView(App.GetDefaultView());
	App.Draw(logo_s);
	App.Draw(wersja);
	return SBI();
}
SBI intro_screen::Animate(sf::RenderWindow &App)
{
	switch (faza)
	{
	case 0:
		logo_s.SetCenter(logo_s.GetSubRect().GetWidth()/2,logo_s.GetSubRect().GetHeight()/2);

		logo_s.Rotate(5*360*App.GetFrameTime());
		logo_s.SetScale(logo_s.GetScale().x-5*App.GetFrameTime(),logo_s.GetScale().x-5*App.GetFrameTime());
		if (logo_s.GetScale().x<=1)
		{
			logo_s.SetRotation(0);
			logo_s.SetScale(1,1);
			faza=1;
			zegar.Reset();
		}
		break;
	case 1:
		if (zegar.GetElapsedTime()>=5)
		{
		    logo_s.SetRotation(0);
			logo_s.SetScale(5,5);
			return SBI(true,2);
		}
		break;
	}
	return SBI();
}
SBI intro_screen::Work()
{
	return SBI();
}
