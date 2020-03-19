/*
Programmer: Victor Amaro 

Section: 2, Amy Byrnes

Date Due: October 23, 2015

Purpose: Program that will process a data set of random numeric information. The information will be needed for later processing, 
so it will be stored in an array that will be displayed, sorted, and displayed
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const double UPPER_BOUND = 100; //Sets constants to be used in program. UPPER_BOUND will be the largest value that can be generated
const double LOWER_BOUND = 0; //LOWER_BOUND will be the lowest value that can be generated
const int ARRAY_SIZE = 100; //Sets the size for the array

double randDouble(); //Function prototypes 
int buildArray( double array[] );
void printArray(double array[], int numberOfValues, int numberPerLine, int afterDecimal, int numberSpaces, string title);
void sortArray( double array[], int numberOfValues );

int main()
{
	double AR[ARRAY_SIZE]; //Creates the array
	int numberElements = 0, lineValues = 0, afterDecimal = 0, numberSpaces = 0; //Sets variables to be used
	srand(time(NULL)); //Calls srand to later produce numbers
	
    numberElements = buildArray(AR); //Fills the array with the random numbers
	cout << "How many values should be displayed per line? ";
	cin >> lineValues; //Gets how many values will be in one line
	cout  << "How many digits after the decimal point? ";
	cin >> afterDecimal; //Gets how many digits will be shown after the decimal
	cout << "How many spaces should be used to display the value? ";
	cin >> numberSpaces; //Gets how many spaces will be in between the nunbers
	
	printArray(AR, numberElements, lineValues, afterDecimal, numberSpaces, "Unsorted Numbers:"); //Prints the unsorted araay
	sortArray(AR, numberElements); //Sorts the array
	printArray(AR, numberElements, lineValues, afterDecimal, numberSpaces, "Sorted Numbers:"); //Prints the sorted array
	
	return 0;
}

/*******************
randDouble() function:
Will produce a random number that in between 0 and 100 and in double value. Will store that number in randomDouble, which is also the value that is reutned
by the function
*******************/
double randDouble()
{
	double randomDouble;

	randomDouble = LOWER_BOUND + ( rand() / ( RAND_MAX / ( UPPER_BOUND  - LOWER_BOUND))); //Produces the random double number 
	
	return randomDouble;
}

/*******************
buildArray() function:
The function will produce a number that is in between 20 and 100 and that will be stored into numberElements, that value will decide how many numbers will be 
put into the array. It then calls the randDouble() function and stores the appropriate number of elements into the array. Will return the number of elements in the array
*******************/
int buildArray(double array[])
{
	int i = 0, numberElements = 0;
	
	numberElements = rand();
	while(numberElements < 20 || numberElements > 100) //Produces the a number between 20 and 100 to be used for the number of elements in the array
	{
		numberElements = rand();
	}
	
	for (i = 0; i < numberElements; i++) //Calls the randDouble() function and places the randomm number into the array
	{
		array[i] = randDouble();
	}
	
	return numberElements;
}

/******************
sortArray() function:
It will then go into loop that will run until the count has reached the number of elements in the array, within in that loop, the elements will be checked one by one
and sorted in an ascending sort. 
******************/
void sortArray(double array[], int numberOfValues)
{	
	double temp = 0;
	
	for(int i = 0; i < numberOfValues; i++) //Will run as long as there is numbers to check
	{
		for (int sub = 0; sub < numberOfValues - 1; sub++)
		{
			if(array[sub] > array[sub+1]) //Will sort the numbers 
			{
				temp = array[sub];
				array[sub] = array[sub+1];
				array[sub+1] = temp;
			}
		}
	}
}

/******************
printArray() function: 
The function responsible for printing the array. The function wil print the whether the array has been sorted or not. It will then go into a loop that will print
each element in the array one by one, printing the number with the appropriate number of digits after the decimal and appropriate number of spaces in between the numbers.
Within the loop, a decision statement will check if the number of elements printed is equal to the number of valuesPerLine, if so, a new line will be started.
******************/
void printArray(double array[], int numberOfValues, int numberPerLine, int afterDecimal, int numberSpaces, string title)
{
	int count = 0;
	
	cout << endl << endl << title << endl << endl; //Prints title
	for(int i = 0; i < numberOfValues; i++) //Will print each value in the array one by one with spacing, and digits after decimal
	{
		cout << fixed << setprecision(afterDecimal) << setw(numberSpaces) << right << array[i] << " ";
		count++;
		if ( count == numberPerLine) //Will go into a new line if the number of elements to be printed in a line is met
		{
			count = 0;
			cout << endl;
		}
	}
}