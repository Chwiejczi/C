#ifndef GLOBAL_H

#define GLOBAL_H

//zzdefiniowac sta³¹ pprocesora QINFO-wartoœci¹ jest nazwa któr¹ stworzylisœmy 


//ma zawierac tablicê 2 elementow¹ intów(dynamiczna)  


//wskaznik pTab,key-int  
typedef struct
{  
	int key;
	int* pTab;//TAB 2D
} QInfo;

#define QFINFO QInfo
#endif 