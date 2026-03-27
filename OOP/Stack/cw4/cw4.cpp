// cw4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include "Stack.h"
using namespace std;
int main()
{   
Stack <char> cS; 
Stack <double>dS; 
 
try
{
	char c = cS.top();
} 
catch ( StackException e)
{
cout <<endl<<"***"<<e.getReason()<<"***"<<endl;
}

dS.push(1); 
dS.push(2); 
dS.push(3); 
cS.push('A'); 
cS.push('B'); 
cS.push('C');

cout << dS.pop() << ' '; 
cout << dS.pop() << ' '; 
cout << dS.pop() <<endl; 
try
{
	if( cS.pop() =='C') 
		if( cS.pop() =='B') 
			if( cS.pop() == 'A') 
				{ cout <<"Char stack operations OK"<<endl; 
					cout<< cS.pop(); 
					return 1;
				} 
cout <<endl<< "--->> No error in stack";
} 
catch (StackException& e)
{
	cout<< endl<<"***" <<e.getReason()<<"***"<<endl<<endl;
}
}


