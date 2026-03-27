#pragma once  
#include <iostream> 
#define VEC_OTHER_ERROR 0x01 
#define VEC_DIM_ERROR 0x02  
#define VEC_INCOMP_DIM 0x04  
#define VEC_ALLOC_DIM 0x08
typedef unsigned short  USHORT;
using namespace std;

class VectorException
{
public:
	VectorException(USHORT mErr = VEC_OTHER_ERROR);
	const char* getReason();
private:
	USHORT mErrCode;
};
inline  VectorException::VectorException(USHORT mErr)
{
	mErrCode = mErr;
}
inline const char* VectorException::getReason()
{
	switch (mErrCode)
	{
	case VEC_DIM_ERROR: return "wrong vec dimension";
	case VEC_INCOMP_DIM:return "incompatebile vec dimnsion";
	case VEC_ALLOC_DIM:return "vec allocation error";
	default: return"other vec error";
	}

}

class Vector

{

public:
	Vector(int nSize=2, double nElem=0);
	Vector(const Vector& v);
	virtual ~Vector();

	Vector& operator =(const Vector& v);
	friend istream& operator >>(istream& in, Vector& v);
	friend ostream& operator <<(ostream& out, const Vector& v);

	int getDim() const;

	//indeksowanie 
	double& operator[] (int ix);
	const double& operator[] (int ix) const;
	//operator +
	friend const Vector operator +(const Vector& v1, const Vector& v2);//v1 + v2 
	friend const Vector operator +(const Vector& v, double x);//v1+4 
	friend const Vector operator +(double x, const Vector& v);//4+v1 
	Vector operator += (const Vector& v);// v1 += v2 v1.operator +=(v2) 
	Vector operator += (double x);// v1 +=4

	//operator - 
	friend const Vector operator -(const Vector& v1, const Vector& v2);//v1 + v2 
	friend const Vector operator -(const Vector& v, double x);//v1+4  
	Vector operator -= (const Vector& v);// v1 += v2 v1.operator +=(v2) 
	Vector operator -= (double x);// v1 +=4   

	//operator * 
	friend const Vector operator *(const Vector& v, double x);//v1*4 
	friend const Vector operator *(double x, const Vector& v);//4*v1  
	Vector operator *= (double x);// v1 *=4    
	//rzutowanie 
	explicit operator double* () const { return m_pCoord; } //doczytac 

	//porownanie 
	friend bool operator == (const Vector& v1, const Vector& v2);
	friend bool operator != (const Vector& v1, const Vector& v2);
	//iloczyn skalarny 
	friend double operator *(const Vector& v1, const Vector& v2);
private:
	void createVec(int nSize);
	void copyVec(const Vector& v);
private:
	double* m_pCoord;	//tablica dynamiczna wsp wektora 
	int mDim;			//rozmiar wektora 






};


// inline 

inline int Vector::getDim() const
{
	return mDim;

}

inline void Vector::createVec(int nSize)
{
	if (nSize < 2)
	{
		nSize = 2;
		cerr << "Error: inproper vrctor size!";
	}
	mDim = nSize;
	m_pCoord = new double[mDim];

}

inline void Vector::copyVec(const Vector& v)
{
	//memcpy( this->m_pCoord,(double*)v,v.getDim()*sizeof( double ) ); 
	memcpy(this->m_pCoord, v.m_pCoord, v.getDim() * sizeof(double));
}


inline double& Vector:: operator[] (int ix)
{
	if (ix < 0 || ix >= getDim())
	{
		cerr << "error: index out of range";
		return m_pCoord[0];
	}
	return this->m_pCoord[ix];
}
inline const double& Vector:: operator[] (int ix) const
{

	if (ix < 0 || ix >= getDim())
	{
		cerr << "error: index out of range";
		return m_pCoord[0];
	}
	return this->m_pCoord[ix];

}