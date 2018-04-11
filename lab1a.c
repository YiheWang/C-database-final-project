/*
 ============================================================================
 Name        : lab1a.c
 Author      : Yihe Wang
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define Pi 3.1415926

double AreaOfCircle(double);

int main(void) {
	double radius;
	double area;

	printf("Please enter the radius of the circle:");
	fflush(stdout);//clean the buffer
	scanf("%lf",&radius);
	printf("\n");

	while(radius<0){
		printf("Error! Please enter the radius bigger than 0:");
			fflush(stdout);//clean the buffer
			scanf("%lf",&radius);
	}
	area=AreaOfCircle(radius);//call the function
	printf("The area of the circle is %f\n",area);

	return 0;
}

double AreaOfCircle(double radius)
{
	return Pi*radius*radius;//calculate the area of circle
}
