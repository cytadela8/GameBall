#include "opcja_tekst.h"

opcja_tekst::opcja_tekst()
{
	dan=0;
	//ctor
}

opcja_tekst::~opcja_tekst()
{
	//dtor
}
int opcja_tekst::Load()
{

	return 0;
}
int opcja_tekst::UnLoad()
{

	return 0;
}
SBI opcja_tekst::Draw(sf::RenderWindow & App)
{

	return SBI();
}
SBI opcja_tekst::Animate(sf::RenderWindow & App)
{

	return SBI();
}
SBI opcja_tekst::Work()
{

	return SBI();
}
SBI opcja_tekst::EventProc(sf::Event event)
{
	//cout << "otrzymano event";
	//cout << "dla elem: "<< dan->elem->AktTresc() << "\n";
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
		if (dan->czyliczba&&(((char)event.Key.Code>=(char)sf::Key::Num0&&(char)event.Key.Code<=(char)sf::Key::Num9)||event.Key.Code==sf::Key::Up||event.Key.Code==sf::Key::Down))//
		{
			cout << " edytujesz liczbe :) ";
			dan->elem->EdycjaUserLiczby(dan->min,dan->max,event.Key.Code);
		}
		if ((((char)event.Key.Code>='a'&&(char)event.Key.Code<='z')||((char)event.Key.Code>='0'&&(char)event.Key.Code<='9')||event.Key.Code==sf::Key::Period||event.Key.Code==sf::Key::Back)&&!(dan->czyliczba))
		{
			cout << "edytujesz klawisz :) ";
			dan->elem->EdycjaUserStringa(event.Key.Code,event.Key.Shift,dan->min, dan->max);
		}
	}
	return SBI();
}
void opcja_tekst::Init(void * wskaz)
{
	delete dan;
	dan=(init_form *)(wskaz);
	cout << "wczytane dane: " << dan->czyliczba << dan->min << dan ->max << "\n";
}
