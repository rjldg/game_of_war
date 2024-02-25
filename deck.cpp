#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "deck.h"

using namespace std;

Card Deck::draw(){

    Card draw = this->deck.back();
    this->deck.pop_back();

    return draw;
}

void Deck::shuffle(){
    
    random_shuffle(this->deck.begin(), this->deck.end());

}

bool Deck::isEmpty(){

    return this->deck.empty();
}

vector<Card> Deck::getDeck(){
    
    return deck;
}

Deck::Deck(){

    string suits[4] = {"♣", "♦", "♥", "♠"};
    int r = 1;

    // "♥", "♦", "♣", "♠"

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 13; ++j){
            deck.push_back(Card(r, suits[i]));
            ++r;
        }
        r = 1;
    }

    top = deck.back();
}