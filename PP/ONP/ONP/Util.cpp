#include "Util.h"


int isOper(char c)
{
  switch (c)
  {
  case '+':
  case '-':
  case'*':
  case'/':
  case '^': return 1;
  }
  return 0;
}

int prior(char oper)
{
  switch(oper)
  {
  case '+':
  case '-': return 1;
  case'*':
  case '/': return 2;
  case '^': return 3;
  }
  return 0;
}
char getOper()
{
  return getchar();
}
double getArg() //wczytywanie operanda
{
  double d;
  scanf("%lf", &d);
  return d;
}