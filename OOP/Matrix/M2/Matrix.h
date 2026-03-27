#pragma once 
#include "Vector.h"  
#define MATRIX_OTHER_ERROR 0x01 
#define MATRIX_DIM_ERROR 0x02  
#define MATRIX_INCOMP_DIM 0x04  
#define MATRIX_ALLOC_DIM 0x08
typedef unsigned short  USHORT;

class MatrrixException
{
public:
	MatrrixException(USHORT mErr = MATRIX_OTHER_ERROR);
	const char* getReason();
private:
	USHORT mErrCode;
};
inline  MatrrixException::MatrrixException(USHORT mErr)
{
	mErrCode = mErr;
}
inline const char* MatrrixException::getReason()
{
	switch (mErrCode)
	{
	case MATRIX_DIM_ERROR: return "wrong vec dimension";
	case MATRIX_INCOMP_DIM:return "incompatebile vec dimnsion";
	case MATRIX_ALLOC_DIM:return "vec allocation error";
	default: return"other vec error";
	}

}

class Matrix
{
private:
	Vector* mRows; //tablica wierszy
	//int ColsNo;  //ilosc kolumn
	int RowsNo;//ilosc wierszy
	void createMatrix(int nRows, int nCols, double nElem);
	void copyMatrix(const Matrix& M);
public:
	Matrix(int nRows = 2, int nCols = 2, double nElem = 0);
	Matrix(const Matrix& M);
	virtual ~Matrix();
	int getRowNo() const;
	int getColNo() const;

	//operatory we/wy 
	friend istream& operator >>(istream& in, Matrix& M);
	friend ostream& operator <<(ostream& out, const Matrix& M);
	//
	Matrix& operator =(const Matrix& v);
	//indeksowanie 
	Vector& operator[] (int ix);
	const Vector& operator[] (int ix) const;

	//rzutowanie do Vector* 
	explicit operator Vector* () const { return mRows; }

	//porownanie ==  != 
	friend bool operator == (const Matrix& M1, const Matrix& M2);
	friend bool operator != (const Matrix& M1, const Matrix& M2);


	//mnozenie
	friend const Matrix operator *(const Matrix& M1, const Matrix& M2);//M1*M2
	friend const Vector operator *(const Matrix& M, const Vector& V);//M*v





};

inline int Matrix::getRowNo() const
{
	return RowsNo;

}
inline int Matrix::getColNo() const
{
	return this->mRows[0].getDim();
}

inline Vector& Matrix:: operator[] (int ix)
{
	if (ix<0 || ix>getRowNo())
	{
		cerr << "error: index out of range";
		return mRows[0];
	}
	return this->mRows[ix];

}
inline const Vector& Matrix:: operator[] (int ix) const
{
	if (ix<0 || ix>getRowNo())
	{
		cerr << "error: index out of range";
		return mRows[0];
	}
	return this->mRows[ix];

}




//rozmiar tablicy, ile wierszy ma macierz
//operator indeksowania(tylko indeksowanaie wiersza bo kolumne mamy juz napisana dla wektora)