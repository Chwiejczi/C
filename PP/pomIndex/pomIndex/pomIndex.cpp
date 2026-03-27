//QFINFO
//zwalniaæ pamiêæ //
#include <stdio.h> 
#include <stdlib.h> 
#include <memory.h> 
#include "pom.h" 


int main()
{
    FQueue* MyQueue = FQCreate();

    for(int i = 1; i <= 4; i++)
    {
        
        if(!FQEnqueue( MyQueue,i ))
        {
            printf( "FQEnqueue:  allocation error!\n" );
            return 1;
        }
    }

    QFPrint( MyQueue );

    for(int i = 1; i <= 3; i++)
    {
        FQDel( MyQueue );
    }

    QFPrint( MyQueue );

    for(int i = 20; i <= 21; i++)
    {
         
        if(!FQEnqueue( MyQueue,i ))
        {
            printf( " FQEnqueue:  allocation error\n" );
            return 2;
        }
    }

    QFPrint( MyQueue );
    FQClear( MyQueue);

    for(int i = 21; i <= 23; i++)
    {
        
        if(!FQEnqueue( MyQueue,i+1 ))
        {
            printf( "FQEnqueue: allocation error!\n" );
            return 3;
        }
    }

    QFPrint( MyQueue );
    FQDel( MyQueue );
    QFPrint( MyQueue );
    FQRemove( &MyQueue );

    return 0;


}

