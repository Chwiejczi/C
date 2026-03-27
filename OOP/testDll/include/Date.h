#ifndef DATA_H
#define DATA_H 
#include <iostream>  
using namespace std;

class TESTDLL_API Date
{
private:
	int m_nDay;//member 
	int m_nMonth;
	int m_nYear;

public://constructors  
	//nie posiada typu i musi nazywac sie tak jka klasa, moze byc wiecej konstruktorow
//	Date();//konstruktor domyslny 
	Date(int d = 1, int m = 2, int y = 0);
	Date(const Date& d);
	~Date();
	Date& operator = (const Date& d);

	friend TESTDLL_API istream& operator >>(istream& in, Date& d);//in,d- parametry WY
	friend TESTDLL_API ostream& operator <<(ostream& out, const Date& d);//d- param WE 


public:
	void setDate(int d, int m, int y);//strukture zawsze jako wskaznik 
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	int getDay() const;
	int getMonth() const;
	int getYear() const;
public:
	void printDate();
	void readDate();
};
inline int Date::getDay() const
{
	return m_nDay;

}
inline int Date::getMonth() const
{
	return m_nMonth;
}

inline int Date::getYear() const
{
	return m_nYear;
}

//======================================
inline void Date::setDate(int d, int m, int y)
{
	setDay(d);
	setMonth(m);
	setYear(y);

}
inline void Date::setDay(int d)//Date:: operator zasiegu
{

	this->m_nDay = d; //operator niejawny kazdej metody klasy
}
inline void Date::setMonth(int m)
{
	if (m > 0 && m < 13)
		this->m_nMonth = m;
	else//obsluga bledu 
		cerr << "Eroor:wrong month given\n";
}
inline void Date::setYear(int y)
{
	this->m_nYear = y;
}





#endif
