/*********************************************************************
** Program Filename: ass8.cpp
** Author: Rogers Dong
** Date: 3/18/2018
** Description: Checkers game, with board sizes 8, 10, and 12
** Input: Coordinates in the form row,col
** Output: Checker board and pieces
*********************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;


/*********************************************************************
** Function: is_int
** Description: Checks a string input for valid int characteristics
** Parameters: string
** Pre-Conditions: get_real_num is called 
** Post-Conditions: bool
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
** Description: Turns a string of numbers into an int
** Parameters: string
** Pre-Conditions:  is_int is true
** Post-Conditions: integer
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
** Description: Asks user for a number input, turns it from string to int
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: integer returned
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
** Function: print_board
** Description: Prints the board with color and pieces in the board
** Parameters: board, rows, cols
** Pre-Conditions: Board is initialized
** Post-Conditions: Board printed
*********************************************************************/ 

void print_board(char** board, int rows, int col){
	cout << "   ";
	for(int i=0; i<rows; i++)
		cout << i << "   ";
	cout << endl;
	for(int i=0; i<rows; i++){
		if(rows == 12){
			if(i < 10)
			cout << i << " ";
			else
			cout << i;
		}
		else
			cout << i;
		for(int j=0; j<col; j++) {
			if (i%2 == 0 && j%2 == 0)
				cout << "|\033[30;47m " << board[i][j] << " ";
			else if (i%2 == 1 && j%2 == 1)
				cout << "|\033[30;47m " << board[i][j] << " ";
			else
				cout << "|\033[0m " << board[i][j] << " ";
				cout << "\033[0m";
		}
	cout << endl;
	}
}

/*********************************************************************
** Function: which_player
** Description: Returns the player who is going
** Parameters: turn
** Pre-Conditions: Game is running
** Post-Conditions: character X or O
*********************************************************************/ 

char which_player(int turn){
	if(turn == 0){
		return 'O';
	}
	if(turn == 1){
		return 'X';
	}
}

/*********************************************************************
** Function: piece_exists
** Description: Checks if the user input has a piece in the board
** Parameters: board, row, col, turn
** Pre-Conditions: User inputted row and col
** Post-Conditions: true or false
*********************************************************************/ 

bool piece_exists(char** board, int row, int col, int turn){
	char player = which_player(turn);
	if(board[row][col] == player || board[row][col] == 'x' || board[row][col] == 'o'){
		return true;
	}
	else{
		return false;
	}
}

/*********************************************************************
** Function: any_moves_o
** Description: Checks if O pieces have any moves left
** Parameters: board, turn, boardsize
** Pre-Conditions: O has moved 
** Post-Conditions: True/False
*********************************************************************/ 

bool any_moves_o(char** board, int turn, int boardsize){
	for(int i=0; i<boardsize; i++){
		for(int j=0; j<boardsize; j++){
			if(board[i][j] == 'O'){
				if(j == 0){
					if(board[i+1][j+1] == ' ')
						return true;
				}
				else if(j == boardsize-1){
					if(board[i+1][j-1] == ' ')
						return true;
				}
				else{
					if((board[i+1][j-1] == ' ') || (board[i+1][j+1] == ' '))
						return true;
				}
			}
		}
	}
	return false;

}

/*********************************************************************
** Function: any_moves_x
** Description: Checks if X pieces have any moves left
** Parameters: board, turn, boardsize
** Pre-Conditions: X has moved
** Post-Conditions: True/False
*********************************************************************/ 

bool any_moves_x(char** board, int turn, int boardsize){
	for(int i=0; i<boardsize; i++){
		for(int j=0; j<boardsize; j++){
			if(board[i][j] == 'X'){
				if(j == 0){
					if(board[i-1][j+1] == ' '){
						return true;
					}
				}
				else if(j == boardsize-1){
					if(board[i-1][j-1] == ' ')
						return true;
				}
				else{
					if((board[i-1][j-1] == ' ') || (board[i-1][j+1] == ' ')){
						return true;

					}
				}
			}
		}
	}
	return false;
}

/*********************************************************************
** Function: any_pieces_left
** Description: Checks if a player has pieces left
** Parameters: board, turn, boardsize
** Pre-Conditions: Turn ended
** Post-Conditions: True/False
*********************************************************************/

bool any_pieces_left(char** board, int turn, int boardsize){
	int countx = 0, counto = 0;
	for(int i=0; i<boardsize; i++){
		for(int j=0; j<boardsize; j++){
			if((board[i][j] == 'X') || (board[i][j] == 'x'))
				countx++;
			if((board[i][j] == 'O') || (board[i][j] == 'o'))
				counto++;
		}
	}
	if(countx == 0){
		cout << "Player X has lost, no more pieces." << endl;
		cout << countx << endl;
		return false;
	}
	if(counto == 0){
		cout << "Player O has lost, no more pieces." << endl;
		return false;
	}
	return true;
}

/*********************************************************************
** Function: opposite_both
** Description: Used to check if condition is true for multiple pieces
** Parameters: turn, iterate (for loop i)
** Pre-Conditions: Checking for some condition for two pieces
** Post-Conditions: Character 
*********************************************************************/

