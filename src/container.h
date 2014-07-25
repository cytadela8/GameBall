#ifndef CONTAINER_H
#define CONTAINER_H

template <class typ>
class container
{
	public:
		container();
		container(typ * wskazek);
		container(typ & elek);
		~container();
		typ * Getwskaz() { return wskaz; }
		void Setwskaz(typ * val) { wskaz = val; }
		operator typ() {return *wskaz;}
	protected:
	private:
		typ * wskaz;
};
template <class typ>
container<typ>::container()
{
	//ctor
}
template <class typ>
container<typ>::container(typ * wskazek)
{
	wskaz=wskazek;
}
template <class typ>
container<typ>::container(typ & elek)
{
	wskaz=&elek;
}
template <class typ>
container<typ>::~container()
{
	//dtor
}

#endif // CONTAINER_H
