#include "opcja_klaw.h"

opcja_klaw::opcja_klaw(int rd,int gd,int bd,sf::RenderWindow & App)
{
	dan=0;
	r=rd;
	g=gd;
	b=bd;
	napis.SetText("Nacisnij klawisz...");
	napis.SetSize(45);
	napis.SetPosition(App.GetWidth()/2-napis.GetRect().GetWidth()/2,App.GetHeight()-napis.GetRect().GetHeight()-10);
	//ctor
}
opcja_klaw::~opcja_klaw()
{
	//dtor
}
int opcja_klaw::Load()
{
	return 0;
}
int opcja_klaw::UnLoad()
{

	return 0;
}
SBI opcja_klaw::Draw(sf::RenderWindow & App)
{
	App.SetView(App.GetDefaultView());
	App.Draw(napis);
	return SBI();
}
SBI opcja_klaw::Animate(sf::RenderWindow & App)
{
	if (czas.GetElapsedTime()<=0.5)
		napis.SetColor(sf::Color::Color(r,g,b,czas.GetElapsedTime()*255*2));
	else
		napis.SetColor(sf::Color::Color(r,g,b,255-czas.GetElapsedTime()*255*2));
	if (czas.GetElapsedTime()>=1)
		czas.Reset();
	return SBI();
}
SBI opcja_klaw::Work()
{

	return SBI();
}
SBI opcja_klaw::EventProc(sf::Event event)
{
	if (event.Type==sf::Event::KeyPressed)
	{
		cout << "otrzymano klawiszowy event";
		if (event.Key.Code==sf::Key::Return||event.Key.Code==sf::Key::Escape)
			return SBI(true);
		//cout << " nie exituje... \n";
		if ((((char)event.Key.Code>='a'&&(char)event.Key.Code<='z')||((char)event.Key.Code>='0'&&(char)event.Key.Code<='9')||event.Key.Code==sf::Key::Back))
		{
			cout << "edytujesz klawisz norm :) ";
			dan->elem->SetSpecDopiskFont(*dan->czcionnorm);
			dan->elem->EdycjaUserStringa(event.Key.Code,true,0,1);
			return SBI(true);
		}
		//else if (event.Key.Code==sf::Key::Code::)
	}
	return SBI();
}

void opcja_klaw::Init(void * wskaz)
{
	delete dan;
	dan=(init_form *)(wskaz);
	czas.Reset();
	napis.SetColor(sf::Color::Color(r,g,b,0));
}
sf::Key::Code opcja_klaw::nasf(char znak,bool rodz)
{
	/*
	if (rodz==false)
	{
		if ('0'<=znak&&znak<='9')
		{
			return (sf::Key::Code)znak;
		}
		else if ('A'<=znak&&znak<='Z')
		{
			return (sf::Key::Code)(char)((int)znak+32);
		}
		else switch (znak)
			{
			case ',':
				return sf::Key::Comma;
				break;
			case '.':
				return sf::Key::Period;
				break;
			case '/':
				return sf::Key::Slash;
				break;
			case '\\':
				return sf::Key::BackSlash;
				break;
			case ';':
				return sf::Key::SemiColon;
				break;
			case '[':
				return sf::Key::LBracket;
				break;
			case ']':
				return sf::Key::RBracket;
				break;
			case '-':
				return sf::Key::Minus;
				break;
			case '=':
				return sf::Key::Equal;
				break;
			case '\'':
				return sf::Key::Quote;
				break;
			case '~':
				return sf::Key::Tilde;
				break;
			case '*':
				return sf::Key::Multiply;
				break;
			}
	}
	else
	{
		switch (znak)
		{
		case 'N':
			return sf::Key::Tab;
			break;
		case 'O':
			return sf::Key::CapsLock;
			break;
		case 'G':
			return sf::Key::ShiftLeft;
			break;
		case 'F':
			return sf::Key::CtrlRight;
			break;
		case 'E':
			return sf::Key::AltLeft;
			break;
		case 'i':
			return sf::Key::Windows;
			break;
		case 'h':
			return sf::Key::Space;
			break;
		case 'w':
			return sf::Key::Left;
			break;
		case 'y':
			return sf::Key::Right;
			break;
		case 'x':
			return sf::Key::Up;
			break;
		case 'z':
			return sf::Key::Down;
			break;
		case 'H':
			return sf::Key::ShiftRight;
			break;
		case 'J':
			return sf::Key::Return;
			break;
		case 'e':
			return sf::Key::BackSpace;
			break;
		}
	}*/
}
sf::Key::Code opcja_klaw::nasf(int kod)
{
	return nasf(kod%256,kod/256);
}
keycont opcja_klaw::nacont(sf::Key::Code klaw)
{
	/*if ()
	{

	}
	else if()
	{

	}
	else switch(klaw)
	{

	}*/
}
