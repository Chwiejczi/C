#include <iostream>
#include "testDll.h"
#include "Date.h"
#include "CTime.h" 
#include "DateTime.h"
using namespace std;
int main()
{  
Date d1(11,12,1222); 
cout<<d1; 
cout<<endl; 
Time t1(1,1,1); 
cout<<t1; 
cout<<endl;   
DateTime dt(d1,t1); 
cout<<dt;

return 0;
}


