#include "List.h" 
#include <stdio.h>  
#include <memory.h> 
#include <stdlib.h> 
ListItem* ListCreate()
{
	ListItem* l = ( ListItem* )calloc( 1,sizeof( ListItem ) );
	if(!l)
	{
		return NULL;
	}  
	l->pNext=NULL; 
	l->pPrev=NULL;	
	return l;

}  
//x- wartosc ktora wastawiamy do klucza 
//element-element ktorego szukamy na liscie
void    Add2List( int x,ListItem* l,int element, int Param )//paramert okresla, czy dodajemy przed czy po elemencie
{
	
	ListItem* q = ( ListItem* )calloc( 1,sizeof( ListItem ) );
	if(q == NULL) {
		printf( "Add2List: allocation error\n" );
		return;
	}

	q->key = x;
	if( Param == -2 )//dodajemy na pocz¹tek kolejki 
	{ 
		//jezeli lista pusta 
		if( ListEmpty( l ) )
		{ 
			q->pNext=l->pNext;	
			l->pPrev=q; 
		}
		else
		{ 
			q->pNext=l->pNext;		
			( q->pNext )->pPrev=q; 
		} 	  
		q->pPrev=NULL; 
		l->pNext=q;
		return;

	}
	if( Param==2 )//dodajemy na koniec kolejki 
	{ 
		
		if( ListEmpty( l ) )//jezeli pusta
		{ 	
			l->pNext=q;
		}   
		else
		{ 
			( l->pPrev )->pNext=q;
		}  
		q->pPrev=l->pPrev;
		q->pNext=NULL; 
		l->pPrev=q;
		return;
	}
	
	ListItem* temp=ListSearch( l,element ); 
	if(!temp)
	{  
		return ;
	}
	//wstawianie z lewej strony
	if(Param == -1)
	{
		q->pNext=temp;
		if( temp->pPrev==NULL )//wstawaimy na sam poczatek
		{
			temp->pPrev=q;  
			q->pPrev=NULL; 
			l->pNext=q;
		} 
		else
		{ 
			( temp->pPrev )->pNext=q; 
			q->pPrev= temp->pPrev;
			temp->pPrev=q; 
		} 

	}
	if(Param == 1)//dodajemy z prawej
	{   
		
		if(temp->pNext==NULL)//wstawiamy na sam koniec 
		{ 
			q->pNext=NULL; 
			l->pPrev=q;
		} 
		else
		{ 
			( temp->pNext )->pPrev=q; 
			q->pNext=temp->pNext; 

		}
		temp->pNext=q;
		q->pPrev=temp;
	}

		

} 
int     ListEmpty( ListItem* l )
{
	return( !(l->pNext) );
} 
ListItem*  ListSearch( ListItem* l,int x )//przeszukuje listê, jezeli znajdzie dany element(spr wg key) to go zwraca, jesli nie, to NULL
{	
	ListItem* temp=l->pNext;
	while(temp)
	{ 
		if(temp->key==x)return temp;
		temp=temp->pNext;
	} 
	printf( "there isnt %d key on the list",x ); 
	return NULL;

} 

ListItem* RemoveElem( ListItem* l,int key )
{
	ListItem* target = ListSearch( l,key );
	if(!target) {
		printf( "ListDequeue: key %d not found\n",key );
		return l;
	}

	ListItem* tempPrev = target->pPrev;
	ListItem* tempNext = target->pNext;

	if( tempPrev ) 
		tempPrev->pNext = tempNext;
	else
	{
		l->pNext=tempNext; 
		tempNext->pPrev=NULL;
	}


	if(tempNext)
		tempNext->pPrev = tempPrev;
	else
	{
		l->pPrev=tempPrev; 
		tempPrev->pNext=NULL;
	}
	free( target );
	target = NULL;

	return l;
}
void ListPrint( ListItem* l )
{
	if( !l )
	{
		printf( "list doesnt't exist" ); 
		return;
	} 
	ListItem* temp=l->pNext;
	while(temp)
	{
		printf( " %d ",temp->key ); 
		temp=temp->pNext;
	}
} 
void  ListClear( ListItem* l )
{
	if(!l||ListEmpty(l))
	{
		printf( "ListClear: error" ); 
		return;
	} 
	ListItem* temp=l->pNext; 
	ListItem* next;
	while(temp)
	{
		next=temp->pNext; 
		free( temp ); 
		temp=NULL; 
		temp=next;
	}
	l->pNext=NULL;
}
void    ListRemove( ListItem** l )
{
	ListClear( *l ); 
	free( *l ); 
	*l=NULL;
}