char opposite_both(int turn, int iterate){
	if((turn == 0) && (iterate == 0))
		return 'X';
	if((turn == 0) && (iterate == 1))
		return 'x';
	if((turn == 1) && (iterate == 0))
		return 'O';
	if((turn == 1) && (iterate == 1))
		return 'o';
}

/*********************************************************************
** Function: return_kings
** Description: Used  to check if condition is true for piece and kinged piece
** Parameters: turn
** Pre-Conditions: Conditon is being checked
** Post-Conditions: Chars o or x is returned
*********************************************************************/

char return_kings(int turn){
	if(turn == 0)
		return 'o';
	if(turn == 1)
		return 'x';
}

/*********************************************************************
** Function: any_moves_kings
** Description: Checks if the king pieces have any moves left (depending on turn)
** Parameters: board, turn, boardsize
** Pre-Conditions: User has a king
** Post-Conditions: True/False
*********************************************************************/

bool any_moves_kings(char** board, int turn, int boardsize){
	for(int i=0; i<boardsize; i++){
		for(int j=0; j<boardsize; j++){
			if(board[i][j] == return_kings(turn)){
				if((i == 0) && (j != boardsize-1)){ //top row
					if((board[i+1][j+1] == ' ') || (board[i+1][j-1] == ' '))
						return true;
				}
				if((i == 0) && (j == boardsize-1)){ //top right
					if(board[i+1][j-1] == ' ')
						return true;
				}
				if((j == 0) && (i == boardsize-1)){ //bot left
					if(board[i-1][j+1] == ' ')
						return true;
				}
				if((j != boardsize-1) && (i == boardsize-1)){ //bot row
					if((board[i-1][j-1] == ' ') || (board[i-1][j+1] == ' '))
						return true;
				}
				if((board[i+1][j-1] == ' ') || (board[i+1][j+1] == ' ')){ //elsewhere
					if((board[i-1][j-1] == ' ') || (board[i-1][j+1] == ' ') || (board[i+1][j+1] == ' ') || (board[i+1][j-1] == ' '))
					return true;
				}
			}
		}
	}
	return false;
}

/*********************************************************************
** Function: moves_available
** Description: Checks all pieces of whos going to see if they have valid moves left
** Parameters: board, turn, boardsize
** Pre-Conditions: User has moved 
** Post-Conditions: True/False
*********************************************************************/

bool moves_available(char** board, int turn, int boardsize){
	if(turn == 0){
		if(any_moves_o(board, turn, boardsize) == true)
			return true;	
	}
	if(turn == 1){
		if(any_moves_x(board, turn, boardsize) == true)
			return true;	
	}
	if(turn == 0){
		if(any_moves_kings(board, turn, boardsize) == true)
			return true;
	}
	if(turn == 1){
		if(any_moves_kings(board, turn, boardsize) == true)
			return true;	
	}
	cout << "Player " << which_player(turn) << " has run out of moves. Game Over. " << endl;
	return false;	
}

/*********************************************************************
** Function: moves_check
** Description: Checks if a regular O or X piece has inputted a valid move
** Parameters: board, row input, col input, where row, where col, turn
** Pre-Conditions: User has inputted a location to move and where piece is
** Post-Conditions: True/False
*********************************************************************/

bool moves_check(char** board, int row_input, int col_input, int whr_row, int whr_col, int turn){ //without hop 
	if(piece_exists(board, whr_row, whr_col, turn) == true){
		if(turn == 0){ //white pieces
			if((board[whr_row+1][whr_col+1] == ' ') || (board[whr_row+1][whr_col-1] == ' ')){
				if((board[row_input][col_input] == ' ') && ((row_input == whr_row+1))){
					return true;
				}
			}
		}
	
		else if(turn == 1){ //red pieces 
			if((board[whr_row-1][whr_col+1] == ' ') || (board[whr_row-1][whr_col-1] == ' ')){
				if((board[row_input][col_input] == ' ') && ((row_input == whr_row-1))){
					return true;
				}
			}
		}
	}
	return false;
}  

/*********************************************************************
** Function: king_moves_check
** Description: Checks if the king piece can move, if user input is valid
** Parameters: board, row input, col input, where row, whr col, turn
** Pre-Conditions: User has a king and is moving the king
** Post-Conditions: True/False
*********************************************************************/

bool king_moves_check(char** board, int row_input, int col_input, int whr_row, int whr_col, int turn){ //without hop just check
	if((turn == 0) && (board[whr_row][whr_col] == 'o')){
		if(board[row_input][col_input] == ' '){
			if((row_input == whr_row+1) || (row_input == whr_row-1)){
				return true;
			}
		}
	}
	if((turn == 1) && (board[whr_row][whr_col] == 'x')){
		if(board[row_input][col_input] == ' '){
			if((row_input == whr_row+1) || (row_input == whr_row-1)){
				return true;
			}
		}
	}
	return false;
}

/*********************************************************************
** Function: opposite_piece
** Description: Checks opposite pieces depending on turn, including kings
** Parameters: turn
** Pre-Conditions: Checking for some condition involving other piece (hops)
** Post-Conditions: Char returned
*********************************************************************/

