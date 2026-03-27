#include <stdio.h> 
#include "PQueue.h" 
#include<memory.h> 
#include <stdlib.h>  
void UpdateDown( int l,int p,PQueue* q );
void UpdateUp( int l,int p,PQueue* q );
//QPINFO* PQDeQueue( PQueue* q ); 
//void PQEnQueue( PQueue* q );
PQueue* PQInit( int nSize )// kreuje kolejke o zadanym rozmiarze i zwraca wskaznik do niej lub NULL gdy blad// ma zwrocic wskazik do pQueue
{
	if(nSize<=0)
	{
		return NULL;
	}
	PQueue* q = ( PQueue* )calloc( 1,sizeof( PQueue ) );
	if(!q)
	{
		return NULL;
	}
	q->pPQueue=( PQItem** )calloc( nSize,sizeof( PQItem* ) );
	if(!( q->pPQueue ))
	{
		return NULL;
	}
	q->nPQMAXSize=nSize;
	q->nPQCurrSize=0;
	return q;
}
int PQisEmpty( PQueue* q )// zwraca 0 lub 1 - kolejka pusta/nie pusta
{
	return !q || !( q->nPQCurrSize );
}
int PQSize( PQueue* q )// zwraca ilosc elementow w kolejce//zawsze sprawdziæ, czy kolejka istnieje
{
	return ( !q )? PRIOR_ERROR : q->nPQCurrSize;
}

int PQMaxPrior( PQueue* q ) // zwraca najwiekszy priorytet w kolejce (z zerowej pozycji) lub PRIOR_ERROR
{
	return ( !PQisEmpty(q) )? PRIOR_ERROR : q->pPQueue[ 0 ]->nPrior;
	
}
int PQEnqueue( PQueue* q,int prior,QPINFO* Info )// wstawia do kolejki informacje o zadanym priorytecie, zwraca 0 (niepowodzenie) lub 1 (powodzenie)
{
	if( !q ) 
		return 0;
	
	if(q->nPQCurrSize>=q->nPQMAXSize)
	{
		return 0;
	}
	PQItem* p=( PQItem* )calloc( 1,sizeof( PQItem ) );
	if(!p)
	{
		return 0;
	}
	p->nPrior=prior;
	p->pInfo=Info;
	q->pPQueue[ q->nPQCurrSize ]=p;
	
	if(q->nPQCurrSize)UpdateUp( 0,q->nPQCurrSize,q ); 
	q->nPQCurrSize++;
	return 1;

}
QPINFO* PQDequeue( PQueue* q )// zwraca informacje o najwyzszym priorytecie lub NULL gdy niepowodzenie
{
	if( !q||PQisEmpty(q) )
	{
		return NULL;
	}
	int size = --q->nPQCurrSize;
	QPINFO* res= q->pPQueue[ 0 ]->pInfo;
	if( size > 0 )
	  q->pPQueue[ 0 ] = q->pPQueue[ size ];
	q->pPQueue[ size ] = NULL;
	if( size > 1 )
	  UpdateDown( 0,size-1,q );
	return res;

}
void PQClear( PQueue* q,void ( __cdecl* freeMem )( const void* ) )
{
	if( !q )
	{
		printf( "PQClear queue doesn't exist" ); 
		return;
	}
	if( !freeMem )
	{
		printf( "PQClear function error" );
		return;
	}
	int size = PQSize( q );

	while( q->nPQCurrSize )
	{
		freeMem( PQDequeue( q ) );
	}
}

