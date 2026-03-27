#include "worker.h" 


worker::worker(string name, int age, double salary, int seniority)
{ 
setName(name); 
setAge(age); 
setSalary(salary); 
setSeniority(seniority);
}
worker::worker(const worker& p)
{
*this=p;
}
//void worker::printWorker()
//{
//	cout<<"name: " << getName() << ", age: " << getAge() << ", seniority:" << getSeniority() << ',' << endl;
//	cout<<'\t';printProfession();
//} 


double worker::calculateTax(double gross, double kosztyUzyskaniaPrzychodu)
{ 
	//-koszty uzykania przychodu : 111.25 / miesiac
	//- kwota wolna 556.02 / 12 = 46, 34 z³
	double tax = ((gross - kosztyUzyskaniaPrzychodu) * TAX) - WOLNA;
	if (tax < 0)
		return 0;
	return tax;

}
double worker::calcBonus(double years)
{ 
	double Bonus = 0;
	if (years >= 5 && years <= 20)
		Bonus = years * 0.01;
	if (years > 20)
		Bonus = 0.20;
	return Bonus;

}
