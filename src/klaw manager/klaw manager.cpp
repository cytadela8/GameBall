#include "klaw manager.h"

klaw_manager::klaw_manager()
{
	//ctor
}

klaw_manager::~klaw_manager()
{
	//dtor
}

const klaw & klaw_manager::szukaj(int num)
{
	if (num<tab.size())
	return tab[num];
	else
	{
		cout << "\n ERROR! odwolanie do nieistniejacego klawisza: nr. " << num;
		return tab[tab.size()-1];
	}
}

const klaw & klaw_manager::szukaj(sf::Key::Code klaw)
{
	for (int i=0;i<tab.size();i++)
	{
		if (tab[i].sfcode==klaw)
			return tab[i];
	}
	cout << "\n ERROR! klawisz nie istnieje!! (szukano na podstawie sf::Key::Code) ";
	return tab[tab.size()-1];
}

const klaw & klaw_manager::szukaj(sf::Image* obraz)
{
	for (int i=0;i<tab.size();i++)
	{
		if (tab[i].image==obraz)
			return tab[i];
	}
	cout << "\n ERROR! klawisz nie istnieje!! (szukano na podstawie sf::Image) ";
	return tab[tab.size()-1];
}

int klaw_manager::lacz(sf::Key::Code kod, sf::Image* obraz)
{
	tab.push_back(klaw(tab.size(),kod,obraz));
	return 0;
}
