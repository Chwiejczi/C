#include "Admin.h" 

Admin::Admin(string name, int age, double salary,int seniority) :worker(name,age,salary,seniority)
{

}
//void Admin::AdminSalary()  //skrocic jak bêdzie dzia³a³o
//{  
////pobieramy podstawe
//double salary=getSalary(); 
//int years= getSeniority();
////double tax=(salary-111.25)*0.18 -46.34; 
//double bonus =calcBonus(years); 
////liczymy brutto 
//double gross=salary*(1+bonus);
//double tax= calculateTax(gross, 111.25); 
//double net=gross-tax; 
//
//cout << "gross=" << gross << ",net=" << net <<' ';
//} 
void Admin:: whichProfession(Profession prof)
{  

	switch (prof)
	{
	case Mlodszy_specjalista: profes="Mlodszy specjalista";break; 
	case Specjalista: profes = "Specjalista";break;
	case Starszy_specjalista: profes = "Starszy specjalista";break;
	}

}


//void Admin::printProfession()
//{ 
//	AdminSalary(); 
//	cout<<profes;  
//}
void Admin::printInfo()
{  
	cout << "Admin=" << getName()
		<< ",age=" << getAge()
		<< ",years of service: " << getSeniority() << " lat"<<endl;
	calcSalary(); 
	cout << profes<<endl;
}
void Admin::calcSalary()
{ 

	//pobieramy podstawe
	double salary = getSalary();
	int years = getSeniority();
	//double tax=(salary-111.25)*0.18 -46.34; 
	double bonus = calcBonus(years);
	//liczymy brutto 
	double gross = salary * (1 + bonus);
	double tax = calculateTax(gross, 111.25);
	double net = gross - tax;

	cout << "gross=" << gross << ",net=" << net << ' ';

}