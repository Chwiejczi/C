#include "QFIFO.h"   
#include <stdlib.h> 
#include <stdio.h> 
#include<memory.h>   

void FQDel( FQueue* q ); 

FQueue* FQCreate()//tworzenie
{  
	FQueue* q = NULL;   
	q = (FQueue*)calloc(1, sizeof( FQueue ) ); 
	if( !q )
	{ 
		return NULL;
	}
	//memset( q, 0, sizeof( FQueue ) );  
	q->pHead=q->pTail=NULL;
	return q;
}
int     FQEmpty( FQueue* q )// if FIFO empty returned 1 else 0
{ 
	return  !q || !( q->pHead ); 

}
int   FQEnqueue( FQueue* q, QFINFO* pInfo )//dodawanie elementu
{ 
	if( !q )
	{ 
		return 0 ;
	}
	
	FQItem* newItem = ( FQItem* )malloc( sizeof( FQItem ) );
	if(!newItem)
	{
		return 0 ;
	}
	newItem->pInfo=pInfo;
	newItem->pNext = NULL;
	if( FQEmpty( q ) )
	{
		q->pHead = newItem;		
	}
	else
	{
		q->pTail->pNext = newItem;
	} 
	q->pTail = newItem;
	return 1;
}
QFINFO* FQDequeue( FQueue* q )// zwraca  element
{ 
	if( FQEmpty( q ) )
	{
		return NULL; 
	}
    QFINFO* a=q->pHead->pInfo;
    FQDel( q ); 
		
    return a;
		
}
void    FQClear( FQueue* q,void ( __cdecl* freeMem )( const void* ) )
{ 
	if(!q || !freeMem) // freememe
	{
		printf("FQClear: doesn't exist or function freeMem doesn't exist\n"); 
		return ;
	}
	while( !FQEmpty(q) )
	{   

		freeMem( FQDequeue( q ) );
	
	}
	
}
void FQRemove( FQueue** q,void ( __cdecl* freeMem )( const void* ) )//usuwa kolejke
{ 
	if( !q || !*q )
	{
		printf( " FQRemove: doesn't exist\n" );
		return;
	}
	FQClear( *q,freeMem ); 
	free( *q ); 
	*q = NULL;
}
void    FQDel( FQueue* q )//usuwa 1 elem
{ 
	if( FQEmpty(q) )
	{
		printf( " FQDel: queue is empty\n" );
		return;
	}
	FQItem* ptr = q->pHead;
	q->pHead = ptr->pNext; 
	if( !( q->pHead ) )  
		q->pTail = NULL;
	free( ptr ); 
} 
void    QFPrint( FQueue* q , void ( __cdecl* printInfo )( const void* ) )
{ 
	if( FQEmpty( q ) )
	{
		printf( "  QFPrint: empty " );
		return;
	}  
	FQItem* info=q->pHead; 
	const void* p=NULL;

	while( info )
	{  
		p=( const void* )info->pInfo; 
		printInfo( p ); 
		printf( "\n" );
		info=info->pNext;
	}  
	printf( "\n" );

} 
