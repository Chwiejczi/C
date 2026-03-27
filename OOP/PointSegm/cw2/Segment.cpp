#include "Segment.h" 
#include <iostream> 
#include <math.h>
using namespace std; 
#define PI 3.14159265358979
Segm :: Segm( double x1,double y1,double x2,double y2 )
{ 
	SetSegm( x1,y1,x2,y2 );

}
Segm:: Segm( const Point& Pt1/*=Point()*/,const Point& Pt2/*=Point()*/ )
{ 
	SetSegm( Pt1,Pt2 );

} 


Segm:: Segm( const Segm& segm )
{
	*this=segm;
} 


void Segm::SetPt1( double x,double y )
{
	this->mPt1.mx=x;
	this->mPt1.my=y;

}
void Segm::SetPt1( Point& pt )
{
	this->mPt1=pt;

}

void Segm::SetPt2( double x,double y )
{
	this->mPt2.mx=x;
	this->mPt2.my=y;

}
void Segm::SetPt2( Point& pt )
{
	this->mPt2=pt;

}


Segm& Segm:: operator = ( const Segm& segm )
{ 
	mPt1.mx=segm.GetPt1().GetX(); 
	mPt1.my=segm.GetPt1().GetY(); 
	mPt2.mx=segm.GetPt2().GetX();
	mPt2.my=segm.GetPt2().GetY(); 
	return *this;


}

istream& operator >>( istream& in,Segm& segm )
{ 
	Point pt; 
	in>> pt; segm.SetPt1( pt ); 
	in>> pt; segm.SetPt2( pt ); 
	return in;

}
ostream& operator <<( ostream& out,Segm& segm )
{
	out<<segm.GetPt1()<<"---"<<segm.GetPt2(); 
	return out;
}


void Segm::SetSegm( const Point& pt1,const Point& pt2 )
{ 
	mPt1.SetPoint( pt1.mx,pt1.my ); 
	mPt2.SetPoint( pt2.mx, pt2.my );


}
void Segm:: SetSegm( double x1,double y1,double x2,double y2 )
{ 
	mPt1.SetPoint(x1,y1); 
	mPt2.SetPoint( x2,y2 );

}
void Segm:: SetSegm( const Segm& segm )
{ 
	mPt1.SetPoint( segm.GetPt1().GetX(),segm.GetPt1().GetY());
	mPt2.SetPoint( segm.GetPt2().GetX(),segm.GetPt2().GetY() );

} 
void Segm::Translate( double vx,double vy )
{ 
	mPt1.SetPoint(mPt1.GetX()+vx,mPt1.GetY()+vy);
	mPt2.SetPoint( mPt2.GetX()+vx,mPt2.GetY()+vy );
} 


double Segm::ave( double x,double y )
{
	return ( x+y )/2;
}

void Segm::Rotate( int alpha )//alpha w stopniach 
{ 
	//alpha do rad 
	double rad=alpha*PI/180;
	//obliczy wsp srodka - punkt(vx,vy) 
	//z tablicy, ale zle przepisane//Point mid( ave( mPt1.GetX(),mPt2.GetX()) ,ave( getPt1().getY(),getPt2().getY() );  
	Point mid( ave( mPt1.GetX(),mPt2.GetX() ),ave( mPt1.GetY(),mPt2.GetY() ) );
	// przesunac o wektor [-vx, -vy]   
	Translate( -mid.GetX(),-mid.GetY() );
	
	//obrocic oba punkty  
    SetPt1(mPt1.GetX()*cos( rad )-mPt1.GetY()*sin( rad ),mPt1.GetX()*sin( rad )+mPt1.GetY()*cos( rad ) ); 
	SetPt2( mPt2.GetX()*cos( rad )-mPt2.GetY()*sin( rad ),mPt2.GetX()*sin( rad )+mPt2.GetY()*cos( rad ) );
	//przesunac o wketor [vx,vy]
	Translate( mid.GetX(),mid.GetY() );
} 