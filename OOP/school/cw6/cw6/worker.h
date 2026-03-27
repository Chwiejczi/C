#pragma once
#include "person.h"  
#define WOLNA 46.34 
#define TAX 0.18 
#define KUP 111.25
enum Profession{Mlodszy_specjalista, Specjalista, Starszy_specjalista }; 
//enum SUBJ { POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI };
class worker :public person
{ 
private: 
double mSalary; 
int mSeniority; 
	
public: 
worker(string name,int age, double salary, int seniority); 
worker(const worker& p); 
double getSalary() const; 
int getSeniority() const; 
void setSalary(double Salary); 
void setSeniority(int Seniority);  
//void printWorker(); 

virtual void printInfo() = 0;
virtual void calcSalary() = 0;

double calculateTax(double gross , double kosztyUzyskaniaPrzychodu); 
double calcBonus(double years);



};


inline double worker::getSalary() const
{
return this->mSalary;
}
inline int worker::getSeniority() const
{
return this->mSeniority;
}
inline void worker::setSalary(double Salary)
{
mSalary=Salary;
}
inline void worker::setSeniority(int Seniority)
{
mSeniority=Seniority;
}
