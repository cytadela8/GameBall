#include "tostring.h"

string IntToString(int d)
{
	stringstream ss;
	ss << d;
	return ss.str();
}
string DoubleToString(double d)
{
	stringstream ss;
	ss << d;
	return ss.str();
}
