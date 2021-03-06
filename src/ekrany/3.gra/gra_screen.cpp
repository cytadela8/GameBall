#include "gra_screen.h"

gra_screen::gra_screen(sf::RenderWindow &App,sf::Font & font)
{
	osttime=0;
	korektatime=0;
	zam=false;
	WspolTarciaGracz=0;
	WspolTarciaPilka=0;
	dan=0;
	pozres=false;
	lingran=0;
	pilka=0;
	slupek=0;
	gracz1_im=0;
	gracz2_im=0;
	gracz=0;
	boisko_im=0;
	wynl=0;
	wynp=0;
	bg=100;
	bd=500;
	bl=100;
	bp=700;
	bramka=100;
	gracze_ob=0;
	gracze_ev=0;
	obiekty=0;
	loaded=false;
	view=App.GetDefaultView();
	events=new EventComp;
	(*events).Set(sf::Event::KeyPressed,sf::Key::Escape);
	wynik_obl.SetFont(font);
	//wynik_obs.SetFont(font);
	wynik_obp.SetFont(font);
	Timer_ob1.SetFont(font);
	//Timer_ob2.SetFont(font);
	wynik_obl.SetSize(80);
	//wynik_obs.SetSize(80);
	wynik_obp.SetSize(80);
	wynik_obl.SetStyle(sf::String::Bold);
	//wynik_obs.SetStyle(sf::String::Bold);
	wynik_obp.SetStyle(sf::String::Bold);
	wynik_obl.SetText("0");
	//wynik_obs.SetText(":");
	wynik_obp.SetText("0");
	wynik_obl.SetPosition(App.GetWidth()/4,wynik_obl.GetRect().GetHeight()/2);
	//wynik_obs.SetPosition(App.GetWidth()/2-wynik_obs.GetRect().GetWidth()/2,0);
	wynik_obp.SetPosition(App.GetWidth()*3/4,wynik_obp.GetRect().GetHeight()/2);
	wynik_obl.SetColor(sf::Color(30,30,250));
	//wynik_obs.SetColor(sf::Color(250,30,30));
	wynik_obp.SetColor(sf::Color(30,250,30));
	wynik_obl.SetCenter(wynik_obl.GetRect().GetWidth()/2,wynik_obl.GetRect().GetHeight()/2);
	wynik_obp.SetCenter(wynik_obp.GetRect().GetWidth()/2,wynik_obp.GetRect().GetHeight()/2);
	Timer_ob1.SetSize(60);
	//Timer_ob2.SetSize(60);
	Timer_ob1.SetStyle(sf::String::Bold);
	//Timer_ob2.SetStyle(sf::String::Bold);
	Timer_ob1.SetText("00:00");
	//Timer_ob2.SetText("00:00");
	Timer_ob1.SetPosition(App.GetWidth()/2,wynik_obl.GetRect().GetHeight()/2);  // wynik_obl zastosowany umyslnie. aby byly wzglednie wysrodkowane.
	Timer_ob1.SetCenter(Timer_ob1.GetRect().GetWidth()/2,Timer_ob1.GetRect().GetHeight()/2);
	//Timer_ob2.SetPosition(App.GetWidth()-Timer_ob2.GetRect().GetWidth(),0);
	Techdata.SetPosition(10,App.GetHeight()-40);
}

