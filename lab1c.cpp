//============================================================================
// Name        : lab1c.cpp
// Author      : Yihe Wang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

int main() {
	cout<<"Welcome to Yihe calculator! "<<endl;

	double num1,num2;
	char operand;
	int choice;

	do{
		cout << "Please follow the format :operand, operator, operand :" <<endl;
		//tell user the right format
	do{
	cin >> num1>>operand>>num2;
	if(cin.fail()){
		cout << "Wrong format! Please re-enter:"<<endl;//check error
		cin.clear();
		cin.ignore();//clean the burffer
	}
	else if((operand=='/')&&(num2==0)){
		cout << "Error! Division by zero, please re-enter:"<<endl;
		//check division
	}
	else
		break;
	}while(1);

		switch(operand){
		case '+':
			cout << "The answer of "<< num1<<"+"<< num2<<" is "
						<<num1+num2 << endl;
						break;//the case of "+"

		case '-':
			cout << "The answer of "<< num1<<"-"<< num2<<" is "
						<<num1-num2 << endl;
						break;//the case of "-"

		case '*':
					cout << "The answer of "<< num1<<"*"<< num2<<" is "
								<<num1*num2 << endl;
						break;//the case of "*"

		case '/':
					cout << "The answer of "<< num1<<"/"<< num2<<" is "
								<<num1/num2 << endl;
						break;//"the case of "/"
		}
		cout<<"Do you want continue to calculate? yes:1, no:0"<<endl;
		cin >> choice;//ask user if they want run again

	}while(choice);

	cout << "Have a nice day!"<<endl;

	return 0;
}
