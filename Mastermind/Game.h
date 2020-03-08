#ifndef GAME
#define GAME

#include <iostream>
#include "MM_Guess.h"
using namespace std;

class Game : public Guess {
private:
	int numGuesses;
	int whitePegs;
	int blackPegs;
public:
	Game() 
	{
		numGuesses = 0;
		whitePegs = 0;
		blackPegs = 0;
	}
	void getUserGuess()
	{
		int a, b, c, d;
		cout << "please enter your guess: ";
		cin >> a >> b >> c >> d;
		setGuess(a, b, c, d);
	}
	int getMin(int a, int b) { //used in finding white peg
		if (a < b)return a;
		else return b; }
	void generateFeedback()
	{
		blackPegs = 0;
		whitePegs = 0;
		int userColors[9];
		int codeColors[8];
		for (int i = 0; i < 8; i++) {//setting guess and code array to 0
			userColors[i] = codeColors[i] = 0;
		}
		for (int i = 0; i < 4; i++) { //Black pegs/ white peg initialization
			if (aGuess[i] == masGuess[i]) {
				//cout << aGuess[i] << " is correct" << endl;
				blackPegs++;
			}
			userColors[aGuess[i] -1]++;
			codeColors[masGuess[i] -1]++;
		}
		for (int i = 0; i < 8; i++) { //White peg calculation
			int x = getMin(userColors[i], codeColors[i]);
			whitePegs = whitePegs + x;
		}
		whitePegs = whitePegs - blackPegs;
		cout << "Black pegs = " << blackPegs << " White pegs = " << whitePegs << endl << endl;
	}
	bool isWinner() 
	{
		if (blackPegs == 4) {
			return true;
		}
		else {
			return false;
		}
	}
	bool outOfGuess()
	{
		if (numGuesses == 10) {
			return true;
		}
		else {
			return false;
		}
	}
	void playGame()
	{
		cout << "The master code has no repeating values" << endl;
		setMaster();
		/*for (int i = 0; i < 4; i++) {
			cout << masGuess[i] << ", ";
		}*/
		cout << endl;
		numGuesses = 0;
		do {
			cout << "Attempt number " << numGuesses + 1 << endl;
			getUserGuess();
			/*for (int i = 0; i < 4; i++) {
				cout << aGuess[i] << ", ";
			}
			cout << endl;*/
			generateFeedback();
			numGuesses++;
		} while (numGuesses < 10 && blackPegs != 4);
		if (isWinner())
			cout << "you win" << endl;

		if (outOfGuess())
			cout << "you lose, the secret code was (";
		for (int i = 0; i < 3; i++) {
			cout << masGuess[i] << ", ";
		}
		cout << masGuess[3] << ")";
	}
};
#endif