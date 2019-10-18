/*********************************************************************
** Program Filename: ass1.cpp
** Author: Rogers Dong
** Date: 1/14/2018
** Description: Use the CMath library, print equations
** Input: None
** Output: Result of equations
*********************************************************************/

#include <iostream>
#include <cmath> 
using namespace std;

int main(){
// Part 1 of Assignment

	double eq1 = cos(2.0/3.0);
	float eq2 = 2*(sin(2.0/3.0));
	float eq3 = tan(-3.0/4.0);
	float eq4 = log10(55.0);
	float eq5 = log(60.0);
	float lnx1 = log(2);
	float lnb1 = log(15);
	float lnx2 = log(4);
	float lnb2 = log(40);
	float eq6 = lnx1/lnb1;
	float eq7 = lnx2/lnb2;

	cout << "The result of cos(2/3) is " << eq1 << endl;
	cout << "The result of 2sin(2/3) is " << eq2 << endl;
	cout << "The result of tan(-3/4) is " << eq3 << endl;
	cout << "The result of log(55) is " << eq4 << endl;
	cout << "The result of ln(60) is " << eq5 << endl;

	cout << endl;	

//Part 2

	cout << "Find the result of log base 2 of 15." << endl;
	cout << "ln(x) = " << lnx1 << endl;
	cout << "ln(b) = " << lnb1 << endl;
	cout << "ln(x)/ln(b) = " << eq6 << endl;

	cout << endl;

	cout << "Find the result of log base 4 of 40." << endl;
	cout << "ln(x) = " << lnx2 << endl;
	cout << "ln(b) = " << lnb2 << endl;
	cout << "ln(x)/ln(b) = " << eq7 << endl;

	cout << endl;

//Part 3

	float x = 1;
	float eq8 = pow(3,sin(x));

	cout << "x = " << x << endl;
	cout << "If x is 1, 3^(sinx) = " << eq8 << endl;

	x = 10;
	eq8 = pow(3,sin(x));

	cout << "x = " << x << endl;
	cout << "If x is 10, 3^(sinx) = " << eq8 << endl;

	x = 100;
	eq8 = pow(3,sin(x));

	cout<< "x = " << x << endl;
	cout << "If x is 100, 3^(sinx) = " << eq8 << endl;
	
	cout << endl;

//Part 4

	x = 1;
	float eq9 = log2(pow(x, 2) + 1);

	cout << "If x = 1, log base 2 of (x^2+1) = " << eq9 << endl;

	x = 10;
	eq9 = log2(pow(x, 2) + 1);

	cout << "If x = 10, log base 2 of (x^2+1) = " << eq9 << endl;

	x = 100;
	eq9 = log2(pow(x, 2) + 1);

	cout << "If x == 100, log base 2 of (x^2+1) == " << eq9 << endl;
	return 0;
}
