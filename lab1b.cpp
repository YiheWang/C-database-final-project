//============================================================================
// Name        : lab1b.cpp
// Author      : Yihe Wang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double cost;
	double selling;

	cout<< "Please enter the cost price and the selling price:"<<endl;
	cin>>cost>>selling;//input the cost and selling

	while(cost<0||selling<0){
		cout<< "Please re-enter the cost price and the selling price in positive number:"<<endl;
		cin>>cost>>selling;//input the cost and selling
	}
	if(cost>selling)
		cout<<"The seller loss "<<cost-selling<<"$"<<endl;
	//when they cost bigger than selling
	else if(cost==selling)
		cout<<"The seller do not make profit or have loss"<<endl;
	//when cost equal to selling
	else
		cout<<"The seller make "<<selling-cost<<"$ profit"<<endl;
	//when cost less than selling

	cout<<"Have a nice day!"<<endl;

	return 0;
}