char opposite_piece(int turn){
	if(turn == 0)
		return 'X';
	if(turn == 1)
		return 'x';
}

/*********************************************************************
** Function: check_both
** Description: Checks opposite pieces depending on turn, including kings
** Parameters: turn
** Pre-Conditions: Checking for some condition involving other piece (hops)
** Post-Conditions: Char returned
*********************************************************************/

char check_both(int turn){
	if(turn == 0)
		return 'O';
	if(turn == 1)
		return 'o';
}

/*********************************************************************
** Function: hop_check
** Description: Checks if a hop from a O or X piece is valid
** Parameters: board, row input, col input, where row, where col, turn
** Pre-Conditions: User entered a 2 space diagonal move
** Post-Conditions: True/False
*********************************************************************/

bool hop_check(char** board, int row_input, int col_input, int whr_row, int whr_col, int turn){ //return true if user is hopping and hop is valid 
	if(piece_exists(board, whr_row, whr_col, turn) == true){
		if(turn == 0){ //white pieces
			if((board[row_input][col_input] == ' ') && ((row_input == whr_row+2))){ //if spot they want is empty and is only two spaces diagonal
				for(int i=0; i<2; i++){
					if((board[row_input-1][col_input+1] == opposite_piece(i)) || (board[row_input-1][col_input-1] == opposite_piece(i))){ 
						return true;
					}
				}
			}
			else{
				return false;
			}
		}

		if(turn == 1){ //red pieces
			if(board[row_input][col_input] == ' '){
				if((row_input == whr_row-2)){
					for(int i=0; i<2; i++){
						if((board[row_input+1][col_input+1] == check_both(i)) || (board[row_input+1][col_input-1] == check_both(i))){
							return true;
						}
					}
				}
			}
			else{
				return false;
			}
		}
	}
	
	return false;
}	 

/*********************************************************************
** Function: hop_check_king
** Description: Checks if a hop from a x or o piece is valid
** Parameters: board, row input, col input, where row, where col, turn
** Pre-Conditions: User entered a 2 space diagonal move with a king piece
** Post-Conditions: True/False
*********************************************************************/

bool hop_check_king(char** board, int row_input, int col_input, int whr_row, int whr_col, int turn){ //return true if user is hopping and hop is valid
	char opposite;
	for(int i=0; i<2; i++){
		if((board[row_input+1][col_input-1] == opposite_both(turn, i)) || (board[row_input+1][col_input+1] == opposite_both(turn, i))){ //log, depends on the direction. this line only checks up hops
			if(board[row_input][col_input] == ' '){
				return true;
			}
		}
		if((board[row_input-1][col_input+1] == opposite_both(turn, i)) || (board[row_input-1][col_input-1] == opposite_both(turn, i))){ //log, depends on the direction. this line only checks up hops
			if(board[row_input][col_input] == ' '){
				return true;
			}
		}	
	}
	return false;
}

/*********************************************************************
** Function: hop_available_general
** Description: Checks if a user can hop again after hopping once
** Parameters: board, row input, col input, where row, where col, turn
** Pre-Conditions: User hopped once, piece is around middle of board
** Post-Conditions: True/False
*********************************************************************/

bool hops_available_general(char** board, int turn, int boardsize, int whr_row, int whr_col){ //if piece can hop to the right diagonally
	if((whr_col >= 2) && (whr_col <= (boardsize-2)) && (whr_row >= 2) && (whr_row <= (boardsize-3))){ //starting at top left
		for(int i=0; i<2; i++){
			if(board[whr_row][whr_col] != 'O'){
				if(board[whr_row-1][whr_col-1] == opposite_both(turn, i)){
					if(board[whr_row-2][whr_col-2] == ' '){ //Log, not working correctly.
						return true;
					}
				}
				if((board[whr_row-1][whr_col+1] == opposite_both(turn, i)) && (whr_col >= 1)){
					if(board[whr_row-2][whr_col+2] == ' ')
						return true;
				}
			}
			if(board[whr_row][whr_col] != 'X'){
				if(board[whr_row+1][whr_col-1] == opposite_both(turn, i)){
					if(board[whr_row+2][whr_col-2] == ' ')
						return true;
				}
				if((board[whr_row+1][whr_col+1] == opposite_both(turn, i)) && (whr_col <= 5)){
					if(board[whr_row+2][whr_col+2] == ' ')
						return true;
				}
			}
		}
	}
	return false;
}

/*********************************************************************
** Function: hop_available_right
** Description: Checks if a user can hop again after hopping once
** Parameters: board, row input, col input, where row, where col, turn
** Pre-Conditions: User hopped once, piece is on left edge 
** Post-Conditions: True/False
*********************************************************************/

