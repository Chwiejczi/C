#pragma once
#include "pupil.h"
class SchoolGirl : public pupil
{ 
public: 
SchoolGirl(string name="", int age=0, string className="");
virtual void printOutfit();//nadpisuje funkcjê klasy bazowej

};

