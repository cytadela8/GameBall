#include "klaw.h"

klaw::klaw(int numd, sf::Key::Code sfcoded, sf::Image* imaged)
{
	num=numd;
	sfcode=sfcoded;
	image=imaged;
}
klaw::~klaw()
{
	//dtor
}
klaw::operator sf::Key::Code () const
{
	return sfklaw;
}

klaw::operator sf::Image * () const
{
	return image;
}
klaw::operator int() const
{
	return num;
}
