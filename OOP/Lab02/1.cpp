#include<stdio.h>
#include<iostream>
using namespace std;
void fixsumNum(int [],int);

int main()
{
	int x,i,n,*p;
	scanf("%d",&n);
	p=new int [n];
	for(i=0;i<n;i++){
		scanf("%d",&x);
		p[i]=x;}
	cout<<"The array is ";
	for(i=0;i<n;i++)
		cout<<p[i]<<", ";
	cout<<endl;
	fixsumNum(p,n);
	
	return 0;
}

void fixsumNum(int p[],int n)
{
	int i=0,j=n-1,x=0,y=0,m=0;
	x+=p[i];
	y+=p[j];
	while(i<n&&j>=0){
		if(x==y)
		{
			for(int  m1=0;m1<=i;m1++)
				cout<<p[m1]<<"+ ";
			cout<<"= ";
			for(int m2=n-1;m2>=j;m2--){
				cout<<p[m2];
				if(m2!=j) cout<<"+ ";
			}
			cout<<endl;
			i++;
			j--;
			m++;
			x+=p[i];
			y+=p[j];
		}
		if(x<y)
		{
			i++;
			x+=p[i];
		}
		if(x>y)
		{
			j--;
			y+=p[j];
		}
	}
	cout<<endl;
	printf("There are %d pairs.",m);
}
