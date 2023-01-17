#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
vector<int> fib_sequence(double);


int main()
{
	double err;
	vector<int> fibs;

	printf("Please input the absolute error: ");
	scanf("%lf",&err);

	fibs=fib_sequence(err);
	
	for(int i=0;i<fibs.size();i++)
		printf("%d ",fibs[i]);
	cout<<endl;

	return 0;
}

vector<int> fib_sequence(double err)
{
	int x=1,y=2,t;
	vector<int> vd;
	vd.push_back(0);
	vd.push_back(1);
	vd.push_back(1);
	while((y/(double)x)-1.618>err||-((y/(double)x)-1.618)>err)
	{
		t=x;
		x=y;
		y+=t;
		vd.push_back(x);
	}
	vd.push_back(y);
	return vd;
}
