#include "matrix.h" 
#include <stdio.h> 
#include <memory.h> 
#include <stdlib.h> 

void Complement( double** pTabO,double** pTabI,int nRow,int nCol,int nDim );
void ComplMatrix( double** pTabD,double** pTab,int nDim ); 

int CreateMatrix( double*** pTab,int nDim )
{ 
	if(nDim<0 || !pTab)
	{
		return 0;
	} 

	*pTab=( double** )malloc( nDim* sizeof( double* ) ); 
	if(!*pTab)
	{
		return 0;
	}
	memset( *pTab,0,nDim* sizeof( double* ) );
	for(int i=0; i<nDim; i++)
	{ 
		(*pTab)[ i ]=( double* )malloc( nDim*sizeof( double ) ); 
		if(!( *pTab )[ i ])
		{ 
			free( *pTab );
			return 0;
		} 
		memset( (*pTab)[ i ],0,nDim*sizeof( double ) );
	}
	return 1;
} 
void DeleteMatrix( double*** pTab,int nDim )
{ 
	if( nDim<0 || !pTab )
	{
		printf( "DeleteMatrix: size error" ); 
		return;
	}
	for( int i=0; i<nDim; i++ )
	{ 
		free( (*pTab)[ i ] ); 
		( *pTab )[ i ]=NULL;
	} 
	free( *pTab ); 
	*pTab=NULL;
}
void TransMatrix( double** pTab,int nDim )
{  
	if(nDim<0 || !pTab)
	{
		printf( "TransMatrix: error" );
		return ;
	}

	for(int i=0; i<nDim-1; i++)
	{
		for(int j=i+1; j<nDim; j++)
		{	
			double temp=pTab[ i ][ j ]; 
			pTab[ i ][ j ]=pTab[ j ][ i ]; 
			pTab[ j ][ i ]=temp;

		}
	}
}  

// macierz odwrotna, na we obliczony wczesniej w main() det  (tu w funkcji juz na pewno musi byc det!=0)
void InverseMatrix( double** pInv,double** pTab,int nDim,double det )
{   
	if( pInv==NULL || pTab==NULL ||nDim<=0 ) return;
	ComplMatrix( pInv,pTab,nDim );
	TransMatrix(pInv ,nDim );

	for(int i=0; i<nDim; i++)
	{
		for(int j=0; j<nDim; j++)
		{
			pInv[ i ][ j ] /= det;
		}
	}  
}  


// wyznacznik rekurencyjnie 
// dla 2x2 uzyc znanego wzoru - mozna zaindeksowac
double Det( double** pTab,int nDim ) //rozwiniecie wzgl 0-go wiersza 
{ 
	if(nDim<0 || !pTab)
	{
		printf( "Det: error" );
		return 0;
	}   
	if(nDim==1)	return **pTab;
	if(nDim==2) return **pTab*pTab[ 1 ][ 1 ]-pTab[ 0 ][ 1 ]*pTab[ 1 ][ 0 ]; 

	double** minor = NULL;  
	if( !CreateMatrix( &minor,nDim-1 ) )
	{
		printf( "Det: creating Matrix error" ); 
		return 0;

	}
	double det=0;
	double sign = 1;
	for(int j=0; j<nDim; j++)
	{
		Complement( minor,pTab,0,j,nDim ); 
		det+=sign*pTab[ 0 ][ j ]*Det( minor,nDim-1 );
		sign = -sign;
	}  
	DeleteMatrix( &minor,nDim-1 );
  return det;

} 

void PrintMatrix( double** pTab,int nDim )
{  
	for(int i=0; i<nDim; i++)
	{ 
		double* p=*pTab++;//pTab[i]
		for(int j=0; j<nDim; j++)
		{
			printf( " %lf ",*p++);
		}
		printf( "\n" );
	}
	
} 


// wycina wiersz nRow i kolumne nCol z tab we pTabI i reszte kopiuje do 
// tabl wyjsciowej pTabO 
// nalezy uzyc dwa razu continue pomijajac wiersz nRow i kolumne nCol
void Complement( double** pTabO,double** pTabI,int nRow,int nCol,int nDim )
{  
	if( pTabO==NULL||pTabI==NULL||nDim<=0 )return;
	int Row=0; 
	for( int i=0; i<nDim; i++ )
	{  	
		if(i==nRow)continue; 
		int Col=0;
		for( int j=0; j<nDim; j++ )
		{
			if(j==nCol)continue; 
			pTabO[ Row ][ Col ]=pTabI[ i ][ j ]; 
			Col++; 
		} 
		Row++;
	}
} 


// oblicza macierz dopelnien pTabD na podstawie tablic wejsc pTab
void ComplMatrix( double** pTabD,double** pTab,int nDim ) //macierz dopelnien
{  
	if(pTabD==NULL || pTab==NULL || nDim<=0)return;
	double** minor = NULL; 
	CreateMatrix( &minor,nDim-1 );
	for(int i=0; i<nDim; i++)	
	{
		int sign = ( i%2 )? -1 : 1;
		for(int j=0; j<nDim; j++)
		{  
			Complement( minor,pTab,i,j,nDim );
			pTabD[ i ][ j ]=sign*Det( minor,nDim-1 );
			sign =-sign;
		}
	} 
	DeleteMatrix( &minor,nDim-1 ); 
	
	
}





