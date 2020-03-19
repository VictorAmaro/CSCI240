/*
CSCI 240         Program 4     Fall 2015

Programmer: Victor Amaro 

Section: 2, Amy Byrnes

Date Due: August 25, 2015

Purpose: Program that will calculate the monthly service fee that a bank charges for a commercial checking account. Checks for errors along the way
and also checking certain parameters that are set.

*/

#include <iostream>
#include <iomanip>
using namespace std;

//sets constant variables to be used in the program
const double MONTHLY_FEE = 10.00;
const double MINIMUM_BALANCE = 400.00;
const double MAINTENACE_CHARGE = 15.00;
const double CHECKS_LESS_THAN_20 = 0.10;
const double CHECKS_20_THRU_39 = 0.08;
const double CHECKS_40_THRU_59 = 0.06;
const double CHECKS_MORE_THAN_60 = 0.04;

int main()
{
	//Creates needed variables and places them in the correct variable type
	int checksWritten, i;
	double accountBalance, checkFee, checkFeeTotal, totalFees;
	bool minBalance = false;
	
	cout << "What is your checking account balance? ";
	cin >> accountBalance;
	accountBalance -= MONTHLY_FEE;
	if (accountBalance < MINIMUM_BALANCE) //Checks to see if user input balance is above the minimum balance fee, if not, 
	{                              //the maintenace fee will be applied to the running totalFees. And the value of minBalance is changed to true 	
		minBalance = true;
		totalFees += MAINTENACE_CHARGE;
	}

	cout << "How many checks did you wrtie this month? ";
	cin >> checksWritten;
	while(checksWritten < 0) //Checks that the user input is a positive number or atleast 0. If not, a error message will appear
	{
		cout << "Error: the number of checks cannot be negative. Try again: ";
		cin >> checksWritten;
	}
	
	if (checksWritten >= 60) //Comapres the user input to certain parameters. Depending on the number of checks written, the appropriate fee will be applied
	{
		checkFee = CHECKS_MORE_THAN_60;
	}
	else if (checksWritten >= 40)
	{
		checkFee = CHECKS_40_THRU_59;
	}
	else if (checksWritten >= 21 )
	{
		checkFee = CHECKS_20_THRU_39;
	}
	else if (checksWritten <= 20)
	{
		checkFee = CHECKS_LESS_THAN_20;
	}
    
	checkFeeTotal = checkFee * checksWritten; //Does the calculations for the number of checks written and the check fees, places them in checkFeeTotal
	totalFees += MONTHLY_FEE + checkFeeTotal; //Adds the checkFeeTotal as well as the monthly fee to the running total fees.
	
	cout << fixed << setprecision(2); //Sets the appropriate precision for a dollar amount. 
	cout << "\nMonthly Fee " <<setw(26) << MONTHLY_FEE << endl; //Prints the monthly fee
	if (minBalance == true) //Checks if minBalance was set to true, if so, will display another cout statement along with the maintenace charge
	{
		cout << "Balance Below the Minimum Charge " << MAINTENACE_CHARGE <<endl; 
	}
	
	cout << "Check Fee (" << checksWritten << " checks)" << setw(17) << checkFeeTotal << endl; //Prints the number of checks and the total fees for the checks
	
	for (i = 0; i < 75; i++) //Sets a line for easier readability
	{
		cout << "-";
		i++;	
	}
	cout << "\nTotal Fees" << setw(28) << totalFees << endl; //Prints the total fees, and the serivce fees
	cout << "\nThe service fee for this month is $" << totalFees << endl;
	
	return 0;	
}