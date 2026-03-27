
#include <stdlib.h> 
#include <stdio.h>  
#include "matrix.h"  
#include "math.h"
#define E 1e-20
void ReadData( FILE* fin,double** pMatrix,int nDim );

#define _DEBUG_

int main( int argc,char* argv[] )
{ 
   
    if(argc != 2)
    {   
        printf( "Usage: %s <input_file>",argv[ 0 ] );
        return 1;
    }
    // otworzyc plik do odczytu   -- argv[1] i sprawdzic czy sie powiodlo 
    FILE* fin=fopen( argv[ 1 ],"r" ); 
    if(!fin)
    {
        printf( "fin error" ); 
        return 2;
    } 

  /*=========================================
  Uzywac fopen a nie fopen_s jak proponuje Visual Studio
  Aby wylaczyc ewentualne bledy lub warningi nalezy do projektu dodac stosowna stala

  menu->Project-> <nazwa_projektu> Properties -> Configuration Properties -> C/C++ -> Preprocessor
  dodac stala preprocesora: _CRT_SECURE_NO_WARNINGS

  I przekompilowac calosc od zera
  ====================================*/
  // odczytac rozmiar nDim  
    int Dim; 
    fscanf( fin,"%d",&Dim );
   

#ifdef _DEBUG_
     
    if(Dim<=0)
    {
        printf( "wrong dimension" );
        return 4;
    } 
    printf( "\nDim size =%d\n",Dim );
#endif 
    // wykreowac macierz ukladu nDim x nDim
    double** pMatrix = NULL; 
    if( !CreateMatrix( &pMatrix,Dim ) )
    {
        printf( "CreateMatrix error" ); 
        return 33;
    }
    // wczytac dane ( ReadData() ) 
    ReadData( fin,pMatrix,Dim );

#ifdef _DEBUG_
//wydruk kontrolny wczytanych danych  
    printf( "test print\n" );
    PrintMatrix( pMatrix,Dim );
#endif
 // obl wyznacznik
    double det=Det( pMatrix,Dim ); 
    if(fabs( det )<E)
    {
        printf( "\ndeterminant=0\n" ); 
        return -1;
    }
    
    printf( "\ndeterminant=%lf\n\n",det );
  // obrocic macierz  
    double** InvMatrix = NULL; 
    if( !CreateMatrix( &InvMatrix,Dim ) )
    {
        printf( "Create Matrix error" ); 
        return 13;
    }
    InverseMatrix( InvMatrix,pMatrix,Dim,det ); 

    printf( "Inversed Matrix\n" );
    PrintMatrix( InvMatrix,Dim );
  
  // wyniki
    DeleteMatrix( &pMatrix,Dim ); 
    DeleteMatrix( &InvMatrix,Dim );
    return 0;
}
void ReadData( FILE* fin,double** pMatrix,int nDim )
{ 

    for(int i=0; i<nDim; i++)
    { 
        double* v=*pMatrix++;
        for(int j=0; j<nDim; j++)
        {
            fscanf( fin,"%lf",v++);
        }
    }
}

/*
UWAGI DODATKOWE:

-mozna najpierw przetestowac na ukladzie 3x3
- wydruki kontrolne na warunkowej kompilacji
- parametrem programu jest nazwa pliku z danymi - pierwsza linia
to rozmiar macierzy ukladu ( lub ilosc rownan i niewiadomych )
a potem wiersz macierzy ukladu i wyraz wolny w tej samej linii np dla ukl 3x3 byloby
3
1   2  3
2   0  0
-1 -1 -1

- tylko standardowe we/wy
-  _CRT_SECURE_NO_WARNINGS
*/