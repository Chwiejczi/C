#pragma once 
#include <iostream> 
#include <math.h> 
using namespace std;
class Rational
{ 
private: 
	int Numerator; 
	int Denominator; 
	int NWD(int a, int b);

public: 
	Rational( int num=0,int denum=1 ); 
	Rational( const Rational& R ); 
	virtual ~Rational();
	
	void setNumerat( int num ); 
	void setDenominat( int denum ); 
	void setRational( int num,int denum ); 
	int getNumerat() const; 
	int getDenominant() const;  
	
	
	Rational& operator =( const Rational& R ); 
	friend istream& operator >>( istream& in, Rational& R );
	friend ostream& operator <<( ostream& out,const Rational& R );
	friend const Rational operator +( const Rational& R1,const Rational& R2 ); 
	friend const Rational operator -( const Rational& R1,const Rational& R2 ); 
	friend const Rational operator *( const Rational& R1,const Rational& R2 ); 
	friend const Rational operator /( const Rational& R1,const Rational& R2 ); 
	Rational operator +=( const Rational& R ); 
	Rational operator -=( const Rational& R ); 
	Rational operator *=( const Rational& R ); 
	Rational operator /=( const Rational& R ); 
	 
	double Val( const Rational& R );
	void Skr(  );

};



inline int Rational:: getNumerat() const
{ 
	return Numerator; 

} 

inline int Rational::getDenominant() const
{
	return Denominator;
}
inline void Rational:: setNumerat( int num )
{
	this->Numerator=num;  
	Skr();
}
 
inline void Rational::setDenominat( int denum )
{ 
	if(denum ==0)
	{
		denum=1; 
		cerr<<"Error, wrong denum"<<endl;;
	}
	this->Denominator=denum;  
	Skr();
} 

inline int Rational::NWD( int a,int b ) // poprawic na abs()
{  
	int a1 =abs(a); 
	int b1=abs(b);
	while(b1!=0)
	{ 
		int temp=a1%b1; 
		a1=b1; 
		b1=temp;
		
	} 
	return a1;
} 
inline void Rational::Skr(  )
{  
	int NWP= NWD( getNumerat(),getDenominant() ); 
	int N1=getNumerat()/NWP; 
	int D1=getDenominant()/NWP; 
	setRational( N1,D1 );
	
} 