#ifndef EVENTCOMP_H
#define EVENTCOMP_H
#include "head.h"
#include "screen_c/SBI.h"
using namespace sf;
typedef SBI (* FNaEvent)(Event);
using namespace std;
class EventComp
{
public:
    EventComp();
    EventComp(sf::Event event);
    ~EventComp();
    EventComp & operator = (FNaEvent funkcjad);
    EventComp & operator = (sf::Event event);
    bool operator == (sf::Event event);
    bool SprZFunkcja(sf::Event event);
    void Set(sf::Event::EventType typ,sf::Key::Code kod);
	void Set(sf::Event::EventType typ,sf::Mouse::Button but);
	void Set(sf::Event::EventType typ);
private:
    sf::Event::EventType EventTypek;
    sf::Key::Code KeyCode;
    sf::Mouse::Button MouseButton;
    FNaEvent Funkcja;
};
#endif // EVENTCOMP_H
