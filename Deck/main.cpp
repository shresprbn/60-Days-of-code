#include <iostream>
#include "card.h"
#include "Deck.h"
using namespace std;


int main() {

	Deck D1;
	D1.suffleDeck();
	for (int i = 0; i < 53; i++) {
		Card C1 = D1.takeTop();
		C1.turnCard();
		C1.ShowCard();

		}
	return 0;
}
