#include<stdio.h>
#include<iostream>
using namespace std;

void multiplication(int **,int **,int,int,int);

int main()
{	int c1,r1,c2,i,j;
	int **p1,**p2;
	cout<<"Please enter the row and column of the first matrix."<<endl;
	cin>>r1>>c1;
	cout<<"Please enter the column of the second matrix."<<endl;
	cin>>c2;
	
	p1=new int *[r1];
	for(i=0;i<r1;i++)
		p1[i]=new int [c1];
	
	p2=new int *[c1];
	for(i=0;i<c1;i++)
		p2[i]=new int [c2];

	cout<<"Please enter the values of the first matrix."<<endl;
	for(i=0;i<r1;i++)
		for(j=0;j<c1;j++)
			cin>>p1[i][j];
	cout<<"Please enter the values of the second matrix."<<endl;
	for(i=0;i<c1;i++)
		for(j=0;j<c2;j++)
			cin>>p2[i][j];

	cout<<"The first matrix."<<endl;
	for(i=0;i<r1;i++)
	{	for(j=0;j<c1;j++)
			cout<<p1[i][j]<<" ";
		cout<<endl;
	}

	cout<<"The second matrix."<<endl;
	for(i=0;i<c1;i++)
	{	for(j=0;j<c2;j++)
			cout<<p2[i][j]<<" ";
		cout<<endl;
	}

	multiplication(p1,p2,r1,c1,c2);

	return 0;
}

void multiplication(int **p1,int **p2,int r1,int c1,int c2)
{	int i,j,k,t=0,**p3;
	p3=new int *[r1];
	for(i=0;i<r1;i++)
		p3[i]=new int [c2];
	for(i=0;i<c2;i++)
		for(j=0;j<r1;j++)
		{	for(k=0;k<c1;k++)
				t+=p1[j][k]*p2[k][i];
			p3[j][i]=t;
			t=0;
		}
	
	cout<<"The result of multiplication."<<endl;
	for(i=0;i<r1;i++)
	{	for(j=0;j<c2;j++)
			cout<<p3[i][j]<<" ";
		cout<<endl;
	}
}
