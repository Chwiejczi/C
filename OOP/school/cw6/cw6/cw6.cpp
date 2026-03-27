// cw6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include "SchoolGirl.h" 
#include "SchoolBoy.h" 
#include "teacher.h" 
#include "Admin.h"
using namespace std; 

void printAllPupils(pupil* pupils[], int pupilsNo);
void printAllWorkers(worker* workers[],int workersNo); 
void sort(worker* workers[], int workersNo);
int main()
{ 
SchoolGirl g1("Nowak Agnieszka",17, "3A"); 
g1.setNote(POLSKI,3.5); 
g1.setNote(INFORMATYKA, 4.5);
g1.setNote(CHEMIA, 3.5); 
g1.setNote(FIZYKA, 3.5);
g1.setNote(NIEMIECKI, 3.0);


SchoolGirl g2("Sobota Paulina", 18, "4B");
g2.setNote(POLSKI, 3.5);
g2.setNote(MATEMATYKA, 4.5);
g2.setNote(CHEMIA, 3.5);
g2.setNote(ANGIELSKI, 3.5);


SchoolGirl g3("Kozub MAria", 17, "3A");
g3.setNote(POLSKI, 3.5);
g3.setNote(MATEMATYKA, 4.5);
g3.setNote(INFORMATYKA, 3.5);
g3.setNote(NIEMIECKI, 3.0); 


SchoolBoy b1("Kowalski Marcin",17,"3B");
b1.setNote(POLSKI, 3.5);
b1.setNote(MATEMATYKA, 4.5);
b1.setNote(CHEMIA, 3.5);


SchoolBoy b2("Pawelek Marcin", 18, "4B");
b2.setNote(POLSKI, 3.5);
b2.setNote(MATEMATYKA, 4.5);
b2.setNote(ANGIELSKI, 4);


pupil* pupils[] ={&g1, &g2, &g3, &b1, &b2}; 
printAllPupils(pupils,sizeof(pupils)/sizeof(pupil*));  


//===================================workers=============================
cout<<endl<<endl<<endl;
teacher t1("Jan Jan", 30,12000,10,MATEMATYKA);  
t1.setTutor("4b");

teacher t2("Jan Kowalski", 30, 10000, 10, CHEMIA);
t2.setTutor("2b");

teacher t3("Jan Nowak", 30, 9000, 10, POLSKI);

Admin a1("Jan Wazny",40, 1300,6); 
a1.whichProfession(Mlodszy_specjalista);

Admin a2("Jacek Soplica", 40, 8000, 6);
a2.whichProfession(Starszy_specjalista);


worker* workers[]={&t1,&t2,&t3,&a1,&a2}; 
sort(workers, sizeof(workers) / sizeof(worker*));
printAllWorkers(workers, sizeof(workers) / sizeof(worker*));

    return 0;
}

void printAllPupils(pupil* pupils[], int pupilsNo)
{
    for (int i = 0;i < pupilsNo;i++)
    { 
        pupils[i]->calcAve();
        pupils[i]->printPupil(); 
        cout<<endl;
    }
} 

void printAllWorkers(worker* workers[], int workersNo)
{ 
    for (int i = 0;i < workersNo;i++)
    {
        //wo[i]->calcAve();
        workers[i]->printInfo();
        cout << endl;
    }

}

void sort(worker* workers[], int workersNo)
{
    for (int i = 0; i < workersNo; i++)
    {
        worker* min = workers[i];
        int ix_min = i;
        for (int j = i + 1; j < workersNo; j++)
            if (workers[j]->getSalary() < min->getSalary())
            {
                min = workers[j];
                ix_min = j;
            }
        workers[ix_min] = workers[i];
        workers[i]= min;
    }

}
