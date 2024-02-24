#include <iostream>
#include <vector>
#include <algorithm>
#include "pile.h"

void Pile::flipPile(){

    reverse(this->faceUp.begin(), this->faceUp.end());
}

Card Pile::draw(){

    Card draw = this->pile.back();
    this->pile.pop_back();

    return draw;
}

bool Pile::isEmpty(){

    return this->pile.empty();
}

vector<Card> Pile::getPile(){

    return pile;
}

Pile::Pile(Deck& d, bool firstHalf){

    vector<Card> dk = d.getDeck();

    auto mid = dk.begin() + dk.size() / 2;

    vector<Card> first(dk.begin(), mid);
    vector<Card> second(mid, dk.end());

    pile = (firstHalf) ?  first : second;
}