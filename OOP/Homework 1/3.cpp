#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

int main(){
	int i,j,t=0,s,p[150];
	srand(time(NULL));
	
	cout<<"======(a)======"<<endl;
	for(i=0;i<150;i++)
		p[i]=rand()%200+1;
	for(i=0;i<200;i++){
		s=rand()%200+1;
		for(j=0;j<150;j++){
			if(s==p[j]){
				t++;
				break;}
		}
	}
	cout<<"The number of successful searches is: "<<t<<endl;
	cout<<"======(b)======"<<endl;
	cout<<"The percentage of successful searches is: "<<(t/200.0)<<endl;

	return 0;
}
