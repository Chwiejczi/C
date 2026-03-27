#pragma once 

#include <iostream> 
#include <string> 
enum Subjects { POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI };
using namespace std;
class person
{ 
public: 
	person(string name="", int age=0);
	person(const person& p);  
	virtual ~person();
	person& operator = (const person& p)=default; 
	string getName() const; 
	int getAge() const; 
	void setName(string NewName); 
	void setAge(int NewAge); 
	void setPerson(string NewName,int NewAge);
private: 
	string mName; 
	int mAge; 

}; 


inline string person::getName() const
{
	return this->mName;

}
inline int person::getAge() const
{
	return this->mAge;
}
inline void person::setName(string NewName)
{
	mName = NewName;
}
inline void person::setAge(int NewAge)
{
	mAge = NewAge;
}
inline void person::setPerson(string NewName, int NewAge)
{
	setName(NewName);
	setAge(NewAge);
}

