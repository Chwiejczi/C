#include "person.h"

person:: person(string name , int age )
{
setPerson(name,age);
}
person::person(const person& p)
{
*this=p;
}
person::~person()
{

}

