#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int x;
	vector<int> vd;
	cout<<"Please enter a positive integer."<<endl;
	cin>>x;
	while(x!=0)
	{
		vd.push_back(x%2);
		x/=2;
	}
	cout<<"The positions of 1's in the binary representation of "<<x<<" are ";
	for(int i=0;i<vd.size();i++)
		if(vd[i]!=0)
			cout<<i<<",";
	cout<<endl;

	return 0;
}
