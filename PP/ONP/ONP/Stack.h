//zabezpieczyc przed wielokrotnym inkludowaniem
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

//interfejs publiczny modulu stosu

typedef struct tagStackItem
{
  double key;
  tagStackItem* pNext;
} StackItem;

void push(StackItem** pStack, double c); //wlozyc na stos znak x
double pop(StackItem** pStack); //zdjecie ze stosu elementu szczytowego i zwrocenie go (=top() + del())
double top(StackItem* pStack); // zwraca wartosc elementu szczytowego (nie usuwa go)
void del(StackItem** pStack); // usuwa element szczytowy
int isEmpty(StackItem* pStack);//sprawdza, czy stos jest pusty, jesli tak to TRUE(1) else FALSE(0)
void createStack(StackItem** pStack);

#endif 