bool hops_available_right(char** board, int turn, int boardsize, int whr_row, int whr_col){ //if piece can hop to the right diagonally
	if(whr_col == 0){ //starting at top left
		if((whr_row == 1) && (board[whr_row][whr_col] != 'X')){ //special case
			for(int i=0; i<2; i++){
				if(board[whr_row+1][whr_col+1] == opposite_both(turn, i)){
					if(board[whr_row+2][whr_col+2] == ' ')
						return true;
				}
			}
		}
		else if((whr_row == boardsize-1) && (board[whr_row][whr_col] != 'O')){ //special case
			for(int i=0; i<2; i++){
				if(board[whr_row-1][whr_col+1] == opposite_both(turn, i)){
					if(board[whr_row+2][whr_col+2] == ' ')
						return true;
				}
			}
		}
		else if((whr_row >= 3) && (whr_row <= boardsize-3)){ //wont seg fault
			for(int i=0; i<2; i++){
				if((board[whr_row+1][whr_col+1] == opposite_both(turn, i)) && (board[whr_row+2][whr_col+2] == ' '))
						return true;
				if((board[whr_row-1][whr_col+1] == opposite_both(turn, i)) && (board[whr_row-2][whr_col+2] == ' '))
						return true;
			}
		}
	}
	return false;
}

/*********************************************************************
** Function: hop_available_left
** Description: Checks if a user can hop again after hopping once
** Parameters: board, row input, col input, where row, where col, turn
** Pre-Conditions: User hopped once, piece is on right edge 
** Post-Conditions: True/False
*********************************************************************/

bool hops_available_left(char** board, int turn, int boardsize, int whr_row, int whr_col){ //if piece can hop to the right diagonally
	if(whr_col == boardsize-1){ //starting at top left
		if((whr_row == 0) && (board[whr_row][whr_col] != 'X')){ //special case
			for(int i=0; i<2; i++){
				if(board[whr_row+1][whr_col-1] == opposite_both(turn, i)){
					if(board[whr_row+2][whr_col-2] == ' ')
						return true;
				}
			}
		}
		else if((whr_row == boardsize-2) && (board[whr_row][whr_col] != 'O')){ //special case
			for(int i=0; i<2; i++){
				if(board[whr_row-1][whr_col-1] == opposite_both(turn, i)){
					if(board[whr_row-2][whr_col-2] == ' ')
						return true;
				}
			}
		}
		else if((whr_row >= 2) && (whr_row <= boardsize-3)){ //wont seg fault
			for(int i=0; i<2; i++){
				if((board[whr_row+1][whr_col-1] == opposite_both(turn, i)) && (board[whr_row+2][whr_col-2] == ' '))
						return true;
				if((board[whr_row-1][whr_col-1] == opposite_both(turn, i)) && (board[whr_row-2][whr_col-2] == ' '))
						return true;
			}
		}
	}
	return false;
}

/*********************************************************************
** Function: hop_available_topbot
** Description: Checks if a user can hop again after hopping once
** Parameters: board, row input, col input, where row, where col, turn
** Pre-Conditions: User hopped once, piece is on top row
** Post-Conditions: True/False
*********************************************************************/

bool hops_available_topbot(char** board, int turn, int boardsize, int whr_row, int whr_col){ //if piece can hop to the right diagonally
	if(whr_row == 0){ //starting at top left
		if((whr_col == 1) && (board[whr_row][whr_col] != 'X')){ //special case
			for(int i=0; i<2; i++){
				if(board[whr_row+1][whr_col+1] == opposite_both(turn, i)){
					if(board[whr_row+2][whr_col+2] == ' ')
						return true;
				}
			}
		}
		else if((whr_col == boardsize-1) && (board[whr_row][whr_col] != 'X')){ //special case
			for(int i=0; i<2; i++){
				if(board[whr_row+1][whr_col-1] == opposite_both(turn, i)){
					if(board[whr_row+2][whr_col-2] == ' ')
						return true;
				}
			}
		}
		else if((whr_col >= 3) && (whr_col <= boardsize-3)){ //wont seg fault
			for(int i=0; i<2; i++){
				if((board[whr_row+1][whr_col-1] == opposite_both(turn, i)) && (board[whr_row+2][whr_col-2] == ' '))
						return true;
				if((board[whr_row+1][whr_col+1] == opposite_both(turn, i)) && (board[whr_row+2][whr_col+2] == ' '))
						return true;
			}
		}
	}
	return false;
}

/*********************************************************************
** Function: hop_available_right
** Description: Checks if a user can hop again after hopping once
** Parameters: board, row input, col input, where row, where col, turn
** Pre-Conditions: User hopped once, piece is bottom row 
** Post-Conditions: True/False
*********************************************************************/

bool hops_available_bottop(char** board, int turn, int boardsize, int whr_row, int whr_col){ //if piece can hop to the right diagonally
	if(whr_row == boardsize-1){ //starting at top left
		if((whr_col == 0) && (board[whr_row][whr_col] != 'O')){ //special case
			for(int i=0; i<2; i++){
				if(board[whr_row-1][whr_col+1] == opposite_both(turn, i)){
					if(board[whr_row-2][whr_col+2] == ' ')
						return true;
				}
			}
		}
		else if((whr_col == boardsize-2) && (board[whr_row][whr_col] != 'O')){ //special case
			for(int i=0; i<2; i++){
				if(board[whr_row-1][whr_col-1] == opposite_both(turn, i)){
					if(board[whr_row-2][whr_col-2] == ' ')
						return true;
				}
			}
		}
		else if((whr_col >= 2) && (whr_col <= boardsize-4)){ //wont seg fault
			for(int i=0; i<2; i++){
				if((board[whr_row+1][whr_col-1] == opposite_both(turn, i)) && (board[whr_row+2][whr_col-2] == ' '))
						return true;
				if((board[whr_row+1][whr_col+1] == opposite_both(turn, i)) && (board[whr_row+2][whr_col+2] == ' '))
						return true;
			}
		}
	}
	return false;
}

