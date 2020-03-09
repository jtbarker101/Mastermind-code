// Jon Barker
// This is my code
// Mastermind

#include <iostream>
#include "GAME.h"
#include "MM_Guess.h"
using namespace std;

void instructions() {
	string play;
	cout << "Tt seems that you do not know the how to play the game. That is okay." << endl;
	cout << "The purpose of this game is to guess my secret code, you do this by entering in a string of 4 numbers ranging 1-8" << endl;
	cout << "I will then tell you how many numbers are in the exact position (signified by a black peg)";
	cout << " and how many numbers were correct but in the wrong area (signified by a white peg)" << endl;
	cout << "It is up to your logic and reasoning skills to put together the clues I give you, if you are not able to solve the code in 10 turns you will lose." << endl;
	cout << "Best of luck to you in this game" << endl << endl;
	cout << "please press any key then enter to stat the game ";
	cin >> play;
}

int main() 
{
	Game g1;
	string start;
	cout << "This is the game of MASTERMIND" << endl << "if you wish for instructions enter 'i' or if you wish to play enter literally anything else.";
	cin >> start;
	if (start == "i") {
		cout << endl << endl << endl;
		instructions();
		g1.playGame();
	}
	else {
		cout << endl << endl << endl;
		g1.playGame();
	}
	return 0;
}