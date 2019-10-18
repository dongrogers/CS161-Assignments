/******************************************************
** Program: ass2.cpp
** Author: Rogers Dong
** Date: 21 January 2018
** Description: Maze Adventure with the Minotaur, avoid dying to win
** Input: Integers
** Output: Text
******************************************************/

#include <iostream>
#include <cstdlib> 

using namespace std;

int main(){
	int start, first, blackdoor, swordgrab, leftright, shootrun, turnrun, dodge;

	cout << "Welcome to the Minotaur Maze, to win you must go through without being eaten. Enter any number to continue." << endl;
	cin >> start;

	cout << "You have entered the maze, enter 1 to go towards the black door with a skull on it, or 2 to go through the rainbow door." << endl;
	cin >> first;

	if (first == 1) {
		cout << "You have chosen to go into the Minotaur's room and he sees you. Inside are swords. Enter 1 to grab one, 2 to run, or 3 to do nothing." << endl;
		cin >> blackdoor;
		if (blackdoor == 1) {
			cout << "You grab the sword. The minotaur runs at you. Enter 1 to swing at it, or 2 to dodge." << endl;
			cin >> swordgrab;
			if (swordgrab == 1) {
				cout << "You stab the minotaur. It dead. Nice. You win!" << endl;
			}
			else if (swordgrab == 2) { 
				cout << "You dodge the minotaur's charge. It run into wall. It dead. Nice. You win!" << endl;
			}
		}
	
		else if (blackdoor == 2) {
			cout << "You start to run but the Minotaur runs much faster. He stomps you. You dead." << endl;
		}
		else if (blackdoor == 3) {
			cout << "You do nothing while the Minotaur charges at 90 mph. You get ran. You dead." << endl;
		}
	}

	else if (first == 2) {
		cout << "You go through the rainbow colored door. You continue to walk the hall and it leads to two doors. Enter 1 to go left, or 2 to go right." << endl;
		cin >> leftright;
		if (leftright == 1) {
			cout << "You open the left door and behind it is a fat gun. Nothing else is in the room. Enter any number to continue to the other door." << endl;
			cin >> start;
			cout << "You open the right door and a rainbow minotaur is behind it. Enter 1 to shoot with the fat gun, or 2 to run." << endl;
			cin >> shootrun;
			if (shootrun == 1) {
				cout << "You shoot the minotaur and it dies. At the end of the room is the exit, you win!" << endl;
							}
			else if (shootrun == 2) {
				cout << "You run but the minotaur is a lot faster and is about to stomp you. Enter 1 to turn around and shoot, or keep running." << endl;
				cin >> turnrun;
				if (turnrun == 1) {
					cout << "You turn and shoot the minotaur. It dead. You win!" << endl;
				}
				else {
					cout << "You get stomped. You die. You lose." << endl;
					}
			}
		}
	}

		if (leftright == 2) {
			cout << "You open the right door and behind it is the minotaur. It charges at you. Enter 1 dodge left, or 2 to dodge right." << endl;
			cin >> dodge;
			srand(time(NULL));

			int minotaur = (rand() % 2 + 1);
			if (dodge == minotaur) {
				cout << "You dodged and the minotaur went the other direction, and slammed into the wall. It died. You win." << endl;
			}
			else if (dodge != minotaur) {
				cout << "You dodged but the minotaur saw and stomped you. You died. You lose." << endl;
			}
		}	
	return 0;
}
