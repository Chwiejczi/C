//ODWROTNA NOTACJA POLSKA

#include <iostream>
#include <stdio.h>
#include "Util.h"
#include "Stack.h"

void ONP();

int main()
{
  ONP();
  return 0;
}

void ONP()
{
  StackItem* pStack = NULL;
  createStack(&pStack);
  StackItem* pStack2 = NULL;
  createStack(&pStack2);

  double cOper = getArg();
  printf("%f", cOper);
  while (isOper(cOper = getOper()))
  {
    while (prior(cOper) <= prior(top(pStack)))
      printf("%f", pop(&pStack));
    push(&pStack, cOper);
    printf("%f", cOper = getArg());
  }
  while (!isEmpty(pStack))
    printf("%f", pop(&pStack));
}