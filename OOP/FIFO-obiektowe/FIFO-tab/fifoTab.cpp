#include "fifoTab.h" 
FIFO::FIFO(int Size)
{
  if( Size < 2 )
	throw StackException(FIFO_OTHER_ERROR);
  
Tab=new QFINFO* [Size]; 
if (!Tab)
{
	throw StackException(FIFO_OTHER_ERROR);
}
NoElem = m_Tail = m_Head=0; 
MaxSize=Size;

}
FIFO:: ~FIFO()
{  
FQClear();
delete [] Tab;

} 
bool FIFO:: FQFull()
{ 
return NoElem==MaxSize;
}
bool FIFO:: FQEmpty()
{
return NoElem==0;
}

void FIFO:: FQClear()
{ 
	while (!FQEmpty())
	{ 
	FQDel();
	}

} 
QFINFO* FIFO::FQDequeue()
{ 
	if( FQEmpty() ) 
		throw StackException(FIFO_EMPTY);
	QFINFO* temp = Tab[m_Head]; 
	FQDel(); 
	return temp;
	
}
void FIFO:: FQDel()
{  
		if ( FQEmpty() ) 
			throw StackException(FIFO_EMPTY); 

		m_Head = (m_Head + 1) % MaxSize;
		NoElem--;
	/*
		if (m_Head == MaxSize-1)
		{   
			m_Head=0;
		} 
		else
		{	
			m_Head++; 
		} 
		NoElem--;
	*/
} 
void FIFO::FQEnqueue(QFINFO* info) //ewentualnie zmienic typ zeby zwracalo 1 jak sie powiedzie albo 0 jak nie
{  
	if( FQFull() )  
		throw StackException(FIFO_FULL);

/*
	if (m_Tail == MaxSize - 1)
	{ 
	Tab[m_Tail]=info; 
	m_Tail=0;
	}
	else
	{ 
	Tab[m_Tail]=info; 
	m_Tail+=1;
	} 
	NoElem++;
 */ 

	Tab[m_Tail] = info;
	m_Tail = (m_Tail + 1) % MaxSize;
	NoElem++;

}
void FIFO:: FQPrint()
{ 
	/*
	if ( !FQEmpty() )
	{ 
	int ix=m_Head; 
	
	while (ix != m_Tail)
		{ 
		cout<<*(Tab[ix])<<endl;
			if(ix==MaxSize-1) 
				ix=0;
			else 
				ix++;
		} 

*/
	//if (FQEmpty()) 
		//throw StackException(FIFO_EMPTY);
	 
		
		for (int i = 0; i < NoElem;i++)
		{ 
		    int ix=(m_Head+i)%MaxSize;	
			cout<<*(Tab[ix])<<endl;
		}
	

}


