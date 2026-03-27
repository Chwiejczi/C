// cw3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
using namespace std;


#include "Vector.h" 
#include "Matrix.h"
int main()
{
    Vector v1;
    cout << "v1=" << v1 << endl;

    Vector v2(4, 1.0);
    cout << "v2=" << v2 << endl;

    Vector v3(5, 3.0);
    Vector v4(v3);
    cout << "v4=v3=" << v4 << endl;


    v2 = v4;
    cout << "v2=" << v2 << endl;

    v3 = v2 + v4;
    cout << "v2+v4=" << v3 << endl;


    v3 = v3 + (-2);
    cout << "v3-2=" << v3 << endl;

    double Sum = v4 * v3;
    cout << "v3*v4=" << Sum << endl;



    cout << "Matrix" << endl;
    Matrix m1;
    cout << "m1=" << endl << m1 << endl;



    Matrix m2(3, 3, 3);
    cout << "m2=" << endl << m2 << endl;

    Vector mult(3, 1);
    cout << "vec=" << mult << endl;
    mult = m2 * mult;
    cout << "matrix*vec=" << mult << endl;

    Matrix a(3, 2, 1);
    Matrix b(2, 3, 1);
    cout << "a=" << endl << a << endl;
    cout << "b=" << endl << b << endl;
    Matrix c(3, 3, 0);
    c[2][2] = 1;
    cout << "c=" << endl << c << endl;
    //c = a; 
    c = a * b;
    cout << "c=" << endl << c << endl;
    
    //cout<<"c="<<endl <<c<<endl;
  
    return 0;
}

