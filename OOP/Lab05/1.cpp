#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char* hexToDec(char []);

int main(){
	char *hex,*dec;
	hex = new char [100];
	dec = new char [100];
	hex[0]='\0';
	dec[0]='\0';
	while(gets(hex)){
		dec=hexToDec(hex);
		for(int i=strlen(dec)-1;i>=0;i--)
			cout<<dec[i];
		hex[0]='\0';
		dec[0]='\0';
		cout<<endl;
	}
	return 0;
}

char* hexToDec(char hex[]){
	char *dec;
	dec = new char [100];
	int i,n=0,x=1,sum=0;
	for(i=0;i<strlen(hex);i++)
		if(hex[i]>70)
			hex[i]-=32;
	for(i=strlen(hex)-1;i>=0;i--){
		if(hex[i]>57)
			sum+=(hex[i]-55)*x;
		else
			sum+=(hex[i]-48)*x;
		x*=16;
	}
	for(i=0;sum>0;i++){
		dec[i]=sum%10+48;
		sum/=10;
	}
	return dec;
}