/*********************************************************************
** Function: all_hop_check
** Description: Checks if a piece can hop again after hopping once
** Parameters: board, turn, boardsize, where row, where col
** Pre-Conditions: Piece has hopped once
** Post-Conditions: True/False
*********************************************************************/

bool all_hop_check(char** board, int turn, int boardsize, int whr_row, int whr_col){
	if(hops_available_general(board, turn, boardsize, whr_row, whr_col) == true)
		return true;	
	if(hops_available_left(board, turn, boardsize, whr_row, whr_col) == true)
		return true;	
	if(hops_available_right(board, turn, boardsize, whr_row, whr_col) == true)
		return true;
	if(hops_available_topbot(board, turn, boardsize, whr_row, whr_col) == true)
		return true;
	if(hops_available_bottop(board, turn, boardsize, whr_row, whr_col) == true)
		return true;
}

/*********************************************************************
** Function: hop
** Description: Performs the hopping of pieces
** Parameters: board, row input, col input, where row, where col, turn, score
** Pre-Conditions: Hop checks are true
** Post-Conditions: Score is added, pieces are moved
*********************************************************************/

void hop(char** board, int row_input, int col_input, int whr_row, int whr_col, int turn, int score[]){ //which piece got hopped
	if((whr_row+2 == row_input) && (whr_col+2 == col_input)){ //Top pieces bottom right, test --
		board[row_input][col_input] = board[whr_row][whr_col];
		board[whr_row][whr_col] = ' ';
		board[whr_row+1][whr_col+1] = ' '; 
		score++;
	}
	if((whr_row+2 == row_input) && (whr_col-2 == col_input)){ //Top pieces bottom left, `
		board[row_input][col_input] = board[whr_row][whr_col];
		board[whr_row][whr_col] = ' ';
		board[whr_row+1][whr_col-1] = ' ';
		score++;
	}

}

/*********************************************************************
** Function: hop2
** Description: Performs the hopping of pieces
** Parameters: board, row input, col input, where row, where col, turn, score
** Pre-Conditions: Hop checks are true
** Post-Conditions: Score is added, pieces are moved
*********************************************************************/

void hop2(char** board, int row_input, int col_input, int whr_row, int whr_col, int turn, int score[]){ //which piece got hopped
	if((whr_row-2 == row_input) && (whr_col+2 == col_input)){ //Bot pieces top right, test++
		board[row_input][col_input] = board[whr_row][whr_col];
		board[whr_row][whr_col] = ' ';
		board[whr_row-1][whr_col+1] = ' ';
		score++;
	}
	if((whr_row-2 == row_input) && (whr_col-2 == col_input)){ //Bot pieces top left
		board[row_input][col_input] = board[whr_row][whr_col];
		board[whr_row][whr_col] = ' ';
		board[whr_row-1][whr_col-1] = ' ';
		score++;
	}
}

/*********************************************************************
** Function: move_piece
** Description: Performs the moving of pieces
** Parameters: board, row input, col input, where row, where col, turn, boardsize
** Pre-Conditions: User input is valid for where to go
** Post-Conditions: Piece is moved one space
*********************************************************************/

void move_piece(char** board, int row_input, int col_input, int whr_row, int whr_col, int turn, int boardsize){
	board[row_input][col_input] = board[whr_row][whr_col];
	board[whr_row][whr_col] = ' ';
}

/*********************************************************************
** Function: check_kings
** Description: Checks if a piece should be Kinged
** Parameters: board, boardsize
** Pre-Conditions: Piece reaches the other side
** Post-Conditions: Piece is turned from O to o or X to x
*********************************************************************/

void check_kings(char** board, int boardsize){ //converts kings
	for(int i=0; i<boardsize; i++){
		if(board[0][i] == 'X'){
			board[0][i] = 'x';
		}
		if(board[boardsize-1][i] == 'O'){
			board[boardsize-1][i] = 'o';
		}
	}
}

/*********************************************************************
** Function: check_command
** Description: Checks command line arguement for validity
** Parameters: argc, argv, rows, cols, boardsize
** Pre-Conditions: Command Line Arg is given
** Post-Conditions: Boardsize is returned, true/false returned
*********************************************************************/

