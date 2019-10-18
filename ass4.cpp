#include <iostream>
#include <cmath>

using namespace std;

float get_int(string num){
	bool good;
	string num;
	int counter = 0;
	do{	
		cin >> num;
		for(int i=0; i<num.length(); i++){
			if ((num[i] < char(48))  || (num[i] > char(57))){
				int counter = 0;
			}
			else {
				counter += 1;
			}
			if (counter == num.length()){
				good = true;
				break;
			}
			if (i = num.length()){
				counter = 0;
			}
		}
	}while (good != true);	
	
	float newnum = 0;
	for(int i=(num.length()-1), j=1; i>0; i--){
		newnum += ((num[i]-48)*j);
		j = j*10;
	}
	cout << "Number is an integer. " << endl;
		cout << "PASS" << endl;
	return newnum;
}


float get_float(string prompt){
	bool good = false;
	int i = 0; //count of nums checked, if j = length, all checked
	float thefloat = 0.0; //add stuff to this
	int where_dec = 0;
	string the_float = ""; //strung float
	float decimalside = 0.0; 
	while (good != true){
		int j = 0;
		int decimalpresent = 0;
		getline(cin, the_float);
		for(int x=0; x<the_float.length(); x++){
			if (((the_float[x]) < char(48)) || ((the_float[x]) > char(57))){
				if (the_float[x] == char(46)){
					decimalpresent++;
				}
				else{
					break;
				}
			}
			else{
				j++;
			}
		}
		if (j == (the_float.length()-1)){
			good = true;
		}
	}

	while (the_float[i] != char(46)){ //counts the place of the decimal
		if (the_float[i] != char(46)){
			i++;
			where_dec += 1;
		}
	}

	for(int i=(where_dec-1), j = 1; i>0; i--){ //adds up the left side of the float
		thefloat += ((int(the_float[i])-48)*j);
		j = j*10;
	}

	float f_d = 0;
	for(int i=(the_float.length()-1), j = 1 ; the_float[i] != char(46); i--){
		decimalside += ((int(the_float[i])-48)*j);
		j = j*10;
		f_d++;
	}
	
	float divider = pow(10, f_d);

	thefloat += (decimalside/divider);
	return thefloat;
}

bool float_or_int(string op){
	for(int i=0; i<op.length(); i++){
		if (op[i] == char(46)){
			return true;
		}
		else{
			return false;
		}
}

float standard(){
	char op;
	bool flag = true;
	string op_1, op_2;

	do{
		cout << "What operator (+, -, *, /)? " << endl;
		cin >> op;
			
		if (op == '+' || op == '-' || op == '*' || op == '/'){
			flag = false;
		}
	}while(flag == true);
	
	do{
		cout << "Enter operand 1 : " << endl;
		cin >> op_1;

		if (float_or_int(op_1) == true){
			get_int(
		}

		cout << "Enter operand 2: " << endl;
		cin >> op_2;

		flag = valid_num(op_2);
	}while(flag == true);
}


int main() {
	standard();


}
