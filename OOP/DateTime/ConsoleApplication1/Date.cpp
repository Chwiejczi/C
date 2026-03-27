#include "pch.h" 
#include "testDll.h"
#include "Date.h" 
#include <iostream> 
using namespace std; 


//Date::Date()
//{ 
	//setDate( 1,1,1990 );
//} 


Date::Date(int d/*=1*/,int m/*=1*/,int y/*=1990*/)
{
	setDate( d,m,y );
} 

Date::Date( const Date& d )
{ 
	*this=d;//powienien byc wywolany operator podstawienia(=)

} 

Date& Date:: operator = ( const Date& d )
{
	setDate( d.getDay(),d.getMonth(),d.getYear() ); 
	return *this;
} 
//===================destructor 
Date::~Date()
{
}



//======================================
void Date::setDate( int d,int m,int y )
{ 
	setDay( d ); 
	setMonth( m ); 
	setYear( y );

}
void Date:: setDay( int d )//Date:: operator zasiegu
{ 

	this->mDay=d; //operator niejawny kazdej metody klasy
}
void Date:: setMonth(int m )
{  
	if(m>0 && m<13)
		this->mMonth=m; 
	else//obsluga bledu 
		cerr<<"Eroor:wrong month given\n";
}
void Date:: setYear( int y )
{  
	this->mYear=y;
}



void Date:: printDate(  )
{  
	cout<<mDay<<"//"<<mMonth<<"//"<<mYear;
} 

void Date:: readDate( )
{  
	int temp;
	char c;//separator 
	cin>>temp>>c; 
	setDay( temp ); 

	cin>>temp>>c;
	setMonth( temp ); 

	cin>>temp;
	setYear( temp );
} 

 
//===========================================
istream& operator >>( istream& in,Date& d )
{ 
	int temp;
	char c;//separator 
	in>>temp>>c;
	d.setDay( temp );

	in>>temp>>c;
	d.setMonth( temp );

	in>>temp;
	d.setYear( temp );
	return in;

}
ostream& operator <<( ostream& out,const Date& d )
{ 
	out<<d.getDay()<<'/'<<d.getMonth()<<'/'<<d.getYear(); 
	return out;
}