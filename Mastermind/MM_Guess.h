#ifndef MM_Guess
#define MM_Guess

#include <time.h>
#include <iostream>
using namespace std;

class Guess {
protected:
	int masGuess[4];
	int aGuess[4];
	bool isValid(int ch) 
	{
		return ch >= 0 && ch <= 8;
	};
public:
	Guess() 
	{
		aGuess[0] = -1;
		aGuess[1] = -1;
		aGuess[2] = -1;
		aGuess[3] = -1;
		srand(time(0));
	};
	void setGuess(int a, int b, int c, int d) 
	{
		if (isValid(a)) aGuess[0] = a;
		else { cout << "The first number was not a valid numnber" << endl; aGuess[0] = 9; }
		if (isValid(b)) aGuess[1] = b;
		else { cout << "The second number was not a valid numnber" << endl; aGuess[1] = 9; }
		if (isValid(c)) aGuess[2] = c;
		else { cout << "The third number was not a valid numnber" << endl; aGuess[2] = 9; }
		if (isValid(d)) aGuess[3] = d;
		else { cout << "The fourth number was not a valid numnber" << endl; aGuess[3] = 9; }
	};
	void setMaster() 
	{
		masGuess[0] = (rand() % 8) + 1;
		do { masGuess[1] = (rand() % 8) + 1; } while (masGuess[0] == masGuess[1]);
		do { masGuess[2] = (rand() % 8) + 1; } while (masGuess[0] == masGuess[2] || masGuess[2] == masGuess[1]);
		do { masGuess[3] = (rand() % 8) + 1; } while (masGuess[0] == masGuess[3] || masGuess[3] == masGuess[1] || masGuess[3] == masGuess[2]);
	};
	int operator[](int indx) const { return aGuess[indx]; };
};


#endif