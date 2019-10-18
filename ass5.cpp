#include <iostream>
#include <cmath>

using namespace std;
//Function List
//Check if Decimal or Int
//Turn string back into int/float

/*********************************************************************
** Function: Is_Int
** Description: Checks if integer
** Parameters: String
** Pre-Conditions: String is entered as parameter
** Post-Conditions: True or False
*********************************************************************/
bool is_int(string op){
	for(int i=0; i<op.length(); i++){
		if ((op[i] < '0') || (op[i] > '9')){
			return false;
		}
	}
	return true;
}

/*********************************************************************
** Function: Is_Float
** Description: Checks if float
** Parameters: String
** Pre-Conditions: String is entered as parameter
** Post-Conditions: True or False
*********************************************************************/
bool is_float(string op){
	int counter = 0, nums = 0;
	for(int i=0; i<op.length(); i++){
		if (op[i] == char(46)){
			counter++;
		}
		if ((op[i] >= '0') && (op[i] <= '9')){
			nums += 1;
		}
		if ((nums == (op.length()-1)) && (counter == 1)){
			return true;
		}
	}
}

/*********************************************************************
** Function: Dec_Float
** Description: Checks where the decimal is in the float
** Parameters: String
** Pre-Conditions: String has a decimal point
** Post-Conditions: Integer
*********************************************************************/
int dec_float(string the_float){
	int i = 0, where_dec = 0; //count of nums checked, if j = length, all checked
	while (the_float[i] != char(46)){ //counts the place of the decimal
		if (the_float[i] != char(46)){
			i++;
			where_dec += 1;
		}
	}
	return where_dec;
}

/*********************************************************************
** Function: Get_Int
** Description: Turns a string of some num into an integer
** Parameters: String
** Pre-Conditions: String is parameter, only numbers
** Post-Conditions: Integer
*********************************************************************/
float  get_int(string num){
	int counter = 0;
	float newnum = 0;
	for(int i=(num.length()-1), j=1; i>=0; i--){
		newnum += ((num[i]-48)*j);
		j = j*10;
	}
	return newnum;
}

