#ifndef Deck_H

#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class Deck {

    public:
        
        Card draw();

        void shuffle();

        bool isEmpty();

        vector<Card> getDeck();

        Deck();

    private:

        vector<Card> deck;
        Card top;

};

#endif