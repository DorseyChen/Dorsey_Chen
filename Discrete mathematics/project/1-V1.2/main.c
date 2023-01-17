#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20 
#define MAXMESS 10

typedef struct bigint{
	int position[MAX];
}bigint;

void string_to_bigint(char*,bigint*);
void int_to_bigint(int,bigint*);
void RSA(int,int,bigint);
void mul(bigint*,int);
void mod(bigint*,bigint);
void sub(bigint*,bigint);
bool compare(int* ,int* );
int main() {
	int power,i,j,mes[MAX];
	bigint mod;
	char modc[MAX],mesc[MAXMESS];//strlen(mesc)代表有幾個字 
	
	scanf("%s%d%s",modc,&power,mesc);
	
	string_to_bigint(modc,&mod);

	for(i=strlen(mesc)-1;i>=0;i--)
		mes[strlen(mesc)-1-i]=mesc[i];

	for(i=strlen(mesc)-1;i>=1;i--){
		RSA(mes[i],power,mod);
		printf(",");
	}
	RSA(mes[i],power,mod);
	return 0;
}

void string_to_bigint(char* str,bigint* big){
    memset(big->position, 0, sizeof(int)*MAX);
    int i;
    for(i=0;i<=strlen(str)-1;i++)
        big->position[i]=str[strlen(str)-i-1]-'0';
}
void int_to_bigint(int mes,bigint* big){
    memset(big->position, 0, sizeof(int)*MAX);
    int i;
    for(i=0;mes!=0;i++){
        big->position[i]=mes%10;
        mes/=10;
    }
}
void RSA(int mes,int p,bigint m){//mes^p≡? (mod m)
	int i;
	bigint ans;
	int_to_bigint(mes,&ans);
	
	//進行加密 
	for(;p>1;p--){
		mod(&ans,m);
		mul(&ans,mes);
	}
	mod(&ans,m);
	//輸出答案 
	for(i=MAX-1;ans.position[i]==0;i--);
	for(;i>=0;i--)
		printf("%d",ans.position[i]);
}
bool compare(int* a,int* b){//若a>=b 是TRUE 
	int na=MAX,nb=MAX,i;
	
    for(;na>1&a[na-1]==0;na--);
    for(;nb>1&b[nb-1]==0;nb--);
    if(na>nb){
    	return true;
    }
    if(na==nb){
    	for(i=na-1;i>=0;i--){
    		if(a[i]>b[i]){ 
    			return true;
			} 
    		if(a[i]<b[i]){
    			return false;	
    		} 
		}
		if(i==-1){
			return true;
		} 
	}
	return false;
}
void mul(bigint* big,int m){
	int i;
	for(i=0;i<MAX;i++)
		big->position[i]*=m;
	for(i=0;i<MAX;i++){
		if(big->position[i]>=10){
			big->position[i+1]+=big->position[i]/10;
			big->position[i]%=10;
		}
	}
}
void mod(bigint* a,bigint b){
	int i;
	while(compare(a->position,b.position)){//當a>=b
		sub(a,b);
	}
}

void sub(bigint* a,bigint b){
	int i=MAX-1;
    while(i>=0) a->position[i]-=b.position[i],i--;
    while(i<=MAX-1){
    	if(a->position[i]<0){
    		a->position[i]+=10;
    		a->position[i+1]-=1;
		}
		i++;
	}
}
