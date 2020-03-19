/*
CSCI 240         Program 2     Fall 2015

Programmer: Victor Amaro 

Section: 2, Amy Byrnes

Date Due: September 11, 2015

Purpose: This program calculates and displays the shooting percentage for an NHL team and checks for errors.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int numberOfGoalsScored, numberOfShotsAttempted;
	double shootingPercentage; 
	
	cout << "Please enter the number of goals scored: ";
	cin >> numberOfGoalsScored;
	while (numberOfGoalsScored <= -1)
	{ 
		cout << "Number of goals must be positive:  ";
		cin >> numberOfGoalsScored;
	}
	
	cout << "Please enter the number of shots attempted: ";
	cin >> numberOfShotsAttempted;

	while (numberOfShotsAttempted <= -1)
	{ 
		cout << "Number of shots must be positive:  ";
		cin >> numberOfShotsAttempted;
	}

	shootingPercentage = (double)numberOfGoalsScored / (double)numberOfShotsAttempted * 100;
	cout << "The Shooting Percentage is: " 
	     << fixed << setprecision(1) << shootingPercentage;
	
	return 0;
}