#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,i,j;
	vector<int> vd;

	cin>>n;
	for(i=0;i<n-1;i++)
		vd.push_back(i+2);
	for(i=0;vd[i]*vd[i]<=n;i++)
		for(j=i+1;j<n-1;j++)
			if(vd[j]%vd[i]==0&&vd[i]!=1)
				vd[j]=1;
	for(i=0;i<n-1;i++)
		if(vd[i]!=1)
			cout<<vd[i]<<" ";
	
	return 0;
}
