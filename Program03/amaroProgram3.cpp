/*
CSCI 240         Program 3     Fall 2015

Programmer: Victor Amaro 

Section: 2, Amy Byrnes

Date Due: September 18, 2015

Purpose: This program calculates and displays the shooting percentage for an NHL team and checks for errors.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	string userInput = "y"; //creates variables in the appropriate variable type
	int numberOfGoalsScored, numberOfShotsAttempted, gameCount;
	double totalGoalsScored, totalGoalsAttempted, shootingPercentage;
			
	while (userInput == "y") //Sets special value to continue with loop, asking the user to input values for the goals/shots
	{
		cout << "Please enter the number of goals scored: "; 
		cin >> numberOfGoalsScored;
		while (numberOfGoalsScored < 0) //This loop checks to make sure the user input is a positive one, if not, a error messages displays
		{
			cout << "Please enter a positive number of goals scored: ";
			cin >> numberOfGoalsScored;
		}
		cout << "Please enter the number of shots attempted: ";
		cin >> numberOfShotsAttempted;
		while (numberOfShotsAttempted < 0) //This loop checks to make sure the user input is a positive one, if not, a error messages displays
		{
			cout << "Please enter a positive number of attempted shots: ";
			cin >> numberOfShotsAttempted;
		}
		
	gameCount ++; //calculations are done and are set in the appropriate variables, then displayed.
	totalGoalsScored += numberOfGoalsScored;
	totalGoalsAttempted += numberOfShotsAttempted;
	shootingPercentage = totalGoalsScored / totalGoalsAttempted * 100; 
	cout << "The Team Shooting Percentage after " << gameCount << " game(s) is " 
		 << fixed << setprecision(1) << shootingPercentage << endl;
	
	cout << "Is there more data? (y or n) "; //asks the user if there is more data, a "y" will continue with program. Anything else will exit the program.
	cin >> userInput;
	}
	return 0;
}
