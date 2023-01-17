#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;

int main(){
	int i, j, tmp, score[200], final[400];
	char get;
	FILE *fp;
	srand(time(NULL));
	
	while(1){
		//step1
		for(i=0; i<200; i++)
			score[i]=rand();
		if((fp=fopen("t1.dat", "w+b"))==NULL){
			cout<<"Cannot open the file. "<<endl;
			exit(1);
		}
		rewind(fp);
		fwrite(&score, sizeof(score), 1, fp);
		cout<<"Step 1 finished."<<endl;
		
		//step2
		rewind(fp);
		fread(&score, sizeof(score), 1, fp);
		fclose(fp);
		for(i=0; i<199; i++)
			for(j=i+1; j<200; j++)
				if(score[i]>score[j]){
					tmp=score[i];
					score[i]=score[j];
					score[j]=tmp;
				}
		if((fp=fopen("t2.dat", "wb"))==NULL){
			cout<<"Cannot open the file. "<<endl;
			exit(1);
		}
		fwrite(&score, sizeof(score), 1, fp);
		fclose(fp);
		cout<<"Step 2 finished."<<endl;
		
		//step3
		if((fp=fopen("t1.dat", "a+b"))==NULL){
			cout<<"Cannot open the file. "<<endl;
			exit(1);
		}
		fwrite(&score, sizeof(score), 1, fp);
		rewind(fp);
		fread(&final, sizeof(final), 1, fp);
		fclose(fp);
		cout<<"Step 3 finished. "<<endl;
		for(i=0;i<400;i++)
			cout<<final[i]<<endl;
		cin>>get;
	}
	return 0;
}
