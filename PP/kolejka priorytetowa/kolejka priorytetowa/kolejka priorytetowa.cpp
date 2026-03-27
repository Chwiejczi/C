// kolejka priorytetowa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "global.h"
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>  
#include "PQueue.h" 
QPINFO* allocInfo( int a,int b,int c );
void printInfo( const void* ptr );
void freeInfo( const void* pInfo ); 
int compare( const void* comp1,const void* comp2 );
int main()
{ 
	PQueue* myQueue=PQInit( 20 );  
	if(!myQueue)
	{
		printf( "myQueue Init error\n" ); 
		return 1;
	} 

	

	QPINFO* Info=0; 
	//dodawanie elementow do kolejki
	for(int i=0; i<6; i++)
	{
		if(!( Info=allocInfo( i,2*i,3*i ) ))
		{
			printf( "allocation error" ); 
			return 2;
		} 
		if(!PQEnqueue( myQueue,i,Info ))
		{
			printf( "PQEnqueue error" ); 
			return 3;
		}
	} 
	PQPrint( myQueue,printInfo,0 ); 
	printf( "\n\n" ); 
	//usuniecie elem z max prior 

	freeInfo( PQDequeue( myQueue ) ); 
	PQPrint( myQueue,printInfo,0 );
	printf( "\n\n" ); 


	//dodawanie 2 elem 
	for(int i=0; i<2; i++)
	{ 
		if(!( Info=allocInfo( i+10,i+11,i+12 ) ))
		{
			printf( "allocation error" );
			return 4;
		}
		if(!PQEnqueue( myQueue,i+7,Info ))
		{
			printf( "PQEnqueue error" );
			return 5;
		}

	}
	PQPrint( myQueue,printInfo,0 ); 
	printf( "\n\n" ); 
	//wyszukiwanie elementu 

	QPINFO* find; 
	if(!( find=allocInfo( 1,2,3 ) ))
	{
		printf( "allocation error" );
		return 4;
	}

	int ix=PQFind( myQueue,compare,find ); 
	printf( "index=%d",ix ); 
	printf( "\n\n" ); 

	//zwiekszyc prior na 100 

	PQsetPrior( myQueue,ix,100 ); 
	PQPrint( myQueue,printInfo,0 ); 
	printf( "\n\n" );

	//zmniejszyc prior na 0  

	if(!( find=allocInfo( 0,0,0 ) ))
	{
		printf( "allocation error" );
		return 4;
	} 
	PQSetPrior( myQueue,find,compare,0 ); 
	printf( "\n\n" );
	//usunac kolejke
	PQRelease( &myQueue,freeInfo );

	//-------------------------------------------  
	printf( "\nTest nr 2\n" );
	PQueue* Queue=PQInit( 4);
	if(!Queue)
	{
		printf( " Queue Init error\n" );
		return 10;
	}


	for(int i=0; i<4; i++)
	{
		if(!( Info=allocInfo( i,2*i,3*i ) ))
		{
			printf( "allocation error" );
			return 11;
		}
		if(!PQEnqueue( Queue,i,Info ))
		{
			printf( "PQEnqueue error" );
			return 12;
		}
	}
	PQPrint( Queue,printInfo,0 );
	printf( "\n\n" );

	if(!( find=allocInfo( 0,0,0 ) ))
	{
		printf( "allocation error" );
		return 13;
	}

	PQSetPrior( Queue,find,compare,PQMaxPrior( Queue ) );
	PQPrint( Queue,printInfo,0 );
	printf( "\n\n" );

	freeInfo( PQDequeue( Queue ) );
	PQPrint( Queue,printInfo,0 );
	printf( "\n\n" );

	PQRelease( &Queue,freeInfo );
	free( find );

	return 0;



}
void printInfo( const void* ptr )
{
	QPINFO* pInfo=( QPINFO* )ptr;

	printf( "key:%d tab[0]:%d tab[1]:%d\n",pInfo->key,pInfo->pTab[ 0 ],pInfo->pTab[ 1 ] );
}
QPINFO* allocInfo( int a,int b,int c )
{  
	
	QPINFO* p=NULL;
	p=(QPINFO*)calloc( 1,sizeof(QPINFO) ); 
	if( !p )
	{ 
		printf( "allocInfo:allocation error 1" );
		return NULL;
	} 	
	p->pTab=( int* )calloc( 2,sizeof( int ) ); 
	if( !p->pTab )
	{
		printf( "allocInfo:allocation error 2" ); 
		free( p );
		return NULL;
	}
	
	p->pTab[ 0 ]=b;
	p->pTab[ 1 ]=c;
	p->key=a;
	return p; 
	
}
void freeInfo( const void* pInfo )
{
	free( (( QPINFO* )pInfo)->pTab );
	free( ( QPINFO* )pInfo );
}
int compare( const void* comp1,const void* comp2 )
{ 
	QPINFO* x=( QPINFO* )comp1; 
	QPINFO* y=( QPINFO* )comp2; 
	if(x->key<y->key)return -1; 
	if(x->key>y->key)return 1; 
	return 0;
}