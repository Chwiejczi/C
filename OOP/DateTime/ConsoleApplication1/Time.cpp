#include "Time.h" 
#include <iostream> 
using namespace std;
//Time :: Time()
//{ 
//	setTime( 1,22,13 );
//}
Time:: Time( int h/*=0*/,int m/*=0*/,int s/*=0*/)
{  
	setTime( h,m,s );
}

void Time:: setTime( int h,int m,int s )
{ 
	setHour(h); 
	setMin(m); 
	setSec(s);

} 
Time::Time( const Time& t )
{
	*this=t;

} 
//operator= jest niezbedny gdy w klasie s¹ dynamiczne struktury danych
Time& Time::operator = ( const Time& t )
{ 

	setTime( t.getHour(),t.getMin(),t.getSec());
	return *this;

}


//=============================
void Time:: setHour( int h )
{   
	this->mHour=h;
	
}
void Time:: setMin( int m )
{  
	if(m>0 && m<60)
		this->mMin=m; 
	else 
		cerr<<"Eroor:wrong minute given\n";

}
void Time:: setSec( int s )
{  
	if(s>0 && s<60)
		this->mSec=s;
	else
		cerr<<"Eroor:wrong second given\n";

}
void Time:: printTime()
{  
	cout<<mHour<<"//"<<mMin<<"//"<<mSec;
}
void Time:: readTime()
{  
	char c; 
	int temp; 
	cin>>temp>>c; 
	setHour( temp ); 
	cin>>temp>>c;
	setMin( temp ); 
	cin>>temp;
	setSec( temp );
} 


//======================================= 

istream& operator >>( istream& in,Time& t )
{
	int temp;
	char c;//separator 
	in>>temp>>c;
	t.setHour( temp );

	in>>temp>>c;
	t.setMin( temp );

	in>>temp;
	t.setSec( temp );
	return in;

}
ostream& operator <<( ostream& out,const Time& t )
{
	out<<t.getHour()<<':'<<t.getMin()<<':'<<t.getSec();
	return out;
}