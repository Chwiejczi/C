#pragma once
#include "person.h" 
//enum Subjects{POLSKI,MATEMATYKA,FIZYKA,CHEMIA,INFORMATYKA,ANGIELSKI,NIEMIECKI};
#define MAXSUBJECTS NIEMIECKI+1
class pupil : public person
{ 
public: 
pupil(string name,int age, string className); 
pupil(const pupil& p);
string getID() const;
string getClassName() const;
void setClassName(string newClassName); 
void clearNotes(); 
void setNote(Subjects subj, double note); 
double calcAve(); 
void printPupil(); //to potrzebuje print outfit
virtual void printOutfit() {cerr<<"blad uzycia\n"; }



protected: 
string mID; 



private: 
string className; 
static int baseID; 
double mAve; 
double mNotes[MAXSUBJECTS];
};

inline string pupil:: getID() const 
{ 
return this->mID;
}
inline string pupil::getClassName() const
{
return this->className;
}
inline void pupil::setClassName(string newClassName)
{
	this->className=newClassName;
}