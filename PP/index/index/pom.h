//zabezpiczenie preprocesorem
#ifndef QFIFO

#define QFIFO

typedef struct tagFQItem
{
	int key;
	tagFQItem* pNext;
} FQItem;

typedef struct
{
	FQItem* pHead;
	FQItem* pTail;
} FQueue;

FQueue* FQCreate();
int     FQEmpty( FQueue* q );
int     FQEnqueue( FQueue* q,int key );
int     FQDequeue( FQueue* q );
void    FQClear( FQueue* q);
void    FQRemove( FQueue** q );//void ( __cdecl* freeMem )-pozwala przekazaæ funckje jako parametr
void    FQDel( FQueue* q );
void    QFPrint( FQueue* q );
//funkcja printinfo zdefiniowana przez usera
//
#endif 