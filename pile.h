#ifndef Pile_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "deck.h"

class Pile {

    public:

        void flipPile();            // for pile reset

        Card draw();

        bool isEmpty();

        vector<Card> getPile();

        Pile(Deck& d, bool firstHalf);

    private:

        vector<Card> pile;
        vector<Card> faceUp;        // for wins
        vector<Card> faceDown;      // for ties
        Card top;

};

#endif