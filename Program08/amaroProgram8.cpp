/***************************************************************
CSCI 240         Program 8     Fall 2015

Programmer: Victor Amaro

Section: 2, Amy Byrnes

Date Due: November 6 2015

Purpose: Implement the methods for a class called Pitcher
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

//Pitcher class definition

class Pitcher
{
	public:
	Pitcher();
	Pitcher( const char [], int, int, int, double );
  
	void changeName( const char [] );
	void changeHits( int );
	void changeWalks( int );
	void changeEarnedRuns( int );
	void changeInnings( double );

	char * getName();  
	int getHits();
	int getWalks();
	int getEarnedRuns();
	double getInnings();
  
	void display();
  
	double calcWHIP();
	double calcERA();

	private:
	char name[50];
	int hitsAllowed, walksAllowed, earnedRunsAllowed;
	double inningsPitched;
};


int main()
{
	//Create a Pitcher object with the default constructor
	Pitcher pitcher1;

	//Display the default information with a label

	cout << "*****  Test 1  *****"
		 << endl << endl << "The default values are" << endl << endl;

	pitcher1.display();


	//Create a second Pitcher object

	Pitcher pitcher2( "Jake Arrieta", 150, 48, 45, 229.0 );

	//Display the second Pitcher with a label

	cout << endl << endl << "*****  Test 2  *****"
		 << endl << endl << "Regular Season statistics" << endl << endl;

	pitcher2.display();


	//Add the statistics for another game (the wild card game) and then
	//display the updated values

	pitcher2.changeInnings(9.0);
	pitcher2.changeHits(5);
	pitcher2.changeEarnedRuns(0);
	pitcher2.changeWalks(0);

	cout << endl << endl << "Regular Season + Wild Card Game statistics" << endl << endl;

	pitcher2.display();


	//Add the statistics for a second game (NLDS game 4) and then display
	//the updated values

	pitcher2.changeInnings(5.66666);
	pitcher2.changeHits(5);
	pitcher2.changeEarnedRuns(4);
	pitcher2.changeWalks(2);

	cout << endl << endl << "Regular Season + Wild Card Game + NLDS Game 4 statistics" << endl << endl;

	pitcher2.display();

	//Create a third Pitcher object

	Pitcher pitcher3 = Pitcher( "Jon Lester", 13, 2, 7, 14.0 );


	//Display only the name, earned run average, and number of innings pitched
	//for the third Pitcher

	cout << endl << endl << "*****  Test 3  *****"
		 << endl << endl << "Post-Season statistics" << endl << endl;

	cout << pitcher3.getName() << " has an ERA of " << setprecision(2) << pitcher3.calcERA()
		 << " over " << setprecision(1) << pitcher3.getInnings() << " innings pitched." << endl;


	//Create a fourth Pitcher object

	Pitcher pitcher4 = Pitcher( "Fernando Rodney", 0, 1, 0, 2.0/3 );


	//Display only the name, number of hits, number of walks, number of innings pitched,
	//and earned runs for the fourth Pitcher

	cout << endl << endl << "*****  Test 4  *****"
		 << endl << endl << "Post-Season statistics" << endl << endl;

	cout << pitcher4.getName() << " has given up " << pitcher4.getHits() << " hits, "
		 << pitcher4.getWalks() << " walks, and " << pitcher4.getEarnedRuns() << " earned runs."
		 << endl << "His WHIP is " << setprecision(2) << pitcher4.calcWHIP() << "." << endl;

	return 0;
}


/***************************************************************
Method:  char * getName()

Use: This method returns the name of the Pitcher

Arguments: none

Returns: the address of the name data member for the Pitcher
         class
***************************************************************/
char * Pitcher::getName()
{
return name;
}

//***************  Code the remaining constructors and methods below this line  ***************

/*********************************************************
Constructor: Pitcher()

Use: The passed in arguments are used to initialize the corresponding data members of the object.

Arguments: const char Newname [], int newHitsAllowed, int newWalksAllowed, int newRunsAllowed, double newInnings

Returns: Nothing
**********************************************************/
Pitcher::Pitcher(const char Newname [], int newHitsAllowed, int newWalksAllowed, int newRunsAllowed, double newInnings)
{
	strcpy(name, Newname);
	hitsAllowed =  newHitsAllowed;
    walksAllowed = newWalksAllowed;
	earnedRunsAllowed = newRunsAllowed;
	inningsPitched = newInnings;
}

