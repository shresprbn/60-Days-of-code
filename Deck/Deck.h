#pragma once
#include <iostream>
#include "card.h"
#include <random>
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
    int t = 0;

    
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
   
public:
    Deck() {
        size = 0;
        head = tail = NULL;
        initializeDeck();
    }
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
    void initializeDeck() {
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                Card c1 = Card(i, j);
                insertBeg(c1);
            }
        }
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
        while (size < 52) {
            bool isThere = false;
            random_device rd;       //random number gen that is fast
            mt19937 gen(rd());
            temp = gen() % 52 + 1;
            //   cout << temp << "\n";
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
            if (isThere == false) {
                insertBeg(temp);
                t++;
                //cout << t;
                Card card(temp % 4 + 1, temp % 13 + 1);
                insertBeg(card);
                size++;
            }
        }
    }
    
    int getTotal() {
        int sum = 0;
        Node* temp = head;
        while (temp!=NULL)
        {
            sum += temp->top.giveValue();
            temp = temp->next;
        }
      
        return sum;
   }
    void showDeck() {
        Node* temp = head;
        Card tempCard;
        while (temp!=NULL)
        {
            tempCard = temp->top;
            tempCard.turnCard();
            tempCard.ShowCard();
            cout << "\n";
            temp = temp->next;
        }
    }
};