#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int r,c,i,j,**p;
	p=new int *[r];
	cout<<"Enter row: ";
	cin>>r;
	cout<<"Enter col: ";
	cin>>c;
	for(i=0;i<r;i++)
		p[i]=new int[c];
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			cin>>p[i][j];
	cout<<"The oringal picture."<<endl;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			cout<<" "<<p[i][j];
			if(j==c-1)
				cout<<endl;
		}
	cout<<"The fixed picture."<<endl;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			if(p[i][j]==1)
				if(i!=0&&j!=0&&i!=(r-1)&&j!=(c-1))
					if((p[i-1][j]!=0)&&(p[i][j-1]!=0)&&(p[i+1][j]!=0)&&(p[i][j+1]!=0))
						p[i][j]=2;
		}
	
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			if(p[i][j]==2)
				p[i][j]=0;
			cout<<" "<<p[i][j];
			if(j==c-1)
				cout<<endl;
		}
	for(i=0;i<r;i++)
		delete []p[i];
	delete []p;

	return 0;
}
