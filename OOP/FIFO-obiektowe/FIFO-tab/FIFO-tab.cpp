// FIFO-tab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include "fifoTab.h"
using namespace std;
int main()
{  
FIFO fifo(5); 
//dodac 4 elementy   
cout<<"dodawanie 4 elementow"<<endl;
QFINFO* item=new QFINFO(1, 1, 1);
QFINFO* item2= new QFINFO(2, 2, 2);
QFINFO* item3=new QFINFO(3, 3, 3);
QFINFO* item4= new QFINFO(4, 4, 4);
fifo.FQEnqueue(item);
fifo.FQEnqueue(item2); 
fifo.FQEnqueue(item3); 
fifo.FQEnqueue(item4); 
fifo.FQPrint(); 
//tu bêdzie trzeba dopisac obsluge bledu  

//usunac 2 
cout << "usuwanie 2 elementow" << endl;
fifo.FQDel(); 
fifo.FQDel(); 
fifo.FQPrint();  

cout << "dodawanie 4 elementow" << endl; 
QFINFO* item5= new QFINFO(5, 5, 5);
QFINFO* item6= new QFINFO(6, 6, 6);
QFINFO* item7= new QFINFO(7, 7, 7);
QFINFO* item8= new QFINFO(8, 8, 8);
fifo.FQEnqueue(item5);
fifo.FQEnqueue(item6);
fifo.FQEnqueue(item7); 
try 
{ 
fifo.FQEnqueue(item8); 
} 
catch (StackException& e)
{
	cout << endl << "***" << e.getReason() << "***" << endl << endl;
}
fifo.FQPrint(); 
cout<<"clear"<<endl; 
fifo.FQClear(); 
fifo.FQPrint();


    return 0;
}
