#include "Matrix.h"
#include "Vector.h" 


Matrix::Matrix(int nRows, int nCols, double nElem)
{
	//	ColsNo=nCols;
	RowsNo = nRows;
	//	!!!! try 
	try
	{
		createMatrix(nRows, nCols, nElem);
		//mRows=nRows; 
	}
	catch (MatrrixException& e)
	{
		cerr << e.getReason();
	}

}
Matrix::Matrix(const Matrix& M)//konstruktor kopiuj¹cy
{
	RowsNo = 0;
	//ColsNo=0; 
	mRows = nullptr;
	*this = M;

}
Matrix:: ~Matrix()
{
	delete[] mRows;


}

void Matrix::createMatrix(int nRows, int nCols, double nElem)
{
	//ColsNo=nCols; 
	RowsNo = nRows;


	
	//!!!  
	if (nRows < 2)
	{
		nRows = 2;
		throw MatrrixException(MATRIX_DIM_ERROR);
	} 
	mRows = new Vector[nRows];
	for (int i = 0; i < nRows; i++)
		mRows[i] = Vector(nCols, nElem);




}

void Matrix::copyMatrix(const Matrix& M)
{
	for (int i = 0; i < M.getRowNo(); i++)
	{
		mRows[i] = M.mRows[i];
	}

}

//==========operatory we/wy=================== 
istream& operator  >>(istream& in, Matrix& M)
{
	for (int i = 0; i < M.getRowNo(); i++)
	{
		in >> M.mRows[i];//tutaj odwo³a siê do klasy wektor i tam uzupe³ni to o elementy poszczegolnego wektora
	}
	return in;
}


ostream& operator <<(ostream& out, const Matrix& M)
{
	for (int i = 0; i < M.getRowNo(); i++)
	{
		out << "|" << M.mRows[i] << "|" << endl;
	}
	return out;
}


//**************operator= 
Matrix& Matrix:: operator =(const Matrix& M)
{
	if (getColNo() != M.getColNo() || getRowNo() != M.getRowNo())
	{
		delete[] mRows;
		//try!!!!!!!!!!!!!!! 
		try
		{
			createMatrix(M.getRowNo(), M.getColNo(), 0);
		}
		catch (MatrrixException& e)
		{
			cerr << e.getReason();
		}
	}
	copyMatrix(M);
	return *this;


}


//=====================porownania 
bool operator == (const Matrix& M1, const Matrix& M2)
{
	if (M1.getColNo() != M2.getColNo() || M1.getRowNo() != M2.getRowNo())
	{//!!!! throw 
		throw(MatrrixException(MATRIX_DIM_ERROR));
		cerr << "different dimentions";
		return false;
	}
	for (int i = 0; i < M1.RowsNo; i++)
	{
		if (M1.mRows[i] != M2.mRows[i])
			return false;
	}
	return true;
}
bool operator != (const Matrix& M1, const Matrix& M2)
{

	if (M1.getColNo() != M2.getColNo() || M1.getRowNo() != M2.getRowNo())
	{
		cerr << "different dimentions";
		return true;
	}
	for (int i = 0; i < M1.RowsNo; i++)
	{
		if (M1.mRows[i] != M2.mRows[i])
			return true;
	}
	return false;


}


//=====mnozenie macierzy 

const Matrix operator *(const Matrix& M1, const Matrix& M2)
{  

	if (M1.getColNo() != M2.getRowNo())
		throw MatrrixException(MATRIX_INCOMP_DIM);

	Matrix C(M1.getRowNo(), M2.getColNo(), 0);

	for (int i = 0; i < M1.getRowNo(); i++)
		for (int j = 0; j < M2.getColNo(); j++)
		{
			double sum = 0;
			for (int k = 0; k < M1.getColNo(); k++)
				sum += M1[i][k] * M2[k][j];

			C[i][j] = sum;
		}

	return C;



//
//
//if (M1.getColNo() != M2.RowsNo)
//	{
//		cerr << "wrong matrices dimentions given " << endl;
//		return M1;
//	}
//	Matrix M(M1.RowsNo, M2.getColNo(), 0);
//	for (int i = 0; i < M1.RowsNo; i++)
//	{
//		double S = 0;
//		Vector temp(M2.getColNo(), 0);
//		for (int j = 0; j < M2.getColNo(); j++)
//		{
//			Vector temp2(M2.RowsNo, 0);//zrobimy z tego wektor pionowy
//			for (int k = 0; k < M1.getColNo(); k++)
//			{
//				temp2[k] = M2[k][j];
//			}
//			S = M1[i] * temp2;
//			temp[j] = S;
//		}
//	 M[i] = temp;
//	}
//	return M;
//
//
}


//=========macierz * vec 

const Vector operator *(const Matrix& M, const Vector& V)
{
	if (M.getColNo() != V.getDim())
	{
		cerr << "wrong matrices dimentions given " << endl;
		return V;
	}

	Vector Vres(M.RowsNo, 0);
	for (int i = 0; i < M.getRowNo(); i++)
	{
		Vres[i] = M.mRows[i] * V;
	}
	return Vres;



}
