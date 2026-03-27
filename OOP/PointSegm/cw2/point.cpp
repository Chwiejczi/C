#include "point.h" 
#include <iostream> 
#include <math.h>
using namespace std; 
Point::Point( double x,double y )
{
	SetPoint( x,y );
}


Point::Point( const Point& p )
{
	*this=p;
} 
/*
Point::Point(  )
{
	mx=GetX(); 
	my=GetY();
} 
*/
void Point:: SetPoint( double x,double y )
{ 
	SetX( x ); 
	SetY( y );

}


void Point:: SetX( double x )
{
	this->mx=x;
} 
void Point::SetY( double y )
{
	this->my=y;
} 

void Point:: Translate( double vx,double vy )
{
	SetX( GetX()+vx ); 
	SetY( GetY()+vy );
}
void Point:: Rotate( double radians )
{ 
	double tmpX=mx; 
	double z=cos( radians ); 
	SetX( tmpX*cos( radians )-my*sin( radians ) );
	SetY( tmpX*sin( radians )+my*cos( radians ) );
}

istream& operator >>( istream& in,Point& p )
{ 
	double temp; 
	char c; 
	in>>temp>>c; 
	p.SetX( temp ); 
	in>>temp; 
	p.SetY( temp );
	return in;
}
ostream& operator <<( ostream& out,const Point& p )  
{ 

	out<<'('<<p.GetX()<<','<<p.GetY()<<')'; 
	return out;

}