#pragma once
#include "worker.h"
class teacher :public worker
{ 
public:
teacher(string name, int age, double salary, int seniority, Subjects subj);
void TeacherSalary(); 
virtual void printProfession(); 
void setTutor(string cl);  
int isTutor();
void setSubject(Subjects sub); 
string subject2string(Subjects s);

virtual void printInfo();
virtual void calcSalary();


private: 
string subject; 
int tut; 
string Class;
 

}; 

inline void teacher::setSubject(Subjects sub)
{
subject=sub;
}  


inline string teacher::subject2string(Subjects s)
{ 
    switch (s) 
    {
    case POLSKI: return "POLSKI";
    case MATEMATYKA: return "MATEMATYKA";
    case FIZYKA: return "FIZYKA";
    case CHEMIA: return "CHEMIA";
    case INFORMATYKA: return "INFORMATYKA";
    case ANGIELSKI: return "ANGIELSKI";
    case NIEMIECKI: return "NIEMIECKI"; 
    }
return "";
}


