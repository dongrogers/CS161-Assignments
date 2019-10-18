/*********************************************************************
** Program Filename: ass7.cpp
** Author: Rogers
** Date: 3/4/2018
** Description: Farkle, a Dice Game
** Input: Numbers
** Output: Print statements, scores
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*********************************************************************
** Function: is_int
** Description: Check if int
** Parameters: String
** Pre-Conditions: Input in string
** Post-Conditions: True/False if Int
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
** Function: get_int
** Description: String to Int
** Parameters: String
** Pre-Conditions: Input in string
** Post-Conditions: Number returned
*********************************************************************/ 
int get_int(string num){
	int counter = 0;
	float newnum = 0;
	for(int i=(num.length()-1), j=1; i>=0; i--){
		newnum += ((num[i]-48)*j);
		j = j*10;
	}
	return newnum;
}

/*********************************************************************
** Function: get_real_num
** Description: Takes input as string, turns to num
** Parameters: None
** Pre-Conditions: Input taken
** Post-Conditions: Num returned
*********************************************************************/ 
int get_real_num(){
	bool good = true;
	string num;
	while(good == true){
		cout << "Enter a number: " << endl;
		cin >> num;
		if(is_int(num) == true){
			return get_int(num);
		}
	}
	
}

/*********************************************************************
** Function: print_dyn
** Description: Prints array
** Parameters: Array, rows, turn
** Pre-Conditions: Parameters are inputted
** Post-Conditions: Print statement
*********************************************************************/ 
void print_dyn(int** ar, int rows, int turn){
	for(int i=0; i<rows; i++){
		cout << "Player " << i+1 << "'s Score: "; 
		cout << ar[i][0] << " "; 
		cout << endl;
	}
	cout << "It is now Player's " << turn+1 << " turn." << endl;
	cout << endl;
}

/*********************************************************************
** Function: print_dices
** Description: Prints array
** Parameters: Array
** Pre-Conditions: Parameters are inputted
** Post-Conditions: Print statement
*********************************************************************/ 
void print_dices(int* diceboard){
	for(int i=0; i<6; i++){
		if(diceboard[i] != 0){
			cout << "Dice: " << diceboard[i] << endl;
		}
	}
	cout << endl;
}

/*********************************************************************
** Function: reset_dices
** Description: Turns dice values to 0
** Parameters: Array
** Pre-Conditions: Parameters are inputted
** Post-Conditions: Values at ar[][0] are 0
*********************************************************************/ 
void reset_dices(int ar[][2]){
	for(int i=0; i <= 14; i++){
		ar[i][0] = 0;
	}	
}

/*********************************************************************
** Function: populate_zeros
** Description: Fills 2d Array with 0
** Parameters: Array, rows
** Pre-Conditions: Parameters are inputted
** Post-Conditions: Array filled
*********************************************************************/ 
int** populate_zeros(int** ar, int rows){ //set j = 1 because every player only has 1 assosciated score
	for(int i=0; i<rows; i++){
		(*ar)[i] = i;
		for(int j=0; j<1; j++){
			ar[i][j] = 0;
		}
	}
	return ar;
}

/*********************************************************************
** Function: trio_combo_check
** Description: Checks for a certain combo
** Parameters: Dice array, dices, point system array
** Pre-Conditions: Parameters are inputted
** Post-Conditions: Point system array checked to 1 if true
*********************************************************************/ 
void trio_combo_check(int* scoreboard, int dice_available, int arr[][2]){
	int doub_triplet[2], double_triplet = 0, three_check = 0, pair_check = 0;
	for(int i=0; i<=dice_available; i++){
		three_check = 0;
		for(int j = 0; j<=dice_available; j++){
			if((scoreboard)[j] == i+1){ //Checks if any of the dices are equivalent to i+1, bumps i++ after it checks all dices.
				three_check++;
			}
			if(three_check == 3){
//				cout << "Three of a Kind for Dice:  " << i+1 << endl;
				arr[i+2][0] = 1; //Sets dicepoints to true
				double_triplet++;
				three_check = 0;
			}
		}
	}
	if (double_triplet == 2){
			arr[14][0] = 1;
//			cout << "Double Triplet Found" << endl;
	}
	else{
		arr[14][0] = 0;
	}
}

