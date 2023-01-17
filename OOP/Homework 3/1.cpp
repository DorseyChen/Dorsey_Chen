#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;

struct student
{
	char name[20];
	char id[7];
	int chinese;
	int english;
	int math;
	int total;
};

void read(student stu[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Please enter the student's name."<<endl;
		cin>>stu[i].name;
		cout<<"The student's ID."<<endl;
		cin>>stu[i].id;
		cout<<"The student's scores."<<endl;
		cin>>stu[i].chinese;
		cin>>stu[i].english;
		cin>>stu[i].math;
		stu[i].total=stu[i].chinese+stu[i].english+stu[i].math;
	}
}

int equal(student stu[],int i,int j)
{
	if(stu[i].total>stu[j].total)
		return 2;
	else if(stu[i].total<stu[j].total)
		return 1;
	if(stu[i].chinese>stu[j].chinese)
		return 2;
	else if(stu[i].chinese<stu[j].chinese)
		return 1;
	if(stu[i].english>stu[j].english)
		return 2;
	else if(stu[i].english<stu[j].english)
		return 1;
	if(stu[i].math>stu[j].math)
		return 2;
	else if(stu[i].math<stu[j].math)
		return 1;
	return 0;
}

void sort(student stu[],int n)
{
        int i,j;
        student tmp;
        for(i=0;i<n-1;i++)
                for(j=i+1;j<n;j++)
                        if(equal(stu,i,j)>1)
                        {

                                tmp=stu[i];
                                stu[i]=stu[j];
                                stu[j]=tmp;
                        }
}


void print(student stu[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Name:      ";
		cout<<"ID:     ";
		cout<<"Chinese score: ";
		cout<<"English score: ";
		cout<<"Math score: ";
		cout<<"Total score: "<<endl;
		cout<<std::left<<setw(11)<<stu[i].name;
		cout<<std::left<<setw(8)<<stu[i].id;
		cout<<std::left<<setw(15)<<stu[i].chinese;
		cout<<std::left<<setw(15)<<stu[i].english;
		cout<<std::left<<setw(13)<<stu[i].math;
		cout<<stu[i].total<<endl;
		cout<<"======================================="<<endl;
	}
}

int main()
{
	int n,i,j;
	cout<<"Please enter the number of students: "<<endl;
	cin>>n;
	student stu[n];
	read(stu,n);
	sort(stu,n);
	print(stu,n);
	return 0;
}
