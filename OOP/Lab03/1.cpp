#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char suit[4][13]={"\xE2\x99\xA0","\xE2\x99\xA5","\xE2\x99\xA6","\xE2\x99\xA3"};

char num[13][3]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

struct Card{
	char num[3];
	char suit[13];
};

void getCards(struct Card *cards){
	int x=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++){
			strcpy(cards[x].num,num[j]);
			strcpy(cards[x].suit,suit[i]);
			x++;
		}
}

void displayCards(struct Card cards[52]){
	int x=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			printf("%s%s ",cards[x].suit,cards[x].num);
			x++;
		}
		printf("\n");
	}
}

void swapCards(struct Card &card1,struct Card &card2){
	struct Card tmp;
	tmp=card1;
	card1=card2;
	card2=tmp;
}

void shuffleCards(struct Card *cards){
	for(int i=0;i<52;i++){
		int x=rand()%52;
		int y=rand()%52;
		swapCards(cards[x],cards[y]);
	}
}

int main(){
	srand(time(NULL));

	struct Card *cards;
	cards = new Card [52];

	getCards(cards);
	displayCards(cards);

	shuffleCards(cards);
	displayCards(cards);

	return 0;
}
