#include "Sort.h" 
#include <stdio.h> 

void Update( int l, int p, int* pTab );
void Quick( int l, int p, int* pTab );

void  simpleInsertion( int* pTab, int nSize )
{
	for( int i = 1; i < nSize; i++ )
	{
		int x = pTab[i];
		int j = i - 1;
		while( j >= 0 && pTab[j] > x )
		{
			pTab[j + 1] = pTab[j--];
		}
		pTab[j + 1] = x;
	}


}


void  simpleSelection( int* pTab, int nSize )
{
	for( int i = 0; i < nSize; i++ )
	{
		int min = pTab[ i ];
		int ix_min = i;
		for( int j = i + 1; j < nSize; j++ )
			if( pTab[ j ] < min )
			{
				min = pTab[ j ];
				ix_min = j;
			}
		pTab[ ix_min ] = pTab[ i ];
		pTab[ i ] = min;
	}


}
void  bubbleSort( int* pTab, int nSize )
{ 
	for( int i = 1; i < nSize; i++ )
	{
		for( int j = nSize - 1; j >= i; j-- )
		{
			if( pTab[j] < pTab[j - 1] ) 
			{
				int temp = pTab[j];
				pTab[j] = pTab[j - 1];
				pTab[j - 1] = temp;	
			}
		}
	}

} 
void mixSort( int* pTab, int nSize )
{ 
	int l = 1;
	int p = nSize - 1;
	int k = nSize - 1; 
	int temp;
	do
	{
		for( int i = p; i >= l; i-- )
		{
			if( pTab[ i - 1 ] > pTab[ i ] )
			{
				temp = pTab[ i ];
				pTab[ i ] = pTab[ i - 1 ];
				pTab[ i - 1 ] = temp;
				k = i;
			}
		}
		l++;

		for( int i = l; i <= p; i++ )
		{
			if( pTab[ i - 1 ] > pTab[ i ] )
			{
				temp = pTab[ i ];
				pTab[ i ] = pTab[ i - 1 ];
				pTab[ i - 1 ] = temp;
				k = i;
			}

		}
		p = k - 1;

	} while( l < p );


} 
void halfFindSort( int* pTab, int nSize )
{
	for( int i = 1; i < nSize; i++ )
	{
		int x = pTab[ i ]; 
		int l = 0; 
		int p = i - 1; 
		int m;
		do
		{ 
			m = ( l + p ) / 2; 
			if( x < pTab[ m ] )p = m - 1;
			else l = m + 1;
		} while( l <= p ); 
		for( int j = i - 1; j >= l; j-- )
		{
			pTab[ j + 1 ] = pTab[ j ]; 
			
		} 
		pTab[ l ] = x;
	}

} 
void QuickSort( int* pTab, int nSize ) 
{ 
	Quick( 0, nSize - 1, pTab );

} 

void Quick( int l, int p, int* pTab )
{
	int i = l; 
	int j = p; 
	int x = pTab[ ( l + p ) / 2 ];  
	do
	{ 
		while( pTab[ i ] < x )i++;
		while( pTab[ j ] > x )j--;
		if( i <= j )
		{
			int temp = pTab[ i ];
			pTab[ i ] = pTab[ j ];
			pTab[ j ] = temp;
			i++;
			j--;
		}

	} while( i <= j ); 

	if( l < j )Quick( l, j, pTab );
	if( i < p )Quick( i, p, pTab );
  
   }
	
	
 
void HeapSort( int* pTab, int nSize )
{
	int p = nSize - 1; 
	for( int i = nSize / 2; i >= 0; i-- ) 
		Update( i, p , pTab );
	
	for( ;p>0;p--)
	{
		int temp = pTab[ 0 ];
		pTab[ 0 ] = pTab[ p ];
		pTab[ p ] = temp;
		Update( 0, p-1, pTab ); 
		
	}

} 
void Update( int l, int p, int* pTab )
{
	if( l >= p ) return;
	int i = l; //index rodzica
	int j = 2 * i + 1; //index lewego dziecka
	int temp = pTab[ i ];
	while( j <= p ) 
	{ 
		 if( j<p && pTab[ j ] < pTab[ j + 1 ] )  j++;    
		 if( temp >= pTab[ j ] ) break;
		pTab[ i ] = pTab[ j ];
		i = j; 
		j = 2 * i + 1; 
	}
	pTab[ i ] = temp;


}


//quicksort,heapSort,halffindSort,mixSort