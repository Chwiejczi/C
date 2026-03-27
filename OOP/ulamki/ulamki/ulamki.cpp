// ulamki.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include "Rational.h"
using namespace std;
int main()
{   
	
	Rational R1;
	cout << "R1=" << R1 << endl;
	Rational R2(21, 3);
	cout << "R2=" << R2 << endl;
	
	
	R2.setRational( 6,2 ); 
	cout<<"R2="<<R2<<endl; 
	R1+=R2; //ok 
	cout<<"R1+=R2: "<<R1<<endl; 

	Rational R3(8,5);
	cout<<"R3="<<R3<<endl;
	Rational R4( 2,5 );
	cout<<"R4="<<R4<<endl;
	R3-=R4;//ok
	cout<<"R3-=R4: "<<R3<<endl; 
	
	
	Rational R5( 8,5 );
	cout<<"R5="<<R3<<endl;
	Rational R6( 2,5 );
	cout<<"R6="<<R6<<endl;
	R5*=R6;//ok
	cout<<"R5*=R6: "<<R5<<endl; 
	
	
	Rational R7( 8,5 );
	cout<<"R7="<<R7<<endl;
	Rational R8( 2,5 );
	cout<<"R8="<<R8<<endl;
	R7/=R8;//ok
	cout<<"R7/=R8: "<<R7<<endl;  
	
	// spr setterow 
	R7.setNumerat( 12 ); 
	cout<<"R7="<<R7<<endl;
	R7.setDenominat(4);
	cout<<"R7="<<R7<<endl;
	return 0; 

} 
//skracanie ulamkow

//static cast do obliczania wartosci ulamkow(mozna przetestowac) <- nawet trzeba
// przeczytac dynamic_cast 
//dopisac destructor virtualny
