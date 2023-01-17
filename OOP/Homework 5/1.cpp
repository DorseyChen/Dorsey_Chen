#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	char s[11]="0123456789";
	char s0;
	
	for(int i=0;i<10;i++){
		puts(s);
		for(int i=0;i<10;i++){
			if(i==0)
				s0=s[i];
			if(i==9)
				s[i]=s0;
			else
				s[i]=s[i+1];
		}
	}
	return 0;
}
