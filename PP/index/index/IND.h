#ifndef INDEX
#define INDEX 
#include "pom.h"
typedef struct TagTreeItem
{
    char* word; 
	TagTreeItem* pLeft;
	TagTreeItem* pRight; 
	int counter; 
	FQueue* FIFO;

} TreeItem;

TreeItem*   FindInsert2( TreeItem* pRoot,char* string,int lineNumber ); 
void        Visit( TreeItem* pRoot,int lineNumber );
int         compStr( char* s1,char* s2 ); 
void        ReadFile( char* File,TreeItem** pRoot );
TreeItem*   FreeTree3( TreeItem* pRoot ); 
void        inOrder( TreeItem* pRoot ); 
void        _2File( TreeItem* pRoot, FILE*fout ); 
void        QFprintFile( FQueue* q,FILE* fout );
#endif