#include "opcja_czas.h"

opcja_czas::opcja_czas()
{
	dan=0;
}

opcja_czas::~opcja_czas()
{
	delete dan;
}
int opcja_czas::Load()
{

	return 0;
}
int opcja_czas::UnLoad()
{

	return 0;
}
SBI opcja_czas::Draw(sf::RenderWindow & App)
{

	return SBI();
}
SBI opcja_czas::Animate(sf::RenderWindow & App)
{

	return SBI();
}
SBI opcja_czas::Work()
{

	return SBI();
}
SBI opcja_czas::EventProc(sf::Event event)
{
	if (event.Type==sf::Event::MouseButtonPressed)
	{
		return SBI(true);
	}
	if (event.Type==sf::Event::KeyPressed)
	{
		cout << "otrzymano klawiszowy event";
		if (event.Key.Code==sf::Key::Return||event.Key.Code==sf::Key::Escape||event.Key.Code==sf::Key::Left||event.Key.Code==sf::Key::Right)
			return SBI(true);
		cout << " nie exituje... \n";
		if ((((char)event.Key.Code>=(char)sf::Key::Num0&&(char)event.Key.Code<=(char)sf::Key::Num9)))
		{
			cout << " edytujesz liczbe :) ";
			int cyfra=(int)(char)event.Key.Code-(int)'0';
			minut*=10;
			minut+=cyfra;
			if (minut>dan->max)
				minut=dan->max;
			akt();
		}
		if (event.Key.Code==sf::Key::Up)
		{
			if (sekund==30)
			{
				sekund=0;
				minut++;
				if (minut>dan->max)
				minut=dan->max;
			}
			else
			{
				sekund=30;
			}
			akt();
		}
		if (event.Key.Code==sf::Key::Down)
		{
			if (sekund==0)
			{
				sekund=30;
				minut--;
				if (minut<dan->min)
				{
					minut=dan->min;
					sekund=0;
				}
			}
			else
				sekund=0;
			akt();
		}
		if (event.Key.Code==sf::Key::Back)
		{
			minut/=10;
			sekund=0;
			if (minut<dan->min)
				minut=dan->min;
			akt();
		}
	}
	return SBI();
}
void opcja_czas::Init(void * wskaz)
{
	delete dan;
	dan=(init_form *)(wskaz);
	cout << "wczytane dane: " << dan->min << dan->max << "\n";
	minut=getmin(dan->elem);
	sekund=getsek(dan->elem);
}
int getmin(opcja * op)
{
	string akt=op->AktString();
	string tmp="0";
	int minu=0;
	if (akt.size()>=5)
	{
		if (akt[0]!=0)
		tmp=akt[0];
		else
		tmp="";
		tmp+=akt[1];
	}
	istringstream ss(tmp);
	ss >> minu;
	return minu;
}
int getsek(opcja * op)
{
	string akt=op->AktString();
	string tmp="0";
	int sek=0;
	if (akt[3]!=0)
		tmp=akt[3];
		else
		tmp="";
		tmp+=akt[4];
	istringstream ss2(tmp);
	ss2 >> sek;
	return sek;
}
void opcja_czas::akt()
{
	string bud="";
	string tmp=IntToString(minut);
	if (tmp.size()<2)
		bud+="0";
	bud+=tmp;
	bud+=":";
	tmp=IntToString(sekund);
	if (tmp.size()<2)
		bud+="0";
	bud+=tmp;
	if (bud!="00:00")
	dan->elem->UstString(bud);
	else
	dan->elem->UstString("");
}