/*********************************************************************
** Function: Get_Float
** Description: Turns a string of some float into an integer
** Parameters: String
** Pre-Conditions: String is parameter, has a decimal
** Post-Conditions: Float
*********************************************************************/
float get_float(string the_float){
	bool good = false;
	float thefloat = 0.0, decimalside = 0.0; 
	
	int where_dec = dec_float(the_float);

	for(int i=(where_dec-1), j = 1; i>-1; i--){ //adds up the left side of the float
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
	return (thefloat += (decimalside/divider));

}

/*********************************************************************
** Function: get_num
** Description: Prompts for a number, if float or int
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Valid number in string form
*********************************************************************/
string get_num(){ //if is float or is int is true, then num is true
	bool flag = true;
	string num = "";
	while(flag == true){
		cin >> num;
		if ((is_int(num)) || (is_float(num))){
			flag = false;
		}
	}
	return num;
}

/*********************************************************************
** Function: get_bin_num
** Description: Prompts for a number, checks if all 1 or 0
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Valid number in string form
*********************************************************************/
string get_bin_num(){
	bool flag = true;
	int checked = 0;
	string num = "";
	while(flag == true){
		cin >> num;
		checked = 0;
		for(int i = 0; i<num.length(); i++){
			if(num[i] > '1'){
				flag = true;
				checked++;
				break;
			}
			if((i == num.length()-1) && (checked == 0)){
				flag = false;
			}
		}
	}
	cout << "Num: " << num << endl;
	return num;
}

/*********************************************************************
** Function: get_real_num
** Description: Prompts for number, returns as float or int
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Valid number in integer or float type
*********************************************************************/
float get_real_num(){
	bool good = true;
	string num;
	while(good == true){
		cin >> num;
		if(is_float(num) == true){
			return get_float(num);
		}
		if(is_int(num) == true){
			return get_int(num);
		}
	}
	
}

/*********************************************************************
** Function: valid_ops
** Description: Checks if there are multiple operators, if no number after op, or no ops at all
** Parameters: String of an equation
** Pre-Conditions: Equation entered into parameter
** Post-Conditions: True/False
*********************************************************************/
bool valid_ops(string equation){ //if there is two ops in a row, if there is no number after the op, if there are no ops at all
	int ops_ = 0;
	for(int i = 0; i<equation.length(); i++){
		if(equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == char(47)){
			if(i == 0){
				return true;
			}
			i++;
			ops_++;
			if(equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == char(47)){
				return true;
			}
			if(equation[i] == '\0'){
				return true;
			}
		}
		if((i == (equation.length()-1)) && (ops_ == 0)){
			return true;
		}
	}
	return false;
}

/*********************************************************************
** Function: String_to_num
** Description: Takes any given string, checks if only numbers, returns in float/integer data type
** Parameters: String
** Pre-Conditions: String in parameter entered
** Post-Conditions: Number as a float
*********************************************************************/
float string_to_num(string unknown_num){
	float num1 = 0;
	if (is_int(unknown_num) == true){
		num1 = get_int(unknown_num);
	}
	if (is_float(unknown_num) == true){
		num1 = get_float(unknown_num);
	}
	return num1;
}

/*********************************************************************
** Function: equation_taker
** Description: Takes in two floats and an operator 
** Parameters: num1, op, num2
** Pre-Conditions: two float nums and an operator character
** Post-Conditions: float number
*********************************************************************/
float equation_taker(float num1, char op, float num2){
	float res = 0;
	
	switch(op){
		case '+':
			res = num1+num2;
			break;
		case '-':
			res = num1-num2;
			break;
		case '*':
			res = num1*num2;
			break;
		case '/':
			res = num1/num2;
			break;
	}
	return res;
}

/*********************************************************************
** Function: equation_checker
** Description: Standard calculator, checks for the first two numbers and operator, performs calculation. Then takes
the remainder of the equation and returns the function again, performing operations until equation is at the end.
** Parameters: result from first operation, equation in string form, number of times it has run
** Pre-Conditions: valid_equations has to be true
** Post-Conditions: floating number returned as result
*********************************************************************/
float equation_checker(float resulting, string equation, float run){ //function finds the first number, an operator, and the second number
	float i = 0, num1, num2, op_found = 0, j = 0, fact, runtime = 0; 
	string unknown_num = "", unknown_num2 = "", new_string = "", remaining_eq = "", strung_fact = "";
	char op;

	for(int k = 1; i<equation.length(); i++){ // finds num1 and op
		if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == char(47)){
			if (op_found == 0){
				op = equation[i];
			}
			op_found++;
			i++;
		}
		if (op_found == 0){
			if((equation[i] >= '0') && (equation[i] <= '9')){
				unknown_num += (equation[i]);
				fact = string_to_num(unknown_num);
			}
		}
		if (op_found == 1){
			if((equation[i] >= '0') && (equation[i] <= '9')){
				unknown_num2 += (equation[i]);
				num2 = string_to_num(unknown_num2);
			}
		}
		if (op_found == 2){
			i--;
			break;
		}
	}

	for(j = i; j<(equation.length()); j++){ //pin the rest of the unused equation to new variable, add result of the first round to beginning of remaining equation, rerun
			remaining_eq += equation[j];
	}

	if (run == 0)
		fact = equation_taker(fact, op, num2); 
	else if (run > 0)
		fact = equation_taker(resulting, op, num2);

	cout << "Result: " << fact << endl;

	if (remaining_eq == "")
		return fact;
	
	runtime += 1;
	return equation_checker(fact, remaining_eq, runtime);
}

/*********************************************************************
** Function: whitespaces()
** Description: Checks if white spaces are between each operand/operator, checks for non-numbers as well
** Parameters: Equation
** Pre-Conditions: None
** Post-Conditions: True/False
*********************************************************************/
bool whitespaces(string equation) {
	bool checks = true;
	for(int i=0; i<equation.length(); i++){ //should check for anything other than ops and numbers
			if(equation[i] < char(41) || equation[i] > char(57)){
				if(equation[i] != char(32)){
					checks = false;
					break;
				}
			}
			if((equation[i] >= char(48)) && (equation[i] <= char(57))){ //if i is a number
				if((i) == (equation.length()-1)){
					break;
				}
				if(equation[i+1] != char(32)){ //if next thing is not a number or a space
					checks = false;
				}
				if((equation[i] >= char(48)) && (equation[i] <= char(57)))
					checks = true;
			}
			if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == char(47)){
				if(equation[i+1] != char(32)){
					checks = false;
					break;
				}
	
			}
	} return checks;
}

/*********************************************************************
** Function: valid_equation()
** Description: Starts the calculator by taking user input and checking for validity, then passing onto equation_checker()
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Equation is checked and good
*********************************************************************/
float valid_equation(){
	int checks = 0;
	string equation = "";
	while (checks != 2){
		checks = 0;
		cout << "Enter an equation with spaces between operands/operators" << endl;
		getline(cin, equation);
		if (valid_ops(equation) == false){
			checks++;
		}

		if (whitespaces(equation) == false){
			checks = 0;
		}

		checks++;
	}
	return equation_checker(0, equation, 0);
}