bool check_command(int arg_num, char** args, int& rows, int& cols, int& boardsize){
	int i=0;
	if(args[i+1][0] == '-' && args[i+1][1] == 's'){
		if((strlen(args[i+2]) > 2) || (arg_num <= 2)){
			return false;
		}
		if((strlen(args[i+2]) == 1 && args[i+2][0] == '8')){
			rows = atoi(args[i+2]);
			boardsize = rows;
			cols = rows;
			return true;
		}
		if(strlen(args[i+2]) == 2){
			if((args[i+2][0] == '1' && args[i+2][1] == '0') || (args[i+2][0] == '1' && args[i+2][1] == '2')){
				rows = atoi(args[i+2]);
				boardsize = rows;
				cols = rows;
				return true;
			}
		}

	}
	else{
		return false;
	}	
	
}

/*********************************************************************
** Function: middle_rows
** Description: Formula to find where middle rows of board should be empty
** Parameters: lim1, lim2, boardsize
** Pre-Conditions: Boardsize is entered
** Post-Conditions: Empty rows are returned
*********************************************************************/

void middle_rows(int& lim1, int& lim2, int boardsize){
	lim1 = boardsize/2;
	lim2 = (boardsize/2)-1;
}

/*********************************************************************
** Function: populate_zeros
** Description: Populates board with empty spaces and pieces
** Parameters: board, rows, cols, boardsize
** Pre-Conditions: Empty rows found, boardsize entered
** Post-Conditions: Board is filled and returned
*********************************************************************/

char** populate_zeros(char** board, int rows, int cols, int boardsize){
	int lim1 = 0, lim2 = 0;
	middle_rows(lim1, lim2, boardsize);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if((((j%2 == 1) && (i%2 == 0)) && (i < lim2)) || (((j%2 == 0) && (i%2 == 1)) && (i<lim2)))
				board[i][j] = 'O';
			else
				board[i][j] = ' ';
			if(((j%2 == 1) && (i%2 == 0)) && (i >= lim2))
				board[i][j] = ' ';
			if(((j%2 == 1) && (i%2 == 0)) && (i > lim1))
				board[i][j] = 'X';
			if(((j%2 == 0) && (i%2 == 1)) && (i > lim1))
		//		board[i][j] = 'X';
			if((j%2 == 1) && (i%2 == 1)) //every even row and odd column gets a space	
				board[i][j] = ' ';
		}	

	}

	return board;
}

/*********************************************************************
** Function: init_board
** Description: Initializes a 2D Dynamic Board
** Parameters: rows, cols, boardsize
** Pre-Conditions: Command Line Arg given or Boardsize given
** Post-Conditions: Board is init and returned.
*********************************************************************/

char** init_board(int rows, int cols, int boardsize){
	char** board;
	board = new char*[rows];
	for(int i=0; i<rows; i++){
		board[i] = new char[cols];
	}

	board = populate_zeros(board, rows, cols, boardsize);

	return board;
}

/*********************************************************************
** Function: comma_find_coord
** Description: Finds the comma in the user input for coordinate
** Parameters: input
** Pre-Conditions: User inputs something
** Post-Conditions: True/False
*********************************************************************/

bool comma_find_coord(char* input){
	for(int i=0; i<strlen(input); i++){
		if(input[i] >= 'A' && input[i] <= 'z')
			return false;
	}

	for(int i=0; i<strlen(input); i++){
		if(input[i] == ','){
			return true;
		}
	}
	return false;
}

/*********************************************************************
** Function: your_piece
** Description: Returns both possible pieces you may hold, kinged and unkinged
** Parameters: turn, iterate
** Pre-Conditions: Checking some condition
** Post-Conditions: character returned
*********************************************************************/

char your_piece(int turn, int iterate){
	if((turn == 0) && (iterate == 0))
		return 'O';
	if((turn == 0) && (iterate == 1))
		return 'o';
	if((turn == 1) && (iterate == 0))
		return 'X';
	if((turn == 1) && (iterate == 1))
		return 'x';
}

/*********************************************************************
** Function: correct_piece
** Description: Checks if you selected your own piece or not
** Parameters: board, row input, col input, turn
** Pre-Conditions: Input coordinate entered
** Post-Conditions: True/False/Print statement
*********************************************************************/

bool correct_piece(char** board, int row_inp, int col_inp, int turn){
	int count = 0;
	for(int i=0; i<2; i++){
		if(board[row_inp][col_inp] == your_piece(turn, i)){
			count++;
		}
	}
	if(count == 0){
		cout << "You did not select your piece, try again." << endl;
		return false;
	}
	if(count > 0){
		return true;
	}
}

/*********************************************************************
** Function: check_coord
** Description: Checks user coordinate for inbounds, nonnunmbers, noncommas, existence
** Parameters: board, turn, input, boardsize, rows, cols
** Pre-Conditions: User coordinate input entered
** Post-Conditions: True/False/Print statement
*********************************************************************/

bool check_coord(char** board, int turn, char* input, int boardsize, int rows, int cols){
	int limit = boardsize;
	if(comma_find_coord(input) == true){
		if((rows <= limit) && (rows >= 0)){
			if(cols <= limit && cols >= 0){
				return true;
			}
		}
		else{
			cout << "Input out of bounds" << endl;
			return false;
		}
	}
	else{
		cout << "No comma in input or non-numbers entered" << endl;
		return false;
	}
}


