#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

void readint(char []);
void printint(char []);

int main(){
	char *s1,*s2,*s3,len=0;
	int x=0,i;
	s1=new char [41];
	s2=new char [41];
	s3=new char [41];
	s1[0]='\0';
	s2[0]='\0';
	s3[0]='\0';
	cout<<"Please enter the first interger: "<<endl;
	readint(s1);
	cout<<"Please enter the second interger: "<<endl;
	readint(s2);
	if(strlen(s1)<strlen(s2)){
		len=strlen(s2)-strlen(s1);
		for(i=strlen(s1);i<strlen(s2);i++)
			s1[i]='0';
	}
	else
		for(i=strlen(s2);i<strlen(s1);i++)
			s2[i]='0';
	for(i=0;i<strlen(s1)+len;i++){
		if((s1[i]-48)+(s2[i]-48)+x>9){
			s3[i]=s1[i]+s2[i]+x-58;
			x=1;
		}
		else{
			s3[i]=s1[i]+s2[i]+x-48;
			x=0;
		}
	}
	
	printint(s1);
	cout<<" + ";
	printint(s2);
	cout<<" = ";
	if(x)
		cout<<x;
	printint(s3);
	cout<<endl;
	return 0;
}

void readint(char s1[]){
	char s2[41];
	s2[0]='\0';
	gets(s2);
	for(int i=0;i<strlen(s2);i++)
		s1[i]=s2[strlen(s2)-i-1];
}

void printint(char s[]){
	for(int i=strlen(s);i>=0;i--)
		cout<<s[i];
}
