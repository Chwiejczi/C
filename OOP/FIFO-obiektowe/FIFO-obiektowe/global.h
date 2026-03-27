#ifndef GLOBAL_H
#define GLOBAL_H  
#define QFINFO Structure
#include <iostream> 
using namespace std;
	
//zzdefiniowac sta³¹ pprocesora QINFO-wartoœci¹ jest nazwa któr¹ stworzylisœmy 
//ma zawierac tablicê 2 elementow¹ intów(dynamiczna)  
//wskaznik pTab,key-int  
class Structure
{ 
public:
	Structure( int key, int t1, int t2) ;
	virtual ~Structure(); 
friend ostream& operator << (ostream& out , const Structure& str ); 
friend istream& operator >> (istream& in,  Structure& str);
private: 
	int key; 
	int *pTab;



} ;  

#endif  

