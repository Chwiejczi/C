#pragma once
#include "worker.h"
class Admin :public worker
{   
public:
Admin(string name, int age, double salary,int seniority);
//void AdminSalary(); 
void whichProfession(Profession prof);
//virtual void printProfession(); 
virtual void printInfo(); 
virtual void calcSalary();

private: 
string profes;
};

