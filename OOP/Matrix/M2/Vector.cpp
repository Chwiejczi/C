#include "Vector.h"
Vector::Vector(int nSize, double nElem)
{
	createVec(nSize);
	for (int i = 0; i < getDim();i++)
	{
		m_pCoord[i] = nElem;
	}


}
Vector::Vector(const Vector& v)
{
	m_pCoord = nullptr;
	mDim = 0;
	*this = v;
}
Vector:: ~Vector()
{
	delete[] m_pCoord;

}

Vector& Vector:: operator =(const Vector& v)
{
	if (getDim() != v.getDim())
	{
		delete[] m_pCoord;
		createVec(v.getDim());
	}
	copyVec(v);
	return *this;
}
istream& operator >>(istream& in, Vector& v)
{
	for (int i = 0; i < v.getDim(); i++)
		in >> v.m_pCoord[i];
	return in;

}
ostream& operator <<(ostream& out, const Vector& v)
{
	out << '[';
	for (int i = 0; i < v.getDim(); i++)
	{
		out << v.m_pCoord[i];
		if (i < v.getDim() - 1)out << ',';
	}
	out << ']';
	return out;
}


const Vector operator +(const Vector& v1, const Vector& v2)//v1 + v2  
{
	Vector res(v1);
	return res += v2;


}
const Vector operator +(const Vector& v, double x)//v1+4  
{

	Vector res(v);
	return res += x;

}
const Vector operator +(double x, const Vector& v)//4+v1  
{
	return v + x;

}
Vector Vector:: operator += (const Vector& v)// v1 += v2 v1.operator +=(v2)  
{
	//if(this->getDim() != v.getDim())
	//{
		//throw VectorException( VEC_INCOMP_DIM );
	//}
	if (this->getDim() != v.getDim())
	{
		cerr << "error: incompaibile vector sizes";
		return *this;
	}
	for (int i = 0; i < getDim(); i++)
		m_pCoord[i] += v.m_pCoord[i];
	return *this;

}
Vector Vector:: operator += (double x)// v1 +=4 
{
	for (int i = 0; i < getDim(); i++)
		m_pCoord[i] += x;
	return *this;

}



const Vector operator -(const Vector& v1, const Vector& v2)//v1 - v2 
{
	Vector res(v1);
	return res -= v2;
}
const Vector operator -(const Vector& v, double x)//v1-4   
{
	Vector res(v);
	return res -= x;
}
Vector Vector:: operator -= (const Vector& v)// v1 -= v2 v1.operator -=(v2)  
{
	if (this->getDim() != v.getDim())
	{
		//throw VectorException( VEC_INCOMP_DIM );
		cerr << "error: incompaibile vector sizes";
		return *this;
	}
	for (int i = 0; i < getDim(); i++)
		m_pCoord[i] -= v.m_pCoord[i];
	return *this;

}
Vector Vector:: operator -= (double x) // v1 -=4 
{
	for (int i = 0; i < getDim(); i++)
		m_pCoord[i] -= x;
	return *this;

}


//operator * 
const Vector operator *(const Vector& v, double x)//v1*4  
{
	Vector res(v);
	return res *= x;

}
const Vector operator *(double x, const Vector& v)//4*v1 
{
	Vector res(v);
	return res *= x;

}
Vector Vector:: operator *= (double x)// v1 *=4   
{
	for (int i = 0; i < getDim(); i++)
		m_pCoord[i] *= x;
	return *this;

}

//iloczyn skalarny 
double operator *(const Vector& v1, const Vector& v2)
{
	if (v1.getDim() != v2.getDim())
	{
		cerr << "error: incompaibile vector sizes";
		return -12345;

	}
	double sum = 0;
	for (int i = 0; i < v1.getDim(); i++)
		//sum+=v1.m_pCoord[i] * v2.m_pCoord[i]; 
		sum += v1[i] * v2[i];
	return sum;

}


//porownanie 
bool operator == (const Vector& v1, const Vector& v2)
{
	if (v1.getDim() != v2.getDim())
	{
		cerr << "error: incompaibile vector sizes";
		return false;

	}
	for (int i = 0; i < v1.getDim(); i++)
	{
		if (v1[i] != v2[i])
			return false;
	}
	return true;

}
bool operator != (const Vector& v1, const Vector& v2)
{
	if (v1.getDim() != v2.getDim())
	{
		return true;

	}
	for (int i = 0; i < v1.getDim(); i++)
	{
		if (v1[i] != v2[i])
			return true;
	}
	return false;

}


