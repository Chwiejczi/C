#include "pupil.h" 
int pupil:: baseID=10000;//

pupil::pupil(string name, int age, string className)
{
setClassName(className); 
mID=to_string(baseID++);
}
pupil::pupil(const pupil& p)
{
*this=p;
}
void pupil::clearNotes()
{
memset(mNotes,0,MAXSUBJECTS*sizeof(double)); 
mAve=0;
}
void pupil::setNote(Subjects subj, double note)
{
if(subj>=POLSKI && subj<=NIEMIECKI) 
	if(note>1) 
		mNotes[subj]=note;
}
double pupil::calcAve()
{
	double sum=0; 
	int no=0; 
	for (int subj = POLSKI;subj < MAXSUBJECTS;subj++)
	{
		if(mNotes[subj]>1) 
		{  
			sum+=mNotes[subj] ;  
			no++;
		}
	} 
return mAve=(no)? sum/no :0;
}
void pupil::printPupil()
{
cout<<getID()<<' '<<getName()<<'('<<getClassName()<<')'<<mAve<<endl;  
cout<<'\t';printOutfit();
}
//void pupil:: printOutfit() { cerr << "blad uzycia\n"; }