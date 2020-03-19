/*
CSCI 240         Program 6     Fall 2015

Programmer: Victor Amaro 

Section: 2, Amy Byrnes

Date Due: October 16, 2015

Purpose: Program that will count different types of characters in a text file.
*/
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <cstdlib>
using namespace std;

bool isvowel(char ch); //Function prototypes 
bool isconsonant(char ch);

int main()
{
	char ch; //Sets variable where next charatcer of file will be placed for the checking
	int charCnt = 0, alphaCnt = 0, upperCnt = 0, lowerCnt = 0, digitCnt = 0, punctCnt = 0, //Sets counters for the different types of chraracters 
		consonantCnt = 0, vowelCnt = 0, whiteSpaceCnt = 0, spaceCnt = 0, newLineCnt = 0,
		commaCnt = 0, periodCnt = 0, quoteCnt = 0, questionCnt = 0, exclamationCnt = 0, otherCnt = 0;
	
	ifstream infile; //input file stream variable, this will be used instead of cin
	infile.open("input.txt");
	
	if(infile.fail()) //if the inout file failed to open
	{
		cout << "input file did not open" << endl;
		exit(-1); //stop execution of program immediately
	}
	
	ch = infile.get();
	while(infile) //Sets loop that will run as long there in more data to get from file
	{
		cout << ch;
		if(isalpha(ch)) //If the character is an alphabetic one it will go into this decicsion statement and add one to the alpha count.
		{               
			alphaCnt++;
			if (isupper(ch)) //Then it will come to this decision statement where it will check if the character is upper case 
				upperCnt++;  //or a lower case character and add one to the respective count.
			else
				lowerCnt++;
			if (isvowel(ch)) //Then it will come to this decision statement where it will check if the character is a vowel or a consonant
				vowelCnt++;  // and add one to the respective count
			else  
				consonantCnt++;
		}
		else if(isdigit(ch)) //If the character is not alphabetic, and is a digit instead it will add one to digit count
			digitCnt++;
		else if(ispunct(ch)) //If the character is neither an alphabetic or digit character and is a punctuation character instead it will 
		{	            //go into this decision statement and add one to punt count.
			punctCnt++;
			if(ch == ',') //This will check for what type of punctuation the character is and add one to the respective counter 
				commaCnt++;
			else if (ch == '.')
				periodCnt++;
			else if(ch == '\'' || ch == '\"')
				quoteCnt++;
			else if(ch == '?')
				questionCnt++;
			else if(ch == '!')
				exclamationCnt++;
			else
				otherCnt++;
		}
		else if(isspace(ch)) //If white space is found, one will be added to white space count, and it will go into the decision statement
		{
			whiteSpaceCnt++;
			if(ch == ' ' ) //If a space is found, it will add one to space count.
				spaceCnt++;
		 	else //If a new line is found, it will add one to new line count
				newLineCnt++;
		}
		charCnt++; //adds one to the total character count
		ch = infile.get(); //continues to get the next character in the file
	}
	
	cout << "\n\nTotal Number of Characters: " << setw(5) << charCnt << endl << endl //Prints the total number of counts for the respecitve checking
		 << "Alphabetic Characters: " << setw(10) << alphaCnt << endl
		 << "  UpperCase: " << setw(20) << upperCnt << endl
		 << "  LowerCase: " << setw(20) << lowerCnt << endl << endl
		 << "  Vowels: " << setw(23) << vowelCnt << endl
		 << "  Consonants: " <<setw(19) <<  consonantCnt << endl << endl
		 << "Digit Characters: " << setw(15) << digitCnt << endl << endl
		 << "Punctuation Characters: " << setw(9) << punctCnt << endl 
		 << "  Commas:" << setw(24) << commaCnt << endl
		 << "  Periods:" << setw(23) << periodCnt  << endl
		 << "  Quotes:" << setw(24) << quoteCnt << endl
		 << "  Question Marks:" << setw(16) << questionCnt << endl
		 << "  Exclamation Points:" << setw(12) << exclamationCnt << endl
		 << "  Other:" << setw(25) << otherCnt << endl << endl
		 << "Whitespace Characters: " << setw(10) << whiteSpaceCnt << endl
		 << "  Spaces: " << setw(23) << spaceCnt << endl
		 << "  Newline Characters: " << setw(11) << newLineCnt << endl;
	infile.close(); //Closes file
	return 0;
}

bool isvowel(char ch) //Function that will check if the character is a vowel
{
	switch(tolower(ch)) //Use tolower to change character into a lower case and then checks if it is a vowel, returning true if it is or false if not
	{
		case 'a' : return true;
			break;
		case 'e' : return true;
			break;
		case 'i' : return true;
			break;
		case 'o' : return true;
			break;
		case 'u' : return true;
			break;
		default : return false;
	}
}

bool isconsonant(char ch) //Function that wll check if character is a consonant.
{
	if(isvowel(tolower(ch)) == false) //Calls the isvowel function, and if returned false, then isconsonant will return true
		return true;
}
