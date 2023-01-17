#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
void sort(vector<double> *);
void print(vector<double> *);
void mix(vector<double> *,vector<double> *);

int main()
{
	int i,j,x;
	double y;
	vector<double> vd1,vd2;
	
	cout<<"Please enter vd1's size: ";
	cin>>x;
        cout<<"Please enter the data to store in vd1."<<endl;
        for(i=0;i<x;i++)
        {
                cin>>y;
                vd1.push_back(y);
        }

	cout<<"Please enter vd2's size: ";
        cin>>x;
        cout<<"Please enter the data to store in vd2."<<endl;
        for(i=0;i<x;i++)
        {
                cin>>y;
                vd2.push_back(y);
        }
	
	sort(&vd1);
	sort(&vd2);
	
	cout<<"The first array:"<<endl;
	print(&vd1);
	cout<<"The second array:"<<endl;
	print(&vd2);

	if(vd1.size()<vd2.size())
        {
		for(i=0;i<vd1.size();i++)
		{
			y=vd1[i];
			vd1[i]=vd2[i];
			vd2[i]=y;
		}
		for(i=vd1.size();i<vd2.size();i++)
		{
			y=vd2[i];
			vd1.push_back(y);
		};
        }

	cout<<"The merged array:"<<endl;
	mix(&vd1,&vd2);
	print(&vd1);

	return 0;
}

void sort(vector<double> *vd)
{
        int i,j;
	vector<double> t(1);
        for(i=0;i<vd->size()-1;i++)
                for(j=i+1;j<vd->size();j++)
                        if((vd->at(i))>(vd->at(j)))
                        {
                                t[0]=vd->at(i);
                                vd->at(i)=vd->at(j);
                                vd->at(j)=t[0];
                        }
}

void print(vector<double> *vd)
{
	for(int i=0;i<vd->size();i++)
		cout<<vd->at(i)<<", ";
	cout<<endl;
}

void mix(vector<double> *vd1,vector<double> *vd2)
{
	int i,j;
	for(i=0;i<vd2->size();i++)
		for(j=0;j<vd1->size()-1;j++)
		{
			if(vd2->at(i)==vd1->at(j))
				break;
			else if(vd2->at(i)<vd1->at(j))
			{
				vd1->insert(vd1->begin(),vd2->at(i));
				break;
			}
			else if(vd2->at(i)>vd1->at(j)&&vd2->at(i)<vd1->at(j+1))
			{
				vd1->insert(vd1->begin()+j+1,vd2->at(i));
				break;
			}
			else if(vd2->at(i)>vd1->at(vd1->size()-1))
			{
				vd1->push_back(vd2->at(i));
				break;
			}
		}
}
