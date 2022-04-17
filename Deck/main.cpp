#include <iostream>
#include "card.h"
#include "Deck.h"
#include "blackjack.cpp"
using namespace std;


int main() {
	Deck deck;
	char a;
	bool padd = true;
	deck.suffleDeck();
	Player Dealer;
	Player P;
	for (int j = 0; j < 2; j++) {
		Dealer.requestCard(deck.takeTop());
		P.requestCard(deck.takeTop());
	}
	P.showHand();
	P.getTotal();
	P.showTotal();
	while (P.status() == false && padd == true) {
		P.playerLosing();
		cout << "Do you want to add a card?";
		cin >> a;



		if (a == 'y') {
			P.requestCard(deck.takeTop());
		}
		if (a == 'n') {
			padd = false;
		}
		P.showHand();
		P.getTotal();
		P.showTotal();
	}
	if (P.status() == false) {
		Dealer.showHand();
		Dealer.getTotal();
		Dealer.showTotal();
		int playerTotal = P.giveTotal();
		while(playerTotal > Dealer.giveTotal()) {
			Dealer.requestCard(deck.takeTop());
			Dealer.playerLosing(Dealer,P);
			if (Dealer.status() == true) {
				cout << "you Won";
				break;
			}
		}

	}
	return 0;
}
