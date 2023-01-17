#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

int binary_search(int [],int,int);
void swap(int *,int *);
using namespace std;

int main(){
	int i,j,t=0,p[150],;
	srand(time(NULL));
	
	cout<<"======(a)======"<<endl;
	for(i=0;i<150;i++)
		p[i]=rand()%200+1;
	for(i=0;i<149;i++)
		for(j=i+1;j<150;j++)
			if(p[i]>p[j])
				swap(&p[i],&p[j]);
	for(i=0;i<200;i++)
		t+=binary_search(p,150,rand()%200+1);
	cout<<"The number of successful searches is: "<<t<<endl;
	cout<<"======(b)======"<<endl;
	cout<<"The percentage of successful searches is: "<<(t/200.0)<<endl;

	return 0;
}

int binary_search(int p[],int l,int t)
{
	int first=0;
	int last=l-1;
	int mid;
	bool found=false;
	while(first<=last&&!found)
	{
		mid=(first+last)/2;
		if(p[mid]==t)
			found=true;
		else if(p[mid]>t)
			last=mid-1;
		else
			first=mid+1;
	}
	if(found)
		return 1;
	else
		return 0;
}

void swap(int *i,int *j)
{
	int t=*i;
	*i=*j;
	*j=t;
}
