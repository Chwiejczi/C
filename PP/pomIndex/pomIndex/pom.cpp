#include "pom.h"   
#include <stdlib.h> 
#include <stdio.h> 
#include<memory.h> 
FQueue* FQCreate()//tworzenie
{
	FQueue* q = NULL;
	q = ( FQueue* )malloc( sizeof( FQueue ) );
	if(!q)
	{
		return NULL;
	}
	memset( q,0,sizeof( FQueue ) );
	q->pHead=q->pTail=NULL;
	return q;
}
int     FQEmpty( FQueue* q )// if FIFO empty returned 1 else 0
{
	return  !q || !( q->pHead ); // blad kolejnosc!!!!!

}
int   FQEnqueue( FQueue* q,int key )//dodawanie elementu
{
	if(!q)
	{
		return 0;
	}

	FQItem* newItem = ( FQItem* )malloc( sizeof( FQItem ) );
	if(!newItem)
	{
		return 0;
	}
	newItem->key=key;
	newItem->pNext = NULL;
	if(FQEmpty( q ))
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
int FQDequeue( FQueue* q )// zwraca  element
{
	if(FQEmpty( q ))
	{
		return NULL;
	}
	
	int key= q->pHead->key; 
	FQDel( q );

	return key;

}
void    FQClear( FQueue* q)
{
	if(!q) 
	{
		printf( "FQClear: doesn't exist\n" );
		return;
	}
	while(!FQEmpty( q ))
	{
		FQDel(q);
		

	}

}
void FQRemove( FQueue** q)//usuwa kolejke
{
	if(!q || !*q)
	{
		printf( " FQRemove: doesn't exist\n" );
		return;
	}
	FQClear( *q );
	free( *q );
	*q = NULL;
}
void    FQDel( FQueue* q )//usuwa 1 elem
{
	if(FQEmpty( q ))
	{
		printf( " FQDel: queue is empty\n" );
		return;
	}
	FQItem* ptr = q->pHead; 
	
	q->pHead = ptr->pNext;
	if(!( q->pHead ))
		q->pTail = NULL;
	free( ptr );
}
void    QFPrint( FQueue* q )
{
	if(FQEmpty( q ))
	{
		printf( "  QFPrint: empty " );
		return;
	}
	FQItem* info=q->pHead;
	const void* p=NULL;

	while(info)
	{
		p=( const void* )info;
		printf( "%d ",info->key );
		info=info->pNext;
	}
	printf( "\n" );

}
