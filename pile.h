#ifndef Pile_H
#define Pile_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "deck.h"

class Pile {

    public:

        void newPile();            // for face-up pile reset

        Card draw();

        void appFaceUp(Card& opp, Card& drw);

        void appFaceDown(Card& drw);

        void faceDownWon(vector<Card> oppFD, vector<Card> drwFD);

        void faceDownLost();    // probably better if void

        bool isEmptyPile();

        bool isEmptyFaceUp();

        vector<Card> getPile();

        int getPileSize();

        int getFaceUpSize();

        void setPile(Deck d, bool firstHalf);

        Pile(Deck d, bool firstHalf);

        Pile();

    private:

        vector<Card> pile;
        vector<Card> faceUp;        // for wins
        vector<Card> faceDown;      // for ties
        Card top;

};

#endif