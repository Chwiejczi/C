// Statek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>  
#include "ship.h" 
#define N 10 
#define M 10 
#define SHIP_DEPTH 5
void PrintTab( int** pTab,int nRow,int nCol ); 
int** CreateTab2D( int nCol,int nRow );  
void freeTab2D( int*** pTab );

int main( int argc,char* argv[] )
{ 
	
	//!!argc
	if(argc != 2)
	{
		printf( "Usage: %s <input_file>",argv[ 0 ] );
		return 1;
	}
	
  //Wykreowac dynamicznie dwie tablice dwuwymiarowe (ogolnie moga byc rozne wymiary szerok i wysok)
	int** pTab=CreateTab2D( N,M ); 
	int** pRoot=CreateTab2D( N,M ); 
  // kreowanie  druga metoda tworzenia dynamicznego tablic 2D
	if( !pTab )
	{
		printf( "pTab allocaion error" ); 
		return 12;

	}   
	if( !pRoot )
	{
		printf( "pRoot allocaion error" );
		return 12;

	}

  // wyzerowac obie tablice (zaleznie czy bylo malloc czy calloc) 
	clearRoot( pTab,N,M ); 
	clearRoot( pRoot,N,M );
  // wczytac dane (sprawdzic argc)  glebokosci 
	if( !setTab( argv[1],pTab,N,M ) )
	{
		printf("loading file error"); 
		freeTab2D( &pTab );
		freeTab2D( &pRoot ); 
		return 5;
	} 
	printf( "\nmorze:\n" ); 
	PrintTab( pTab,N,M ); 
	printf( "\n" );

	

		// Jezeli nie znaleziono drogi od (0,0) do (N-1,M-1)- funkcja rekur root - wypisac 
	if( !root( pTab,N,M,SHIP_DEPTH,0,0,pRoot,N-1,M-1 ) )
	{ 
		printf( " Nie ma mozliwosci doplynac do portu!!\n\n" ); 	 
		PrintTab( pRoot,N,M );
	}
	else
	{  
		// jesli ok to wypisac trase 
		PrintTab( pRoot,N,M );
	}
	 //zwolnic pamiec!! - w funkcji 
	freeTab2D( &pTab ); 
	freeTab2D( &pRoot ); 
	
	return 0;
}
int** CreateTab2D( int nCol,int nRow )
{ 
	if( nCol<=0 || nRow<=0 )
	{
		printf( "CreateTab2D:wrong size" ); 
		return 0;
	}
	int** p = (int**)calloc( nRow,sizeof( int* ) );
	if( !p ) return NULL;
	p[ 0 ] = (int*)calloc( nRow*nCol,sizeof( int ) );
	if( !*p )return NULL; 

	int* t=p[ 0 ]; 
	for( int i=1; i<nRow; i++ )
	{
		t += nCol; 
		p[i] = t;
	}
	return p; 

}


	void freeTab2D( int*** pTab )
	{
		// zwolnic 0-owy elem tablicy  
		free( (*pTab)[ 0 ] );
		// zwolnic tablice tablic 
		free( *pTab );
		// wynulowac wskaznik 
		pTab=NULL;
	}
void PrintTab( int** pTab,int nRow,int nCol )
{ 
	//int** pRow=pTab;
	for( int i=0; i<nRow; i++ )
	{  
		
		int* pCol=*pTab++;
		for( int j=0; j<nCol; j++ )
		{ 
			
			printf( "%2d ",*pCol++);
			
		}
		printf( "\n" ); 
	}

}