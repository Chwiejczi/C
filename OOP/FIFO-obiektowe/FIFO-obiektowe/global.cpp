#include "global.h" 
Structure::Structure(int key, int t1, int t2)
{
	this->key = key; 
	pTab=new int[2];
	this->pTab[0] = t1; 
	this->pTab[1] =t2;
}

Structure::~Structure()
{ 
delete [] pTab;
}
ostream& operator << (ostream& out, const Structure& str)
{
	out << "key = " << str.key << " pTab[0]=" << str.pTab[0] << " pTab[1]=" << str.pTab[1];
	return out;
}

istream& operator >> (istream& in, Structure& str)
{
	in >> str.key >> str.pTab[0] >> str.pTab[1];
	return in;
}
