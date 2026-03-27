#pragma once 
using namespace std; 
#include <iostream> 


#define STACK_OVERFLOW 0x01 
#define STACK_UNDERFLOW 0x02 
#define STACK_OTHER_ERROR 0xFF 
template <class T> class Stack;  //zapowiedz klasy
class StackException
{ 
public:
	StackException( int mErr=STACK_OVERFLOW ) { mErrCode=mErr; }
	const char* getReason();
private:
	int mErrCode;
}; 

inline const char* StackException::getReason()
{
	switch(mErrCode)
	{
	case STACK_OVERFLOW: return "stack is overflow";
	case STACK_UNDERFLOW:return "stack is empty"; 
	case STACK_OTHER_ERROR:return "stack other err";
	default: return"other satck error";
	}

}

template <class T> class StackItem
{ 
private: 
	StackItem( T key, StackItem<T>* pNext);
	virtual ~StackItem();
	T getKey() const; 
	void setKey(T key); 
	void setNext( StackItem<T>* pNext ); 
	StackItem<T>* getNext() const;
	friend class Stack<T>;//wszystkie metody klasy stack maja dostep do interface prywatnego

private:  
	T mKey;
	StackItem<T>* m_PNext;


};

//------------------------

template<class T> class Stack
{ 

private: 
	StackItem<T>* m_pHead; 


public: 
	Stack(); 
	virtual ~Stack();
	void push( T key ); 
	T pop(); 
	T top(); 
	void del(); 
	bool isEmpty() const;
}; 




 template <class T> T StackItem<T>:: getKey() const
{
	return mKey;
}
 template <class T> StackItem<T>* StackItem<T>::getNext() const
{
	return  m_PNext;
}
template <class T> void StackItem<T>:: setKey( T key )
{ 
	this->mKey=key;

}
template <class T> void StackItem<T>:: setNext( StackItem<T>* pNext )
{
	this->m_PNext=pNext;
}
 template <class T> bool Stack<T>::isEmpty() const
{
	return !m_pHead;
} 



//--------przeniesione z cpp
 template <class T> Stack<T>::Stack()
 {
	 m_pHead = nullptr;
 }

 template <class T> StackItem<T>:: ~StackItem()
 {

 }


 template <class T>StackItem<T>::StackItem(T key, StackItem<T>* pNext)
 {
	 setKey(key);
	 setNext(pNext);
 }

 template <class T> Stack<T>:: ~Stack()
 {
	 while (!isEmpty())
		 del();
 }
 template <class T> void Stack<T>::push(T key)
 {
	 StackItem<T>* p = new(nothrow) StackItem<T>(key, m_pHead);//przy bledzie zwracamy null 
	 if (!p)
		 throw StackException(STACK_OVERFLOW);
	 m_pHead = p;


 }
 template <class T> T Stack<T>::pop()
 {
	 if (!isEmpty())
	 {
		 T c = top();
		 del();
		 return c;
	 }
	 throw StackException(STACK_UNDERFLOW);
 }

 template <class T> T Stack<T>::top()
 {
	 if (!isEmpty())
	 {
		 return m_pHead->getKey();
	 }
	 throw StackException(STACK_UNDERFLOW);
 }
 template <class T> void Stack<T>::del()
 {
	 if (!isEmpty())
	 {
		 StackItem<T>* p = m_pHead;
		 m_pHead = p->getNext();
		 delete p;
	 }
	 else
	 {
		 throw StackException(STACK_UNDERFLOW);
	 }
 }