#include <iostream>
#include <vector>
#include <algorithm>
#include "pile.h"

void Pile::newPile(){

    reverse(this->faceUp.begin(), this->faceUp.end());

    pile = faceUp;
    top = pile.back();
    faceUp.clear();
}

Card Pile::draw(){

    Card draw = this->pile.back();
    this->pile.pop_back();

    return draw;
}

void Pile::appFaceUp(Card& opp, Card& drw){

    this->faceUp.push_back(opp);
    this->faceUp.push_back(drw);
}

void Pile::appFaceDown(Card& drw){

    this->faceDown.push_back(drw);
}

bool Pile::isEmptyPile(){

    return this->pile.empty();
}

bool Pile::isEmptyFaceUp(){

    return this->faceUp.empty();
}

vector<Card> Pile::getPile(){

    return pile;
}

void Pile::faceDownWon(vector<Card> oppFD){

    for(Card c: oppFD){
        this->faceUp.push_back(c);
    }

    for(Card c: faceDown){
        this->faceUp.push_back(c);
    }

    faceDown.clear();
}

vector<Card> Pile::faceDownLost(){

    vector<Card> temp = faceDown;
    faceDown.clear();

    return temp;
}

void Pile::setPile(Deck d, bool firstHalf){

    vector<Card> dk = d.getDeck();

    auto mid = dk.begin() + dk.size() / 2;

    vector<Card> first(dk.begin(), mid);
    vector<Card> second(mid, dk.end());

    pile = (firstHalf) ? first : second;
    top = pile.back();

}

Pile::Pile(Deck d, bool firstHalf){
    
    this->setPile(d, firstHalf);
    
}

Pile::Pile(){
    
    vector<Card> p;

    pile = p;
    top = pile.back();

}