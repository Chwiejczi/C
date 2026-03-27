// PD 17.03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Sort.h"
#include <stdio.h> 
#include<memory.h> 
#include<time.h>
#include<stdlib.h>
#define ARGNO 2
#define TEST 

typedef void( *Sort )( int[],int );

int CreateTab( int** pTab, int nSize ); 
void initTab( int* pTab, int nSize );
void printTab( int* pTab, int nSize );

int main( int argc,char* argv[] ) //argc romiar tablicy argv, argv[0]-nazwa,argv[1]-1 argument<-w tym przypadku wielkosc tablicy<-ARGNO2//ilosc elementow do posortowania w properties-> debugging
{   
   
    
    //sprawdzic parametry 
    if( argc != ARGNO )
    {
        printf( "Usage:%s <tab_size>\n", argv[ 0 ] );
        return 1;
    }
    //obliczyc rozmiar tablicy  
    //argv[1]<-string, to uzywamy atoi 
    int nSize = atoi( argv[1] ); 
    printf( "Tab size =%d\n", nSize );
    
    //alokacja tablicy wzorcowej i jej zainicjowanie (funkje) 

    int* pTab = NULL; 
    if( !CreateTab( &pTab,nSize ) )
    { 
        printf( "pTab allocation error\n" );
        return 2;
    }
    initTab( pTab,nSize );
  
    // wydruk na warunkowej kompil
#ifdef TEST 
    printf( "\nTablica wzorcowa:\n" ); 
    printTab( pTab, nSize );  
    printf( "\n\n" );
#endif 
    //zdefiniowac tablice napisow - nazw tych sortowan (do wypisywania) 
    Sort pSortTab[] = { simpleInsertion ,simpleSelection,bubbleSort,mixSort,halfFindSort,QuickSort,HeapSort };
    const char* names[] = { "Insertionsort","Selectionsort","Bubblesort","Mixsort","HalfFindSort","Quicksort","Heapsort" };
    //----------odczytac czasy poszczegolnych sortowan

        // alokacja pamieci na tabl do sortow 
    int* pCpy = NULL; 
    if(!CreateTab( &pCpy,nSize ))
    {
        printf( "pCpy allocation error" );
        return 3;
    }

     // obliczyc rozmiar tablicy adresoww funkcji 
    int nSizeTab = sizeof( pSortTab ) / sizeof( Sort );

   //TO W PETLI for 
    for( int i = 0; i < nSizeTab; i++ )
    {
        // wkopiowanie do niej tabl wzorcowej
        memcpy( pCpy, pTab, sizeof(int)* nSize );
         // -- odczytac czas  clock() 
        clock_t reading = clock();
        
           // -- posortowac 
        pSortTab[i]( pCpy, nSize );
         // -- odczytac czas i wypisac czas sortowania (wzor w helpach), wypisac nazwe srtowania 
        
        double time = ( double )( clock() - reading ) / CLOCKS_PER_SEC;
        printf( "\nSorting time for %s = %.3f s\n", names[i], time );
         // -- na warunkowej kompilacji wydruk posortowanej 
   #ifdef TEST 
        printf( "\nPosortowana Tablica:\n" );
        printTab( pCpy, nSize );
   #endif
    }
        // zwolnic pamiec
   
   
    free( pTab ); 
    free( pCpy );
    return 0;
}

void initTab( int* pTab, int nSize )
{
   
    srand( unsigned( time( NULL ) ) );
    for( int i = 0; i < nSize; i++ )
    {
        pTab[i] = rand() % nSize; 
    }

} 
void printTab( int* pTab, int nSize )
{
    for( int i = 0; i < nSize; i++ )
    {
        printf( "%2d ", *pTab++ );
        if( (i + 1) % 10 == 0 )
            printf( "\n" );
    }

} 
int CreateTab( int** pTab, int nSize )
{

    *pTab = ( int* )malloc( nSize * sizeof(int) );
    if( !*pTab )
    {
        return 0;
    }
    memset( *pTab, 0, nSize * sizeof(int) ); 
    return 1;
} 





