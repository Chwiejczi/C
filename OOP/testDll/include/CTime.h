#ifndef Time_H
#define Time_H 
#include <iostream> 
using namespace std;
class TESTDLL_API Time
{
private:
	int m_nHour;
	int m_nMin;
	int m_nSec;
public:

	//constructors 
	//Time(); 
	Time(int h = 0, int m = 0, int s = 0);
	Time(const Time& t);
	Time& operator = (const Time& t);

	friend TESTDLL_API istream& operator >>(istream& in, Time& t);//in,d- parametry WY
	friend TESTDLL_API ostream& operator <<(ostream& out, const Time& t);//d- param WE


	void setTime(int h, int m, int s);//strukture zawsze jako wskaznik 
	void setHour(int h);
	void setMin(int m);
	void setSec(int s);

	int getHour() const;
	int getMin() const;
	int getSec() const;
public:
	void printTime();
	void readTime();
};


inline int Time::getHour() const
{
	return m_nHour;

}
inline int Time::getMin() const
{
	return m_nMin;
}

inline int Time::getSec() const
{
	return m_nSec;
} 
//=============================
inline void Time::setHour(int h)
{
	this->m_nHour = h;

}
inline void Time::setMin(int m)
{
	if (m > 0 && m < 60)
		this->m_nMin = m;
	else
		cerr << "Eroor:wrong minute given\n";

}
inline void Time::setSec(int s)
{
	if (s > 0 && s < 60)
		this->m_nSec = s;
	else
		cerr << "Eroor:wrong second given\n";

}
#endif

