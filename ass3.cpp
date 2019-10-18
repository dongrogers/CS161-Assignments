/************************************************************
** Function: To test strings and inputs for certain characteristics.
** Description: Group of functions to test user inputs and strings for certain data types or if it contains something specific.
** Paramters: numbers, strings
** Pre-Conditions: None
** Post-Conditions: None
************************************************************/


#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool check_range(int lower_bound, int upper_bound, int test_value) {
	if ((test_value >= lower_bound) && (test_value <= upper_bound)) {
		cout << "PASS" << endl;
	}
	else {
			cout << "FAIL" << endl;
		cout << "Value out of range" << endl;
		return false;
	}
}

bool is_int(string num) {
	for(int i=0; i<num.length(); i++) {
		if (num[i] < char(48) || num[i] > char(57)){
			cout << "FAIL" << endl;
			cout << "Not an integer. " << endl;
			return false;
		}
		else {
			cout << "PASS" << endl;
			return true;
		}
	}
}

bool is_float(string num) {
	for(int i=0, count = 0, present = 0; i<num.length(); i++) {
		if (num[i] == char(46)){
			count++;
		}
		if ((num[i] > char(46)) && (num[i] < char(57))) {
			present++;
		}
		if (num[i] < char(46) || num[i] > char(57))  {
			cout << "FAIL" << endl;
			return false;
		}
		else if (num[i] == char(47)) {
			cout << "FAIL" << endl;
			return false;
		}
		else if ((count == 1) && (present > 0)) {
			cout << "PASS" << endl;
			return true;
		}
		if ((i == (num.length()-1))&&(count == 0)){
			cout << "FAIL" << endl;
			return false;
		}
		if (present = 0){
			cout << "FAIL" << endl;
			return false;
		}
		if (((num[i+1] > char(57)) || (num[i+1] < char(46))) && (num[i] == char(46))){
			cout << "FAIL" << endl;
			return false;
		}
	}
}

bool is_capital(char letter) {
	if ((letter < char(65)) || (letter > char(90))){
			cout << "Not a float. " << endl;
		return false;
	}
	else{
		cout << "PASS" << endl;
		return true;
	}	
}

bool is_even(int num) {
	if (num % 2 == 0) {
		cout << "PASS" << endl;
		return true;
	}
	else {
			cout << "Not a float. " << endl;
		return false;
	}
}

bool is_odd(int num) {
	if (num % 2 == 0) {
			cout << "Not a float. " << endl;
		return false;
	}
	else {
		cout << "PASS" << endl;
		return true;
	}
}

int equality_test(int num1, int num2){
	if (num1 < num2){
		cout << "-1" << endl;
	}
	else if (num1 > num2){
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
}

bool float_is_equal(float num1, float num2, float precision){
	int upperbound = num1 + precision;
	int lowerbound = num1 - precision;
	if ((num2 >= lowerbound) && (num2 <= upperbound)){
		cout << "PASS" << endl;
		return true;
	}
	else{
			cout << "FAIL. " << endl;
		return false;
	}
}	

bool numbers_present(string sentence) {
	for(int i=0; i<sentence.length(); i++){
		if ((sentence[i] > char(47)) && (sentence[i] < 58)){
			cout << "PASS" << endl;
			return true;
			break;
		}
		else{
			cout << "FAILED" << endl;
		}
	}
}

bool letters_present(string sentence) {
	for(int i=0; i<sentence.length(); i++){
		if ((sentence[i] > char(64)) && (sentence[i] < char(89))){
			cout << "PASS" << endl;
			return true;
		}
		if ((sentence[i] > char(96)) && (sentence[i] < char(123))){
			cout << "PASS" << endl;
			return true;
		}
		else{

			cout << "FAILED" << endl;
		}
	}
}

bool contains_sub_string(string sentence, string sub_string) {
	int j = 0, present = 0, i = 0;
	while (present != sub_string.length()){
		if (sub_string[i] == sentence[j]){
			i++;
			j++;
			present++;
		}
		if ((present) == (sub_string.length())){
			cout << "PASS" << endl;
			return true;
		}
		if (sub_string[i] != sentence[j]){
			j++;
		}
		if (j == sentence.length()) {
			j = 0;
			i++;
		}
		if (i > sub_string.length()){
			cout << "FAILED" << endl;
			return false;
		}
	}
}


int word_count(string sentence){
	int thecount = 1;
	for(int i=0; i<(sentence.length()+1); i++){
		if (sentence[i] == char(32)) {
			thecount++;
		}
		if ((sentence.length() == 0)){
			int thecount = 0;
			return thecount;
		}
	}
	return thecount;
}

string to_upper(string sentence){
	string newstring = "";
	for(int i=0; i<sentence.length(); i++){
		if ((sentence[i] > char(96)) && (sentence[i] < char(123))) {
			newstring += (sentence[i] - char(32));
		}
	}
	return newstring;
}

string to_lower(string sentence){
	string newstring = "";
	for(int i=0; i<sentence.length(); i++){
		if ((sentence[i] > char(64)) && (sentence[i] < char(91))) {
			newstring += (sentence[i] + char(32));
		}
	}
	return newstring;
}


int get_int(string prompt){
	cout << prompt << endl;
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
	
	int newnum = 0;
	for(int i=0, j=1; i<num.length(); i++){
		newnum += ((num[i]-48)*j);
		j = j*10;
	}
	cout << "Number is an integer. " << endl;
		cout << "PASS" << endl;
	return newnum;
}

// divide it by weird number like 3.14 and see if it rounds down
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
			cout << "Checking = " << (the_float[x]) << endl;
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
	cout << "VALID FLOAT" << endl;

	while (the_float[i] != char(46)){ //counts the place of the decimal
		if (the_float[i] != char(46)){
			cout << "Increment Where_Dec" << endl;
			i++;
			where_dec += 1;
		}
		if (the_float[i] == char(46)){
			cout << "Decimal found, final place is " << where_dec << endl;	
		}
	}

	for(int i=(where_dec-1), j = 1; i>-1; i--){ //adds up the left side of the float
		cout << "Currently adding = " << the_float[i] << endl;
		thefloat += ((int(the_float[i])-48)*j);
		cout << "Num added, new value =  " << thefloat << endl;
		j = j*10;
	}

	float f_d = 0;
//if decimals on the right equal to lenght of 3, divide by 1000
//should add up all the integers on the right side in thsi func, then divide by 1000 at end -> add
	for(int i=(the_float.length()-1), j = 1 ; the_float[i] != char(46); i--){
		cout << "Currently adding = " << the_float[i] << endl;
		decimalside += ((int(the_float[i])-48)*j);
		cout << "Decimal num added, new value = " << decimalside << endl;
		j = j*10;
		f_d++;
	}
	
//want to create a divison variable which has length of f_d + 1
//10 to the power of length
	float divider = pow(10, f_d);
	cout << "Divider = " << divider << endl;

	thefloat += (decimalside/divider);
	cout << "Final Float = " << thefloat << endl;
}




int main() {
	cout << get_float("Enter integer : ")  << endl;
//	cout << get_float("Enter float: " ) << endl;
	return 0;
}

