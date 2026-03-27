#include "Header.h" 
#include "stdio.h" 
#include "stdlib.h" 
typedef enum{G1,G2,P1,P2,D1,D2,L1,L2} move;
int** CreateTab ( int nRows,int nCols )
{
	if(nCols<=0 || nRows<=0)
	{
		printf( "CreateTab2D:wrong size" );
		return 0;
	}
	int** p = ( int** )calloc( nRows,sizeof( int* ) );
	if(!p) return NULL;
	p[ 0 ] = ( int* )calloc( nRows*nCols,sizeof( int ) );
	if(!*p)return NULL;

	int* t=p[ 0 ];
	for(int i=1; i<nRows; i++)
	{
		t += nCols;
		p[ i ] = t;
	}
	return p;

} 
int Move ( int** pTab,int nRows,int nCols,int x,int y,int* px,int* py,int move )
{
	if(!pTab)
	{
		printf( "pTab error" ); 
		return 0;
    } 
	if(x<0|| x>=nRows || y<0 || y>=nCols)
	{
		return 0;
	} 
	switch(move)
	{
	case G1: *px=x-1; *py=y+2; break;
	case G2: *px=x+1; *py=y+2; break;
	case P1: *px=x+2; *py=y+1; break;
	case P2: *px=x+2; *py=y-1; break;
	case D1: *px=x-1; *py=y-2; break; 
	case D2: *px=x+1; *py=y-2; break; 
	case L1: *px=x-2; *py=y+1; break; 
	case L2: *px=x-2; *py=y-1; break;
	default: return 0;
	}
	if(*px<0|| *px>=nRows || *py<0 || *py>=nCols)
	{
		return 0;
	} 
	if(pTab[ *px ][ *py ]!=0)return 0;
	return 1;
} 
int FillTab( int** pTab,int nRows,int nCols,int x,int y )//rekurencyjna
{	
	int xnew;
	int ynew;
	static int step=1; 
	pTab[ x ][ y ]=step;
	if(step==nRows*nCols) return 1; 
		step++;
	for(int i=G1; i<=L2; i++)
	{
		if(Move( pTab,nRows,nCols,x,y,&xnew,&ynew,i ))
		{ 
				if(FillTab( pTab,nRows,nCols,xnew,ynew ))return 1;
				
	    }  
		
	} 
	step--;
	pTab[ x ][ y ]=0;
	return 0;
}
