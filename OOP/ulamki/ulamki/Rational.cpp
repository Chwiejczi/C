#include "Rational.h"  

Rational::Rational( int num,int denum )
{  
	//Numerator=num; 
	//Denominator=denum; 
	setRational( num,denum );
	
}
Rational::Rational( const Rational& R )
{ 
	Numerator=0; 
	Denominator=0;
	*this=R;
} 
void Rational::setRational( int num,int denum )
{ 
	//setNumerat( num );
	//setDenominat( denum ); 
	this->Numerator=num; 
	this->Denominator=denum;
	if(NWD(num,denum)!=1)
		Skr();
	
	
}
Rational:: ~Rational()
{

}

Rational& Rational:: operator =( const Rational& R )
{ 
	setRational( R.getNumerat(),R.getDenominant() );

	return *this;
} 

istream& operator >>( istream& in,Rational& R )
{ 
	int temp; 
	char c; 
	in>>temp>>c; 
	R.setNumerat( temp ); 
	in>>temp; 
	R.setDenominat( temp ); 
	return in;


}
ostream& operator <<( ostream& out,const Rational& R )
{

	out<<R.getNumerat()<<'/'<<R.getDenominant(); 
	return out;

} 

const Rational operator +( const Rational& R1,const Rational& R2 )
{ 
	Rational res( R1 ); 
	return res+=R2;
} 
const Rational operator -( const Rational& R1,const Rational& R2 )
{ 
	Rational res( R1 ); 
	return res-=R2;
}
const Rational operator *( const Rational& R1,const Rational& R2 )
{ 
	Rational res( R1 ); 
	return res*=R2;

}
const Rational operator /( const Rational& R1,const Rational& R2 )
{
	Rational res( R1 ); 
	return res/=R2; 
} 
Rational Rational::operator +=( const  Rational& R )
{   
	int a=getNumerat(); 
	int c=R.getNumerat();
	if(Denominator!=R.getDenominant()) //a/b +c/d
	{   
		int b= getDenominant(); 
		int d= R.getDenominant(); 
		Numerator=Numerator*d; 
		Denominator=Denominator*d;  
		c=c*b; 
		d=d*b;
		//R.Numerator=R.Numerator*b; 
		//R.Denominator=R.Denominator*b;
		
		
	} 
	int N1=getNumerat()+c;  
	setNumerat( N1 );
	setDenominat( getDenominant() );
	return *this;



}
Rational Rational:: operator -=( const Rational& R )// a/b -c/d
{ 
	int a=getNumerat();
	int c=R.getNumerat();
	if(Denominator!=R.getDenominant()) 
	{
		int b= getDenominant();
		int d= R.getDenominant();
		Numerator=Numerator*d;
		Denominator=Denominator*d;
		c=c*b;
		d=d*b;
		


	}
	int N1=getNumerat()-c;
	setNumerat( N1 );
	setDenominat( getDenominant() );
	return *this;


}
Rational Rational:: operator *=( const Rational& R )
{ 
	int N1=getNumerat()*R.getNumerat(); 
	int D1=getDenominant()*R.getDenominant();  
	setRational( N1,D1 );
	//setNumerat( N1 );
	//setDenominat( D1 ); 
	return *this;


}
Rational Rational:: operator /=( const Rational& R )
{ 
	int N1=getNumerat()*R.getDenominant();
	int D1=getDenominant()*R.getNumerat(); 
	setRational( N1,D1 );
	//setNumerat( N1 );
	//setDenominat( D1 );
	return *this;

} 

double Rational:: Val( const Rational& R )
{
	return R.getNumerat()/R.getDenominant();
}