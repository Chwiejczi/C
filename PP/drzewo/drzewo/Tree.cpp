#include "Tree.h"  
#include<stdio.h> 
#include<stdlib.h> 
void Visit( TreeItem* pRoot )
{
	//tu wykonuje siê opeeracja na dole wêz³a 
	printf( "key=%d\n",pRoot->key );
}
void preOrder( TreeItem* pRoot )
{
	if( !pRoot )return; //koniec 
	printf( " %d ",pRoot->key ); 
	preOrder( pRoot->pLeft ); 
	preOrder( pRoot->pRight );


} 
void inOrder( TreeItem* pRoot )
{
	if( !pRoot )return; //koniec 
	inOrder( pRoot->pLeft ); 
	printf( "word:%s,  ",pRoot->key );
	inOrder( pRoot->pRight );


} 
void postOrder( TreeItem* pRoot )
{
	if(!pRoot)return; //koniec 
	postOrder( pRoot->pLeft );
	postOrder( pRoot->pRight ); 
	printf( " %d ",pRoot->key );


} 
TreeItem* TreeFinalyBalanced( int n )
{
	if(n<1) return NULL; 
	//roznica miêdzy ilosci¹ wêz³ow drzewa w lewym i prawym poddrzewei moze siê roznic max o 1 
	int nl=n/2; 
	int np=n-nl-1; 
	printf( "podaj klucz:" ); 
	int x; 
	scanf( "%d",&x ); 
	TreeItem* p=( TreeItem* )calloc( 1,sizeof( TreeItem ) );//calloc zeruje pLeft i pRight 
	// jak malloc to wyzerowac pLeft i pRight 
	if(!p)return NULL;  
	p->key=x;
	p->pLeft=TreeFinalyBalanced( nl ); 
	p->pRight=TreeFinalyBalanced( np ); 
	return p;
} 

void FreeTree1( TreeItem* pRoot )
{
	if( !pRoot )return; 
	FreeTree1( pRoot->pLeft ); 
	FreeTree1( pRoot->pRight ); 
	free( pRoot );
}
void FreeTree2( TreeItem** pRoot )
{
	if(*pRoot)
	{
		FreeTree2( &(*pRoot)->pLeft );
		FreeTree2( &(*pRoot)->pRight );
		free( pRoot );
	} 
	pRoot=NULL;
}
TreeItem* FreeTree3( TreeItem* pRoot )
{
	if(pRoot)
	{
		pRoot->pLeft=FreeTree3( pRoot->pLeft );
		FreeTree3( pRoot->pRight );
		free( pRoot );
	} 
	return NULL;
} 
void FindInsert( TreeItem** pRoot,int x )
{
	if(!*pRoot)
	{
		*pRoot=( TreeItem* )calloc( 1,sizeof( TreeItem ) ); 
		( *pRoot )->key=x; 
		//(*pRoot)->pLeft=(*pRoot)->pRight=NULL;nnie potzrebne bo calloc
	} 
	else
	{
		if(x<( *pRoot )->key)
			FindInsert( &( ( *pRoot )->pLeft ),x );
		else if(x>( *pRoot )->key)
			FindInsert( &( ( *pRoot )->pRight ),x );
		else Visit( *pRoot );
	}
} 

TreeItem * FindInsert2( TreeItem* pRoot,int x )
{ 

	if(!pRoot)
	{
		TreeItem *v=( TreeItem* )calloc( 1,sizeof( TreeItem ) );
		v->key=x;
		//(*pRoot)->pLeft=(*pRoot)->pRight=NULL;nnie potzrebne bo calloc 
		return v;
	}
	
	
	if(x<pRoot ->key)
		pRoot->pLeft=	FindInsert2(pRoot ->pLeft ,x );
	else if(x>pRoot ->key)
			pRoot->pRight=FindInsert2( pRoot ->pRight ,x );
	else Visit( pRoot ); 
	return pRoot;
}
