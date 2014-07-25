#include "Gol.h"

Gol_screen::Gol_screen(sf::RenderWindow & App,sf::Font &font)
{
	dan=0;
	faza=0;
	gol_ob.SetFont(font);
	win_ob.SetFont(font);
	gol_ob.SetText("GOL!");
	gol_ob.SetSize(0);
	gol_ob.SetCenter(gol_ob.GetRect().GetWidth()/2,gol_ob.GetRect().GetHeight()/2);
    win_ob.SetCenter(win_ob.GetRect().GetWidth()/2,0);
	pozx=App.GetWidth()/2;
	pozy=App.GetHeight()/2;
	gol_ob.SetPosition(pozx,pozy);
	win_ob.SetPosition(pozx,pozy+200);
	loaded=false;
}

Gol_screen::~Gol_screen()
{
	//dtor
}
int Gol_screen::Load()
{
	if (!loaded)
	{
		loaded=true;
		gol_b=new sf::SoundBuffer;
		czas_b=new sf::SoundBuffer;
		if (!gol_b->LoadFromFile(files+"gol.wav"))
		{
			cout << "Nie moge otworzyc pliku gol.wav";
		}
		if (!czas_b->LoadFromFile(files+"matchend.wav"))
		{
			cout << "Nie moge otworzyc pliku matchend.wav";
		}
		gol.SetBuffer(*gol_b);
		czas.SetBuffer(*czas_b);
	}
	return 0;
}
int Gol_screen::UnLoad()
{

	return 0;
}
void Gol_screen::Init(void* wskaz)
{
	if (!loaded)
		Load();
	delete dan;
	gol_ob.SetText("GOL!");
	dan=(init_form *)wskaz;
	if (dan->Pstrone)
	{
	    gol_ob.SetColor(sf::Color(30,30,250));
        win_ob.SetColor(sf::Color(30,30,250));
	}
	else
	{
	    gol_ob.SetColor(sf::Color(30,250,30));
        win_ob.SetColor(sf::Color(30,250,30));
	}
	win_ob.SetSize(1000);
	win_ob.SetText(dan->win);
	if (dan->czas)
	gol_ob.SetText("CZAS");
	if (dan->czas)
		czas.Play();
	else
		gol.Play();
}
SBI Gol_screen::Draw(sf::RenderWindow & App)
{
	App.Draw(gol_ob);
	if (dan->win!=""&&faza>=2)
	App.Draw(win_ob);
	return SBI();
}
SBI Gol_screen::Animate(sf::RenderWindow & App)
{
	switch(faza)
	{
	case 0:
		gol_ob.Rotate(3*360*App.GetFrameTime());
		gol_ob.SetSize(gol_ob.GetSize()+App.GetFrameTime()*50);
		gol_ob.SetCenter(gol_ob.GetRect().GetWidth()/2,gol_ob.GetRect().GetHeight()/2);
	    //win_ob.SetCenter(win_ob.GetRect().GetWidth()/2,win_ob.GetRect().GetHeight()/2);
		//gol_ob.SetPosition(pozx-gol_ob.GetRect().GetWidth()/2 ,pozy-gol_ob.GetRect().GetHeight()/2);
		if (gol_ob.GetSize()>=100)
		{
			gol_ob.SetSize(100);
			gol_ob.SetRotation(0);
			if (dan->win=="")
			faza=1;
			else
			faza=2;
			zegar.Reset();
		}
		break;
	case 1:
		if (zegar.GetElapsedTime()>3)
		faza=4;
		break;
    case 2:
        win_ob.SetSize(win_ob.GetSize()-App.GetFrameTime()*500);
   	    win_ob.SetCenter(win_ob.GetRect().GetWidth()/2,win_ob.GetRect().GetHeight()/2);
        if(win_ob.GetSize()<=100)
        {
   			win_ob.SetSize(100);
            faza=3;
            zegar.Reset();
        }
        break;
	case 3:
	{
	    if (zegar.GetElapsedTime()>5)
		faza=4;
		break;
	}
	case 4:
		gol_ob.Rotate(-3*360*App.GetFrameTime());
		gol_ob.SetSize(gol_ob.GetSize()-App.GetFrameTime()*50);
		win_ob.SetSize(win_ob.GetSize()-App.GetFrameTime()*50);
		gol_ob.SetCenter(gol_ob.GetRect().GetWidth()/2,gol_ob.GetRect().GetHeight()/2);
		win_ob.SetCenter(win_ob.GetRect().GetWidth()/2,win_ob.GetRect().GetHeight()/2);
		//gol_ob.SetPosition(pozx-gol_ob.GetRect().GetWidth()/2 ,pozy-gol_ob.GetRect().GetHeight()/2);
		if (gol_ob.GetSize()<=0)
		{
			gol_ob.SetSize(0);
			gol_ob.SetRotation(0);
			faza=0;
			return SBI(true);
		}
		break;
	}
	return SBI();
}
SBI Gol_screen::Work()
{
	return SBI();
}
SBI Gol_screen::EventProc(sf::Event event)
{
	return SBI();
}
