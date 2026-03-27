#pragma once
#include "Date.h" 
#include "Time.h" 
#include <iostream> 
using namespace std; 

//w klasie pochodnej mozna uzywac calego interfejsu publicznego i chronionego 
//klas bazowych 
class DateTime :public Date, public Time
{ 
public: 
	DateTime( int D=1,int M=1,int Y=1990,int h=8,int m=10,int s=12 );
	DateTime( const DateTime& dt ); 
	DateTime& operator = ( const DateTime& dt ); 

public: 
	void setDateTime( int D,int M,int Y,int h,int m,int s ); 

	friend istream& operator >>( istream& in,DateTime& dt ); 
	friend ostream& operator <<( ostream& out,DateTime& dt );

};

