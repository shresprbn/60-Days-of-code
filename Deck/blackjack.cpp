#include "deck.h"
#include <iostream>
#include "card.h"
class Player {
private:
	Deck D1;
	int count;
	bool lose;
	int total;
public:
	Player() {
		count = 0;
		total = 0;
		lose = false;
		D1.emptyDeck();
	}
	void getTotal() {
		total = D1.getTotal();		
	}
	int giveTotal() {
		return total;
	}
	bool status() {
		return lose;
	}
	void playerLosing() {
		if (total > 21) {
			lose = true;
		}
	}
	void requestCard(Card C1) {
		D1.insertBeg(C1);
	}
	void playerLosing(Player P, Player Dealer) {
		if (Dealer.total > P.total && Dealer.total < 21) {
			P.lose = true;
		}
	}
	void showHand() {
		D1.showDeck();
	}
	void showTotal() {
		cout << "\n" << total;
	}
};