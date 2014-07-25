#ifndef KLAW_H
#define KLAW_H

#include "head.h"

class klaw
{
	public:
		klaw(int numd,sf::Key::Code coded,sf::Image * imaged);
		~klaw();
		operator sf::Key::Code() const;
		operator sf::Image * () const;
		operator int() const;
		int num;
		sf::Key::Code sfcode;
		sf::Image * image;
	protected:
	private:
};

#endif // KLAW_H
