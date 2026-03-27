#ifndef Time_H
#define Time_H 
#include <iostream> 
using namespace std;
class Time
{  
private:
	int mHour; 
	int mMin; 
	int mSec; 
public: 

	//constructors 
	//Time(); 
	Time( int h=12,int m=1,int s=4 );  
	Time( const Time& t );
	Time& operator = ( const Time& t );

	friend istream& operator >>( istream& in,Time& t );//in,d- parametry WY
	friend ostream& operator <<( ostream& out,const Time& t );//d- param WE


	void setTime( int h,int m,int s );//strukture zawsze jako wskaznik 
	void setHour( int h );
	void setMin( int m );
	void setSec( int s );

	int getHour() const;
	int getMin() const;
	int getSec() const;
public:
	void printTime();
	void readTime();
}; 


inline int Time::getHour() const
{
	return mHour;

}
inline int Time::getMin() const
{
	return mMin;
}

inline int Time::getSec() const
{
	return mSec;
}
#endif
