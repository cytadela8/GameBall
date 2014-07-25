#ifndef KEYCOMP_H
#define KEYCOMP_H
#include "head.h"
#include "screen_c/SBI.h"
using namespace sf;
typedef SBI (* FNaKod)(Key::Code);
using namespace std;

class KeyComp
{
public:
    KeyComp();
    KeyComp(sf::Key::Code keyek);
    ~KeyComp();
    KeyComp & operator = (FNaKod funkcjad);
    KeyComp & operator = (sf::Key::Code event);
    bool operator == (sf::Key::Code keyek);
    bool SprZFunkcja(sf::Key::Code keyek);
    void Set(sf::Key::Code kod);
    sf::Key::Code KeyCode;
private:
    FNaKod Funkcja;
};

#endif // KEYCOMP_H
