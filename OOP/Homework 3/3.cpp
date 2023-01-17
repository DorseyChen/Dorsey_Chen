#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;

struct Point
{
	int x;
	int y;
};

int quadrant(Point pos)
{
	if(pos.x>0&&pos.y>0)
		return 1;
	else if(pos.x<0&&pos.y>0)
		return 2;
	else if(pos.x<0&&pos.y<0)
		return 3;
	else if(pos.x>0&&pos.y<0)
		return 4;
}

int main()
{
	Point pos;
	do
	{
		cin>>pos.x>>pos.y;
	}while(pos.x==0||pos.y==0);
	cout<<"The point is in the "<<quadrant(pos)<<" quadrant."<<endl;
	return 0;
}
