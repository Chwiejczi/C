// drzewo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h> 
#include <stdlib.h>
#include "Tree.h"  
#include <time.h> 
#define BST 
#define MAXBST 10
int main()
{
	TreeItem* pRoot=NULL; 
	//LP_TreeItem p=NULL; 
	
	//pRoot=TreeFinalyBalanced( 10 ); 
#ifndef BST 
pRoot=TreeFinalyBalanced( 10 ); 
#else 
	srand( ( unsigned )time( NULL ) ); 
	for(int i=0; i<MAXBST; i++)
	{  
		pRoot=FindInsert2( pRoot, rand()%(MAXBST<<1) );

	}
	

#endif
	printf( "preorder: " ); 
	preOrder( pRoot ); 
	printf( "\n\n" ); 

	printf( "inorder: " );
	inOrder( pRoot );
	printf( "\n\n" );  

	printf( "postorder: " );
	postOrder( pRoot );
	printf( "\n\n" ); 
	FreeTree1;
	return 0;
}
//kolejny projekt bez polskich liter
//uzyc fifo 
//skupic siê g³ownie na funckji czytaj¹cej 
// 
// 
// 
//KARNIAK
//elementy struktury 
//key,pNexr,pPrev 
//kreowanie, usuwanie dowolnego, wsatwianie dowolnego, czyszczenie, usuwanie listy,drukowanie,wyszukiwanie<-pomocne we wstawianiu 
//5,6 elementow do testu