/*********************************************************************
** Function: bin_to_dec
** Description: Takes in a binary number, converts into decimal form
** Parameters: string
** Pre-Conditions: parameter has to be only 0's and 1's
** Post-Conditions: integer with binary converted
*********************************************************************/
int bin_to_dec(string binary){
	int equation = 0;
	for(int i=0; i<binary.length(); i++){
		if(binary[i] == '1'){
			equation += pow(2, (binary.length()-(i+1)));
		}
	}
	return equation;
}

/*********************************************************************
** Function: get_int_bin
** Description: converts the binary string into an integer
** Parameters: string
** Pre-Conditions: dec_to_bin has to pass in some string
** Post-Conditions: integer converted
*********************************************************************/
long int get_int_bin(string num){
	long int newnum = 0;
	for(long int i=(num.length()-1), j=1; i>=0; i--){
		newnum += ((num[i]-48)*j);
		j = j*10;
	}
	return newnum;
}

/*********************************************************************
** Function: dec_to_bin
** Description: Turns decimal numbers to binary
** Parameters: integer
** Pre-Conditions: Integer is valid, only numbers
** Post-Conditions: Integer binary number
*********************************************************************/
long int dec_to_bin(long int num){
	string binary = "", reverse = "";
	long int result = num;
	while(result != 1/2){
		if ((result % 2) == 1){
			binary += "1";
			result = result/2;
		}
		else{
			binary += "0";
			result = result/2;
		}
		if (result == 1){
			binary += "1";
			break;
		}
	}
	for(int i=binary.length()-1; i>=0; i--){
		if(binary[i] >= '0' && binary[i] <= '9')
			reverse += binary[i];
	}
	long int final_binary = get_int_bin(reverse);
	return final_binary;
}


/*********************************************************************
** Function: grade_calc
** Description: Takes in a certain number of grades, averages percentage
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns a float
*********************************************************************/
float grade_calc(){
	float num_grades = 0, total = 0, total_ask = 0, users_total_ask = 0, users_total = 0, percentage = 0;
	cout << "How many grades " << endl;
	num_grades = get_real_num();

	for(int i=0; i != num_grades; i++){
		cout << "How much is this assignment worth " << endl;
		total_ask = get_real_num();
		total += total_ask;
		cout << "Total = " << total << endl;
	
		cout << "How much did you get on this assignment " << endl;
		users_total_ask = get_real_num();
		users_total += users_total_ask;
	}
	percentage = (users_total/total)*100.0;
	return percentage;
}

/*********************************************************************
** Function: weighted_grade_calc
** Description: Calculates grade with weights attatched to points/percentage
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns a float
*********************************************************************/
float weighted_grade_calc(){
	float num_grades = 0, total = 0, total_ask = 0, users_total_ask = 0, users_total = 0, percentage = 0, weight = 0;
	cout << "How many grades " << endl;
	num_grades = get_real_num();

	for(int i=0; i != num_grades; i++){
		weight = 0;
		cout << "What is the weight of this assignment (in percentage) " << endl;
		weight = get_real_num();
		cout << "How much did you get on this assignment " << endl;
		users_total_ask = get_real_num();

		total += users_total_ask;
		users_total += (users_total_ask*weight);
	}
	percentage = (users_total/total);
	return percentage;
}

/*********************************************************************
** Function: initialize
** Description: Asks user which calculator they want to use
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: calculator is ran
*********************************************************************/
void initialize(){
	cout << "Enter 1 for Standard Calculator, 2 for Decimal to Binary, 3 for Binary to Decimal, 4 for Grade Calculator, or 5 for Weighted Grade Calculator"  << endl;
	int choice = get_real_num(), runner = 0;
	cin.ignore(1000, '\n');
	long int binary_num = 0;
	string num = "";
	switch(choice){
		case 1:
			valid_equation();
			break;
		case 2:
			binary_num = get_real_num();
			cout << dec_to_bin(binary_num) << endl;
			break;
		case 3:
			num = get_bin_num();
			cout << bin_to_dec(num) << endl;
			break;
		case 4:
			cout << grade_calc() << "%" << endl;
			break;
		case 5:
			cout << weighted_grade_calc() << "%" << endl;
			break;	
	}
	cout << "Run calculator again? 1 for Yes, 2 for No " << endl;
	cin >> runner;
	if(runner == 1)
		initialize();
}

int main(){
	initialize();
	
}
