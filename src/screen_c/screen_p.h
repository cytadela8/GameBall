#ifndef SCREEN_P_H
#define SCREEN_P_H

#include "screen_c/SBI.h"
#include "screen_c/EventComp.h"

class screen_p
{
	public:
		screen_p();
		virtual ~screen_p();
		virtual int Load()=0;
		virtual int UnLoad()=0;
		virtual SBI Draw(sf::RenderWindow &App)=0;
		virtual SBI Work()=0;
		virtual SBI Animate(sf::RenderWindow &App)=0;
		virtual SBI EventProc(sf::Event event);
		virtual void Init(void * wskaz);
		SBI LoadAndDraw(sf::RenderWindow &App);
	protected:
	EventComp * events;
	bool loaded;
	private:

};

#endif // SCREEN_P_H
