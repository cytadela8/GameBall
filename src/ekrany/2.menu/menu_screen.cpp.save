#include "menu_screen.h"

menu_screen::menu_screen(UsePlik<PD> & danek,sf::RenderWindow & App)
{
	dan=0;
	dane=&danek;
	view.SetFromRect(sf::FloatRect((int)App.GetWidth()/2*-1,(int)App.GetHeight()/2*-1,(int)App.GetWidth()/2,(int)App.GetHeight()/2));
	Appek=&App;
	Load();
}

menu_screen::~menu_screen()
{
	//dtor
}
int menu_screen::Load()
{
	prz=view.GetHalfSize().x*2;
	string tmp=files;
	tmp+="font.ttf";
	if (!font.LoadFromFile(tmp,45))
		cout << "BLAD LADOWANIA CZCIONKI PODSTAWOWEJ!!!";
    tmp=files;
    tmp+="klawfont.ttf";
    if (!klawfont.LoadFromFile(tmp,45))
		cout << "BLAD LADOWANIA CZCIONKI DLA KLAWISZY!!!";
		else
		cout << " czcionke dla klawiszy zaladowano... ";
	tmp=files;
    tmp+="klawfont2.ttf";
    if (!klawfont2.LoadFromFile(tmp,45))
		cout << "BLAD LADOWANIA CZCIONKI DLA KLAWISZY2!!!";
		else
		cout << " czcionke dla klawiszy2 zaladowano... ";
	logo_im=new sf::Image;
	if (!(*logo_im).LoadFromFile((files+"logogameball.png")))
	{
		cout << "Blad przy ladowaniu loga logogameball.png";
	}
	logo_sp.SetImage(*logo_im);
	logo_sp.SetCenter(logo_sp.GetSubRect().GetWidth()/2,0);
	Appek->SetView(view);
	logo_sp.SetPosition(0,(int)20-(int)(Appek->GetHeight()/2));
	mena=new menu* [(int)Ilosc];
	const string menu_glowne[]= {"Szybka gra","Nowa gra","Ustawienia","Wyjscie"};
	const string menu_nowa_gra[]= {"fizyka","czas","punkty","rozpocznij","wstecz"};
	const string menu_fizyk_nowa_gra[]= {"zoptymalizowana","bezkopniec","beztarcia","naturalna","wlasna"};
	const string menu_wlas_fizyk_nowa_gra[]={"PrzyspG","PrzyspGKop","MaxVGraczKop","MaxVGraczNorm","MocKop","WspolTarciaGracz","WspolTarciaPilka","ProgTarcia","wroc"};
	const string menu_ustawienia[]= {"avatar 1","avatar 2","zapisz","anuluj"};
	const string menu_ustawienia_roz[]= {"640x480","800x480","800x600","1024x600","1024x768","1280x720","1280x800","1280x1024","1366x768","inna"};
	const string menu_ustawienia_klaw[]= {"gracz","gora","dol","lewo","prawo","kopniecie","wstecz"};

	string menu_nowa_gra_gracze[IlMaxGraczy+1];
	for (int i=0;i<IlMaxGraczy;i++)
	{
		menu_nowa_gra_gracze[i]="gracz ";
		menu_nowa_gra_gracze[i]+=IntToString(i);
	}
	menu_nowa_gra_gracze[IlMaxGraczy]="wroc";
	string menu_map_nowa_gra[(dane->AktWielkoscTablicy((int)SpisMap))+1];
	const string nic[]= {""};
	string menu_wczytywane[dane->AktWielkoscTablicy((int)SpisZapisow)+1];
	for(int i=0; i<dane->AktWielkoscTablicy((int)SpisMap); i++)
		menu_map_nowa_gra[i]=(string)(*dane)[SpisMap][i];
	menu_map_nowa_gra[dane->AktWielkoscTablicy((int)SpisMap)]="nowa mapa";
	mena[(int)Glowne]=new menu(font,menu_glowne,4,-1,"MENU");
	mena[(int)NowaGra]=new menu(font,menu_nowa_gra,5,-1,"NOWA GRA",prz);
	mena[(int)NowaGra_Gracze]=new menu(font,menu_nowa_gra_gracze,IlMaxGraczy+1,-1,"",2*prz);
	mena[(int)NowaGra_Fizyka]=new menu(font,menu_fizyk_nowa_gra,5,-1,"fizyki:",2*prz);
	mena[(int)NowaGra_Ustaw_Fizyka]=new menu(font,menu_wlas_fizyk_nowa_gra,9,-1,"",3*prz);
	mena[(int)Ustawienia]=new menu(font,menu_ustawienia,4,-1,"USTAWIENIA",prz);
	mena[(int)Ustawienia_roz]=new menu(font,menu_ustawienia_roz,10,-1,"Rozdzielczosc:",2*prz);
	mena[(int)Ustawienia_klaw]=new menu(font,menu_ustawienia_klaw,7,-1,"Klawisze:",2*prz);
	mena[(int)Koniec]=new menu(font,nic,0,0,"",-1*prz);

	(*(mena[(int)Ustawienia]))[0].UstString((*dane)[Avatar1]);
	(*(mena[(int)Ustawienia]))[1].UstString((*dane)[Avatar2]);

	(*(mena[(int)NowaGra]))[0].UstString("zoptymalizowana");
	(*(mena[(int)NowaGra_Fizyka])).UstOpcje(0);
	(*(mena[(int)NowaGra_Ustaw_Fizyka]))[0].UstLiczbe(700+1400);
	(*(mena[(int)NowaGra_Ustaw_Fizyka]))[1].UstLiczbe(300+1400);
	(*(mena[(int)NowaGra_Ustaw_Fizyka]))[2].UstLiczbe(75);
	(*(mena[(int)NowaGra_Ustaw_Fizyka]))[3].UstLiczbe(150);
	(*(mena[(int)NowaGra_Ustaw_Fizyka]))[4].UstLiczbe(500);
	(*(mena[(int)NowaGra_Ustaw_Fizyka]))[5].UstLiczbe(1400);
	(*(mena[(int)NowaGra_Ustaw_Fizyka]))[6].UstLiczbe(600);
	(*(mena[(int)NowaGra_Ustaw_Fizyka]))[7].UstLiczbe(150);//,,,,,,,
	MenuNum=Glowne;
	PrzesowOd=Glowne;
	WspolczynnikPrzesowo=0;
	menuprzesow=0;
	(*(mena[(int)Ustawienia_klaw]))[1].AktySpecDopisek(klawfont);
	(*(mena[(int)Ustawienia_klaw]))[2].AktySpecDopisek(klawfont);
	(*(mena[(int)Ustawienia_klaw]))[3].AktySpecDopisek(klawfont);
	(*(mena[(int)Ustawienia_klaw]))[4].AktySpecDopisek(klawfont);
	(*(mena[(int)Ustawienia_klaw]))[5].AktySpecDopisek(klawfont);
	cout << " aktywacja spec tekstu wykonana ";

	fizyki=new fizykcont[5];
	fizyki[0].Load(700+1400,300+1400,75,150,500,1400,600,150); //zoptymalizowana
	fizyki[1].Load(700+1400,700+1400,150,150,0,1400,600,150); //bezkopniecia
	fizyki[2].Load(700+1400,700+1400,150,150,0,0,0,0); //beztarcia
	fizyki[3].Load(700+1400,300+1400,10000,150,500,1400,600,0); //naturalna
	fizyki[4].Load(700+1400,300+1400,75,150,500,1400,600,150); //wlsasna

	komdolny.SetFont(font);
	komdolny.SetText("A");
	komdolny.SetSize(50);
	komdolny.SetCenter(komdolny.GetRect().GetWidth()/2,komdolny.GetRect().GetHeight());
	komdolny.SetText("");
		komdolny.SetCenter(komdolny.GetRect().GetWidth()/2,komdolny.GetRect().GetHeight());
	komdolny.SetPosition(0,Appek->GetHeight()/2-20);

	events=new EventComp[(int)eaEND];
	(events+(int)MenuDown)->Set(sf::Event::KeyPressed,sf::Key::Down);
	(events+(int)MenuUp)->Set(sf::Event::KeyPressed,sf::Key::Up);
	// (*events[(int)MenuNext1])=Next;
	(events+(int)MenuNext1)->Set(sf::Event::KeyPressed,sf::Key::Right);
	// (*events[(int)MenuNext2])=Next;
	(events+(int)MenuNext2)->Set(sf::Event::KeyPressed,sf::Key::Return);
	(events+(int)MenuNext3)->Set(sf::Event::MouseButtonPressed,sf::Mouse::Left);
	// (*events[(int)MenuBack1])=Back;
	(events+(int)MenuBack1)->Set(sf::Event::KeyPressed,sf::Key::Left);
	// (*events[(int)MenuBack2])=Back;
	(events+(int)MenuBack2)->Set(sf::Event::KeyPressed,sf::Key::Escape);
	return 0;
}
int menu_screen::UnLoad()
{

	return 0;
}
SBI menu_screen::Draw(sf::RenderWindow &App)
{
	App.SetView(view);
	//-----------------------------------------
	App.Draw(logo_sp);
	if (zegarkom.GetElapsedTime()<10)
		App.Draw(komdolny);
	mena[(int)MenuNum]->rysuj(App);
	if (MenuNum!=PrzesowOd)
		mena[(int)PrzesowOd]->rysuj(App);
	return SBI();
}
SBI menu_screen::Animate(sf::RenderWindow &App)
{
	const short int v=3000;
	App.SetView(view);
	sf::Vector2f MousePos = App.ConvertCoords(App.GetInput().GetMouseX(),App.GetInput().GetMouseY());
	if (ostmousepozx-MousePos.x>5||
		ostmousepozx-MousePos.x<-5||
		ostmousepozy-MousePos.y>5||
		ostmousepozy-MousePos.y<-5)
	{
		mena[(int)MenuNum]->UstOpcjeMysz(MousePos.x,MousePos.y);
		ostmousepozx=MousePos.x;
		ostmousepozy=MousePos.y;
	}


	//cout << view.GetCenter().x;
	//int tmp;
	//cin >> tmp;
	if (view.GetCenter().x<mena[(int)MenuNum]->GetPozX())
	{
		view.Move(App.GetFrameTime()*v,0);
		if (view.GetCenter().x>mena[(int)MenuNum]->GetPozX())
			view.SetCenter(mena[(int)MenuNum]->GetPozX(),view.GetCenter().y);
	}
	if (view.GetCenter().x>mena[(int)MenuNum]->GetPozX())
	{
		view.Move(App.GetFrameTime()*v*-1,0);
		if (view.GetCenter().x<mena[(int)MenuNum]->GetPozX())
			view.SetCenter(mena[(int)MenuNum]->GetPozX(),view.GetCenter().y);
	}
	komdolny.SetColor(sf::Color(250,30,30,255));
	if (zegarkom.GetElapsedTime()>7&&zegarkom.GetElapsedTime()<10)
		komdolny.SetColor(sf::Color(250,30,30,255-(zegarkom.GetElapsedTime()-7)*255/3));
	return SBI();
}
SBI menu_screen::Work()
{
	return SBI();
}
SBI menu_screen::EventProc(sf::Event event)
{
	if (*(events+(int)MenuDown)==event)
		return Down(event);
	if (*(events+(int)MenuUp)==event)
		return Up(event);
	if (*(events+(int)MenuBack1)==event)
		return Back(event);
	if (*(events+(int)MenuBack2)==event)
		return Back(event);
	if (*(events+(int)MenuNext1)==event)
		return Next(event);
	if (*(events+(int)MenuNext2)==event)
		return Next(event);
	if (*(events+(int)MenuNext3)==event)
	{
		sf::Vector2f MousePos = Appek->ConvertCoords(event.MouseButton.X,event.MouseButton.Y);
		mena[(int)MenuNum]->UstOpcjeMysz(MousePos.x,MousePos.y);
		return Next(event);
	}
	return SBI();
}
SBI menu_screen::Up(sf::Event event)
{
	cout << " funkcja up ";
	mena[(int)MenuNum]->UstOpcje(mena[(int)MenuNum]->AktOpcja()-1);
	return SBI();
}
SBI menu_screen::Down(sf::Event event)
{
	cout << " funkcja down ";
	mena[(int)MenuNum]->UstOpcje(mena[(int)MenuNum]->AktOpcja()+1);
	cout << " nowa pozycja: " << mena[(int)MenuNum]->AktOpcja();
	cout << "\n";
	return SBI();
}
SBI menu_screen::Next(sf::Event event)
{
	PrzesowOd=MenuNum;
	view.SetCenter(mena[(int)MenuNum]->GetPozX(),view.GetCenter().y);
	switch(MenuNum)
	{
	case Glowne: //"Kontynuuj","Nowa gra","Ustawienia","Wyjccie"
	{
		switch((*mena[(int)Glowne]).AktOpcja())
		{
		case 0:
		{
			if ((*mena[(int)Glowne])[0].AktTekst()=="Kontynuuj")
			return SBI(false,3,Tlo);
			else
			{
				int * tab=new int[2];
				tab[0]=0;
				tab[1]=0;
				gra_screen::init_form * wskaz = new gra_screen::init_form(tab,5*60,10,fizyki[0],(*dane)[Avatar1],(*dane)[Avatar2]);
				(*mena[(int)Glowne])[0].UstTekst("Kontynuuj");
				return SBI(false,3,Tlo,(void *)wskaz);
			}
			break;
		}
		case 1:
		{
			MenuNum=NowaGra;
			break;
		}
		case 2:
		{
			MenuNum=Ustawienia;
			break;
		}
		case 3:
		{
			return SBI(true);
			break;
		}
		}
		break;
	}
	case NowaGra: //"fizyka","czas","punkty","rozpocznij","wroc"
	{
		switch ((*mena[(int)NowaGra]).AktOpcja())
		{

		case 0:
		{
			MenuNum=NowaGra_Fizyka;
			break;
		}
		case 1:
		{
			opcja_czas::init_form * wskaz = new opcja_czas::init_form(&((*mena[(int)NowaGra])[1]),0,99);
			return SBI(false,9,Animacji,(void *)wskaz);
			break;
		}
		case 2:
		{
			opcja_tekst::init_form * wskaz = new opcja_tekst::init_form(&((*mena[(int)NowaGra])[2]),true,0,1000);
			return SBI(false,7,Animacji,(void *)wskaz);
			break;
		}
		case 3:
		{


					int * tab=new int[2];
					tab[0]=0;
					tab[1]=0;
					MenuNum=Glowne;
					int endtime=getmin(&(*mena[(int)NowaGra])[1])*60;
					endtime+=getsek(&(*mena[(int)NowaGra])[1]);
					if (endtime==0)
						endtime=10000*60;
					int endwyn=(*mena[(int)NowaGra])[2].AktLiczba();
					if (endwyn==0)
						endwyn=10000;
						(*mena[(int)Glowne])[0].UstTekst("Kontynuuj");
					gra_screen::init_form * wskaz = new gra_screen::init_form(tab,endtime,endwyn,fizyki[(*mena[(int)NowaGra_Fizyka]).AktOpcja()],(*dane)[Avatar1],(*dane)[Avatar2]);
					return SBI(false,3,Tlo,(void *)wskaz);

			break;
		}
		case 4:
		{
			MenuNum=Glowne;
			break;
		}
		}
		break;
	}
	case NowaGra_Gracze:
	{

		break;
	}
	/*case NowaGra_Mapy:
	{
		MenuNum=NowaGra;
		if (dane->AktWielkoscTablicy((int)SpisMap)==(*mena[(int)NowaGra_Mapy]).AktOpcja())
			;// (*mena[(int)NowaGra_Mapy])
		else
			(*mena[(int)MenuNum]).OpcjaUstString(3,(*dane)[SpisMap][(*mena[(int)NowaGra_Mapy]).AktOpcja()]);
		break;
	}*/
	case NowaGra_Fizyka:
	{

		(*mena[(int)NowaGra])[0].UstString((*mena[(int)NowaGra_Fizyka])[(*mena[(int)NowaGra_Fizyka]).AktOpcja()].AktTekst());
		MenuNum=NowaGra;
		if ((*mena[(int)NowaGra_Fizyka]).AktOpcja()==4)
			MenuNum=NowaGra_Ustaw_Fizyka;
		break;
	}
	case NowaGra_Ustaw_Fizyka:
	{
		if ((*mena[(int)NowaGra_Ustaw_Fizyka]).AktOpcja()!=8)
		{
			opcja_tekst::init_form * wskaz = new opcja_tekst::init_form(&((*mena[(int)NowaGra_Ustaw_Fizyka])[(*mena[(int)NowaGra_Ustaw_Fizyka]).AktOpcja()]),true,0,1000);
			return SBI(false,7,Animacji,(void *)wskaz);
		}
		else
		{
			fizyki[4].Load((*mena[(int)NowaGra_Ustaw_Fizyka])[0].AktLiczba(),
			(*mena[(int)NowaGra_Ustaw_Fizyka])[1].AktLiczba(),
			(*mena[(int)NowaGra_Ustaw_Fizyka])[2].AktLiczba(),
			(*mena[(int)NowaGra_Ustaw_Fizyka])[3].AktLiczba(),
			(*mena[(int)NowaGra_Ustaw_Fizyka])[4].AktLiczba(),
			(*mena[(int)NowaGra_Ustaw_Fizyka])[5].AktLiczba(),
			(*mena[(int)NowaGra_Ustaw_Fizyka])[6].AktLiczba(),
			(*mena[(int)NowaGra_Ustaw_Fizyka])[7].AktLiczba());
			MenuNum=NowaGra;
		}
	}
	case Ustawienia:
	{
		switch ((*mena[(int)Ustawienia]).AktOpcja())
		{
		/*case 0:
			cout << "AKT STRING: " << (*mena[(int)Ustawienia]).OpcjaAktString(0) << endl;
			if ((*mena[(int)Ustawienia]).OpcjaAktString(0)=="NIE")
				(*mena[(int)Ustawienia]).OpcjaUstString(0,"TAK");
			else
				(*mena[(int)Ustawienia]).OpcjaUstString(0,"NIE");
			break;
		case 1:
			MenuNum=Ustawienia_klaw;
			break;
		case 2:
			break;*/
		case 0:
		{
			opcja_tekst::init_form * wskaz=new opcja_tekst::init_form(&((*mena[(int)Ustawienia])[0]),false,0,1000);
			return SBI(false,7,Animacji,(void *)wskaz);
			break;
		}
		case 1:
		{
			opcja_tekst::init_form * wskaz=new opcja_tekst::init_form(&((*mena[(int)Ustawienia])[1]),false,0,1000);
			return SBI(false,7,Animacji,(void *)wskaz);
			break;
		}
		case 2:
		{
			sf::Image test;
			if (!test.LoadFromFile(files+(*mena[(int)Ustawienia])[0].AktString()))
			{
				zegarkom.Reset();
				komdolny.SetPosition(prz,Appek->GetHeight()/2-20);
				komdolny.SetText("Nie moge zaladowac avatara 1 gracza!");
				komdolny.SetSize(30);
				komdolny.SetCenter(komdolny.GetRect().GetWidth()/2,komdolny.GetRect().GetHeight());
			}
			else
			{
				if (!test.LoadFromFile(files+(*mena[(int)Ustawienia])[1].AktString()))
				{
					zegarkom.Reset();
					komdolny.SetPosition(prz,Appek->GetHeight()/2-20);
					komdolny.SetSize(30);
					komdolny.SetText("Nie moge zaladowac avatara 2 gracza!");
					komdolny.SetCenter(komdolny.GetRect().GetWidth()/2,komdolny.GetRect().GetHeight());
				}
				else
				{
					(*dane)[Avatar1]=(*mena[(int)Ustawienia])[0].AktString();
					(*dane)[Avatar2]=(*mena[(int)Ustawienia])[1].AktString();
					MenuNum=Glowne;
				}
			}
			break;
		}
		case 3:
			MenuNum=Glowne;
			(*mena[(int)Ustawienia])[0].UstString((*dane)[Avatar1]);
			(*mena[(int)Ustawienia])[1].UstString((*dane)[Avatar2]);
			dane->Zapis();
			break;
		}
		break;
	}
	case Ustawienia_roz:
	{
		switch ((*mena[(int)Ustawienia_roz]).AktOpcja())
		{
		case 0:
			(*mena[(int)Ustawienia]).OpcjaUstString(1,"640x480");
			MenuNum=Ustawienia;
			break;
		case 1:
			(*mena[(int)Ustawienia]).OpcjaUstString(1,"800x480");
			MenuNum=Ustawienia;
			break;
		case 2:
			(*mena[(int)Ustawienia]).OpcjaUstString(1,"800x600");
			MenuNum=Ustawienia;
			break;
		case 3:
			(*mena[(int)Ustawienia]).OpcjaUstString(1,"1024x600");
			MenuNum=Ustawienia;
			break;
		case 4:
			(*mena[(int)Ustawienia]).OpcjaUstString(1,"1024x768");
			MenuNum=Ustawienia;
			break;
		case 5:
			(*mena[(int)Ustawienia]).OpcjaUstString(1,"1280x720");
			MenuNum=Ustawienia;
			break;
		case 6:
			(*mena[(int)Ustawienia]).OpcjaUstString(1,"1280x800");
			MenuNum=Ustawienia;
			break;
		case 7:
			(*mena[(int)Ustawienia]).OpcjaUstString(1,"1280x1024");
			MenuNum=Ustawienia;
			break;
		case 8:
			(*mena[(int)Ustawienia]).OpcjaUstString(1,"1366x768");
			MenuNum=Ustawienia;
			break;
		case 9:
			break;
		}
		break;
	}
	case Ustawienia_klaw:
	{
		switch((*mena[(int)Ustawienia_klaw]).AktOpcja())
		{
		case 0:
			{
				cout << "to jest wybrana opcja: " << (*mena[(int)Ustawienia_klaw])[0].AktTekst();
				opcja_tekst::init_form * wskaz=(new opcja_tekst::init_form(&((*mena[(int)Ustawienia_klaw])[0]),true,2,7));
				return SBI(false,7,Animacji,(void *)wskaz);
			}
			break;
		case 1:
            {
                opcja_klaw::init_form * wskaz=(new opcja_klaw::init_form(&((*mena[(int)Ustawienia_klaw])[1]),klawfont,klawfont2));
                return SBI(false,8,Animacji,(void *)wskaz);
            }
			break;
		case 2:
            {
                opcja_klaw::init_form * wskaz=(new opcja_klaw::init_form(&((*mena[(int)Ustawienia_klaw])[2]),klawfont,klawfont2));
                return SBI(false,8,Animacji,(void *)wskaz);
            }
			break;
		case 3:
            {
                opcja_klaw::init_form * wskaz=(new opcja_klaw::init_form(&((*mena[(int)Ustawienia_klaw])[3]),klawfont,klawfont2));
                return SBI(false,8,Animacji,(void *)wskaz);
            }
			break;
		case 4:
            {
                opcja_klaw::init_form * wskaz=(new opcja_klaw::init_form(&((*mena[(int)Ustawienia_klaw])[4]),klawfont,klawfont2));
                return SBI(false,8,Animacji,(void *)wskaz);
            }
			break;
		case 5:
            {
                opcja_klaw::init_form * wskaz=(new opcja_klaw::init_form(&((*mena[(int)Ustawienia_klaw])[5]),klawfont,klawfont2));
                return SBI(false,8,Animacji,(void *)wskaz);
            }
			break;
		}
	}
	}
	return SBI();
}
SBI menu_screen::Back(sf::Event event)
{
	PrzesowOd=MenuNum;
	view.SetCenter(mena[(int)MenuNum]->GetPozX(),view.GetCenter().y);
	switch (MenuNum)
	{
	case Glowne:
	{
		return SBI(true);
		break;
	}
	//case WczytajGre:
	case Ustawienia:
	case NowaGra:
	{
		MenuNum=Glowne;
		break;
	}
	case Ustawienia_klaw:
	case Ustawienia_roz:
	{
	    MenuNum=Ustawienia;
	    break;
	}
	case NowaGra_Ustaw_Fizyka:
	case NowaGra_Gracze:
	//case NowaGra_Mapy:
	{
		MenuNum=NowaGra;
		break;
	}
	}
	return SBI();
}
void menu_screen::Init(void * wskaz)
{
	delete dan;
	dan=(init_form *)wskaz;
	if (dan->zakonczona)
	(*mena[(int)Glowne])[0].UstTekst("Szybka gra");
	else
	(*mena[(int)Glowne])[0].UstTekst("Kontynuuj");
}
