#ifndef KLAW MANAGER_H
#define KLAW MANAGER_H

#include <iostream>

#include "head.h"
#include "klaw.h"

class klaw_manager
{
	public:
		klaw_manager();
		~klaw_manager();
		const klaw & szukaj(int num);
		const klaw & szukaj(sf::Key::Code klaw);
		const klaw & szukaj(sf::Image * obraz);
		int lacz(sf::Key::Code kod,sf::Image * obraz);
	protected:
	private:
		vector <klaw> tab;
};

#endif // KLAW MANAGER_H
