//QFINFO
//zwalniaæ pamiêæ //
#include <stdio.h> 
#include <stdlib.h> 
#include <memory.h> 
#include "QFIFO.h" 
#include "Global.h" 

QFINFO* allocInfo( int a,int b,int c );
void printInfo( const void* ptr );
void freeInfo( const void* ptr );
int main()
{
    FQueue* MyQueue = FQCreate();
    if(!MyQueue)
    {
        printf( "MYQueue:allocation error" );
        return 12;
    }
    for(int i = 1; i <= 4; i++)
    {
        QFINFO* p = allocInfo( i,2*i,3*i );
        if( !FQEnqueue( MyQueue,p ) )
        {
            printf( "FQEnqueue:  allocation error!\n" );
            return 1;
        }
    }

    QFPrint( MyQueue,printInfo );

    for(int i = 1; i <= 3; i++)
    {
      QInfo* item=  FQDequeue( MyQueue ) ; 
      freeInfo( item );
    }

    QFPrint( MyQueue,printInfo );

    for(int i = 20; i <= 21; i++)
    {
        QFINFO* p = allocInfo( i,i + 1,i + 2 );
        if(!FQEnqueue( MyQueue,p ))
        {
            printf( " FQEnqueue:  allocation error\n" );
            return 2;
        }
    }

    QFPrint( MyQueue,printInfo );
    FQClear( MyQueue,freeInfo );

    for(int i = 21; i <= 23; i++)
    {
        QFINFO* p = allocInfo( i,i + 1,i + 2 );
        if(!FQEnqueue( MyQueue,p ))
        {
            printf( "FQEnqueue: allocation error!\n" );
            return 3;
        }
    }

    QFPrint( MyQueue,printInfo );
    QInfo* item2= FQDequeue( MyQueue ) ; 
    freeInfo( item2 );
    QFPrint( MyQueue,printInfo );
    FQRemove( &MyQueue,freeInfo );

    return 0;

	
} 


void printInfo( const void* ptr )
{
	QFINFO* pInfo=( QFINFO* )ptr;
	
	printf( "key:%d tab[0]:%d tab[1]:%d",pInfo->key,pInfo->pTab[ 0 ],pInfo->pTab[ 1 ] ); 
}
QFINFO* allocInfo( int a,int b,int c )
{
	QFINFO* p;
	p = ( QFINFO* )malloc( sizeof( QFINFO ) );
	if(!p)
		return NULL;
	memset( p,0,sizeof( QFINFO ) );
	p->pTab=( int* )malloc( 2*sizeof( int ) );
	if( !p->pTab )
		return NULL;
	p->pTab[ 0 ]=b;
	p->pTab[ 1 ]=c;
	p->key=a;
	return p;
}
void freeInfo( const void* ptr )
{
	QFINFO* pInfo = ( QFINFO* )ptr;
	free( pInfo->pTab );
	free( pInfo );
} 
