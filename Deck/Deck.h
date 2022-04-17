#pragma once
#include <iostream>
#include "card.h"
#include <ctime>
#include <cstdlib>
using namespace std;

class Deck {
private:
    struct Track {
        int value;
        Track* next;

        Track(int val) {
            value = val;
        }
    };
    struct Node {
        Card top;
        Node* next;

        Node(Card c1) {
            top = c1;
        }

        Node(Card c1, Node* nextNode) {
            top = c1;
            next = nextNode;
        }
    };
    Node* head, * tail;
    Track* head2,*tail2;
    int size2;
    int size;

    void insertBeg(Card c1) {
        Node* node = new Node(c1);
        node->next = head;
        head = node;

        // if list is empty
        if (tail == NULL) {
            tail = head;
        }
        size++;
    }
    void insertBeg(int c1) {
        Track* node = new Track(c1);
        node->next = head2;
        head2 = node;

        // if list is empty
        if (tail2 == NULL) {
            tail2 = head2;
        }
        size++;
    }
    void initializeDeck() {
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                Card c1 = Card(i, j);
                insertBeg(c1);
            }
        }
    }
public:
    Deck() {
        size = 0;
        head = tail = NULL;
        initializeDeck();
    }
    Card takeTop() {
        if (!head) {
            cout << "List is empty\n";
            return Card(23, 2);
        }
        Card val = head->top;
        head = head->next;

        // if there was only 1 node
        if (head == NULL) {
            tail = NULL;
        }
        size--;
        return val;
    }
    void emptyDeck() {
        do {
            Node *prevHead = head;
            head = head->next;
            delete prevHead;
            size--;
        } while (head != NULL);
    }
    void suffleDeck() {
        emptyDeck();
        int temp;
        int size = 0;
        for (size = 1; size <= 52; size++) {
            bool isThere = false;
            srand(time(NULL));
            temp = rand() % 52 + 1;
            cout << temp << "\n";
            Track* tempTrack = head2;
            if (tempTrack == NULL) {
                isThere = false;
            }
            else {
                while (tempTrack != NULL) {
                    if (tempTrack->value == temp) {
                        isThere = true;
                }
                    tempTrack = tempTrack->next;
                }
            }
            if (isThere == false ) {
                insertBeg(temp);
                Card card(temp % 4 + 1, temp % 13 + 1);
                insertBeg(card);
            }
        }
    }


};