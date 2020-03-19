/***************************************************************
CSCI 240         Program 10     Fall 2015

Programmer: Victor Amaro

Section: 2, Amy Byrnes

Date Due: December 4, 2015

Purpose: Implement and use the methods for a class called Card.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

/**********   Put the Card class definition between these lines   **********/

class Card //Definition for a class that represents a card
{
	public: //Methods and constructor
	Card();
	void setCard(int, char);
	int getFace();
	char getSuit();
	void displayCard();
	
	private:
	int faceCard; //The face of the card
	char suitCard; //The suit of the card
};
/***************************************************************************/
//Definition for a class that represents a deck of cards
class DeckOfCards
{
	public:
	DeckOfCards();
  
	Card draw();
	void shuffle();
	bool isEmpty();

	private:
	static const int MAX_CARDS = 52;       //Maximum number of cards in a deck
	static const int NUM_SUITS = 4;        //Number of card suits
	static const int CARDS_PER_SUIT = 13;  //Number of cards of each suit

	Card deck[MAX_CARDS];     //The deck of cards
	int topCard;              //The subscript of the card on the top of the deck

};

int main()
{
	//Set the seed value for the random number generator
	rand(time(0));
	int player1Sum = 0, player2Sum = 0; //Sums for players
	Card player1, player2; //Creats a player1 and player2 instance of the Card class
	DeckOfCards deck1; //Creates a deck1 instance of the DeckOfCards class
	deck1.shuffle();  //Calls the shuffle method to the deck1 
	char player1Name[20], player2Name[20]; //Creates 20 characters arrays to hold the player's names
	cout << "What is your name player one? "; //Asks users for names and stores them in the variables
	cin >> player1Name;
	cout << "What is your name player two? "; 
	cin >> player2Name;
	
	while(deck1.isEmpty() == false) //Loop that will run untill all cards have been drawn
	{
		player1 = deck1.draw(); //Calls the draw method to draw a card for both players
		player2 = deck1.draw();
		cout << endl << player1Name << ": "; player1.displayCard();  //Displays player's one card
		cout << setw(15) << player2Name  << ": "; player2.displayCard(); //Displays player's two card
	
		if(player1.getFace() > player2.getFace()) //Checks with player had the higher score, printing out who won that hand and adding
		{                                         //to their sum
			cout << endl << player1Name <<" wins the hand!" << endl
				<< "-------------------------------------------------" << endl;
			player1Sum+=2;
		}
		else if (player1.getFace() < player2.getFace())
		{
			cout << endl << player2Name << " wins the hand!" << endl 
				<< "-------------------------------------------------" << endl;
			player2Sum+=2;
		}
		else 
		{
			cout << endl << "Draw" << endl
				<< "-------------------------------------------------" << endl;
			player1Sum+=1;
			player2Sum+=1;
		}
	}
	
	cout << endl << player1Name <<"'s score: " << player1Sum << endl //Prints out the player's score
		 << player2Name <<"s score: " << player2Sum << endl;
	if(player1Sum > player2Sum) //Checks which player had the higer score, will print out who wins or if game ended in a draw
		cout << player1Name << " wins!" << endl;
	else if(player1Sum < player2Sum)
		cout << player2Name << " wins!" << endl;
	else
		cout << "Draw!" << endl; 

	return 0;
}
/**********   Code the Card class methods between these lines   **********/

/***************************************************************
Constructor: Card()

Use: This creates a Card object and sets it a face/number value and suit value

Arguments: None
***************************************************************/
Card::Card()
{
	faceCard = rand() % 13 + 1; 
	if(rand() % 4 + 1 == 1)
		suitCard = 'C';
	else if(rand() % 4 + 1 == 2)
		suitCard = 'D';
	else if(rand() % 4 + 1 == 3)
		suitCard = 'H';
	else
		suitCard = 'S';
}	

/***************************************************************
Method: setCard(int, char)

Use: This method will set passed in values to the face/number value of a card as well as the suit of the card

Arguments: int newFace, char newSuit

Returns: Nothing
***************************************************************/
void Card::setCard(int newFace, char newSuit)
{
	faceCard = newFace;
	suitCard = newSuit;
}

/***************************************************************
Method: getFace()

Use: This method returns the face value of the current card

Arguments: None

Returns: The current value of the face of the card
***************************************************************/
int Card::getFace()
{
	return faceCard;
}

/***************************************************************
Method: getSuit()

Use: This method returns the suit value of the current card

Arguments: None

Returns: The current value of the suit of the card
***************************************************************/
char Card::getSuit()
{
	return suitCard;	
}

/***************************************************************
Method: displayCard()

Use: This method will print out the correct suit of the card after checking as well as the
	correct face/number value after checking	

Arguments: None

Returns: Nothing
***************************************************************/
void Card::displayCard()
{
	if(faceCard == 1)
		cout << "Ace of";
	else if(faceCard == 11)
		cout << "Jack of";
	else if(faceCard == 12)
		cout << "Queen of";
	else if(faceCard == 13)
		cout << "King of";
	else
		cout << getFace() << " of";
		
	if(suitCard == 'C')
		cout << " Clubs";
	else if(suitCard == 'D')
		cout << " Diamonds";
	else if(suitCard == 'H')
		cout << " Hearts";
	else 
		 cout << " Spades";
}

/*************************************************************************/

//The constructor and methods for the pre-written DeckOfCards class follows

/***************************************************************
Constructor

Use: This creates a DeckOfCards object

Arguments: none

Note: -1 is used to signal that no cards have been removed from the deck
***************************************************************/

DeckOfCards::DeckOfCards()
{
	//An array of the 4 possible values for the card suit
	char suitVals[NUM_SUITS] = { 'C', 'D', 'H', 'S' };

	int cardSub = 0;    //subscript to process the deck of cards

	//Go through all 52 spots in the array of Cards and put a card
	//at the location

	for( int suitSub = 0; suitSub < NUM_SUITS; suitSub++ )
	{
		//For each of the suits, put in all of the cards for the suit
		for( int faceVal = 1; faceVal <= CARDS_PER_SUIT; faceVal++ )
		{	
			//Put the card into the deck
			deck[ cardSub ].setCard( faceVal, suitVals[suitSub] );

			//Move to the next card in the deck    
			cardSub++;
		}
	}


	//Set the top card location to -1 to indicate the deck is brand new

	topCard = -1;
}



/***************************************************************
Method:  Card draw()

Use: This method draws a card from the top of the deck

Arguments: none

Returns: a Card object (the card on the top of the deck)
***************************************************************/

Card DeckOfCards::draw()
{
	//Increment to get the subscript of the current top card
	topCard++;

	//return the card that is currently on the top of the deck
	return deck[topCard];
}



/***************************************************************
Method:  void shuffle()

Use: This method shuffles the deck of cards

Arguments: none

Returns: nothing

Note: this method uses the random_shuffle function that is part
      of the algorithm library to shuffle the 52 cards
***************************************************************/

void DeckOfCards::shuffle()
{
	//Shuffle all 52 cards that are in the deck

	random_shuffle(deck, deck+MAX_CARDS);
}


/***************************************************************
Method:  bool isEmpty()

Use: This method determines if the deck of cards is empty( have
     all of the cards been drawn)

Arguments: none

Returns: boolean value: true if all of the cards have been drawn
                        false if there are still cards in the deck
***************************************************************/

bool DeckOfCards::isEmpty()
{
	return topCard + 1 == MAX_CARDS;
}