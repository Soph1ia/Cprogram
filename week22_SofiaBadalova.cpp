// week22_SofiaBadalova.cpp : generates two hands(5 cards) of cards...
//compares your hand to dealers hand and decides the winner of each round of cards.

#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdarg.h"
#include "stdlib.h"
#include "time.h"

typedef enum S { CLUBS, DIAMONDS, HEARTS, SPADES } SUIT;
char suits[][10] = { "CLUBS", "DIAMONDS", "HEARTS", "SPADES" };

typedef enum F { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } FACE;
char faces[][10] = { "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING", "ACE" };

typedef struct
{
	SUIT suit;
	FACE face;
} card;

typedef struct
{
	card cards[5];
} hand;

// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
// so if same card already in the hand, you would need to draw again
// also, the card cannot appear in another hand either
hand dealHand(hand handsDealt[], int numHandsDealt);

// returns pointer to string containing, for example, "ACE of HEARTS"
char * printCard(card aCard);

// compares the FACE values of two cards (TWO is lowest, ACE is highest)
// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same)
char * compareCards(card yourCard, card dealersCard);

// returns true if the hand contains four ACES
bool fourAces(hand aHand);


void main()
{
	int i = 0;
	hand myHand, dealersHand; // contains the five cards each.. 
	int seed = time(NULL);
	srand(seed);
	hand hands[10];

	// deal the first hand
	myHand = dealHand(hands, 0);

	// add this new hand to the set of dealt hands
	hands[0] = myHand;

	// deal another hand; let dealHand know what has already been dealt
	dealersHand = dealHand(hands, 1);

	// here you are just comparing each card one at a time in the two hands
	while (i<5)
	{
		printf("card#%d: %s (you) vs. %s (dealer). Winner: %s \n", i + 1, printCard(myHand.cards[i]), printCard(dealersHand.cards[i]), compareCards(myHand.cards[i], dealersHand.cards[i]));
		i++;
	}

	// now try to deal 4 Aces !
	while (1)
	{
		// deal a new hand; assume new deck every time, so nothing dealt already
		myHand = dealHand(hands, 0);

		// does it contain 4 ACES?
		if (fourAces(myHand)) break;
		i++; // keep track of number of hands dealt
	}
	// print out how many hands it took to find 4 aces
	printf("\n\n4 aces found after %d hands \n\n\n", i);
}

// compares the FACE values of two cards (TWO is lowest, ACE is highest)
// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same) 
char * compareCards(card yourCard, card dealersCard)
{
	char * sptr;
	sptr = (char *)malloc(10 * sizeof(char));

	if (yourCard.face > dealersCard.face) {
		strcpy(sptr, " YOU ");
	}
	else if (yourCard.face == dealersCard.face) {
		strcpy(sptr, " DRAW ");
	}
	else{
		strcpy(sptr, " DEALER ");
	}

	return sptr;
}

// returns pointer to string containing, for example, "ACE of HEARTS"
char * printCard(card aCard)
{
	char * sptr;
	sptr = (char *)malloc(10 * sizeof(10));

	strcpy(sptr, faces[aCard.face]);
	strcat(sptr, " of ");
	strcat(sptr, suits[aCard.suit]);

	return sptr;
}

// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
// so if same card already in the hand, you would need to draw again
// also, the card cannot appear in another hand either
hand dealHand(hand handsDealt[], int numHands)
{
	int i, n;
	int found = 1;
	hand newHand;
	int ncards = 0;



	// your code goes here
	//fills cards..
	for (i = 0; i < 5; i++) {
		while (found != 0) {
			SUIT newSuit = CLUBS;	
			FACE newFace = TWO;
			newFace = FACE(int(newFace) + (rand() % 13));	// 12 for the diff type of faces		
			newSuit = SUIT(int(newSuit) + (rand() % 4));	// for 4 diff type of suits...

				//if ncards is bigger than 0, we must check if previous hands have beens similar...

				for (n = 0; n < ncards; n++) {
					if (newHand.cards[n].face == newFace && newHand.cards[n].suit == newSuit) { found = 2; }		// sets found to 2, to iterate through while loop again.
				}
				//Here deals with if card present in previous hands..
				if (numHands > 0) {
					for (n = 0; n < 5; n++) {
						if (handsDealt[0].cards[n].face == newFace && handsDealt[0].cards[n].suit == newSuit) { found = 2; }
					}
				}
				found--;					//reduces 2 to 1, so found is iterate..

			if (found == 0) {							// only if found = 0, we fill into the struct. otherwise,  
				newHand.cards[i].face = newFace;		//if found was set to 2, and then brought back to 1, it wont fill.. as it must generate new.
				newHand.cards[i].suit = newSuit;
				ncards++;
			}
		}
		found = 1;
	}
	return newHand;
}


// returns true if the hand contains four ACES
bool fourAces(hand aHand)
{
	int i;
	int numAces = 0;
	bool fourAces = false;


	for (i = 0; i < 5; i++) {
		if (aHand.cards[i].face == ACE) {
			numAces++;
		}
		if (numAces == 4) {
			fourAces = true;
		}
	}

	return fourAces;

}

