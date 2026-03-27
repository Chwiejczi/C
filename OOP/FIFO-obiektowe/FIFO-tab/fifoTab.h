#include "global.h" 
#include <iostream> 
using namespace std; 

#define FIFO_EMPTY 0x01 
#define FIFO_FULL 0x02 
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
	case FIFO_FULL:return "fifo is full";
	case FIFO_OTHER_ERROR:return "other fifo error";
	default: return"other fifo err";
	}

}



class FIFO 
{ 
private: 
  int m_Head; 
  int m_Tail; 
  int NoElem; 
  int MaxSize; 
  QFINFO** Tab;

public: 
  FIFO(int Size); 
  virtual ~FIFO(); 
  bool FQFull(); 
  bool FQEmpty(); 
  void FQClear(); 
  void FQDel(); 
  void FQPrint();
  QFINFO* FQDequeue(); 
  void FQEnqueue( QFINFO* info); 
 
 
};