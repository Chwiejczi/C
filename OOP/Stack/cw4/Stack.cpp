/*
#include "Stack.h" 
using namespace std;
#include <iostream> 

Stack::Stack()
{
	m_pHead=nullptr;
}  



StackItem:: ~StackItem()
{

} 


StackItem::StackItem( const StackItem* SI )
{

}

StackItem::StackItem( char key,StackItem* pNext )
{
	setKey( key );
	setNext( pNext );
}
 
Stack:: ~Stack()
{
	while(!isEmpty())
		del();
}  
void Stack::push( char key )
{  
	StackItem* p=new(nothrow) StackItem( key,m_pHead );//przy bledzie zwracamy null 
	if(!p)
		throw StackException( STACK_OVERFLOW );
	m_pHead=p;


}
char Stack::pop()
{
	if(!isEmpty())
	{
		char c = top(); 
		del();
		return c;
	} 
	throw StackException( STACK_OVERFLOW );
} 

char Stack:: top()
{
	if(!isEmpty())
	{
		return m_pHead->getKey();
	} 
	throw StackException( STACK_OVERFLOW );
}
void Stack::del()
{
	if(!isEmpty())
	{
		StackItem* p=m_pHead; 
		m_pHead=p->getNext(); 
		delete p; 
	} 
	else
	{
		throw StackException( STACK_OVERFLOW );
	}
}
*/