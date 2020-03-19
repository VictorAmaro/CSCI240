/***************************************************************
CSCI 240         Program 8     Fall 2015

Programmer: Victor Amaro

Section: 2, Amy Byrnes

Date Due: November 6 2015

Purpose: Implement the methods, constructor and class for a game.
***************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

//**********   Put the Die class definition after this line   **********
class Die
{
	public: //Methods and constructor
	Die(); 
	void roll();
	void draw();
	int getValue();
		
	private: //Data members 
	static const int NUM_SIDES;
	int currentSide;
};

const int Die::NUM_SIDES = 6;

int main()
{
	//seed the random number generator
	srand(time(NULL));
	int numRolls = 0, sum = 0; //Sets variables to be used

	cout << "How many times do you want to try to catch a fish? "; //Asks to the user to input number of rolls
	cin >> numRolls;

	Die die1; //Creates a die1

	for( int rolls = 1; rolls <= numRolls; rolls++ ) //Will roll the die the number of times the user inputed
	{
		die1.roll();
		if(die1.getValue() == 1) //Cascading if statements, that will compare the side the die is on and then assign it the correct point value
		{                    //Will print out what was caught, and add the points to a running total.
			cout << endl << endl << "Roll " << rolls << ":" << endl;
       		die1.draw(); 
	   		cout << endl << "You caught a big fish " << "20 points!" << endl; 	
			sum += 20; 
	    }
		else if (die1.getValue() == 2)
		{
			cout << endl << endl << "Roll " << rolls << ":" << endl;
       		die1.draw(); 
	   		cout << endl << "You caught an old shoe " << "-10 points!" << endl; 	
			sum += -10; 
		}
		else if(die1.getValue() == 3)
		{
			cout << endl << endl << "Roll " << rolls << ":" << endl;
       		die1.draw(); 
	   		cout << endl << "You caught a gold fish " << "5 points!" << endl; 	
			sum += 5; 
		}
		else if(die1.getValue() == 4)
		{
			cout << endl << endl << "Roll " << rolls << ":" << endl;
       		die1.draw(); 
	   		cout << endl << "You caught a fish" << " 10 points!" << endl;
			sum += 10;
		}
		else if (die1.getValue() == 5)
		{
			cout << endl << endl << "Roll " << rolls << ":" << endl;
       		die1.draw(); 
	   		cout << endl << "You caught a toilet seat " << "-20 points!" << endl; 	
			sum += -20; 
		}
		else
		{
			cout << endl << endl << "Roll " << rolls << ":" << endl;
       		die1.draw(); 
	   		cout << endl << "You caught a shark " << "40 points!" << endl; 	
			sum += 40; 
		}
	}
	cout << endl << "Your final score is " << sum << " points." << endl; //Prints out the final score
	return 0;
}

//**********   Code the Die class constructor and methods after this line   **********
/***************************
Constructor: Die()

Use: Default constructor.

Arguments: None

Returns: Nothing
***************************/
Die::Die()
{
	roll();
}

/*************************
Method: Die::roll()

Use: Will generate a random number between 1 and 6, representing the 6 sides of a die. Then place it in currentSide.

Arguments: None

Returns: Nothing
*************************/
void Die::roll()
{
	currentSide = rand() % NUM_SIDES + 1; 
}

/************************
Method: Die::getValue()

Use: Used to get the value (the current side) on which the die is on

Arguments: None

Returns: currentSide, which is the current side the die is on
*************************/
int Die::getValue()
{
	return currentSide;
}

/*********************
Method: Die::draw()

Use: Will check the current side of the die and then print out the correct die picture.

Arguments: None

Returns: Nothing
**********************/
void Die::draw()
{
	int numLines = 0;
	if(currentSide == 1)
	{
		cout << " ----- " << endl
			<< "|O    |" << endl
			<< "|     |" << endl
			<< "|     |" << endl
			<< " -----";	
	}
	else if(currentSide == 2 )
	{
	    cout << " ----- " << endl
	        << "|O    |" << endl
			<< "|     |" << endl
			<< "|    O|" << endl
			<< " -----";	
	}
	else if(currentSide == 3)
	{
	     cout << " ----- " << endl
	        << "|O    |" << endl
			<< "|  O  |" << endl
			<< "|    O|" << endl
			<< " -----";	
	}	
	else if(currentSide == 4)
	{
		cout << " ----- " << endl
			<< "|O   O|" << endl
			<< "|     |" << endl
			<< "|O   O|" << endl
			<< " -----";			
		}
	else if(currentSide == 5)
	{
        cout << " ----- " << endl
	        << "|O   O|" << endl
			<< "|  O  |" << endl
			<< "|O   O|" << endl
			<< " -----";			
	}
	else
	{
        cout << " ----- " << endl
	        << "|O   O|" << endl
			<< "|O   O|" << endl
			<< "|O   O|" << endl
			<< " -----";			
	}
}