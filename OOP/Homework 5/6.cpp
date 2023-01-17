#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	char **s1;
	char **s2;
	int i,j,time=1,k=0,cases;

	cout<<"Please enter a number of cases: "<<endl;
	cin>>cases;
	s1=new char *[cases];
	s2=new char *[cases];
	for(i=0;i<=cases;i++){
		s1[i]=new char [1000];
		s1[i][0]='\0';
		s2[i]=new char [1000];
		s2[i][0]='\0';
	}
	
	cout<<"Please give the numbers of cases: "<<endl;
	for(i=0;i<=cases;i++){
		cin.getline(s1[i],1000);
		cin.clear();
	}
	for(i=0;i<=cases;i++){
		for(j=0;j<strlen(s1[i]);j++){
			if(s1[i][j]==s1[i][j+1])
				time++;
			else{
				if(time<10){
					s2[i][k++]=time+48;
					s2[i][k++]=s1[i][j];
					time=1;
				}
				else{
					s2[i][k++]=49;
					s2[i][k++]=time+38;
					s2[i][k++]=s1[i][j];
					time=1;
				}
			}
		}
		s2[i][k]='\0';
		k=0;
		puts(s2[i]);
	}
	return 0;
}
