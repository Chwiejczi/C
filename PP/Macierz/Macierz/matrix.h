#ifndef MATRIX 
#define MATRIX 
int CreateMatrix( double*** pTab,int nDim );  
void DeleteMatrix( double*** pTab,int nDim );
void TransMatrix( double** pTab,int nDim ); 
void InverseMatrix( double** pInv,double** pTab,int nDim,double det );
double Det( double** pTab,int nDim ); 
void PrintMatrix( double** pTab,int nDim ); 

#endif