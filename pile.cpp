#include <iostream>
#include <vector>
#include <algorithm>
#include "pile.h"

void Pile::newPile(){

    if (!faceUp.empty()) {

        reverse(faceUp.begin(), faceUp.end());
        pile = move(faceUp);

        if (!pile.empty()) {
            top = pile.back();
        } else {
            cerr << "Error: pile is empty after newPile()" << endl;
        }
    } else {
        cerr << "Error: faceUp vector is empty in newPile()" << endl;
    }
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

int Pile::getPileSize(){

    return pile.size();
}


int Pile::getFaceUpSize(){

    return faceUp.size();
}


void Pile::faceDownWon(vector<Card> oppFD, vector<Card> drwFD){

    for(Card c: oppFD){
        this->faceUp.push_back(c);
    }

    for(Card c: drwFD){
        this->faceUp.push_back(c);
    }

    this->faceDown.clear();
}

void Pile::faceDownLost(){

    //vector<Card> temp = faceDown;
    faceDown.clear();

    //return temp;
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
    Card c;

    pile = p;
    top = c;

}