#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	int triangle[8] = {20, 95, 1000, 20, 500, 500, 20, 95};
	int pts;
	initwindow(1080,720);
	
	moveto(180, 320);
	setfillstyle(1, 2);
	bar(100, 10, 200, 20);
    getch();
    
    setfillstyle(2, 3);
    bar(100, 10, 110, 300);
    getch();
    
    setfillstyle(3, 4);
	bar(100, 80, 200, 90);
    getch();
	
	setcolor(2);
	ellipse(320, 120, 180, 0, 50, 200);
    getch();
	
	setcolor(3);
	ellipse(500, 220, 60, 330, 50, 100);
    getch();
    
 	setcolor(RED);
 	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
 	line(700, 10, 700, 400);
 	getch();
 	
 	setcolor(GREEN);
 	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	line(900, 30, 700, 250);
	line(700, 250, 900, 350);
	getch();
	
	pts = sizeof(triangle) / (sizeof(int) * 2);
	setcolor(GREEN);
	drawpoly(pts, triangle);
	setfillstyle(SOLID_FILL, BLUE);
	fillpoly(pts, triangle);
	getch();
	
	closegraph();
}
