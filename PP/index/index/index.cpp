// index.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "IND.h"
int main( int argc,char* argv[])
{
    if(argc != 2)
    {
        printf( "Usage: %s <input_file>",argv[ 0 ] );
        return 1;
    }  
    TreeItem* pRoot=NULL;
    ReadFile( argv[ 1 ],&pRoot ); 
    FILE* Fnew=fopen( "IndeksSlow.txt","w" ); 
    if(!Fnew)
    {
        printf( "file didn't open\n" ); 
        return 6;
    }   
    _2File( pRoot,Fnew ); 
    FreeTree3( pRoot );
    return 0;
}

