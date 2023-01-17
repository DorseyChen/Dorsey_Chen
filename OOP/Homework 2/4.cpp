#include<stdio.h>
#include<iostream>
#include<iomanip>
#define M 101

void sort(int [M]);
using namespace std;

int main()
{
	int i=0,j=1,x,y=0;
	int p[M]={0};
	
	cout<<"Please enter integers."<<endl;
	do
	{
		cin>>x;
		p[y]=x;
		y++;
	}while(x!=-999);
	
	sort(p);

	cout<<"Test Score    Cout"<<endl;
	while(p[i]!=-999)
	{
		if(p[i]==p[i+1])
			j++;
		if(p[i]!=p[i+1])
		{
			cout<<setw(10)<<p[i]<<"    "<<setw(4)<<j<<endl;
			j=1;
		}
		i++;
	}

	return 0;
}

void sort(int p[M])
{
        int i,j,x;
        for(i=0;i<M-1;i++)
                for(j=i+1;j<M;j++)
		{
			if(p[j]==-999)
				break;	
                        else if(p[i]>p[j])
                        {
                                x=p[i];
                                p[i]=p[j];
                                p[j]=x;
                        }
		}
}
