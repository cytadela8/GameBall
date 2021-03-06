#include "opcja.h"


opcja::opcja(sf::Font & fontek,string tekstek,short const pozek,short const pozxek,bool srodek)
{
    wybr=false;
    blok=false;
    dopisekliczba=0;
    dopisekstring="";
    tekst=tekstek;
    poz=pozek;
    pozx=pozxek;
    //wymiar2=0;
    //wymiar2il=0;
    srod=srodek;
    TEKST.SetSize(45);
    TEKST.SetFont(fontek);
    dopisek_spec=0;
    uptekst();
}
/*opcja::opcja(string tekstek,string wymiar2tekstek[],short int wymiar2ek,unsigned short const pozek)
{
	tekst=tekstek;
	wymiar2=wymiar2ek/2;
	wymiar2il=wymiar2ek;
	for(int i=0;i<wymiar2il;i++)
	{
		opcje[i]=new opcja(wymiar2tekstek[i],-1);
	}
}*/
opcja::~opcja()
{
}
short int opcja::AktSzerokoscTekst() const
{
    return TEKST.GetRect().GetWidth();
}
void opcja::AktySpecDopisek(const sf::Font & czcionka)
{
    //cout << " podchodze do new... ";
    dopisek_spec=new sf::String("",czcionka);
    dopisek_spec->SetSize(45);
    //uptekst();
}
void opcja::SetSpecDopiskFont(const sf::Font & czcionka)
{
	dopisek_spec->SetFont(czcionka);
}
void opcja::EdycjaUserLiczby(long int min,long int max,sf::Key::Code klaw)
{
    if ((char)klaw>='0'&&(char)klaw<='9')
    {
        cout << "zwiekszanie... o " << (int)((char)klaw-'0');
        dopisekliczba*=10;
        dopisekliczba+=(int)((char)klaw-'0');
        if (dopisekliczba>max)
        {
            if (dopisekliczba>=10)
                while (dopisekliczba>max&&dopisekliczba>=10)
                    dopisekliczba%=10;
            if (dopisekliczba>max)
                dopisekliczba=max;
        }
        if (dopisekliczba<min)
            dopisekliczba=min;
    }
    else if (klaw==sf::Key::Back)
    {
        dopisekliczba/=10;
        if (dopisekliczba>max)
            dopisekliczba=max;
        if (dopisekliczba<min)
            dopisekliczba=min;
    }
    else if (klaw==sf::Key::Down)
    {
        dopisekliczba--;
        if (dopisekliczba>max)
            dopisekliczba=max;
        if (dopisekliczba<min)
            dopisekliczba=min;
    }
    else if (klaw==sf::Key::Up)
    {
        dopisekliczba++;
        if (dopisekliczba>max)
            dopisekliczba=max;
        if (dopisekliczba<min)
            dopisekliczba=min;
    }
    else if (klaw==sf::Key::Subtract && min<0 && max>0)
    {
        dopisekliczba*=-1;
    }
    uptekst();
}