/*********************************************************************
** Function: check_coord_whites
** Description: Checks if user is trying to move into a white space.
** Parameters: where row, where col, row input, col input
** Pre-Conditions: User has entered where their piece is and where to go
** Post-Conditions: True/False/Print statement
*********************************************************************/

bool check_coord_whites(int whr_row, int whr_col, int row_input, int col_input){
	if((row_input % 2 == 0) && (col_input % 2 == 0)){
		cout << "Invalid move, cant move into white" << endl;
		return false;
	}
	if((row_input  % 2 == 1) && (col_input % 2 == 1)){
		cout << "Invalid move, cant move into white" << endl;
		return false;
	}
	if(((row_input - whr_row) == 0) || ((col_input - whr_col) == 0)){
		cout << "Invalid Row" << endl;
		return false;
	}
	return true;
}

/*********************************************************************
** Function: input_seperate
** Description: Takes in a c-style string, seperates it into int row and int col
** Parameters: board, turn, row input, col input, boardsize
** Pre-Conditions: Game has started
** Post-Conditions: Cstyle string is turned to two seperate readable integers
*********************************************************************/

void input_seperate(char** board, int turn, int& row_inp, int& col_inp, int boardsize){
	bool valid_coord = true;
	do{
		char row[250] = {'0','\0'}, col[250] = {'0','\0'}, input[250] = {'0'};
		cin.getline(input,250);
		
	if(input[1] == ','){
		row[0] = input[0];
		col[0] = input[2];
		if(input[3] > char(47) && input[3] < char(58))
			col[1] = input[3];
	}
	if(input[2] == ','){
		row[0] = input[0];
		row[1] = input[1];
		col[0] = input[3];
		if(input[4] > char(47) && input[4] < char(58))
			col[1] = input[4];
	}
	
	row_inp = atoi(row);
	col_inp = atoi(col);
	valid_coord = check_coord(board, turn, input, boardsize, row_inp, col_inp);
	}while(valid_coord == false);
}

/*********************************************************************
** Function: king_printer
** Description: When dealing with kinged pieces, program goes here to check
** Parameters: board, row input, col input, where row, where col, turn, boardsize, scores, hopped
** Pre-Conditions: User chose a king piece
** Post-Conditions: King piece is moved or hopped
*********************************************************************/

bool king_printer(char** board, int row_inp, int col_inp, int whr_row, int whr_col, int turn, int boardsize, int scores[], bool& hopped){
	if((board[whr_row][whr_col] == 'o') || (board[whr_row][whr_col] == 'x')){
		if(king_moves_check(board, row_inp, col_inp, whr_row, whr_col, turn) == true){
			move_piece(board, row_inp, col_inp, whr_row, whr_col, turn, boardsize);
			return true;
		}
		if(hop_check_king(board, row_inp, col_inp, whr_row, whr_col, turn) == true){ //Log March 14
			hop(board, row_inp, col_inp, whr_row, whr_col, turn, scores);
			hop2(board, row_inp, col_inp, whr_row, whr_col, turn, scores);
			cout << "Capturing piece!" << endl;
			scores[turn]++;
			hopped = true;
			return true;
	
		}
	}
}

/*********************************************************************
** Function: printer
** Description: When dealing with nonkinged piecesm, program goes here to check
** Parameters: board, row input, col input, where row, where col, turn, boardsize, scores, hopped
** Pre-Conditions: User chose non-king piece
** Post-Conditions: Piece is moved or hops
*********************************************************************/

bool printer(char** board, int row_inp, int col_inp, int whr_row, int whr_col, int turn, int boardsize, int scores[], bool& hopped){
	int returner = false;
	if((board[whr_row][whr_col] == 'o') || (board[whr_row][whr_col] == 'x')){
		returner = king_printer(board, row_inp, col_inp, whr_row, whr_col, turn, boardsize, scores, hopped);
		return returner;
	}
	if(moves_check(board, row_inp, col_inp, whr_row, whr_col, turn) == 1){
		move_piece(board, row_inp, col_inp, whr_row, whr_col, turn, boardsize);
		return true;
	}
	else if(hop_check(board, row_inp, col_inp, whr_row, whr_col, turn) == 1){
		cout << "Capturing piece!" << endl; 
		hop(board, row_inp, col_inp, whr_row, whr_col, turn, scores);
		hop2(board, row_inp, col_inp, whr_row, whr_col, turn, scores);
		scores[turn]++;
		hopped = true;
		return true;
	}
	else{
		cout << "Invalid move" << endl;
		return false;
	}

}

/*********************************************************************
** Function: print_scores
** Description: Prints both players scores
** Parameters: scores array
** Pre-Conditions: None
** Post-Conditions: Scores printed
*********************************************************************/

void print_scores(int scores[]){
	for(int i=0; i<2; i++){
		cout << "Player " << which_player(i) << "'s Score: " << scores[i] << endl;
	}
}

/*********************************************************************
** Function: same_hop_check
** Description: If user hops, they must hop the same piece again
** Parameters: board, turn, where row, where col, last row input, last col input, boardsize
** Pre-Conditions: User has hopped once and can hop again
** Post-Conditions: Correct input is given
*********************************************************************/

