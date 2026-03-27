#pragma once 
#include "Point.h" 
#define PI 3.14159265358979
class Segm 
{  
private: 
	Point mPt1; 
	Point mPt2; 

public: 
	Segm( double x1,double y1,double x2,double y2 ); 
	Segm( const Point& Pt1=Point(),const Point& Pt2=Point());
	Segm( const Segm& segm );
	Segm& operator = ( const Segm& segm );

	friend istream& operator >>( istream& in,Segm& segm );
	friend ostream& operator <<( ostream& out,Segm& segm ); 


	void SetPt1( double x, double y ); 
	void SetPt1( Point& pt ); 

	const Point& GetPt1() const; 
	const Point& GetPt2() const;
	void SetPt2( double x,double y );
	void SetPt2( Point& pt );
	
	void SetSegm( const Point& pt1,const Point& pt2 );
	void SetSegm( double x1,double y1,double x2,double y2 ); 
	void SetSegm( const Segm& segm ); 
	void Translate( double vx,double vy ); 
	void Rotate( int alpha );
	double ave( double x,double y );
    

	

};




inline const Point& Segm:: GetPt1() const
{ 

	return mPt1;
}
inline const Point& Segm:: GetPt2() const
{
	return mPt2;
}