/*********************************************************
Constructor: Pitcher()

Use: Creates an "empty" Pitcher object and Initializes the name data member to an empty string

Arguments: None

Returns: Nothing
**********************************************************/
Pitcher::Pitcher()
{
	*name='\0';
	hitsAllowed = 0;
    walksAllowed = 0;
	earnedRunsAllowed = 0;
	inningsPitched = 0;
}

/**************************************
Method: changeName( const char newName[] )

Use: This access method changes the name of the pitcher.

Arguments: An array of constant characters that represents the new name for a pitcher.

Returns: Nothing

***************************************/
void Pitcher::changeName( const char newName[] )
{
	strcpy(name,newName);
}

/*********************************************************
Method: changeHits( int additionalHits )

Use: changes the number of hits allowed by the pitcher

Arguments: additionalHits

Returns: Nothing
**********************************************************/
void Pitcher::changeHits( int additionalHits )
{
	hitsAllowed	+= additionalHits;
}

/*********************************************************
Method: changeWalks( int additionalWalks )

Use: changes the number of walks allowed by the pitcher

Arguments: additionalWalks

Returns: Nothing
**********************************************************/
void Pitcher::changeWalks( int additionalWalks )
{
	walksAllowed += additionalWalks;
}

/*********************************************************
Method: changeEarnedRuns( int additionalRuns )

Use: changes the number of earned runs given up by the pitcher

Arguments: additionalRuns

Returns: Nothing
**********************************************************/
void Pitcher::changeEarnedRuns( int additionalRuns )
{
	earnedRunsAllowed += additionalRuns;
}

/*********************************************************
Method: changeInnings( double additionalInnings )

Use: changes the number of innings pitched by the pitcher

Arguments: additionalInnings

Returns: Nothing
**********************************************************/
void Pitcher::changeInnings( double additionalInnings )
{
	inningsPitched += additionalInnings;
}

/*********************************************************
Method: getHits()

Use: This method will return the number of hits

Arguments: None

Returns: Will return the number of hits allowed
**********************************************************/
int Pitcher::getHits()
{
	return hitsAllowed;
}

/*********************************************************
Method: getWalks()

Use: This method will return the number of walks

Arguments: None

Returns: Will return the number of walks
**********************************************************/
int Pitcher::getWalks()
{
	return walksAllowed;
}

/*********************************************************
Method: getEarnedRuns()

Use: This method will return the number of runs.

Arguments: None

Returns: Will return the number of runs
**********************************************************/
int Pitcher::getEarnedRuns()
{
	return earnedRunsAllowed;
}

/*********************************************************
Method: getInnings()

Use: This method will return the number of innings pitched.

Arguments: None

Returns: Will return the number of innings pitched
**********************************************************/
double Pitcher::getInnings()
{
	return inningsPitched;
}

/*********************************************************
Method: calcWHIP()

Use: Will calculate the WHIP for the player and then return it. Will return a zero if divsion is by zero.

Arguments: None

Returns: Will return the calculated WHIP for the player
**********************************************************/
double Pitcher::calcWHIP()
{
	if(getInnings() == 0)
		return 0;
	else
		return (getHits() + getWalks()) / getInnings();
}

/*********************************************************
Method: calcERA()

Use: Will calculate the ERA for the player and then return it. Will return a zero if divsion is by zero.

Arguments: None

Returns: Will return the calculated ERA for the player
**********************************************************/
double Pitcher::calcERA()
{
	if(getInnings() == 0)
		return 0;
	else
		return (getEarnedRuns() * 9) / getInnings();
}

/*********************************************************
Method: display()

Use: Calls methods to gather  up the data and then will display the data in a formatted way.

Arguments: None

Returns: None
**********************************************************/
void Pitcher::display()
{
	cout << Pitcher::name << endl
		 << "Hits: " << getHits() << setw(10) << "Walks: " << getWalks() << setw(10) << "Runs: " << getEarnedRuns() << setw(11) << "Innings: " 
		 << fixed << setprecision(1) << getInnings() << endl << endl
	     << "ERA: " << fixed << setprecision(2) << calcERA() << setw(8) << "WHIP: " << calcWHIP();
}
