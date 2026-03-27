// Fifo_template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include "FifoTemplate.h" 
#include "global.h"
using namespace std;
int main()
{  
QFIFO<QFINFO> Fifo; 
QFINFO* item = new QFINFO(1, 1, 1);
QFINFO* item2 = new QFINFO(2, 2, 2);
QFINFO* item3 = new QFINFO(3, 3, 3);
QFINFO* item4 = new QFINFO(4, 4, 4);
cout << "dodac 4 elementy" << endl << endl;
Fifo.FQEnqueue(item);
Fifo.FQEnqueue(item2);
Fifo.FQEnqueue(item3);
Fifo.FQEnqueue(item4);
Fifo.QFPrint();
//dodac 1 elem- m abyc blad(tylko dla tablicowej) 
//usunac 3 elementy i wypisac   
cout << "usunac 3 elementy" << endl << endl;
Fifo.FQDel();
Fifo.FQDel();
Fifo.FQDel();
Fifo.QFPrint();
//dodac 2 elementy 
cout << "dodac 2 elementy" << endl << endl;;
QFINFO* item5 = new QFINFO(5, 5, 5);
QFINFO* item6 = new QFINFO(6, 6, 6);
Fifo.FQEnqueue(item5);
Fifo.FQEnqueue(item6);
Fifo.QFPrint();
//wyczyscic kolejke  
cout << "czyszczenie i dodawanie 2 kolejnych" << endl << endl;;
Fifo.FQClear();
QFINFO* item7 = new QFINFO(7, 7, 7);
QFINFO* item8 = new QFINFO(8, 8, 8);
Fifo.FQEnqueue(item7);
Fifo.FQEnqueue(item8);
Fifo.QFPrint();
 
Fifo.FQClear();
cout << endl;
try {
	Fifo.QFPrint();
}
catch (StackException e)
{
	cout << e.getReason() << endl;
}
return 0;


 
}