/*********************************************************************
** Function: singles
** Description: Checks for a certain combo
** Parameters: Dice array, dices, point system array
** Pre-Conditions: Parameters are inputted
** Post-Conditions: Point system array checked to 1 if true
*********************************************************************/ 
void singles(int* scoreboard, int dice_available, int arr[][2]){ //lookin for single 1, single 5
	int dice1 = 0, dice5 = 0;
	for(int i=0; i<= dice_available; i++){
		for(int j=0; j<= dice_available; j++){
			if((scoreboard)[j] == 1)
				dice1++;	
			if((scoreboard)[j] == 5)
				dice5++;
		}
	}	
	if(dice1 > 0){
		arr[0][0] = 1;
	}
	if(dice5 > 0){
		arr[1][0] = 1;
	}
}

/*********************************************************************
** Function: four_five_six
** Description: Checks for a certain combo
** Parameters: Dice array, dices, point system array
** Pre-Conditions: Parameters are inputted
** Post-Conditions: Point system array checked to 1 if true
*********************************************************************/ 
void four_five_six(int diceboard[], int dice_available, int arr[][2]){
	int numcheck = 0, fournum = 0, fivenum = 0, sixnum = 0, fourpair = 0;
	for(int i=0; i<= dice_available; i++){
		numcheck = 0;
		for(int j=0; j<= dice_available; j++){
			if(diceboard[j] == i+1){
				numcheck++;
			} 
			if(numcheck == 4){
				arr[8][0] = 1;
			}
			if(numcheck == 5){
				arr[9][0] = 1;
			}
			if(numcheck == 6){
				arr[10][0] = 1;
			}	
			if((numcheck == 4) && (dice_available == 5)){
				if((diceboard[j+1] == diceboard[j+2]) && (diceboard[j] != diceboard[j+1])){
				fourpair++;
				arr[13][0] = 1;
				}
			}
		} 
	}
}

/*********************************************************************
** Function: three_pairs
** Description: Checks for a certain combo
** Parameters: Dice array, dices, point system array
** Pre-Conditions: Parameters are inputted
** Post-Conditions: Point system array checked to 1 if true
*********************************************************************/ 
void three_pairs(int diceboard[], int dice_available, int arr[][2]){
	int numcheck = 0, paircheck = 0;
	for(int i=0; i<=dice_available; i++){
		numcheck = 0;
		for(int j=0; j<=dice_available; j++){
			if(diceboard[j] == i+1){
				numcheck++;
			}
			if(numcheck >= 2){
				paircheck++;
				numcheck = 0;
			}
		}
	}	
	if(paircheck == 3){
//		cout << "Triple Dice Pair Found" << endl;
		arr[12][0] = 1;
	}
	else
		arr[12][0] = 0;
}

/*********************************************************************
** Function: straight
** Description: Checks for a certain combo
** Parameters: Dice array, dices, point system array
** Pre-Conditions: Parameters are inputted
** Post-Conditions: Point system array checked to 1 if true
*********************************************************************/ 
void straight(int diceboard[], int dice_available, int arr[][2]){
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
	if(dice_available == 5){
		for(int i=0; i<= dice_available; i++){
			if(diceboard[i] == 1){
				one++;
			}
			if(diceboard[i] == 2){
				two++;}
			if(diceboard[i] == 3){
				three++;}
			if(diceboard[i] == 4){
				four++;}
			if(diceboard[i] == 5){
				five++;}
			if(diceboard[i] == 6){
				six++;}
		}
	}
	if((one && two && three && four && five && six) == (1)){
//		cout << "Straight from 1-6 Found" << endl;
		arr[11][0] = 1;
	}
}

/*********************************************************************
** Function: remove single
** Description: Switches dice to zero if combo is chosen
** Parameters: Dice array, combo
** Pre-Conditions: Combo is chosen or found
** Post-Conditions: Dice array switched to 0
*********************************************************************/ 
void remove_single(int diceboard[], int single){
	for(int i=0; i != 6; i++){
		if(single == 0){
			if(diceboard[i] == 1){
				diceboard[i] = 0;
				break;
			}
		}
		if(single == 1){
			if(diceboard[i] == 5){
				diceboard[i] = 0;
				break;
			}
		}
	}
}


