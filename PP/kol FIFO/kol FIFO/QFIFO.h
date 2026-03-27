//zabezpiczenie preprocesorem
#ifndef QFIFO

#define QFIFO
#include "Global.h"
typedef struct tagFQItem
{ 
	QFINFO* pInfo;
	tagFQItem* pNext;
} FQItem; 

typedef struct
{
	FQItem* pHead; 
	FQItem* pTail;
} FQueue;  

FQueue* FQCreate();                  
int     FQEmpty( FQueue* q );         
int     FQEnqueue( FQueue* q,QFINFO* pInfo );
QFINFO*  FQDequeue( FQueue* q );
void    FQClear( FQueue* q,void ( __cdecl* freeMem )( const void* ) );
void    FQRemove( FQueue** q,void ( __cdecl* freeMem )( const void* ) );//void ( __cdecl* freeMem )-pozwala przekazaæ funckje jako parametr
//void    FQDel( FQueue* q );       
void    QFPrint( FQueue* q , void ( __cdecl* printInfo )( const void* ) );
//funkcja printinfo zdefiniowana przez usera
//
#endif 