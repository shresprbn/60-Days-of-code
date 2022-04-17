#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Card {
	int Heart = 1, Diamond = 2, Spade = 3, Club = 4, check = 23;
	int suit;
	int Value;
	bool colour;
	bool face;
	bool hidden;

	bool initializeColour(int ThisCard) {
		if (ThisCard == Heart || ThisCard == Diamond) {
			return true;
		}
		else {
			return false;
		}
	}
	bool initializeFace(int Value) {
		if (Value > 10 || Value == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	// Heart = 1, Diamond = 2, Spade = 3, Club = 4
	string whatSuit(int suit) {
		switch (suit) {
		case 1:
			return "Heart";
			break;
		case 2:
			return "Diamond";
			break;
		case 3:
			return "Spade";
			break;
		case 4:
			return "Club";
			break;
		case 23:
			return "check";
		default:
			break;

		}
	}
public:
	Card() {
		int card, Valu;
		srand(time(NULL));
		card = rand() % 3;
		Valu = rand() % 13;
		Value = Valu + 1;
		suit = card + 1;
		colour = initializeColour(suit);
		face = initializeFace(Value);
		hidden = true;

	}
	Card(int card, int Valu) {
		Value = Valu;
		suit = card;
		colour = initializeColour(suit);
		face = initializeFace(Value);
		hidden = true;
	}
	void turnCard() {
		if (hidden)
			hidden = false;
		else
			hidden = true;
	}
	int giveValue() {
		if (Value > 9) {
			return 10;
		}
		else
		{
			return Value;
		}
	}
	void ShowCard() {
		if (hidden == false) {
			if (face) {
				if (Value == 1) {
					cout << "Ace of ";
				}
				if (Value == 11) {
					cout << "Jack of ";
				}
				if (Value == 12) {
					cout << "Queen of ";
				}

				if (Value == 13) {
					cout << "King of ";
				}
			}
			else {
				cout << Value << " of ";
			}

			cout << whatSuit(suit);
		}
	}

};
