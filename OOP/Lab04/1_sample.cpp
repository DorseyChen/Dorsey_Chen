#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char SUIT[4][13] = {"\xE2\x99\xA0","\xE2\x99\xA5","\xE2\x99\xA6","\xE2\x99\xA3"};
char NUM[13][3] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

class Card {
	private:
		char suit[13];
		short num;
		
	public:
		Card() { /* nothing */ };

        // Create a Card with given suit and number
		Card(char* su, short nu); 

        // Set a blank card's suit and number
		void set(char* su, short nu);

        // Swap a Card itself with another Card (tar)
		void swap(Card& tar);
                       
		// To print a Card on screen
		void show();
};
class A_Deck_Of_Cards {
	private:
		Card* cards;
	public:
        // Initialize "cards" with dynamic array of 52 Cards
        // with their own suits and numbers
		A_Deck_Of_Cards();

        // shuffle "cards"
		void shuffle();

        // Display the cards on the screen
		void show();
};

/* Main Function */
int main() {
	srand(time(NULL));
	
	A_Deck_Of_Cards Dcards;
	
	puts("------ Before Shuffle -----");
	Dcards.show();
	Dcards.shuffle();
	puts("------ After Shuffle ------");
	Dcards.show();
	
	return 0;
}


/* Methods of Card */
Card::Card(char* su, short nu) {
	set(su, nu);
}

void Card::set(char* su, short nu) {
	strcpy(suit, su);
	num = nu;
}

void Card::swap(Card& tar) {
	// Write here
}

void Card::show() {
	printf("%s%-2s",suit,NUM[num]);
}

/* Methods of A_Deck_Of_Cards */
A_Deck_Of_Cards::A_Deck_Of_Cards() {
	cards = new Card[52];
	for(short i=0; i<52 ;i++)
		cards[i].set(SUIT[i/13],i%13);
}

void A_Deck_Of_Cards::shuffle() {
	// Write here
}

void A_Deck_Of_Cards::show() {
	for(int i=0; i<52 ;i++) {
		cards[i].show();
		(i+1)%13 ? printf(" ") : puts("");
	}
}
