#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "player.h"

using namespace std;

Card Player::drawTop(){
    
    return this->playerPile.draw();
}

void Player::playerTurnWin(Card& opCard, Card& drw){

    this->playerPile.appFaceUp(opCard, drw);
}

Card Player::playerTurnLose(Card& drw){

    return drw;
}

void Player::playerTieWin(vector<Card> oppFD){

    this->playerPile.faceDownWon(oppFD);
}

vector<Card> Player::playerTieLose(){

    this->playerPile.faceDownLost();
}

bool Player::hasLost(){

    return this->playerPile.isEmptyPile() && this->playerPile.isEmptyFaceUp();
}

Player::Player(string name, int n, Deck d){
    
    if(n == 1){
        this->playerPile.setPile(d, true);
    } else {
        this->playerPile.setPile(d, false);
    }

    playerName = name;
    playerNo = n;
}