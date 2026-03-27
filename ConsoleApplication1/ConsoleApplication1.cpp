// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 

#include "Date.h"
#include "Time.h" 
#include "DateTime.h"
int main()
{   
    //data
    Date d1;
    d1.setDate( 1,10,2025 );

    cout<<"d1="<< d1;//.printDate(  ); 
    cout<<endl;

    d1.setDay( 6 );
    cout<<"d1="<<d1<<endl;//.printDate(  ); 
    //cout<<endl;  
    Date d2;
    cout<<"podaj date w formacie dd/mm/yyyy";
    cout<<endl;
    cin>>d2; 
    cout<<d2;
    //d2.printDate(); 
    cout<<endl;  


    //time
    Time t1; 
    cout<<"t1="<<t1<<endl;
    t1.setMin( 12 ); 
    cout<<"t1="<<t1<<endl; 
    Time t2; 
    cout<<"podaj czas w formacie hh:mm:ss"<<endl;
    cin>>t2; 
    cout<<"t2="<<t2<<endl;
    
    //DateTime
    DateTime dt1; 
    cout<<"dt1= "<<dt1<<endl; 
    DateTime dt2( 21,10,2025,8 ); 
    cout<<"dt2= "<<dt2<<endl; 
    
    DateTime dt3;
    cout<<"podaj date i cas w formacie dd/mm/yyyy hh:mm:ss"; 
    cin>>dt3; 
    cout<<"dt3= "<<dt3<<endl;

   

   


   

   


    
    return 0;
}