gra_screen::~gra_screen()
{
	//dtor
}
int gra_screen::Load()
{
	czy=true;
	if (loaded==false)
	{
		loaded=true;
		cout << " Loading gra_screen \n";
		pilka=new sf::Image;
		slupek=new sf::Image;
		boisko_im=new sf::Image;
		gracz1_im=new sf::Image;
		gracz2_im=new sf::Image;
		kops_o=new sf::SoundBuffer;
		if (!(*pilka).LoadFromFile(files+"pilkanowa.png"))
		{
			cout << "Blad przy otwieraniu pliku!!! pilkanowa.png \n";
		}
		else if (!(*slupek).LoadFromFile(files+"slupek.png"))
		{
			cout << "Blad przy otwieraniu pliku!!! slupek.png \n";
		}
		else if (!(*gracz1_im).LoadFromFile(files+"gracz1.png"))
		{
			cout << "Blad przy otwieraniu pliku!!! gracz1.png \n";
		}
		else if (!(*gracz2_im).LoadFromFile(files+"gracz2.png"))
		{
			cout << "Blad przy otwieraniu pliku!!! gracz2.png \n";
		}
		else if (!(*boisko_im).LoadFromFile((string)(files+"boisko.png")))
		{
			cout << "Blad przy otwieraniu pliku!!! boisko.png \n";
		}
		else if (!(*kops_o).LoadFromFile((string)(files+"kicks2.wav")))
		{
			cout << "Blad przy otwieraniu pliku!!! kicks2.wav \n";
		}
		else
		{
			kops_p.SetBuffer(*kops_o);
			lingran=new sf::Shape [6];
			lingran[0]=sf::Shape::Line(bl-1,bg-1,bp+1,bg-1,1,sf::Color(255,255,255));
			lingran[1]=sf::Shape::Line(bl-1,bd+1,bp+1,bd+1,1,sf::Color(255,255,255));
			lingran[2]=sf::Shape::Line(bl-1,bg-1,bl-1,bg+(bd-bg)/2-51,1,sf::Color(255,255,255));
			lingran[3]=sf::Shape::Line(bl-1,bd+1,bl-1,bd-(bd-bg)/2+51,1,sf::Color(255,255,255));
			lingran[4]=sf::Shape::Line(bp+1,bg-1,bp+1,bg+(bd-bg)/2-51,1,sf::Color(255,255,255));
			lingran[5]=sf::Shape::Line(bp+1,bd+1,bp+1,bd-(bd-bg)/2+51,1,sf::Color(255,255,255));

			//trawa_t.Load(bg,bd,bl,bp,*trawa_im);
			boisko_sp.SetImage(*boisko_im);
			boisko_sp.SetPosition(0,0);

			obiekty=new kolo[7];
			obiekty_il=7;
			sf::Sprite spritek;
			//////////pilka
			spritek.SetImage(*pilka);
			spritek.SetPosition(400,300);
			spritek.SetScale(0.048,0.048);//0.02 - 5     x - 2   5x=0.04   x=0.008
			(obiekty+0)->Load(spritek,0,0,12,1,WspolTarciaPilka); //stare - 150
			pilka_ob=obiekty+0;
			//////////pacholki
			spritek.SetImage(*slupek);
			spritek.SetScale(0.04,0.04);
			spritek.SetPosition(bl-1,bg+(bd-bg)/2-51);
			(obiekty+1)->Load(spritek,0,0,10,5,1);
			(obiekty+1)->setstat(true);
			spritek.SetPosition(bl-1,bd-(bd-bg)/2+51);
			(obiekty+2)->Load(spritek,0,0,10,5,1);
			(obiekty+2)->setstat(true);
			spritek.SetPosition(bp+1,bg+(bd-bg)/2-51);
			(obiekty+3)->Load(spritek,0,0,10,5,1);
			(obiekty+3)->setstat(true);
			spritek.SetPosition(bp+1,bd-(bd-bg)/2+51);
			(obiekty+4)->Load(spritek,0,0,10,5,1);
			(obiekty+4)->setstat(true);
			///////////gracze
			spritek.SetImage(*gracz1_im);
			spritek.SetScale(0.06,0.06);
			spritek.SetPosition(600,300);
			(obiekty+5)->Load(spritek,0,0,15,10,WspolTarciaGracz);
			spritek.SetImage(*gracz2_im);
			spritek.SetPosition(200,300);
			(obiekty+6)->Load(spritek,0,0,15,10,WspolTarciaGracz);
			gracze_ob=obiekty+5;
			gracz_il=2;
			gracze_ev=new  KeyComp * [gracz_il];
			for (int i=0; i<gracz_il; i++)
			{
				(*(gracze_ev+i))=new KeyComp[(int)Licz];
			}
			gracze_ev[0][(int)Gora].Set(sf::Key::Up);
			gracze_ev[0][(int)Dol].Set(sf::Key::Down);
			gracze_ev[0][(int)Lewo].Set(sf::Key::Left);
			gracze_ev[0][(int)Prawo].Set(sf::Key::Right);
			gracze_ev[0][(int)Uderz].Set(sf::Key::Return);
			gracze_ev[1][(int)Gora].Set(sf::Key::W);
			gracze_ev[1][(int)Dol].Set(sf::Key::S);
			gracze_ev[1][(int)Lewo].Set(sf::Key::A);
			gracze_ev[1][(int)Prawo].Set(sf::Key::D);
			gracze_ev[1][(int)Uderz].Set(sf::Key::Q);
			GraczPowLock=new bool[2];
			pilka_ob->setbram(true);
			Reseter();
		}
		if (dan==0)
		{
			int * tab=new int [2];
			tab[0]=0;
			tab[1]=0;
			Init((void *)(new init_form(tab,60*100000,100000,fizykopty,"gracz1.png","gracz2.png")));
		}

	}

	return 0;
}
int gra_screen::UnLoad()
{

	return 0;
}

