#ifndef DATA_H
#define DATA_H 
#include <iostream>  
using namespace std; 

class TESTDLL_API Date
{
private:
	int mDay;//member 
	int mMonth;
	int mYear; 

public://constructors  
	//nie posiada typu i musi nazywac sie tak jka klasa, moze byc wiecej konstruktorow
//	Date();//konstruktor domyslny 
	Date( int d=1,int m=2,int y=0 ); 
	Date( const Date& d );  
	~Date();
	Date& operator = ( const Date& d );

	friend istream& operator >>( istream& in,Date& d );//in,d- parametry WY
	friend ostream& operator <<( ostream& out,const Date& d );//d- param WE 


public:
	void setDate( int d,int m,int y );//strukture zawsze jako wskaznik 
	void setDay( int d );
	void setMonth( int m );
	void setYear( int y );

	int getDay() const;
	int getMonth() const;
	int getYear() const;
public:
	void printDate();
	void readDate();
}; 
inline int Date::getDay() const
{
	return mDay;

}
inline int Date::getMonth() const
{
	return mMonth;
} 

inline int Date::getYear() const
{
	return mYear;
}





#endif