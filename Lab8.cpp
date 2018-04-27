//============================================================================
// Name        : Lab8.cpp
// Author      : Yihe Wang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdio.h>
#include <climits>
#include <iomanip>
using namespace std;

typedef struct Point{
	double x;
	double y;
}Point;

class BaseConic {
	protected:
		double x;
		double y;

	public:
		BaseConic(double, double);
		virtual ~BaseConic();
		virtual void move(double, double);
		virtual double getArea() = 0; // a pure virtual function ==> ABC
		virtual void display() = 0;
};

BaseConic::BaseConic(double x, double y)
{
	this->x = x;
	this->y = y;
}

BaseConic::~BaseConic()
{
	//do nothing
}

void BaseConic::move(double x, double y)
{
	this->x = x;
	this->y = y;
}

class Ellipse : public BaseConic {
	private:
		double a; 	// semi-major axis
		double b; 	// semi-minor axis
		double angle; // orientation angle
		double area;
		Point leftVertices;
		Point rightVertices;
		Point topVertices;
		Point bottomVertices;

	public:
		Ellipse();
		Ellipse(double, double, double, double, double);
		~Ellipse();
		double getArea();
		void rotate(double);
		void resize(double, double);
		void updateVertices();//update ths position of vertices
		void move(double,double);//override move fucntion because vertices change
		void display();
};

// Notice the default values. Those are used if no parameter is given when
// an object is created.
// Notice how the BaseConic constructor can be called. If other constructors where defined,
// those could be used instead.

Ellipse::Ellipse(double x,double y,double a,double b,double angle) : BaseConic(x,y)
{
	this->a = a;
	this->b = b;
	this->angle = angle;
	this->area = 3.1416 * a * b;
	updateVertices();
}

Ellipse::~Ellipse()
{
	//do nothing
}

void Ellipse::move(double x, double y)
{
	this->x += x;
	this->y += y;
	updateVertices();
}

void Ellipse::updateVertices()
{
	rightVertices.x = a * cos(angle);
	rightVertices.y = a * sin(angle);
	leftVertices.x = - rightVertices.x;
	leftVertices.y = - rightVertices.y;//left and right are symmetrical
	leftVertices.x += x;
	leftVertices.y += y;
	rightVertices.x += x;
	rightVertices.y += y;//shift the vertices according to orgin

	topVertices.x = - b * sin(angle);
	topVertices.y = b * cos(angle);
	bottomVertices.x = - topVertices.x;
	bottomVertices.y = - topVertices.y;//top and bottom are symmetrical
	topVertices.x += x;
	topVertices.y += y;
	bottomVertices.x += x;
	bottomVertices.y += y;//shift the vertices according to orgin
}

double Ellipse::getArea()
{
	return area;
}

void Ellipse::rotate(double angle)
{
	this->angle += angle;
	updateVertices();
}

void Ellipse::resize(double a, double b)
{
	this->a = a;
	this->b = b;//resize the axis
	area = 3.1416 * a * b;//update the area
	updateVertices();
}

void Ellipse::display()
{
	cout << "x = " << x << ", y = " << y << ", a = " << a << ", b = " << b
		 << ", angle = " << angle << ", Area = " << area << endl;
	cout<<"Left vertices is ("<<setprecision(2)<<setiosflags(ios_base::fixed)
			<<leftVertices.x<<","<<leftVertices.y<<")"<<endl;
	cout<<"Right vertices is ("<<setprecision(2)<<setiosflags(ios_base::fixed)
			<<rightVertices.x<<","<<rightVertices.y<<")"<<endl;
	cout<<"Top vertices is ("<<setprecision(2)<<setiosflags(ios_base::fixed)
			<<topVertices.x<<","<<topVertices.y<<")"<<endl;
	cout<<"Bottom vertices is ("<<setprecision(2)<<setiosflags(ios_base::fixed)
			<<bottomVertices.x<<","<<bottomVertices.y<<")"<<endl<<endl;
}

class Circle : public BaseConic
{
	private:
		double r; 	// radius
		double area;

	public:
		double getArea();
		Circle(double,double,double);
		~Circle();
		void resize(double);
		void pointPosition(double, double);//judge the position of point
		void display();
};

Circle::Circle(double x, double y, double r) : BaseConic(x, y)
{
	this->x = x;
	this->y = y;
	this->r = r;
	this->area = 3.1416 * r * r;
}

Circle::~Circle()
{
	//do nothing
}

void Circle::resize(double r)
{
	this->r = r;
	area = 3.1416 * r * r;//update the area
}

void Circle::pointPosition(double x0, double y0)
{
	double squareDistance = pow(x0-x,2) + pow(y0-y,2);
	if(squareDistance < r){
		cout<<"This point is inside the circle"<<endl;
	}
	else if(squareDistance == r){
		cout<<"This point is on the circle"<<endl;
	}
	else{
		cout<<"This point is outside the circle"<<endl;
	}
	cout<<endl;
}

double Circle::getArea()
{
	return area;
}

void Circle::display()
{
	cout <<setprecision(2)<<setiosflags(ios_base::fixed)<< "x = " << x << ", y = " << y << ", r = " << r
		 << ", Area = " << area << endl<<endl;
}

int main()
{
	cout<<"----------Circle-----------"<<endl;
	Point point;
	Circle circle(0,0,1);
	circle.display();//print out circle information

	circle.resize(3.3);
	cout<<"Circle information after resize the radius to 3.3"<<endl;
	circle.display();//print out circle information after resize

	circle.move(4,4);
	cout<<"Circle information after move middle point from origin to (4,4)"<<endl;
	circle.display();//print out circle information after moving

	cout<<"Please enter a point, x: ";
	cin>>point.x;
	cout<<"y: ";
	cin>>point.y;
	circle.pointPosition(point.x,point.y);

	cout<<"----------Ellipse-----------"<<endl;
	Ellipse ellipse(0,0,3,2,0);
	ellipse.display();//print out ellipse information

	ellipse.resize(4,3);
	cout<<"Ellipse information after resize a to 4, b to 3"<<endl;
	ellipse.display();//print out ellipse information after resize

	ellipse.move(4,4);
	cout<<"Move the middle point from origin to (4,4)"<<endl;
	ellipse.display();//print out ellipse information after move

	ellipse.rotate(1.571);//rotate 90 degree
	cout<<"Rotate 90 degree clockwise"<<endl;
	ellipse.display();//print out ellipse information after move

	cout<<"-------------Dynamic Binding--------------"<<endl;
	BaseConic *baseConic;
	baseConic = (BaseConic*)malloc(sizeof(BaseConic));
	cout<<"Use baseConic point to circle"<<endl;
	baseConic = &circle;
	baseConic->display();

	cout<<"Use baseConic point to ellipse"<<endl;
	baseConic = &ellipse;
	baseConic->display();

}
