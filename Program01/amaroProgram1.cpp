/*
CSCI 240         Program 1     Fall 2015

Programmer: Victor Amaro 

Section: 2, Amy Byrnes

Date Due: September 4, 2015

Purpose: This program calculates and displays the shooting percentage for an NHL team
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double numberOfGoalsScored, numberofShotsAttempted, shootingPercentage;
	cout << "Please enter the number of shots attempted: ";
	cin >> numberofShotsAttempted;
	cout << "Please enter the number of goals scored: ";
	cin >> numberOfGoalsScored;
	
	shootingPercentage = numberOfGoalsScored / numberofShotsAttempted * 100;
	
	cout << "The Shooting Percentage is: " << shootingPercentage;
	
	return 0;
}