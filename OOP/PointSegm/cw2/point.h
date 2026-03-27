#ifndef POINT_H
#define POINT_H  
#include <iostream> 
using namespace std;
class Point
{
public : 
	double mx; 
	double my;
public: 
	Point( double x=0,double y=0); 
	Point( const Point& p );   
	//Point();
	void SetPoint( double x,double y );
	void SetX( double x ); 
	void SetY( double y ); 
	double GetX() const; 
	double GetY() const; 

	friend istream& operator >>( istream& in,Point& p );
	friend ostream& operator <<( ostream& out,const Point& p ); 

	void Translate( double vx,double vy ); 
	void Rotate( double radians );
}; 

inline double Point:: GetX() const
{
	return mx;
} 
inline double Point:: GetY() const 
{ 
	return my;

} 


#endif