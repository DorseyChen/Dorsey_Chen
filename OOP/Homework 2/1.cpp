#include<stdio.h>
#include<iostream>
#include<iomanip>
#define M 4
#define N 2

using namespace std;
int knapsack(int,int,int [M][N]);
int Max(int,int);

int main()
{	
	int p[M][N]={{15,1},{10,5},{9,3},{5,4}};
	int i,j;

	cout<<"The maximum under the constraint of weight 8 is "<<knapsack(4,8,p)<<endl;
		
	cout<<"    "<<"        ";
	for(i=0;i<=8;i++)
	cout<<"g="<<i<<" ";
	cout<<endl;
	for(i=0;i<5;i++)
	{	
		cout<<"k="<<i<<" f("<<i<<",g)= ";
		for(j=0;j<9;j++)
			cout<<setw(3)<<knapsack(i,j,p)<<" ";
		cout<<endl;
	}

	return 0;	
}

int knapsack(int k,int g,int p[M][N])
{
	if(k==0||g==0)
		return 0;
	else if(p[k-1][1]>g)
		return knapsack(k-1,g,p);
	else
		return Max(p[k-1][0]+knapsack(k-1,g-p[k-1][1],p),knapsack(k-1,g,p));
}

int Max(int i,int j)
{
	if(i>=j)
		return i;
	else
		return j;
}