/*********************************************************************
** Function: remove_trio
** Description: Switches dice to zero if combo is chosen
** Parameters: Dice array, combo
** Pre-Conditions: Combo is chosen or found
** Post-Conditions: Dice array switched to 0
*********************************************************************/ 
void remove_trio(int diceboard[], int single){
	for(int i=0, check = 0; i != 6; i++){
		if(diceboard[i] == single-1){
			diceboard[i] = 0;
			check++;
		}
		if(check == 3){
			break;
		}
	}
}

/*********************************************************************
** Function: remove_fours
** Description: Switches dice to zero if combo is chosen
** Parameters: Dice array, combo
** Pre-Conditions: Combo is chosen or found
** Post-Conditions: Dice array switched to 0
*********************************************************************/ 
void remove_fours(int diceboard[]){
	int remove = -1;
	for(int i=0; i != 6; i++){
		int check = 0;
		for(int j=0; j!= 6; j++){
			if(diceboard[j] == i+1){
				check++;
			}
			if(check == 4){
				remove = diceboard[j];
				break;
			}
		}
	}

	for(int i=0; i != 6; i++){
		if(diceboard[i] == remove){
			diceboard[i] = 0;
		}
	}
}
	
/*********************************************************************
** Function: remove_fives
** Description: Switches dice to zero if combo is chosen
** Parameters: Dice array, combo
** Pre-Conditions: Combo is chosen or found
** Post-Conditions: Dice array switched to 0
*********************************************************************/ 
void remove_fives(int diceboard[]){
	int remove = -1;
	for(int i=0; i != 6; i++){
		int check = 0;
		for(int j=0; j!= 6; j++){
			if(diceboard[j] == i+1){
				check++;
			}
			if(check == 5){
				remove = diceboard[j];
				break;
			}
		}
	}

	for(int i=0; i != 6; i++){
		if(diceboard[i] == remove){
			diceboard[i] = 0;
		}
	}
}
	
/*********************************************************************
** Function: remove_sixes
** Description: Switches dice to zero if combo is chosen
** Parameters: Dice array, combo
** Pre-Conditions: Combo is chosen or found
** Post-Conditions: Dice array switched to 0
*********************************************************************/ 
void remove_sixes(int diceboard[]){
	int remove = -1;
	for(int i=0; i != 6; i++){
		int check = 0;
		for(int j=0; j!= 6; j++){
			if(diceboard[j] == i+1){
				check++;
			}
			if(check == 6){
				remove = diceboard[j];
				break;
			}
		}
	}

	for(int i=0; i != 6; i++){
		if(diceboard[i] == remove){
			diceboard[i] = 0;
		}
	}
}
	
/*********************************************************************
** Function: remove_all
** Description: Switches dice to zero if combo is chosen
** Parameters: Dice array, combo
** Pre-Conditions: Combo is chosen or found
** Post-Conditions: All dice array switched to 0
*********************************************************************/ 
void remove_all(int diceboard[]){ //used for things like the straight, double triple, four nums and a pair, 3 pairs, six of any number
	for(int i=0; i != 6; i++){
		diceboard[i] = 0;
	}	
}

/*********************************************************************
** Function: all_in_one_checker
** Description: Checks for every combo
** Parameters: Dice array, combo, point system array
** Pre-Conditions: Dice is rolled
** Post-Conditions: Point system array switched to true or false
*********************************************************************/ 
void all_in_one_checker(int diceboard[], int dice_available, int arr[][2]){
	reset_dices(arr);

	trio_combo_check(diceboard, dice_available, arr);
	singles(diceboard, dice_available, arr);
	four_five_six(diceboard, dice_available, arr);
	three_pairs(diceboard, dice_available, arr);
	straight(diceboard, dice_available, arr);
}

