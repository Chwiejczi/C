// skoczek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h" 
#include <stdio.h> 
void PrintTab( int** pTab,int nRow,int nCol ); 
void freeTab2D( int*** pTab );
int main()
{
	int** TAB=CreateTab( 5,5 ); 
	PrintTab( TAB,5,5 ); 
	if(!FillTab(TAB,5,5,0,0))
	{
		printf( "no solution" ); 
		return 15;
	} 
	printf( "\n\n\n" ); 
	PrintTab( TAB,5,5 );
	freeTab2D( &TAB );


	return 0;
}
void PrintTab( int** pTab,int nRow,int nCol ) 
{ 
	for(int i=0; i<nRow; i++)
	{

		int* pCol=*pTab++;
		for(int j=0; j<nCol; j++)
		{

			printf( "%2d ",*pCol++ );

		}
		printf( "\n" );
	}



} 

void freeTab2D( int*** pTab )
{
	// zwolnic 0-owy elem tablicy  
	free( ( *pTab )[ 0 ] );
	// zwolnic tablice tablic 
	free( *pTab );
	// wynulowac wskaznik 
	pTab=NULL;
}