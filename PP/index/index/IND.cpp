#include<stdio.h> 
#include"IND.h" 
#include <memory.h> 
#include <stdlib.h>
#include <string.h>  
#define MAXLenght 41
//_Check_return_
//int __cdecl strcmp(
//	_In_z_ char const* _Str1,
//	_In_z_ char const* _Str2 
int IsIndetyfier( int sign );  


int IsIndetyfier( int sign )
{ 
	if(( sign>='A' && sign<='Z' )|| ( sign>='a'&& sign<='z' )||( sign>='0'&&sign<='9' ) || sign=='_')
		return 1; 
	return 0;
	
}

void Visit( TreeItem* pRoot, int lineNumber )
{ 
	pRoot->counter++; 
	FQEnqueue( pRoot->FIFO,lineNumber );
	
}
int compStr( char* s1,char* s2 )
{
	char* str1 = ( char* )calloc( MAXLenght ,sizeof( char ) );
	if(!str1)
	{
		perror( "compStr:str1 allocation error\n" );
		return 0;
	}
	char* str2 = ( char* )calloc( MAXLenght ,sizeof( char ) );  //zaalokowac dynamicznie pamiec na kopie drugiego stringa
	if(!str2)
	{
		perror( "compStr:str2 allocation error\n" );
		return 0;
	}
	strcpy( str1,s1 ); //wkopiowac pierwszy do kopii-strcpy()
	strcpy( str2,s2 ); //wkopiowac drugi do kopii 
	_strlwr( str1 ); 
	_strlwr( str2 ); 
	int s=strcmp( str1,str2 ); //return 0-jezeli remis,<0-str1 mniejsze,>0-str2 mniejsze
	free( str1 ); 
	free( str2 ); 
	return s;

} 
TreeItem* FindInsert2( TreeItem* pRoot,char* string, int lineNumber )
{
	if(!pRoot)
	{
		TreeItem* v=( TreeItem* )calloc( 1,sizeof( TreeItem ) ); 
		if(!v)
		{
			printf( "FindInsert2: allocation ERROR" ); 
			return NULL;
		}  
		v->counter=1; 
		v->FIFO=FQCreate(); 
		v->word=string;
		FQEnqueue( v->FIFO,lineNumber ); 
		return v;
	} 
	int compare=compStr( pRoot->word,string );
	if(compare>0)//w lewo
	{
		pRoot->pLeft=FindInsert2( pRoot->pLeft,string,lineNumber );
	} 
	else if(compare<0)
	{
		pRoot->pRight=FindInsert2( pRoot->pRight,string,lineNumber);
	} 
	else
	{
		Visit( pRoot,lineNumber );
	} 
	return pRoot;
} 
TreeItem* FreeTree3( TreeItem* pRoot )
{
	if(pRoot)
	{
		pRoot->pLeft=FreeTree3( pRoot->pLeft );
		FreeTree3( pRoot->pRight );
		free( pRoot );
	}
	return NULL;
} 
void inOrder( TreeItem* pRoot )
{
	if(!pRoot)return; //koniec 
	inOrder( pRoot->pLeft );
	printf( "word:%s,counter:%d,line number:  ",pRoot->word,pRoot->counter); 
	QFPrint( pRoot->FIFO );
	inOrder( pRoot->pRight );


}  
void QFprintFile( FQueue* q,FILE* fout )
{
	if(FQEmpty( q ))
	{
		fprintf( fout,"  QFPrint: empty " );
		return;
	}
	FQItem* info=q->pHead;
	const void* p=NULL;

	while(info)
	{
		p=( const void* )info;
		fprintf( fout,"%d ",info->key );
		info=info->pNext;
	}
	fprintf( fout,"\n" );

}

void _2File( TreeItem* pRoot,FILE* fout )
{  
	if(!pRoot)return;  
	_2File( pRoot->pLeft,fout );
	fprintf(fout, "word:%s,counter:%d,line number:  ",pRoot->word,pRoot->counter );
	QFprintFile( pRoot->FIFO,fout );
	_2File( pRoot->pRight,fout );

} 
void ReadFile( char* File,TreeItem**  pRoot )
{ 
	FILE* fin=fopen( File,"r" ); 
	if(!fin)
	{
		printf( "ReadFile: File didn't open\n" ); 
		fclose( fin );
		return ;
	}
	//zmienna na nr linii-int 
	int lineNumber=0;
	//zmienna znak- int 
	int sign=0;
	//pêtla nr1 while !eof 
	while((sign=fgetc(fin))!=EOF)
	{
		//alloc na 41 znakow 
		char* str=( char* )calloc( MAXLenght,sizeof( char ) ); 
		if(!str)
		{
			printf( "ReadFile: allocation error" );  

			return;
		}
		//pêtla nr2    (indetyfikator sie konczy jezeli jest cos nnego niz litera cyfa _) 
		while( !IsIndetyfier( sign ) )//przewijamy dopoki nie znajdziemy indentyfikatora
		{ 
			if(sign==EOF) break;
			// spr, czy nie jest nowa linia 
			if(sign=='\n')
				lineNumber++;
			//fgetc()dopoki nie znjadziemy indentyfikatora 
			sign=fgetc( fin ); 
			// koniec p2 
		}
		//zmienna która indeksuje slowo  
		int index=0;
		//pêtla nr3 while (dopoki indentyfikator siê nie skonczy, s  
		while( index<MAXLenght && IsIndetyfier( sign) )
		{ 
			 
			str[ index ]=( char )sign; 
			index++;
			sign=fgetc( fin );  

		}
		//do wyrazu dodac 0(ASCII)  
		str[ index ]=0; 
		*pRoot=FindInsert2( *pRoot,str,lineNumber );
		 
	}
	fclose( fin );
}