/*********************************************************************
** Function: all_in_one_remover
** Description: Switches dice to zero if combo is chosen
** Parameters: Dice array, combo
** Pre-Conditions: Combo is chosen or found
** Post-Conditions: Dice array switched to 0
*********************************************************************/ 
void all_in_one_remover(int diceboard[], int combo){
	if(combo == 1 || combo == 0){
		remove_single(diceboard, combo);
	}
	
	if(combo >= 2 && combo <= 7){ 
		remove_trio(diceboard, combo);
	}
	if(combo == 8){
		remove_fours(diceboard);
	}
	if(combo == 9){
		remove_fives(diceboard);
	}
	if(combo == 10){
		remove_sixes(diceboard);
	}
	if(combo == 11 || combo == 12 || combo == 13 || combo == 14){
		remove_all(diceboard);
	}
}

/*********************************************************************
** Function: reroll_diceboard
** Description: Checks if diceboard is cleared
** Parameters: Dice array
** Pre-Conditions: None
** Post-Conditions: Return true/false
*********************************************************************/ 
bool reroll_diceboard(int diceboard[]){ //checks if diceboard is rerollable. false means it is.
	int zeros = 0;
	for(int i=0; i != 6; i++){
		if(diceboard[i] == 0){
			zeros++;
		}
	}
	if(zeros == 6){
		return true;
	}
	else{
		return false;
	}
}

/*********************************************************************
** Function: partial_reroll_diceboard
** Description: Checks if diceboard is cleared or partially cleared
** Parameters: Dice array
** Pre-Conditions: None
** Post-Conditions: Return true/false
*********************************************************************/ 
bool partial_reroll_diceboard(int diceboard[]){
	for(int i=0; i != 6; i++){
		if(diceboard[i] != 0){
			return true;
		}
	}
}

/*********************************************************************
** Function: combo_printer
** Description: Prints available combos
** Parameters: Dice array, combo, which dices
** Pre-Conditions: Combo is found
** Post-Conditions: Print statements
*********************************************************************/ 
void combo_printer(int combo, int original, int i, int arr[][2]){
	switch(combo){
		case 0:
			cout << "Combo 0: Dice 1 for 100 Points" << endl; 
			break;
		case 1:
			cout << "Combo 1: Dice 5 for 50 Points" << endl;
			break;
		case 2:
			cout << "Combo 2: Three Dices of 1 for 300 Points" << endl;	
			break;
		case 3:
			cout << "Combo " << original << ": Three Dices of " << i-1 << " for " << arr[i][1] << " Points" << endl;
			break;
		case 8:
			cout << "Combo 8: Four of a Kind for 1000 Points" << endl;
			break;
		case 9:
			cout << "Combo 9: Five of a Kind for 2000 Points" << endl;
			break;
		case 10:
			cout << "Combo 10: Six of a Kind for 3000 Points" << endl;
			break;
		case 11:
			cout << "Combo 11: Straight for 1500 Points" << endl;
			break;
		case 12:
			cout << "Combo 12: Triple Pair for 1500 Points" << endl;
			break;
		case 13:
			cout << "Combo 13: Four of a Kind and a Pair for 1500 Points" << endl;
			break;
		case 14:
			cout << "Combo 14: Double Triplets for 2500 Points" << endl;
			break;
	}
}

/*********************************************************************
** Function: combos_avail
** Description: Checks if combos are available
** Parameters: Point system array, available pointer
** Pre-Conditions: Dices rolled
** Post-Conditions: Change available pointer to true/false
*********************************************************************/ 
void combos_avail(int arr[][2], bool *available){ //Find available combos
	int combo = -1, original = -1;
	for(int i=0, checked = 0; i<=14; i++){
		if((arr[i][0]) == 1){
			checked++;
			*available = true;
			combo = i;
			original = i;
			if(i == 3 || i == 4 || i == 5 || i == 6 || i == 7){
				combo = 3;
			}
		}
		if((i == 14) && (checked == 0)){
			*available = false;
		}
		
		combo_printer(combo, original, i, arr);
			
		combo = -1;
	}

}

