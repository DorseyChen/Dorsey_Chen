#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(char *[],int);
int min(char *[],int);


int main(int argc, char *argv[])
{
	int ans;
	if(strcmp(argv[1],"M")== 0)
		ans=max(argv,argc);
	if(strcmp(argv[1],"m")== 0)
		ans=min(argv,argc);
	printf("Result = %d\n",ans);
	return 0;
}

int max(char *num[],int length)
{
	int max=atoi(num[2]);
	for(int i=3;i<length;i++)
		if(atoi(num[i])>max)
			max=atoi(num[i]);
	return max;
}

int min(char *num[],int length)
{
	int min=atoi(num[2]);
	for(int i=3;i<length;i++)
		if(atoi(num[i])<min)
			min=atoi(num[i]);
	return min;
}
