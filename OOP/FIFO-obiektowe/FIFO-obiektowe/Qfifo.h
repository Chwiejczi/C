#pragma once 
#include "global.h" 

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


class FIFOItem;//zapowiadamy uzycie klasy
class QFIFO
{ 
private: 
FIFOItem* pHead; 
FIFOItem* pTail;

public:  
	QFIFO();
	virtual ~QFIFO();
	bool    FQEmpty() const;
	bool    FQEnqueue(QFINFO* Item);//pomyslec nad intem
	QFINFO* FQDequeue();//chyba tez dopisac
	void    FQClear();
	//void    FQRemove();   // czy jezeli jest destruktor, to to jest potrzebne?
	void    QFPrint(); //dopisac 
	void FQDel();

};

class FIFOItem
{ 
 
public: 
FIFOItem(QFINFO* Info);
virtual ~FIFOItem();  
void setInfo(QFINFO* Info); 
QFINFO* getInfo(); 
void setNext(FIFOItem* Next); 
FIFOItem* getNext();


private:
QFINFO* pInfo;
FIFOItem* pNext;
  
friend class QFIFO; //wszytskie metody tej klasy beda mialy dostep do QFIFO
}; 


//----------gety i sety 
inline void FIFOItem:: setInfo(QFINFO* Info)
{ 
	this->pInfo=Info;
} 
inline QFINFO* FIFOItem::getInfo()
{
	return this->pInfo;
} 

inline void FIFOItem::setNext(FIFOItem* Next)
{
this->pNext=Next;
}


inline FIFOItem* FIFOItem::getNext()
{
return pNext;
}