/*********************************************************************
** Function: combo_valid
** Description: Checks if combo choice is good
** Parameters: Point system array, dices, combo input, score
** Pre-Conditions: Dices rolled, combos available
** Post-Conditions: Add score to temporary, prompt
*********************************************************************/ 
bool combo_valid(int arr[][2], int diceboard[], int combo, int* score){
	int checked = 0;
	if(arr[combo][0] == 1){
		*score += arr[combo][1];	
		all_in_one_remover(diceboard, combo);
		print_dices(diceboard);
		cout << "Running score is now: " << *score << endl;
		arr[combo][0] = 0;
		return true;
	}	

	if(arr[combo][0] == 0){
		cout << "You do not have this combo, try again." << endl;
		return false;
	}
			
}

/*********************************************************************
** Function: another_combo
** Description: Asks for another combo
** Parameters: None
** Pre-Conditions: Dices rolled, combos available
** Post-Conditions: Return boolean
*********************************************************************/ 
bool another_combo(){
	int combo_continue = -1;
		cout << "Do you want another combo? 1 for Yes, 2 for No" << endl;
		combo_continue = get_real_num();
		if(combo_continue == 1){
			return false;
			}
		else{	
			return true;
			} 
}

/*********************************************************************
** Function: get_combo
** Description: Gets a valid number for a combo choice
** Parameters: Point system array, dices, combo input, score
** Pre-Conditions: Dices rolled, combos available
** Post-Conditions: Add score to temporary, prompt
*********************************************************************/ 
int get_combo(int arr[][2], int* diceboard, int combo, int* temp_score, bool* valid){
	combo = get_real_num();
	while(arr[combo][0] != 1){
		cout << "You do not have this combo, try again." << endl;
		combo = get_real_num();
	}
	return combo;
}

/*********************************************************************
** Function: combo_keeper
** Description: Finds combos, adds points to person
** Parameters: Point system array, dices, farkle pointer, player number
** Pre-Conditions: Dices rolled
** Post-Conditions: Add score to player, change farkle pointer
*********************************************************************/ 
int combo_keeper(int arr[][2], int diceboard[], int player, bool* farkle){
	int combo, combo_continue = 0, temp_score = 0;
	bool avail = false, valid = false, rerollable = false, another = false;
	combos_avail(arr, &avail);
	if(avail == false){
		*farkle = true;
		valid = true;
	}
	while(valid == false){
		cout << endl;
		cout << "Which scoring combo do you want to keep?" << endl; 
		combo = get_combo(arr, diceboard, combo, &temp_score, &valid);
		valid = combo_valid(arr, diceboard, combo, &temp_score);
		all_in_one_checker(diceboard, 5, arr);
		combos_avail(arr, &avail);
		rerollable = reroll_diceboard(diceboard); //Check if there was full combo
		if(avail == true){
			another = another_combo();
			if(another == false)
				valid = false;
			if(another == true){
				return temp_score;
	}}}
	return temp_score;
}
	
/*********************************************************************
** Function: dice_roll
** Description: Rolls dices 
** Parameters: Point system array, dices
** Pre-Conditions: None
** Post-Conditions: Dices are rolled randomly
*********************************************************************/ 
int* dice_roll(int arr[][2], int* diceboard){
	int dice_available = 5, roll = 0;
	srand (time(NULL));
	//Random Dice Generator	
	
	for(int i=0; i<=dice_available; i++){
	 	if(diceboard[i] != 0){
			roll = (rand() % 6 + 1);
			diceboard[5-(dice_available-i)] = roll;
			cout << "Roll " << i+1 << ": " << roll << endl;
		}
	}
	cout << endl;
	all_in_one_checker(diceboard, dice_available, arr);

	return diceboard;
}

/*********************************************************************
** Function: init_dicepoints_board
** Description: Holds points for each combo
** Parameters: 2d array
** Pre-Conditions: None
** Post-Conditions: Return array
*********************************************************************/ 
void init_dicepoints_board(int arr[][2]){ //contains points of dice combos and points, if arr[0] = 0, combination is false. not true.
	arr[0][1] = 100;
	arr[1][1] = 50;
	arr[2][1] = 300;
	for(int i=3; i<8; i++)
		arr[i][1] = ((i-1)*100);
	arr[8][1] = 1000;
	arr[9][1] = 2000;
	arr[10][1] = 3000;
	arr[11][1] = 1500;
	arr[12][1] = 1500;
	arr[13][1] = 1500;
	arr[14][1] = 2500;
	for(int i=0; i<15; i++)
			(arr)[i][0] = 0;

}

