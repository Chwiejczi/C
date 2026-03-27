#include <stdio.h> 
//wydaje mi siê, ze bez komentarzy, bo bêdziemy move uzywac w root;
#include "ship.h"  
#include <memory.h>
typedef enum { up,right,down,left } Move;
int move( int** pTab,int nRow,int nCol,int nDepth,int move,int x,int y,int* px,int* py,int** pRoot )
{   
	
	//0<-gora 
	// 1<-prawo 
	// 2<-dó³ 
	// 3<-lewo
	// x  y - wsporzedne skad robimy nowy ruch 
	
	
  // wykonac kolejny ruch w kierunku move obliczajac nowe wspolrzedne *px *py
	switch( move ) 
	{  
	   case up:*px=x; *py=y+1; break; 
	   case right:*px=x+1; *py=y; break;
	   case down:*px=x; *py=y-1; break;
	   case left:*px=x-1; *py=y; break; 
	   default: return 0;
    }

  // sprawdzic czy nowe indeksy *px i *py sa w zakresie indeksow tablicy 
	if( *px<0 || *px>=nCol )
		   return 0;
	
	if( *py<0 || *py>=nRow )
		   return 0;
	
	// a nastepnie sprawdzic warunek czy nie jest za plytko ">nDepth " oraz
  // czy nie bylo sie juz w lokalizacji (*px,*py) - wg tabl pRoot (wart 0 w nowej lokalicacji)
	if( pTab[ *px ][ *py ]<=nDepth )
		return 0; 
	if( pRoot[ *px ][ *py ]!=0 )
		return 0;
  //  jesli wszystkie warunki poprawne to zwracamy 1 
	return 1;
  //    else 0
}
int root( int** pTab,int nRow,int nCol,int nDepth,int x,int y,int** pRoot,int x_dest,int	y_dest )
{
	// tabl pRoot pamieta droge   -   numer ruchu pole przez ktore odwiedzono (plynie statek) 
    //                                0 pole nie odwiedzone
    // wstawic do tablicy pRoot kolejny numer ruchu 
	
	static int step=1;
	
	pRoot[ x ][ y ]=step++;
	if(x==x_dest && y==y_dest)
	{  	
		return 1;
	} 
	//zdefiniowac nowe wspolrzedne (zmienne lokalne xnew, ynew) 
	int xnew;
	int ynew;  
    // sprwadzic wszystkie mozliwosci ruchu 
	for( int i=up; i<=left; i++ )
	{    //jesli ruch jest mozliwy w zadanym kierunku 
		if( move( pTab,nRow,nCol,nDepth,i,x,y,&xnew,&ynew,pRoot )==1 ) 
		{  
		
			//jesli wykonanie kolejnego kroku sie powiodlo - rekurencyjnie root() 
			if( root( pTab,nRow,nCol,nDepth,xnew,ynew,pRoot,x_dest,y_dest )==1 )
			{  			
				return 1;
			}  
			
		}
	} 
	// jesli wracamy to ustawiamy w pRoot ze ruch byl zly
	step--;
	pRoot[ xnew ][ ynew ]=0;
	
	return 0;
} 
void clearRoot( int** pRoot,int nRow,int nCol )
{ 
   // zeruje tablice  
	memset( pRoot[0],0,nRow*nCol);
	return ;
} 

int setTab( char* sFile,int** pTab,int nRow,int nCol )
{
	// wczytuje dane z pliku 
	FILE* fin=fopen( sFile,"r" ); 
	if( fin==NULL )
	{
		printf( "setTab: error" ); 
		return 0;
	} 
	//int** pRow=pTab;
	for( int i=0; i<nRow; i++ )
	{ 
		int* pCol=*pTab++;
		for( int j=0; j<nCol; j++ )
		{
			fscanf( fin,"%d",&(*pCol++) ); 
			
		} 
		//pRow++;
	}
	  // sFile -  nazwa pliku wejsciowego - parametr main()
	  // pTab  - tablica glebokosci morza
		  // param: nRow, nCol wymiary tablicy glebokosci morza
	  // w razie niepowodzenia otwarcia pliku do odczytu zwraca 0 
	  // else 1  
	fclose( fin );
	return 1;
} 