void same_hop_check(char** board, int turn, int& whr_row, int& whr_col, int hop_row, int hop_col, int boardsize){
	while((whr_row != hop_row) || (whr_col != hop_col)){
		cout << "You must hop with the previous piece. Try input again in row,col form." << endl;
		input_seperate(board, turn, whr_row, whr_col, boardsize);
	}
}

/*********************************************************************
** Function: get_boardsize
** Description: If no command line arg given, gets boardsize from here
** Parameters: rows, cols, boardsize
** Pre-Conditions: No command line given or incorrect 
** Post-Conditions: Boardsize given
*********************************************************************/

void get_boardsize(int& rows, int& cols, int& boardsize){
	int size = 0;
	bool good = false;
	cout << "What boardsize do you want? (8, 10, or 12)" << endl;
	size = get_real_num();
	if((size == 8) || (size == 10) || (size == 12))
		good = true;
	while(good == false){
		cout << "Invalid size" << endl;
		size = get_real_num();
		if((size == 8) || (size == 10) || (size == 12))
			good = true;
		cout << size << endl;
	}
	cin.ignore(1000, '\n');
	cin.clear();
	rows = size;
	cols = size;
	boardsize = rows;
}

/*********************************************************************
** Function: run_game
** Description: Bulk of the game, asks for input, prints board, says whos moving
** Parameters: board, where row, where col, row input, turn, boadsize, scores, hopped, valid move
** Pre-Conditions: Game is running, user has not won
** Post-Conditions: Pieces are moved, hops are performed
*********************************************************************/

bool run_game(char** board, int& whr_row, int& whr_col, int& row_inp, int& col_inp, int turn, int boardsize, int scores[], bool& hopped, int& hop_row, int& hop_col, bool& valid_move){
	print_board(board, boardsize, boardsize);
	print_scores(scores);
	cout << "Player " << which_player(turn) << " is going." << endl;
	cout << "Enter a piece to move in the form row,col (no spaces)" << endl;
	input_seperate(board, turn, whr_row, whr_col, boardsize);
	if(correct_piece(board, whr_row, whr_col, turn) == false)
		return false; //If invalid move
	if(hopped == true)
	same_hop_check(board, turn, whr_row, whr_col, hop_row, hop_col, boardsize);
	cout << "Where do you want to move this?" << endl;
	input_seperate(board, turn, row_inp, col_inp, boardsize);
	if((check_coord_whites(whr_row, whr_col, row_inp, col_inp) == true) && (correct_piece(board, whr_row, whr_col, turn) == true)){
		valid_move = printer(board, row_inp, col_inp, whr_row, whr_col, turn, boardsize, scores, hopped);
		if((hopped == true) && (all_hop_check(board, turn, boardsize, row_inp, col_inp) == true)){
			hop_row = row_inp;
			hop_col = col_inp;
			cout << "Hop again" << endl;
			valid_move = false;
		}
	}
	return true; //If valid inputs
}

/*********************************************************************
** Function: turn_checker
** Description: Increments the turns after a player makes a valid move
** Parameters: valid move, turn
** Pre-Conditions: User has made a valid move
** Post-Conditions: Turn is switched to other player
*********************************************************************/

void turn_checker(bool valid_move, int& turn){
	if(valid_move == true){	
			turn++;
			if(turn == 2)
				turn = 0;
		}
}
		
/*********************************************************************
** Function: delete_board
** Description: Frees memory, deletes dynamic 2D board 
** Parameters: board, boardsize
** Pre-Conditions: Player has won, game has ended
** Post-Conditions: Memory freed
*********************************************************************/

void delete_board(char** board, int boardsize){
	for(int i=0; i<boardsize; i++){
		delete [] board[i];
	}
	delete [] board;
}

/*********************************************************************
** Function: main
** Description: Holds important variables, makes function calls, runs game until user wins
** Parameters: argc, argv
** Pre-Conditions: None
** Post-Conditions: User wins
*********************************************************************/

int main(int argc, char** argv){
	int rows = 0, cols = 0, row_inp = 0, col_inp = 0, whr_row = 0, whr_col = 0, turn = 0, hop_row = 0, hop_col = 0, boardsize = 0;
	int scores[2] = {0,0};
	bool winner = false, valid_move = false, hopped = false;
	if((argc != 3) || (check_command(argc, argv, rows, cols, boardsize) == false)){
		cout << "Try again, incorrect number of arguements or board size." << endl;
		get_boardsize(rows, cols, boardsize);
	}
	char** board = init_board(rows, cols, boardsize);
	while(winner != true){	
		valid_move = false;
		hopped = false;
		while(valid_move == false){
			if(run_game(board, whr_row, whr_col, row_inp, col_inp, turn, boardsize, scores, hopped, hop_row, hop_col, valid_move) == false)
				break;
			check_kings(board, boardsize);
			if((moves_available(board, turn, boardsize) == false) || (any_pieces_left(board, turn, boardsize) == false)){
				print_scores(scores);
				delete_board(board, boardsize);
				return 0;
			}
		}
		turn_checker(valid_move, turn);
		
	}
}
