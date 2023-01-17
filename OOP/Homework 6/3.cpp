#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct score
{
	int id;
	char name[10];
	int sc1;
	int sc2;
};

void sort(score [20]);
void merge(FILE *, FILE *, FILE*);

int main(){
	struct score stu[20];
	int i, j;
	FILE *fp1, *fp2, *fp3;
	
	//creat two files
	srand(time(NULL));
	for(i=0; i<20; i++){
		stu[i].id=rand()%100;
		stu[i].sc1=rand()%100;
		stu[i].sc2=rand()%100;
		for(j=0; j<3; j++)
			stu[i].name[j]=97+i;
		stu[i].name[3]='\0';
	}
	if((fp1=fopen("file1.txt", "w+"))==NULL){
		cout<<"Cannot open the file. "<<endl;
		exit(1);
	}
	for(i=0; i<10; i++)
		fprintf(fp1, "%d %s %d %d ", stu[i].id, stu[i].name, stu[i].sc1, stu[i].sc2);
	if((fp2=fopen("file2.txt", "w+"))==NULL){
        cout<<"Cannot open the file. "<<endl;
        exit(1);
	}
	for(i=10; i<20; i++)
		fprintf(fp2, "%d %s %d %d ", stu[i].id, stu[i].name, stu[i].sc1, stu[i].sc2);

	//scanf two files
	i=0;
	rewind(fp1);
	while(fscanf(fp1, "%d %s %d %d ", 
				&(stu[i].id), &(stu[i].name), &(stu[i].sc1), &(stu[i].sc2))!=EOF)
		i++;
	rewind(fp2);
    while(fscanf(fp2, "%d %s %d %d ",
				&(stu[i].id), &(stu[i].name), &(stu[i].sc1), &(stu[i].sc2))!=EOF)
		i++;
	
	//sort data and find the smallest and largest id
	sort(stu);
	cout<<"The person of the smallest id is: "<<endl;
	cout<<stu[0].id<<" "<<stu[0].name<<" "<<stu[0].sc1<<" "<<stu[0].sc2<<endl;
	cout<<"The person of the largest id is: "<<endl;
	cout<<stu[19].id<<" "<<stu[19].name<<" "<<stu[19].sc1<<" "<<stu[19].sc2<<endl;

	//merge
	if((fp3=fopen("file3.dat", "wb"))==NULL){
		cout<<"Cannot open the file. "<<endl;
		exit(1);
	}
	merge(fp1, fp2, fp3);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}

void merge(FILE *fp1, FILE *fp2, FILE *fp3){
	struct score stu[20];
	int i, j;
	
	i=0;
    rewind(fp1);
	while(fscanf(fp1, "%d %s %d %d",
				&(stu[i].id), &(stu[i].name), &(stu[i].sc1), &(stu[i].sc2))!=EOF)
		i++;
	rewind(fp2);
	while(fscanf(fp2, "%d %s %d %d",
				&(stu[i].id), &(stu[i].name), &(stu[i].sc1), &(stu[i].sc2))!=EOF)
		i++;
			
	//sort data
	sort(stu);
	rewind(fp3);
	fwrite(&stu, sizeof(stu), 1, fp3);
}

void sort(score stu[20]){
	int i, j;
	struct score tmp;
	for(i=0; i<19; i++)
		for(j=i+1; j<20; j++)
			if(stu[i].id>stu[j].id){
				tmp=stu[i];
	            stu[i]=stu[j];
	            stu[j]=tmp;
			}
}
