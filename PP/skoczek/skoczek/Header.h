#ifndef SKOCZEK 
#define SKOCZEK  
#include <stdio.h> 
int** CreateTab (int nRows, int nCols);
int Move ( int** pTab,int nRows,int nCols,int x, int y, int* px, int* py, int move );
int FillTab( int** pTab,int nRows,int nCols,int x,int y );



#endif 

