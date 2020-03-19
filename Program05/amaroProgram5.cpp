/*
CSCI 240         Program 5     Fall 2015

Programmer: Victor Amaro 

Section: 2, Amy Byrnes

Date Due: October 9, 2015

Purpose: To  write the functions that can be used to manipulate and test an integer number.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_VALS = 10;   //the maximum number of values to use

//function prototypes
int reverse(int num); 
bool isPrime(int num);
bool isPalindrome(int num); 
int sumDigits(int num);

int main()
{
	int number,  //Holds the random number that is manipulated and tested
		loopCnt; //Controls the loop
		
	//set the seed value for the random number generator
	//Note: a value of 1 will generate the same sequence of "random" numbers every
	//      time the program is executed
	srand(1);
	
	//Generate 10 random numbers to be manipulated and tested
	for( loopCnt = 1; loopCnt <= NUM_VALS; loopCnt++ )
	{
  		//Get a random number
		number = rand();

 		 //Display the sum of adding up the digits in the random number, the reversed
 		 //random number, and whether or not the number is palindromic or a prime number
  
		cout << "The number is " << number << endl
		  << "----------------------------------------" << endl
		  << "Adding the digits result" << setw(16) << sumDigits( number ) << endl
		  << "Reversing the digits result" << setw(13) << reverse(number) << endl
		  << "Is the number a palindrome?" << setw(13) << (isPalindrome(number)? "Yes" : "No") << endl
		  << "Is the number prime?" << setw(20) << (isPrime(number)? "Yes" : "No") << endl
		  << endl << endl;
	}

	return 0;
}

int sumDigits(int num) //Creates function that will add up the digits of the random number
{
	int sum = 0, rem;
	while(num != 0) //Loop that will isolate each digit of the number using modulus division
	{               // Will then add the isolated digit to sum and continue to ioslate the digits
		rem = num % 10;
		sum += rem;
		num /= 10;
	}
	return sum;
}

int reverse(int num) //Creates function that will reverse the number
{
	int reversed = 0;
	int quo, rem;
	quo = num;  
  	while (quo != 0) //Loop will isolate single digits using modulus divsion and display them in reversed order 
  	{
    	rem = quo % 10;
    	reversed = reversed * 10 + rem;
    	quo /= 10;
  	}
  return reversed;
}

bool isPalindrome(int num) //Creates function that will check if the number is a palindrome
{	
	if (reverse(num) == num) //Calls reverse function and checks if the revsered number is a palindrome
		return true;
	else
		return false;
}

bool isPrime(int num) //Creates function that will check if number is prime
{
	int i;
	
	if (num % 2 == 0) //if number is even, it will be checked here if it is prime
		return false;
	for (i = 3; i*i <= num; i+=2) //if number is odd it will be checked here
	{
		if (num % i == 0)
			return false;
	}
	return true;
}