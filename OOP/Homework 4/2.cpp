#include<iostream>
#include<stdio.h>
#include<math.h>
#include <graphics.h>
using namespace std;

class cRectangle
{
    int x;
    int y;
    int width;
    int height;
    public:
    Rectangle();
    Rectangle(int,int,int,int);
    void setx(int);
    void sety(int);
    void setwidth(int);
    void setheight(int);
    int calPerimeter();
    int calArea();
    void drawrect();
};

cRectangle::Rectangle()
{
    x=0;
    y=0;
    width=0;
    height=0;
}

cRectangle::Rectangle(int a,int b,int w,int h)
{
    x=a;
    y=b;
    width=w;
    height=h;
}

void cRectangle::setx(int a)
{
    x=a;
}

void cRectangle::sety(int a)
{
    y=a;
}

void cRectangle::setwidth(int a)
{
    width=a;
}

void cRectangle::setheight(int a)
{
    height=a;
}

int cRectangle::calPerimeter()
{
    return (2*(width+height));
}

int cRectangle::calArea()
{
    return width*height;
}

void cRectangle::drawrect()
{
	bar(540+x, 360-y, 540+x+width, 360-y-height);
}

class cline
{
	int x1;
	int y1;
	int x2;
	int y2;
	public:
	cline();
	cline(int,int,int,int);
	void setx1(int);
	void sety1(int);
	void setx2(int);
	void sety2(int);
	double length();
	void drawl();
};

cline::cline()
{
	x1=0;
	y1=0;
	x2=0;
	y2=0;
}

cline::cline(int a,int b,int c,int d)
{
	x1=a;
	y1=b;
	x2=c;
	y2=d;
}

void cline::setx1(int x)
{
	x1=x;
}

void cline::setx2(int x)
{
	x2=x;
}

void cline::sety1(int x)
{
	y1=x;
}

void cline::sety2(int x)
{
	y2=x;
}

double cline::length()
{
	return sqrt((x1-x2)^2+(y1-y2)^2);
}

void cline::drawl()
{
	setcolor(3);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(540+x1,360-y1,540+x2,360-y2);
}

int main()
{
	cRectangle rect;
	cline cline;
	int x,y,w,h;
	
	cout<<"Please enter the position(x,y), width and height of the rectangle. "<<endl;
	cin>>x>>y>>w>>h;
	rect.setx(x);
	rect.sety(y);
	rect.setwidth(w);
	rect.setheight(h);
	cout<<"The perimeter of the rectangle is "<<rect.calPerimeter()<<endl;
	cout<<"The area of the rectangle is "<<rect.calArea()<<endl;
	
	cout<<"Please enter two points for a line. (x1,y1,x2,y2)"<<endl;
	cin>>x>>y>>w>>h;
	cline.setx1(x);
	cline.sety1(y);
	cline.setx2(w);
	cline.sety2(h);
	cout<<"The length of the line is "<<cline.length()<<endl;
	
	initwindow(1080,720);
	line(540, 0, 540, 720);
	line(0, 360, 1080, 360);
	rect.drawrect();
	cline.drawl();
	getch();
	
	return 0;
}
