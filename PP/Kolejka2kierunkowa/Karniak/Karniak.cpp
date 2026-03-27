
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>  
#include "List.h" 
#define PREV  -1 
#define NEXT   1 
#define FIRST -2 
#define LAST   2
int main()
{ 
	ListItem* list=ListCreate(); 
	if(!list)
	{
		printf( "Creating error" ); 
		return 1;
	}  

	
	Add2List( 1,list,1,FIRST ); 
	ListPrint( list ); 
	printf( "\n" ); 
	//=============
	Add2List( 2,list,1,LAST );  
	ListPrint( list ); 
	printf( "\n" ); 
	//=============
	Add2List( 3,list,1,FIRST ); 
	ListPrint( list ); 
	printf( "\n" ); 
	//============= 
	Add2List( 4,list,1,NEXT );
	ListPrint( list );
	printf( "\n" ); 
	//============= 
	Add2List( 5,list,2,PREV );
	ListPrint( list );
	printf( "\n" ); 
	//============= 
	Add2List( 6,list,2,NEXT );
	ListPrint( list );
	printf( "\n" );
	//============= 
	Add2List( 7,list,3,PREV );
	ListPrint( list );
	printf( "\n" ); 
	//============= 
	RemoveElem( list,7 ); 
	ListPrint( list );
	printf( "\n" );
	//============= 
	RemoveElem( list,6 );
	ListPrint( list );
	printf( "\n" );
	//============= 
	RemoveElem( list,4 );
	ListPrint( list );
	printf( "\n" );
	//=============
	Add2List( 7,list,88,PREV );
	ListRemove( &list ); 

	return 0;
}

