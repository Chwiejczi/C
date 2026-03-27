#include "DateTime.h"




DateTime:: DateTime( int D,int M,int Y,int h,int m,int s ): Date(D,M,Y), Time(h,m,s)
{ 
}
DateTime:: DateTime( const DateTime& dt ):Date( (const Date&)dt ), Time( (Time&)dt )
{  
	( Date& )*this=( Date& )dt;
	*( Time* )this=( const Time& )dt; 
	//te 2 sposoby s¹ rownowa¿ne
}
DateTime& DateTime:: operator = ( const DateTime& dt )
{ 
	return *this;
}


void DateTime:: setDateTime( int D,int M,int Y,int h,int m,int s )
{  
	
	setDate( D,M,Y ); 
	setTime( h,m,s );
	 
}

istream& operator >>( istream& in,DateTime& dt )
{  
	in>>( Date& )dt; 
	in>>( Time& )dt; 
	return in;
	 
}
ostream& operator <<( ostream& out,DateTime& dt )
{
	out<<( Date& )dt<<"--"<<( Time& )dt; 
	return out;
	 
}
