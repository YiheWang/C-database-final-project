/* Simple_formatting.cpp
 Created by: Luis Rivera */

#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int main(){
	float x = 9.123456789;
	int i = 10;
	int y = 0b11001001;
	int z = 0x1248ABCD;
		
	// Formatting - some examples. There are other functions/options.
	cout << "\nFormatting output: \n";
	cout << x << endl << setprecision(1) << x << endl << setprecision(3) << x << endl
		 << setprecision(6) << x << endl << x << endl;
		 
	cout << i << endl << setw(1) << i << endl << setw(3) << i << endl
		 << setw(4) << i << endl << setw(5) << i << endl;
		 
	cout << setfill('0') << setw(4) << i << endl << setfill('*') << setw(5) << i
		 << endl << endl;
	
	// Numerical representations
	cout << "y = " << bitset<8>(y) << " = " << y << " = " << hex << y << endl;
	cout << "z = " << bitset<32>(z) << " = " << dec << z << " = " << hex << z << endl;
	
	cout << showbase << endl;
	cout << "y = " << bitset<8>(y) << " = " << dec << y << " = " << hex << y << endl;
	cout << "z = " << bitset<32>(z) << " = " << dec << z << " = " << hex << z << endl;
	
	cout << uppercase << endl;
	cout << "y = " << bitset<8>(y) << " = " << dec << y << " = " << hex << y << endl;
	cout << "z= " << bitset<32>(z) << " = " << dec << z << " = " << hex << z << endl;
	
	return 0;
}