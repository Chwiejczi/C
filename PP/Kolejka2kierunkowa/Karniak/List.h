#ifndef LIST

#define LIST
typedef struct tagFQItem
{
	int key;
	tagFQItem* pNext; 
	tagFQItem* pPrev;
} ListItem;



ListItem*    ListCreate();  
void         Add2List( int x, ListItem* l, int element, int Param); 
int          ListEmpty( ListItem* l ); 
ListItem*    ListSearch( ListItem* l,int x );
ListItem*    RemoveElem( ListItem* l,int key );
void         ListPrint( ListItem* l );
void         ListClear( ListItem* l );
void         ListRemove( ListItem** l );

#endif 
//KARNIAK
//elementy struktury 
//key,pNexr,pPrev 
//kreowanie, usuwanie dowolnego, wsatwianie dowolnego, czyszczenie, usuwanie listy,drukowanie,wyszukiwanie<-pomocne we wstawianiu 
