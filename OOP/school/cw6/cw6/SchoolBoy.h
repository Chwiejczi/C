#pragma once
#include "pupil.h"
class SchoolBoy : public pupil
{ 
public:
	SchoolBoy(string name = "", int age = 0, string className = "");
	virtual void printOutfit();//nadpisuje funkcjê klasy bazowej
};

