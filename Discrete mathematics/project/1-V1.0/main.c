#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 40

void read_from_string(int*,char*);
void read_from_int(int *, int);
void RSA_Encryption(int,int,int*);
void big_print(int *);
void big_mod(int*,int*);
void big_mul(int*,int);
void big_sub(int*,int*);
bool compare(int* a,int* b);//若a>=b 是TRUE 
int main() {
	int	big[MAX],e,m[MAX];
	char str1[MAX],str2[MAX];
	/*while(1){
	scanf("%s%s",str1,str2);
	read_from_string(big,str1);
	read_from_string(m,str2);
	big_mod(big,m);
	big_print(big);
	printf("\n");
	}*/
	
	scanf("%s%d%s",str1,&e,str2);
	read_from_string(big,str1);
	read_from_string(m,str2);
	int i=MAX-1;
	for(;i>0&m[i]==0;i--);
    for(;i>=0;i--)
	RSA_Encryption(m[i],e,big);
	
	return 0;
}

void read_from_string(int* big, char* str)
{
    memset(big, 0, sizeof(int)*MAX);
    int i;
    for(i=0;i<=strlen(str)-1;i++)
        big[i]=str[strlen(str)-i-1]-'0';
}
void read_from_int(int *big, int x)
{
    memset(big, 0, sizeof(int)*MAX);
    int i=0;
    while(x!=0){
        big[i++]=x%10;
        x/=10;
    }
}
void big_print(int *big)
{
    int i;
    for(i=MAX-1;i>0&big[i]==0;i--);
    while(i>=1){
	printf("%d,", big[i]);
	i--;
	}
	printf("%d", big[0]);
}
void RSA_Encryption(int m,int e,int* n){//輸出是m^e (mod n)
	int ans[MAX];
	read_from_int(ans,m);
	for(;e>1;e--){
		big_mod(ans,n);
		big_mul(ans,m);
	}
	big_print(ans);
}
void big_mod(int* a,int* b){//a (mod b)
	while(compare(a,b)){//當a>=b
		big_sub(a,b);
	}
}
void big_sub(int* a,int* b){
	int i=MAX-1;
    while(i>=0) a[i]-=b[i],i--;
    while(i<=MAX-1){
    	if(a[i]<0){
    		a[i]+=10;
    		a[i+1]-=1;
		}
		i++;
	}
}
void big_mul(int* big,int m){
	int i;
	for(i=0;i<MAX;i++)
		big[i]*=m;
	for(i=0;i<MAX;i++){
		if(big[i]>=10){
			big[i+1]+=big[i]/10;
			big[i]%=10;
		}
	}
}

bool compare(int* a,int* b){//若a>=b 是TRUE 
	int na=MAX,nb=MAX,i;
    for(;na>1&a[na-1]==0;na--);
    for(;nb>1&b[nb-1]==0;nb--);
    if(na>nb)
    	return true;
    if(na==nb){
    	for(i=na-1;i>=0;i--){
    		if(a[i]>b[i])
    			return true;
    		if(a[i]<b[i])
    			return false;
		}
		if(i==-1)
			return true;
	}
	return false;
}
