#ifndef PQueue
#define PQUEUE
#include "global.h"  
#include <limits.h>
#define POS_ERROR -1 
#define PRIOR_ERROR INT_MIN
typedef struct tagPQItem
{
	QPINFO* pInfo;
	int nPrior;
} PQItem; 

typedef struct   // zachowac oryginalne nazwy!!!!!!
{
	PQItem** pPQueue;    // kolejka realizowana w postaci stogu  (dynamiczna tablica)
	int nPQMAXSize;   // rozmiar calkowity kolejki priorytetowej
	int nPQCurrSize;  // ilosc elelemntow w kolejce (jednoczensie indeks pierwszego wolnego miejsc w kolejce)//aktualny rozmiar tablilcy 

} PQueue;

PQueue* PQInit( int nSize ); 
int PQisEmpty( PQueue* q );
int PQSize( PQueue* q );
int PQMaxPrior( PQueue* q );
int PQEnqueue( PQueue* q,int prior,QPINFO* Info );
QPINFO* PQDequeue( PQueue* q );
void PQClear( PQueue* q,void ( __cdecl* freeMem )( const void* ) );
void PQRelease( PQueue** q,void ( __cdecl* freeMem )( const void* ) );
void PQPrint( PQueue* q,void ( __cdecl* print )( const void* ), int i );
int PQgetPrior( PQueue* q , int position);
int PQGetPrior( PQueue* q,QPINFO* pInfo,int ( __cdecl* compare )( const void*,const void* ) );
int PQFind( PQueue* q,int ( __cdecl* compare )( const void*,const void* ),QPINFO* Info ); 
int PQsetPrior( PQueue* q ,int position, int newPrior ); 
int PQSetPrior( PQueue* q,QPINFO* pInfo,int ( __cdecl* compare )( const void*,const void* ),int newPrior );
#endif 