void gra_screen::Init(void * wskaz)
{
	osttime=0;
	korektatime=0;
	zam=false;
	if (!loaded)
		Load();
	delete dan;
	dan=(init_form *)wskaz;
	Timer_c.Reset();
	Timer_ob1.SetText("00:00");
	wynik_obl.SetText("0");
	wynik_obp.SetText("0");
	wynl=0;
	wynp=0;
	PrzyspG=dan->fizyk.PrzyspG;
	PrzyspGKop=dan->fizyk.PrzyspGKop;
	MaxVGraczKop=dan->fizyk.MaxVGraczKop;
	MaxVGraczNorm=dan->fizyk.MaxVGraczNorm;
	MocKop=dan->fizyk.MocKop;
	WspolTarciaGracz=dan->fizyk.WspolTarciaGracz;
	WspolTarciaPilka=dan->fizyk.WspolTarciaPilka;
	ProgTarcia=dan->fizyk.ProgTarcia;
	pilka_ob->SetTarcie(WspolTarciaPilka);
	for (int i=0;i<2;i++)
	(gracze_ob+i)->SetTarcie(WspolTarciaGracz);
	if (!gracz1_im->LoadFromFile(files+dan->ag1))
	{
		cout << "Blad przy ladowaniu " << dan->ag1 << " z poziomu Init";
	}
	if (!gracz2_im->LoadFromFile(files+dan->ag2))
	{
		cout << "Blad przy ladowaniu " << dan->ag2 << " z poziomu Init";
	}
	Reseter();
}