/*********************************************************************
** Function: get_players
** Description: Ask for num of players
** Parameters: Players pointer
** Pre-Conditions: None
** Post-Conditions: Return players
*********************************************************************/ 
void get_players(int* players){
	cout << "How many players? " << endl;;
	*players = get_real_num();
}

/*********************************************************************
** Function: init_scores
** Description: Start array for scoring
** Parameters: Players
** Pre-Conditions: None
** Post-Conditions: Return array
*********************************************************************/ 
int** init_scores(int players){
	int ** scoreboard;
	scoreboard = new int*[players];
	for(int i=0; i<players; i++){
		scoreboard[i] = new int[0];
	}

	scoreboard = populate_zeros(scoreboard, players);
	return scoreboard;
}

/*********************************************************************
** Function: init_dices
** Description: Start dices for scoring
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return array
*********************************************************************/ 
int* init_dices(){
	int *diceboard = new int[6];
	for(int i=0; i!=6; i++){
		diceboard[i] = -1;
	}
	return diceboard;
}

/*********************************************************************
** Function: continue_rolling
** Description: Keep rolling check
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: true/false
*********************************************************************/ 
bool continue_rolling(){
	int contin = -1;
	cout << "Keep Rolling? 1 for Yes, 2 for No." << endl;
	contin = get_real_num();
	if(contin == 1){
		return true;
	}
	if(contin == 2){
		return false;
	}
}

/*********************************************************************
** Function: reset_diceroll
** Description: set dices to -1
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: return array
*********************************************************************/ 
int* reset_diceroll(int* diceboard){
	for(int i=0; i!=6; i++){
		diceboard[i] = -1;
	}
	return diceboard;
}

/*********************************************************************
** Function: add_points
** Description: add points to player if no farkle
** Parameters: scoreboard, score from round, farkle boolean, turn number
** Pre-Conditions: farkle is not true
** Post-Conditions: return array
*********************************************************************/ 
int** add_points(int** scoreboard, int* temp_score, bool farkle, int turn){
	if(farkle == false){
		cout << "Turn ended without Farkle, adding: " << *temp_score << endl;
		scoreboard[turn][0] += *(temp_score);
		*temp_score = 0;
	}
	return scoreboard;	
}

/*********************************************************************
** Function: end_turn
** Description: ends turn and resets diceboard
** Parameters: scoreboard, score from round, farkle boolean, turn number
** Pre-Conditions: None
** Post-Conditions: return array
*********************************************************************/ 
int* end_turn(int* turn, int players, int* diceboard){
	//Turn ends
	int random = 0;
	cout << endl;
	cout << "Enter any number for Next Turn. " << endl;
	random = get_real_num();
	for(int i=0; i < 3; i++)
		cout << endl;
	(*turn)++;
		
	//Resetting dices
	diceboard = reset_diceroll(diceboard);
	if(*turn == players)
	*turn = 0;
	return diceboard;
}

/*********************************************************************
** Function: rolling_short
** Description: Determines if player can continue rolling
** Parameters: score, rolling pointer, partial roll boolean, full roll boolean, dices
** Pre-Conditions: Dices are rolled, no farkle
** Post-Conditions: return array
*********************************************************************/ 
int* rolling_short(int temp_score, bool* rolling, bool partial_roll, bool full_reroll, int* diceboard){
	bool continue_roll = false;
	continue_roll = continue_rolling();
	if((full_reroll == true) && (continue_roll == true)){ //If no dices are left
		diceboard = reset_diceroll(diceboard);
	}
	if((partial_roll == true) && (continue_roll == true)){ //If there are dices left
		*rolling = true;
	}
	if((continue_roll == false) && (temp_score >= 500)){ //user wants to stop rolling and has not farkled, give points
		*rolling = false;
	}
	if((continue_roll == false) && (temp_score < 500)){
		cout << "You have not reached 500, continue rolling." << endl;
		*rolling = true;
	}
	return diceboard;
}

