#include "Qfifo.h" 

//==================Stack  
QFIFO::QFIFO()
{
pHead=pTail=nullptr;

} 

QFIFO:: ~QFIFO()
{ 

	if ( !FQEmpty() )
	{
	FQClear();
	} 



} 
void  QFIFO::FQDel()
{  

	FIFOItem* ptr = pHead;
	pHead = ptr->getNext();
	if ( FQEmpty() )
		pTail = nullptr;
	delete ptr;
 
/*
	if (FQEmpty())
		return;

	FIFOItem* temp = this->pHead;
	this->pHead = temp->getNext();
	if (this->FQEmpty())
		this->pTail = NULL;
	delete temp; 
*/
}

bool QFIFO::FQEmpty() const
{
	//if (pHead == nullptr && pTail == nullptr)
	//{
		//return true;//zwraca 1 jezeli puste
	//} 
//return false; 

	return !(pHead);
}


bool  QFIFO::FQEnqueue(QFINFO* Item)
{
FIFOItem* NEW= new (nothrow) FIFOItem(Item); 
if (!NEW)
{
	cerr << "allocation error!" << endl; 
	throw StackException(FIFO_OTHER_ERROR);
	//return false;
}
NEW->pInfo=Item; 
//NEW->pNext=NULL;
NEW->setNext(nullptr);
if (FQEmpty())
	pHead = NEW;
else
	pTail->setNext(NEW);
pTail = NEW;
return true;
}

QFINFO* QFIFO::FQDequeue()
{ 
if( FQEmpty() ) 
	throw StackException(FIFO_EMPTY);
QFINFO* temp=pHead->pInfo; 


//teraz tzreba usunac ten element- w FIFO bylo FQDEL 
FQDel();
return temp;
}

void QFIFO::FQClear()
{

	while (!FQEmpty())
	{ 
		QFINFO* info = FQDequeue();
		delete info;
	}


}
  
void  QFIFO::QFPrint() 
{ 
	if (FQEmpty()) 
		throw StackException(FIFO_EMPTY);
	
	FIFOItem* info=pHead;  
	while ( info ) 
	{ 
	cout<<*(info->pInfo);  //*() musi byc tak bo drukuje wskaznik, jezeli tego nie bêdzie to drukuje adres
	cout<<'\n';
	info=info->pNext;	
	}
	

}

//==================StackItem

FIFOItem::FIFOItem(QFINFO* Info)
{ 
setInfo(Info); 
setNext(nullptr);
	 
}
FIFOItem:: ~FIFOItem()
{
pInfo=nullptr; 
pNext=nullptr;
}