SBI gra_screen::Draw(sf::RenderWindow &App)
{
	App.SetView(view);
	App.Draw(boisko_sp);
	App.Draw(wynik_obl);
	//App.Draw(wynik_obs);
	App.Draw(wynik_obp);
	App.Draw(Timer_ob1);
	//App.Draw(Timer_ob2);
	#ifndef Release
	App.Draw(Techdata);
	#endif
	//for (int i=0; i<6; i++)
	//	App.Draw(lingran[i]);
	for (int i=0; i<obiekty_il; i++)
	{
		(obiekty+i)->Draw(App);
	}
	return SBI();
}
SBI gra_screen::Animate(sf::RenderWindow &App)
{
	if (Timer_c.GetElapsedTime()-osttime-korektatime>1)
	{
		korektatime=Timer_c.GetElapsedTime()-osttime;
	}
	osttime=Timer_c.GetElapsedTime()-korektatime;
	for (int i=0;i<obiekty_il;i++)
	{
		(obiekty+i)->ZasTarcie(App.GetFrameTime(),ProgTarcia);
	}
	const sf::Input& Input = App.GetInput();
	if (Input.IsKeyDown(sf::Key::B))
	{
		for (int i=0;i<obiekty_il;i++)
		{
			(obiekty+i)->SetV(0,0);
		}
	}
	for (int i=0; i<gracz_il; i++)
	{
		bool cx=false;
		bool cy=false;
		int przyspGDoc;
		bool czyuderz=(Input.IsKeyDown(gracze_ev[i][(int)Uderz].KeyCode));
		if (czyuderz)
		przyspGDoc=PrzyspGKop;
		else
		przyspGDoc=PrzyspG;
		if (Input.IsKeyDown(gracze_ev[i][(int)Lewo].KeyCode))
		{
			gracze_ob[i].SetVX(gracze_ob[i].GetVX()-App.GetFrameTime()*przyspGDoc);
			cx=true;
		}
		if (Input.IsKeyDown(gracze_ev[i][(int)Prawo].KeyCode))
		{
			gracze_ob[i].SetVX(gracze_ob[i].GetVX()+App.GetFrameTime()*przyspGDoc);
			if (cx)
				cx=false;
			else
				cx=true;
		}
		if (Input.IsKeyDown(gracze_ev[i][(int)Gora].KeyCode))
		{
			gracze_ob[i].SetVY(gracze_ob[i].GetVY()-App.GetFrameTime()*przyspGDoc);
			cy=true;
		}

		if (Input.IsKeyDown(gracze_ev[i][(int)Dol].KeyCode))
		{
			gracze_ob[i].SetVY(gracze_ob[i].GetVY()+App.GetFrameTime()*przyspGDoc);
			if (cy)
				cy=false;
			else
				cy=true;
		}
		if (Input.IsKeyDown(gracze_ev[i][(int)Uderz].KeyCode))
		{
			if (GraczPowLock[i])
			gracze_ob[i].PopV(MaxVGraczNorm);
			else
			gracze_ob[i].PopV(MaxVGraczKop);
		}
		else
		{
			gracze_ob[i].PopV(MaxVGraczNorm);
			GraczPowLock[i]=false;
		}


	}

	/*for (int i=0; i<obiekty_il; i++)
	{
		(obiekty+i)->Animate(App.GetFrameTime(),bg,bd,bl,bp,bramka);
	}
	for (int i=0; i<obiekty_il-1; i++)
		for (int j=i+1; j<obiekty_il; j++)
			if (czy&&(obiekty+i)->ZderzenieAnaliz(App.GetFrameTime(),obiekty+j,bg,bd,bl,bp,bramka))
			{
				cout << "ZDERZENIE!!!";
				czy=true;
			}*/

	double anisum=0;
	double tmp;
	double mintmp=10000000;
	double mini;
	int dodnum1,dodnum2;
    int num1,num2;
	num1=0;
	while(num1!=-1)
	{
		num1=-1;
		num2=-1;
		mini=1000000;
		for (int i=0; i<obiekty_il-1; i++)
			for (int j=i+1; j<obiekty_il; j++)
			{
				tmp=(obiekty+i)->TZderzenia(obiekty+j);
				if (tmp<mintmp)
				{
					mintmp=tmp;
					dodnum1=i;
					dodnum2=j;
				}
				if (tmp<mini&&tmp<=App.GetFrameTime()-anisum)
				{
					cout << "tmp = " << tmp << endl;
					mini=tmp;
					num1=i;
					num2=j;
				}
			}
		mini-=0.000001;
		if (mini<0)
			mini=0;
		if (num1!=-1)
		{
			anisum+=mini;
			for (int i=0; i<obiekty_il; i++)
			{
				(obiekty+i)->Animate(mini,bg,bd,bl,bp,bramka);
			}
			cout << "Przeliczanie zderzenia: " << num1 << " i " << num2 << endl;
			double mocude;
			if (num1==0&&num2>=5&&Input.IsKeyDown(gracze_ev[num2-5][(int)Uderz].KeyCode)&&!GraczPowLock[num2-5])
			{
				mocude=(obiekty+num1)->PrzeliczZderzenie(obiekty+num2,MocKop);
				GraczPowLock[num2-5]=true;
			}
			else
			mocude=(obiekty+num1)->PrzeliczZderzenie(obiekty+num2);
			if (num1==0&&num2>=5)
			{
				if (mocude>10&&(kops_p.GetStatus()==sf::Sound::Stopped||kops_p.GetPlayingOffset()>0.2))
				{
					cout << "KOPNIECIE DZWIEK";
					kops_p.SetVolume(mocude/2);
					kops_p.Play();
				}
			}
		}
	}
	for (int i=0; i<obiekty_il; i++)
	{
		(obiekty+i)->Animate(App.GetFrameTime()-anisum,bg,bd,bl,bp,bramka);
	}
	string tmpek;
	if (mintmp<100000)
	{
		tmpek+="czas do zderzenia: ";
		tmpek+=DoubleToString(mintmp);
		tmpek+=" obiektu: ";
		tmpek+=IntToString(dodnum1);
		tmpek+=" z: ";
		tmpek+=IntToString(dodnum2);
	}
	else
	{
		tmpek="brak zderzen...";
	}
	Techdata.SetText(tmpek);
	string czas;
	if ((int)(Timer_c.GetElapsedTime()-korektatime)/60<10)
		czas+="0";
	czas+=IntToString((int)(Timer_c.GetElapsedTime()-korektatime)/60);
	czas+=":";
	if ((int)(Timer_c.GetElapsedTime()-korektatime)%60<10)
		czas+="0";
	czas+=IntToString((int)(Timer_c.GetElapsedTime()-korektatime)%60);
	Timer_ob1.SetText(czas);
	//Timer_ob2.SetText(czas);
	return SBI();
}
SBI gra_screen::Work()
{
	if (Timer_c.GetElapsedTime()-osttime-korektatime>1)
	{
		korektatime=Timer_c.GetElapsedTime()-osttime;
	}
	osttime=Timer_c.GetElapsedTime()-korektatime;
	if (pozres)
		Reseter();
	if (dan->wynmax>0&&(wynl>=dan->wynmax||wynp>=dan->wynmax))
		return SBI(true,0,Brak,(void *)(new menu_screen::init_form(true)),2);
	if (zam)
		return SBI(true,0,Brak,(void *)(new menu_screen::init_form(true)),2);
	pozres=false;

	if (pilka_ob->GetX()<bl)
	{
		pozres=true;
		wynp++;
		wynik_obp.SetText(IntToString(wynp));
		Gol_screen::init_form * wskaz;
		if (wynp>=dan->wynmax)
        wskaz=new Gol_screen::init_form(false,"zielony\nwygral!");
		else
		wskaz=new Gol_screen::init_form(false);
		return SBI(false,6,Interakcji,(void *)wskaz);
	}
	if (pilka_ob->GetX()>bp)
	{
		pozres=true;
		wynl++;
		wynik_obl.SetText(IntToString(wynl));
		Gol_screen::init_form * wskaz;
		if (wynl>=dan->wynmax)
		wskaz=new Gol_screen::init_form(true,"niebieski\nwygral!");
		else
		wskaz=new Gol_screen::init_form(true);
		return SBI(false,6,Interakcji,(void *)wskaz);
	}
	if (Timer_c.GetElapsedTime()-korektatime>=dan->czasmax)
	{
		if (wynl>wynp)
		{
			Gol_screen::init_form * wskaz=new Gol_screen::init_form(true,"niebieski\nwygral!",true);
			zam=true;
			return SBI(false,6,Interakcji,(void *)wskaz);
		}
		else if (wynl<wynp)
		{
			Gol_screen::init_form * wskaz=new Gol_screen::init_form(false,"zielony\nwygral!",true);
			zam=true;
			return SBI(false,6,Interakcji,(void *)wskaz);
		}
	}
	return SBI();
}
SBI gra_screen::EventProc(sf::Event event)
{
	if (*(events)==event)
		return SBI(true);
	return SBI();
}
void gra_screen::Reseter()
{
	pilka_ob->SetPos(400,300);
	pilka_ob->SetV(0,0);
	(gracze_ob+0)->SetPos(600,300);
	(gracze_ob+0)->SetV(0,0);
	(gracze_ob+0)->SetRotation(0);
	(gracze_ob+1)->SetPos(200,300);
	(gracze_ob+1)->SetV(0,0);
	(gracze_ob+1)->SetRotation(180);
}

