#include<stdio.h>
#include<iostream>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct Circle
{
	int rad;
	struct Point p;
};

double area(Circle ihateooptest)
{
	return (ihateooptest.rad*ihateooptest.rad*3.1415);
}

int main()
{
	Circle ihateoophomework;
	cout<<"Please enter a radius for the circle."<<endl;
	cin>>ihateoophomework.rad;
	cout<<"Please the center point of the circle."<<endl;
	cin>>ihateoophomework.p.x>>ihateoophomework.p.y;
	cout<<"The area of the circle is "<<area(ihateoophomework)<<endl;
	return 0;
}