void opcja::EdycjaUserStringa(sf::Key::Code klaw,bool shift, int min, int max)
{
    if (((char)klaw>='0'&&(char)klaw<='9'))
    {
        dopisekstring+=(char)klaw;
        if (dopisekstring.size()>max)
        {
            cout << "erase...";
            dopisekstring.erase(0,1);
        }

    }
    else if ((char)klaw>='a'&&(char)klaw<='z')
    {
        if (shift)
            dopisekstring+=(char)klaw-32;
        else
            dopisekstring+=(char)klaw;
        if (dopisekstring.size()>max)
        {
            cout << "erase...";
            dopisekstring.erase(0,1);
        }
    }
    else if (klaw==sf::Key::Period)
	{
		dopisekstring+='.';
		if (dopisekstring.size()>max)
        {
            cout << "erase...";
            dopisekstring.erase(0,1);
        }
	}
    else if (klaw==sf::Key::Back)
    {
        if (dopisekstring.size()>min)
        dopisekstring.resize(dopisekstring.size()-1);
    }
    uptekst();
}
void opcja::uptekst()
{
    ostringstream ss;
    ss << dopisekliczba;
    string tekstek;
    if (dopisekliczba==0)
        tekstek=tekst;
    else
        tekstek=tekst+":"+ss.str();
    if(dopisekstring!="")
    {
        if (dopisek_spec==0)
        {
            tekstek+=":";
            tekstek+=dopisekstring;
        }
        else
        {
            dopisek_spec->SetText(dopisekstring);
        }
    }
    TEKST.SetText(tekstek);
    if (srod)
        TEKST.SetPosition(pozx-(AktSzerokoscTekst())/2,poz);
    else
        TEKST.SetPosition(pozx,poz);
    if (dopisek_spec!=0)
    {
        if (srod)
            dopisek_spec->SetPosition(pozx+(AktSzerokoscTekst())/2,poz);
        else
            dopisek_spec->SetPosition(pozx+(AktSzerokoscTekst()),poz);
    }

}
void opcja::UstString(string stringek)
{
    dopisekstring=stringek;
    uptekst();
}
void opcja::ZmianPoz(short int pozek)
{
    poz=pozek;
    uptekst();
}
void opcja::UstTekst(string tekstek)
{
    tekst=tekstek;
    uptekst();
}
void opcja::rysuj(sf::RenderWindow &App,bool wybre,int pozek)
{
    poz=pozek;
    rysuj(App,wybre);
}
void opcja::rysuj(sf::RenderWindow &App,bool wybre)
{
    rysuj(App,wybre,(short int)0);
}
void opcja::rysuj(sf::RenderWindow &App,bool wybrek,short int korekta)
{
    //cout << poz << " " << pozx;
    wybr=wybrek;
    short int pozy,cieniowanie,cieniowanie2,cieniowanie3;
    pozy=poz;
    if (wybr)
        TEKST.SetStyle(sf::String::Bold);
    else
        TEKST.SetStyle(sf::String::Regular);
    TEKST.Move(5,5);
    if (dopisek_spec!=0)
    dopisek_spec->Move(5,5);
    for (int i=4; i>=0; i--)
        if (wybr)
        {
            TEKST.Move(-1,-1);
            if (dopisek_spec!=0)
                dopisek_spec->Move(-1,-1);
            cieniowanie=(i)*WspolczynnikCienia;
            if (cieniowanie>250)
                cieniowanie=250;
            cieniowanie2=(i)*WspolczynnikCienia;
            if (cieniowanie2>100)
                cieniowanie2=100;
            cieniowanie3=(i)*WspolczynnikCienia;
            if (cieniowanie3>50)
                cieniowanie3=50;
            if (blok)
            {
                TEKST.SetColor(sf::Color(100-cieniowanie,100-cieniowanie2,100-cieniowanie3));
                if (dopisek_spec!=0)
                dopisek_spec->SetColor(sf::Color(100-cieniowanie,100-cieniowanie2,100-cieniowanie3));
            }

            else
            {
                TEKST.SetColor(sf::Color(250-cieniowanie,100-cieniowanie2,50-cieniowanie3));
                if (dopisek_spec!=0)
                dopisek_spec->SetColor(sf::Color(250-cieniowanie,100-cieniowanie2,50-cieniowanie3));
            }
            App.Draw(TEKST);
            if (dopisek_spec!=0)
            App.Draw(*dopisek_spec);
        }

        else
        {
            TEKST.Move(-1,-1);
            if (dopisek_spec!=0)
                dopisek_spec->Move(-1,-1);
            cieniowanie=(i)*WspolczynnikCienia;
            if (cieniowanie>250)
                cieniowanie=250;
            TEKST.SetColor(sf::Color(250-cieniowanie,250-cieniowanie,250-cieniowanie));
            if (dopisek_spec!=0)
                dopisek_spec->SetColor(sf::Color(250-cieniowanie,250-cieniowanie,250-cieniowanie));
            App.Draw(TEKST);
            if (dopisek_spec!=0)
            App.Draw(*dopisek_spec);
        }
}
