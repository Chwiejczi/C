#pragma once 
using namespace std;
#include <iostream>  
#define FIFO_EMPTY 0x01 
#define FIFO_OTHER_ERROR 0xFF 

class StackException
{
public:
	StackException(int mErr = FIFO_EMPTY) { mErrCode = mErr; }
	const char* getReason();
private:
	int mErrCode;
};

inline const char* StackException::getReason()
{
	switch (mErrCode)
	{
	case FIFO_EMPTY: return "fifo is empty";
	case FIFO_OTHER_ERROR:return "other fifo error";
	default: return"other fifo err";
	}

}



template <class T> class QFIFO;//zapowiadamy uzycie klasy
template <class T> class FIFOItem;//zapowiadamy uzycie klasy
template <class T> class QFIFO
{
private:
	FIFOItem<T>* pHead;
	FIFOItem<T>* pTail; 
	

public:
	QFIFO();
	virtual ~QFIFO();
	bool    FQEmpty() const;
	bool     FQEnqueue(T* Item);
	T* FQDequeue();
	void    FQClear();
	//void    FQRemove();   // czy jezeli jest destruktor, to to jest potrzebne?
	void    QFPrint(); //dopisac 
	void FQDel();

};

template <class T> class FIFOItem
{

public:
	FIFOItem(T* Info);
	virtual ~FIFOItem();
	void setInfo(T* Info);
	T* getInfo();
	void setNext(FIFOItem<T>* Next);
	FIFOItem<T>* getNext();
	

private:
	T* pInfo;
	FIFOItem<T>* pNext; 
	friend class QFIFO<T>; //wszytskie metody tej klasy beda mialy dostep do QFIFO

	
};


//----------gety i sety 
template <class T> void FIFOItem<T>::setInfo(T* Info)
{
	this->pInfo = Info;
}
template <class T> T* FIFOItem<T>::getInfo()
{
	return this->pInfo;
}

template <class T> void FIFOItem<T>::setNext(FIFOItem<T>* Next)
{
	this->pNext = Next;
}


template <class T> FIFOItem<T>* FIFOItem<T>::getNext()
{
	return pNext;
}
 


//===========przeniesione z cpp 



template <class T> QFIFO<T>::QFIFO()
{
	pHead = pTail = nullptr;

}

template <class T> QFIFO<T>:: ~QFIFO()
{

	if (!FQEmpty())
	{
		FQClear();
	}



}
template <class T> void  QFIFO<T>::FQDel()
{
	FIFOItem<T>* ptr = pHead;
	pHead = ptr->getNext();
	if (	FQEmpty())
		pTail = nullptr;
	delete ptr;

}

template <class T> bool QFIFO<T>::FQEmpty() const
{
	return !(pHead);
}


template <class T> bool  QFIFO<T>::FQEnqueue(T* Item)
{
	FIFOItem<T>* NEW = new FIFOItem<T>(Item);  
	if (!NEW)
	{
		cerr << "allocation error!" << endl;
		throw StackException(FIFO_OTHER_ERROR);
		//return false;
	}
	NEW->pInfo = Item;
	NEW->setNext(nullptr);
	if (FQEmpty())
		pHead = NEW;
	else 
		pTail->setNext(NEW);
	pTail = NEW;

	return true;
}

template <class T> T* QFIFO<T>::FQDequeue()
{
	if (FQEmpty())
		throw StackException(FIFO_EMPTY);
	T* temp = pHead->pInfo;


	//teraz tzreba usunac ten element- w FIFO bylo FQDEL 
	FQDel();
	return temp;
}

template <class T> void QFIFO<T>::FQClear()
{

	while (!FQEmpty())
	{
		T* info = FQDequeue();
		delete info;
	}



}

template <class T> void  QFIFO<T>::QFPrint() //dopytac o to
{
	if (FQEmpty())
		throw StackException(FIFO_EMPTY);

	FIFOItem<T>* info = pHead;
	while (info)
	{
		cout << *(info->pInfo);  //*() musi byc tak bo drukuje wskaznik, jezeli tego nie bêdzie to drukuje adres
		cout << '\n';
		info = info->pNext;
	}
}

//==================StackItem

template <class T> FIFOItem<T>::FIFOItem(T* Info)
{
	setInfo(Info);
	setNext(nullptr);

}
template <class T> FIFOItem<T>:: ~FIFOItem()
{
	pInfo = nullptr;
	pNext = nullptr;
}