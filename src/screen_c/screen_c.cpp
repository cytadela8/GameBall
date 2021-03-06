#include "head.h"
#include "screen_c/screen_c.h"
eleinfo::eleinfo() {}
eleinfo::eleinfo(int dnum,PPrzeslony dprz)
{
	num=dnum;
	prz=dprz;
}
eleinfo::operator int()
{
	return num;
}
eleinfo::operator PPrzeslony()
{
	return prz;
}
void eleinfo::operator = (int dnum)
{
	num=dnum;
}
void eleinfo::operator = (PPrzeslony dprz)
{
	prz=dprz;
}
screen_c::screen_c()
{
	loaded=false;
}
screen_c::screen_c(int ilD,screen_p *ekrwskazD [],screen_p *tloD)
{
	Load(ilD,ekrwskazD,tloD);
}
screen_c::~screen_c()
{

}
int screen_c::Load(int ilD,screen_p *ekrwskazD[],screen_p *tloD)
{
	loaded=true;
	il=ilD;
	wskaz=ekrwskazD;
	tlo=tloD;
	GTlo=-1;
	GSzara=-1;
	GAnimacji=-1;
	GInterakcji=-1;
	return 0;
}
int screen_c::Render(sf::RenderWindow &App)
{
	App.Clear();
	(*tlo).Work();
	(*tlo).Animate(App);
	(*tlo).LoadAndDraw(App);
	SBI zwrot;
	int gEvent;
	int poczGInterakcji=GInterakcji;
	sf::Event event;
	while (App.GetEvent(event))
	{
		for (int i=stos.size()-1; i>=poczGInterakcji+1; i--)
		{
			SBIproc(wskaz[stos[i]]->EventProc(event),i);
		}
	}

	for (int i=GTlo+1; i<stos.size(); i++)
	{
		if (i>GInterakcji)
		{
			SBIproc(wskaz[stos[i]]->Work(),i);
		}
		if (i>GAnimacji)
			SBIproc(wskaz[stos[i]]->Animate(App),i);
		SBIproc(wskaz[stos[i]]->LoadAndDraw(App),i);
		//if (i==GSzara)
		//App.Draw(EfektSzarosci);
	}
	App.Display();
	return stos.size()-(GInterakcji+1);
}

void screen_c::SBIproc(SBI sbi,int & i)
{
	if (sbi.Otworzyc)
	{
		cout << " insertuje... ";
		stos.insert(stos.begin()+(i+1),eleinfo(sbi.Otworzyc,sbi.przeslona));
		cout << " insertowano przed " << i+1 << " ekran " << sbi.Otworzyc << " wieloksc vec" << stos.size() << "\n";
		switch(sbi.przeslona)
		{
		case Tlo:
			GTlo=i;
		case Szara:
			GSzara=i;
		case Animacji:
			GAnimacji=i;
		case Interakcji:
			GInterakcji=i;
		case Brak:
			break;
		}
		cout <<" Ginterakcji: " <<GInterakcji << " \n";
	}
	if (sbi.zamknac)
	{
		cout << " kasowanie...";
		switch(stos[i].prz)
		{
		case Tlo:
			if (GTlo==i-1)
			{
				GTlo=-1;
				for (int j=i-1; j>=0; j--)
				{
					if((int)stos[j].prz>=(int)Tlo)
					{
						GTlo=j-1;
					}
				}
			}
		case Szara:
			if (GSzara==i-1)
			{
				GSzara=-1;
				for (int j=i-1; j>=0; j--)
				{
					if((int)stos[j].prz>=(int)Szara)
					{
						GSzara=j-1;
					}
				}
			}
		case Animacji:
			if (GAnimacji==i-1)
			{
				GAnimacji=-1;
				for (int j=i-1; j>=0; j--)
				{
					if((int)stos[j].prz>=(int)Animacji)
					{
						GAnimacji=j-1;
					}
				}
			}
		case Interakcji:
			if (GInterakcji==i-1)
			{
				GInterakcji=-1;
				for (int j=i-1; j>=0; j--)
				{
					if((int)stos[j].prz>=(int)Interakcji)
					{
						GInterakcji=j-1;
					}
				}
			}
		case Brak:
			break;
		}
		stos.erase(stos.begin()+i);
		cout << " skasowanio element " << i << " wieloksc vec " << stos.size() << "\n";
		cout <<" GAnimacji: " <<GAnimacji << " \n";
	}
	if (sbi.wskaz!=0)
	{
		cout << "inicjuje: " << sbi.celinit << "\n";
		wskaz[sbi.celinit]->Init(sbi.wskaz);
	}
}
int screen_c::Acctive(int num,PPrzeslony przeslona)
{
	SBI sbiek(false,num,przeslona);
	int endek=(int)stos.size()-1;
	SBIproc(sbiek,endek);
}




