#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "player.h"

using namespace std;

void Player::turnOverNewPile(){

    this->playerPile.newPile();
}

Card Player::drawTop(){
    
    return this->playerPile.draw();
}

void Player::playerTurnWin(Card& opCard, Card& drw){

    this->playerPile.appFaceUp(opCard, drw);
}

Card Player::playerTurnLose(Card& drw){

    return drw;
}

void Player::playerTieWin(vector<Card> oppFD, vector<Card> drwFD){

    this->playerPile.faceDownWon(oppFD, drwFD);
}

void Player::playerTieLose(){

    this->playerPile.faceDownLost();
}

bool Player::hasLost(){

    return this->playerPile.isEmptyPile() && this->playerPile.isEmptyFaceUp();
}

bool Player::hasEmptyPile(){

    return this->playerPile.isEmptyPile();
}

bool Player::hasEmptyFaceUp(){

    return this->playerPile.isEmptyFaceUp();
}

string Player::getName(){
    
    return playerName;
}

void Player::setPlayer(string name, int n, Deck d){

    if(n == 1){
        this->playerPile.setPile(d, true);
    } else {
        this->playerPile.setPile(d, false);
    }

    playerName = name;
    playerNo = n;
}

Pile Player::getPlayerPile(){

    return playerPile;
}

Player::Player(string name, int n, Deck d){
    
    setPlayer(name, n, d);
}

Player::Player(){

    Pile p;

    playerPile = p;
    playerName = "Unknown Player";
    playerNo = 0;
}

ostream& operator << (ostream& os, Player& p){

	os << p.getName() << " has " << p.getPlayerPile().getPileSize() << " cards in pile and "
       << p.getPlayerPile().getFaceUpSize() << " face-up cards.";

	return os;
}