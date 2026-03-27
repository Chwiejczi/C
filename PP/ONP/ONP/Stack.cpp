#include "Stack.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAXSTACK 10
char Stack[MAXSTACK] = { 0 };
int nHead; //indeks PIERWSZEGO WOLNEGO miejsca na stosie

void push(StackItem** pStack, double c) //wlozyc na stos znak c
{
  StackItem* p = (StackItem*)malloc( sizeof(StackItem) );
  if ( !p )
  {
    printf( "push - memory allocation error!\n" );
    return;
  }
  memset( p, 0, sizeof( StackItem ) );
  p->key = c;
  p->pNext = *pStack;
  *pStack = p;
}

double pop(StackItem** pStack) //zdjecie ze stosu elementu szczytowego i zwrocenie go (=top() + del())
{
  if ( isEmpty( *pStack ) )
  {
    printf("pop - stack is empty!\n");
    return 0;
  }
  double c = top(*pStack);
  del(pStack);
  return c;
}

double top(StackItem* pStack) // zwraca wartosc elementu szczytowego (nie usuwa go)
{
  if ( !isEmpty( pStack ) )
    return pStack->key;
  return 0;
}

void del(StackItem** pStack) // usuwa element szczytowy
{
  if ( isEmpty( *pStack ) )
  {
    printf("del: stack is empty\n");
    return;
  }
  StackItem* p = *pStack;
  *pStack = p->pNext;
  free( p );
}

int isEmpty( StackItem* pStack ) //sprawdza, czy stos jest pusty, jesli tak to TRUE(1) else FALSE(0)
{
  return !pStack;
}

void createStack(StackItem** pStack)
{
  *pStack = NULL;
}