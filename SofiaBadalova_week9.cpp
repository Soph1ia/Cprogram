// labweek9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

double getAreaTriangle(double h, double b);
double getSquare(double a);
double getRectangle(double w, double h);
double getParallelogram(double bP, double hP);
double getTrapeziod(double aT, double bT, double hT);
double getCircle(double r);
double getEllipse(double aE, double bE);
double getSector(double rS, double theta);

int main()
{
	//triangle stuff
	double h = 1.6, b = 1.4;
	double area1 = getAreaTriangle(h, b);
	printf("Area of Triangle (b= 1.4 and h= 1.6) is %.2lf \n", area1);

	//square stuff
	double a = 2.5;
	double area2 =getSquare(a);
	printf("Area of Square (a=2.5) is %.2lf \n", area2);

	//rectangle
	double w = 2.0, hR = 3.0;
	double area3=getRectangle(w, hR);
	printf("Area of rectangle (w=2.0 hR=3.0) is %.2lf \n", area3);

	//parallogram stuff
	double bP = 2.5, hP = 1.4;
	double area4 = getParallelogram(bP, hP);
	printf("Area of parallelogram (w=2.0 hR=3.0) is %.2lf \n", area4);

	//Trapeziod stuff
	double aT = 2.0, bT = 3.0, hT = 4.0;
	double area5 = getTrapeziod(aT, bT, hT);
	printf("Area of Trapeziod (a=2.0 b=3.0 h=4.0) is %.2lf \n", area5);

	//Circle stuff
	double r=6.0;
	double area6 = getCircle(r);
	printf("Area of Circle (r= 6.0) is %.2lf \n", area6);

	//Ellipse stuff
	double aE=3.0, bE=2.0;
	double area7 = getEllipse(aE, bE);
	printf("Area of Ellipse (r= 6.0) is %.2lf \n", area7);

	//Sector stuff
	double rS= 3.0, theta=2.0;
	double area8 = getSector(rS, theta);
	printf("Area of Sector (r= 3.0 and theta =2 in radians) is %.2lf \n", area8);
	
    return 0;
}

double getAreaTriangle(double h, double b)
{
	double result;
	result = (b*h) / 2;
	return result;
}

double getSquare(double a)
{
	double result;
	result = (a*a);
	return result;
}

double getRectangle(double w, double hR)
{
	double result;
	result = (w*hR);
	return result;
}

double getParallelogram(double bP, double hP)
{
	double result;
	result = (bP*hP);
	return result;
}

double getTrapeziod(double aT, double bT, double hT)
{
	double result;
	result = ((aT+bT)/2)*hT;
	return result;
}

double getCircle(double r)
{
	double result;
	result = 3.14*r*r;
	return result;
}

double getEllipse(double aE, double bE)
{
	double result;
	result = 3.14*aE*bE;
	return result;
}

double getSector(double rS, double theta)
{
	double result;
	result = (rS*rS*theta) / 2;
	return result;
}