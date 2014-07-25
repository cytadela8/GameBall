#ifndef TEKSTURA_H
#define TEKSTURA_H

#include "head.h"
class tekstura
{
	public:
		tekstura();
		tekstura(int gd, int dd, int ld, int pd,sf::Image & imaged);
		void Load(int gd, int dd, int ld, int pd,sf::Image & imaged);
		void Draw(sf::RenderWindow & App);
		~tekstura();
	protected:
	private:
		int g;
		int d;
		int l;
		int p;
		int wys;
		int szer;
		sf::Sprite sprit;
};

#endif // TEKSTURA_H