void PQRelease( PQueue** q,void ( __cdecl* freeMem )( const void* ) )// zwraca w parametrze we-wy NULL (kolejka) usuwaj¹c wszyskto wczesniej (czyszczenie kolejki)
{ 
	if( !q || !( *q ) )
	{
		printf( "PQRelease queue doesn't exist" ); 
		return;
	}
	PQClear( *q,freeMem );
	free( ( *q )->pPQueue );
	free( *q );
	*q=NULL;
}
void PQPrint( PQueue* q,void ( __cdecl* print )( const void* ),int i )
{
	if( !q || !print )
	{ 
		printf( "PQPrint queue doesn't exist or element doesn't exist" );
		return;
	}

	//if( PQisEmpty( q ) )
	//{ 
	//	printf( "PQPrint queue is empty" );
	//	return;
	//}
	if( i>=PQSize(q) || i<0)
	{ 
		return;
	}
	const void* t=q->pPQueue[ i ]->pInfo;
	printf( "prior(%d),index[%d] ",q->pPQueue[ i ]->nPrior,i );
	print( t ); 
	//drukujemy lewe i prawe dziecko
	PQPrint( q,print,2*i+1 );
	PQPrint( q,print,2*i+2 );



}
//---------------------------------------------------------------
int PQGetPrior( PQueue* q,QPINFO* pInfo,int ( __cdecl* compare )( const void*,const void* ) )
{
	return PQgetPrior( q,PQFind( q,compare,pInfo ) );

}


int PQgetPrior( PQueue* q,int position )// zwraca priorytet informacji uzytkownika z zadanej pozycji w kolejce lub PRIOR_ERROR
{
	if(position>q->nPQCurrSize || position == POS_ERROR )
	{
		return PRIOR_ERROR;
	}
	return q->pPQueue[ position ]->nPrior;

}
int PQFind( PQueue* q,int ( __cdecl* compare )( const void*,const void* ),QPINFO* Info )
// zwraca indeks wyszukiwanej informacji uzytkownika, nie znana struktura informacji uzytkownika dlatego
// przekazac trzeba funkjce porownujaca informacje uzytkownika
// Zwaraca POS_ERROR jesli nie ma info w kolejce
{
	if( !q || !compare )

	{
		return POS_ERROR;
	}
	int ix=0;
	const void* searched=( const void* )Info;
	const void* current;
	while(ix<q->nPQCurrSize)
	{
		current=( const void* )q->pPQueue[ ix ]->pInfo;
		if(compare( searched,current )==0)
		{
			return ix;
		}
		ix++;
	}
	return POS_ERROR;

}
int PQsetPrior( PQueue* q,int position,int newPrior )
// ustawia nowy priorytet dla informacji uzytkownika bedacej na zadanej pozycji w kolejce (indeks w tablicy),
// Funkcja zwraca poprzedni priorytet. W przypadku bledu zwraca PRIOR_ERROR // wyszkac pozycje i wywo³aæ PQSetPrior()//
{
	if(!q)
	{
		return PRIOR_ERROR;
	}
	if(position>q->nPQCurrSize)
	{
		return PRIOR_ERROR;
	}
	int prevPrior=q->pPQueue[ position ]->nPrior;
	q->pPQueue[ position ]->nPrior=newPrior;
	return prevPrior;



}
int PQSetPrior( PQueue* q,QPINFO* pInfo,int ( __cdecl* compare )( const void*,const void* ),int newPrior )
{
	return PQsetPrior( q,PQFind( q,compare,pInfo ),newPrior );

}
//=======================================


void UpdateDown( int l,int p,PQueue* q )
{
	if(l >= p) return;
	int i = l;
	int j = 2 * i + 1;
	PQItem* temp = q->pPQueue[ l ];
	while(j <= p)
	{
		if( j<p && q->pPQueue[ j ]->nPrior < q->pPQueue[ j+1 ]->nPrior)
			j++;
		if(temp->nPrior >= q->pPQueue[ j ]->nPrior) break;
		q->pPQueue[ i ] = q->pPQueue[ j ];
		i = j;
		j = 2 * i + 1;
	}
	q->pPQueue[ i ] = temp;

}
void UpdateUp( int l,int p,PQueue* q )
{
	

	if(l >= p) return;
	int i = p;
	int j = ( i - 1 )/ 2; // indeks rodzica 

	PQItem* temp=q->pPQueue[i];
	while(j>=l && q->pPQueue[ j ]->nPrior < temp->nPrior)
	{
		
		q->pPQueue[ i ] = q->pPQueue[ j ];
		i = j;
		j = ( i + 1 ) / 2-1;
	} 
	q->pPQueue[ i ]=temp;
	


}

