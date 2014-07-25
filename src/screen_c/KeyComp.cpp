#include "KeyComp.h"

KeyComp::KeyComp()
{

}
KeyComp::KeyComp(sf::Key::Code kod)
{
    KeyCode=kod;
}
KeyComp::~KeyComp()
{
    ;
}

KeyComp & KeyComp::operator = (sf::Key::Code kod)
{
    KeyCode=kod;
    return *this;
}
KeyComp & KeyComp::operator = (FNaKod funkcjad)
{
    Funkcja=funkcjad;
    return *this;
}
bool KeyComp::operator == (sf::Key::Code kod)
{
    if(kod==KeyCode)
        return true;
    return false;
}
bool KeyComp::SprZFunkcja(sf::Key::Code kod)
{
    if (*this==kod)
    {
        Funkcja(kod);
        return true;
    }
    else
        return false;
}
void KeyComp::Set(sf::Key::Code kod)
{
	KeyCode=kod;
}