/*********************************************************************
** Function: win_checker
** Description: Determines if player has won
** Parameters: scorse, player amount
** Pre-Conditions: none
** Post-Conditions: boolean true/false
*********************************************************************/ 
bool win_checker(int** scoreboard, int players){
	cout << "Players: " << players << endl;
	for(int i=0; i < players; i++){
		if(scoreboard[i][0] >= 10000){
			cout << "Player has hit 10,000 points, last round will begin now." << endl;
			return true;
		}
	}
	return false;
}

/*********************************************************************
** Function: win_checker
** Description: Determines which player has won
** Parameters: scorse, player amount
** Pre-Conditions: player has over 10,000 points
** Post-Conditions: print player winner
*********************************************************************/ 
void highest_score(int** scoreboard, int players){
	int highest_score = 0;
	int winner = -1;
	for(int i=0; i < players; i++){
		if(scoreboard[i][0] > highest_score){
			highest_score = scoreboard[i][0];
			winner = i+1;
		}
	}
	cout << "The winner is Player " << winner << endl;
}

/*********************************************************************
** Function: delete_arrays
** Description: Frees arrays from heap
** Parameters: scoreboard, diceboard, player amount
** Pre-Conditions: player has won
** Post-Conditions: memory leaks stopped
*********************************************************************/ 
void delete_arrays(int** scoreboard, int* diceboard, int players){
	for(int i=0; i<players; i++)
		delete [] scoreboard[i];
	delete [] scoreboard;
	scoreboard = NULL;
	delete [] diceboard;
	diceboard = NULL;
}

/*********************************************************************
** Function: win_check1
** Description: Shorten main
** Parameters: win_check, win, final_turn, turn
** Pre-Conditions: none
** Post-Conditions: someone has won
*********************************************************************/ 
bool win_check1(int win, int final_turn, int turn, int** scoreboard, int players, int* diceboard){
	if((win > 1) && (turn == final_turn)){
			cout << "Game Over " << endl;
			highest_score(scoreboard, players);
			delete_arrays(scoreboard, diceboard, players);
			return true;
		}
	else{
		return false;
	}
}

/*********************************************************************
** Function: win_check2
** Description: Shorten main
** Parameters: win_check, win, final_turn, turn
** Pre-Conditions: none
** Post-Conditions: someone is going to win
*********************************************************************/ 
void win_check2(bool win_check, int* win, int* final_turn, int turn){
	if(win_check == true){
		(*win)++;
		if(*win == 1){
			*final_turn += (turn);
		}
	}
}

/*********************************************************************
** Function: main
** Description: Runs Farkle game in order
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: someone has won
*********************************************************************/ 
int main(){
	int** scoreboard; 
	int arr[15][2], players = 2, turn = 0, temp_score = 0, final_turn = 0, win = 0;
	int* diceboard; 
	bool winner = false, win_check = false;
	//Start game
	get_players(&players);
	scoreboard = init_scores(players);
	diceboard = init_dices();
	init_dicepoints_board(arr);
	scoreboard[0][0] += 10000;
	while(winner == false){
		bool full_reroll = false, partial_roll = false, rolling = true, continue_roll = false, farkle = false;	
		print_dyn(scoreboard, players, turn);
		//Win checker
		winner = win_check1(win, final_turn, turn, scoreboard, players, diceboard);
		if(winner == true){
			return 0;
		}
		while(rolling == true){
			diceboard = dice_roll(arr, diceboard);
			temp_score += combo_keeper(arr, diceboard, turn, &farkle);
			cout << "Score for this round is: " << temp_score << endl;
			cout << endl;
			full_reroll = reroll_diceboard(diceboard);
			partial_roll = partial_reroll_diceboard(diceboard);
			if(farkle == true){
				cout << "Farkle! Next turn." << endl;
				temp_score = 0;
				break;}
			if(full_reroll == true || partial_roll == true){
				diceboard = rolling_short(temp_score, &rolling, partial_roll, full_reroll, diceboard);}
		}
		//Add points
		scoreboard = add_points(scoreboard, &temp_score, farkle, turn);
		//Turn ends
		win_check = win_checker(scoreboard, players);
		win_check2(win_check, &win, &final_turn, turn);
		diceboard = end_turn(&turn, players, diceboard);

	}
}



