#include "teacher.h" 

teacher:: teacher(string name, int age, double salary, int seniority, Subjects subj) :worker(name,age,salary,seniority)
{  
tut=0;
//tut=tutor; 
subject=subject2string(subj);

} 

void teacher::printProfession()
{ 
/*
if( tut!=0 ) 
	cout<<"bonus 400, ";   

double tax = TeacherSalary();
double Newsalary= getSalary(); 
cout << "gross=" << Newsalary << ", tax=" << tax << ", net=" << Newsalary-tax <<", subject="<<subject;
if( tut !=0 ) 
	cout<<", tutor of class "<<Class;
*/ 

TeacherSalary(); 
cout<<subject; 
if(isTutor()) 
	cout<<" "<<"Tutor of class"<< Class;
}

void teacher::setTutor(string cl)
{   
Class=cl; 
tut=1;
double salary=getSalary();
	if (tut) 
		salary+=400;
		//setSalary(getSalary()+400);   
//bêdzimy tez tutaj liczyc dodatek stazowy
	
}  

int teacher::isTutor()
{
return tut;
}


void teacher::TeacherSalary()
{ 
	double basic = getSalary();
	int years = getSeniority();
	double bonus = calcBonus(years);
	double gross = basic * (1.0 + bonus);
	if (isTutor())
	{
		gross += 400.0;
	}
	double kup = (0.8 * gross * 0.5);
	double tax = calculateTax(0.8 * gross, kup) + calculateTax(0.2 * gross, 111.25);
	double net = gross - tax;
	cout << "gross=" << gross << ",net=" <<net<<' ';

} 


void teacher::printInfo()
{ 
	cout << "Teacher=" << getName()
		<< ",age=" << getAge()
		<< ",years of service: " << getSeniority() << " lat"<<endl;

calcSalary(); 
cout << subject;
if (isTutor())
cout << " " << "Tutor of class" << Class<<endl;

}
void teacher::calcSalary()
{ 

	double basic = getSalary();
	int years = getSeniority();
	double bonus = calcBonus(years);
	double gross = basic * (1.0 + bonus);
	if (isTutor())
	{
		gross += 400.0;
	}
	double kup = 0.5*KUP;
	double tax = calculateTax(0.8 * gross, kup) + calculateTax(0.2 * gross, KUP);
	double net = gross - tax;
	cout << "gross=" << gross << ",net=" << net << ' ';

}