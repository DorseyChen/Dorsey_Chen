#include<stdio.h>
double**p,**q;
void input(const int,const int,const int,const int);
double**mul(int,int,int);
double** mul(int r1,int c1,int r2,int c2,double**p,double**q);
int main()
{
    int i,j;
    int r1,r2,c1,c2;
    double**r;
    printf("matrix A\n");
    printf("===========\n");
    printf("row:  ");
    scanf("%d",&r1);
    printf("column:  ");
    scanf("%d",&c1);
    printf("matrix B\n");
    printf("===========\n");
    printf("row:  ");
    scanf("%d",&r2);
    printf("column:  ");
    scanf("%d",&c2);
    
    input(r1,r2,c1,c2);
    
    r=mul(r1,c1,r2,c2,p,q);
    printf("result:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
            printf("%5.2lf  ",r[i][j]);
        printf("\n");
    }
    end:
    return 0;
}
void input(const int r1,const int r2,const int c1,const int c2)
{
    int i,j;
    p=new double*[r1];
    for(i=0;i<r1;i++)
       p[i]=new double[c1];
    q=new double*[r2];
    for(i=0;i<r2;i++)
       q[i]=new double[c2];
    printf("matrix A:\n");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%lf",&p[i][j]);
    printf("matrix B:\n");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%lf",&q[i][j]);
}
double**mul(int r,int c,int n)
{
    double**s;
    int i,j,k;
    s=new double*[r];
    for(i=0;i<r;i++)
        s[i]=new double[c];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            s[i][j]=0;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            for(k=0;k<n;k++)
                s[i][j]+=p[i][k]*q[k][j];
    return s;
}
double** mul(int r1,int c1,int r2,int c2,double**p,double**q)
{
	if(c1!=r2)return NULL;
	double**s;
    int i,j,k;
    s=new double*[r1];
    for(i=0;i<r1;i++)
        s[i]=new double[c2];
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            s[i][j]=0;
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            for(k=0;k<c1;k++)
                s[i][j]+=p[i][k]*q[k][j];
    return s;
}
