#include "screen_c/EventComp.h"

EventComp::EventComp()
{

}
EventComp::EventComp(sf::Event event)
{
    if(event.Type==sf::Event::KeyPressed)
    {
        EventTypek=event.Type;
        KeyCode=event.Key.Code;
    }
    if(event.Type==sf::Event::MouseButtonPressed)
    {
        EventTypek=event.Type;
        MouseButton=event.MouseButton.Button;
    }

}
EventComp::~EventComp()
{
    ;
}

EventComp & EventComp::operator = (sf::Event event)
{
    if(event.Type==sf::Event::KeyPressed)
    {
        EventTypek=event.Type;
        KeyCode=event.Key.Code;
    }
    if(event.Type==sf::Event::MouseButtonPressed)
    {
        EventTypek=event.Type;
        MouseButton=event.MouseButton.Button;
    }
    return *this;
}
EventComp & EventComp::operator = (FNaEvent funkcjad)
{
    Funkcja=funkcjad;
    return *this;
}
bool EventComp::operator == (sf::Event event)
{
    if(EventTypek==sf::Event::KeyPressed&&event.Type==EventTypek&&event.Key.Code==KeyCode)
        return true;
    else if(EventTypek==sf::Event::MouseButtonPressed&&event.Type==EventTypek&&event.MouseButton.Button==MouseButton)
        return true;
    else if(EventTypek!=sf::Event::KeyPressed&&EventTypek!=sf::Event::MouseButtonPressed&&event.Type==EventTypek)
        return true;
    return false;
}
bool EventComp::SprZFunkcja(sf::Event event)
{
    if (*this==event)
    {
        Funkcja(event);
        return true;
    }
    else
        return false;
}
void EventComp::Set(sf::Event::EventType typ,sf::Key::Code kod)
{
	EventTypek=typ;
	KeyCode=kod;
}
void EventComp::Set(sf::Event::EventType typ,sf::Mouse::Button but)
{
	EventTypek=typ;
	MouseButton=but;
}
void EventComp::Set(sf::Event::EventType typ)
{
	EventTypek=typ;
}




