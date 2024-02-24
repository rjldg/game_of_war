#ifndef Player_H
#define Player_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "pile.h"

using namespace std;

class Player {

    public:

        void turnOverNewPile();

        Card drawTop();

        void playerTurnWin(Card& opCard, Card& drw);

        Card playerTurnLose(Card& drw);             // probably useless

        void playerTieWin(vector<Card> oppFD);

        void playerTieLose();               // probably better if void

        bool hasLost();

        bool hasEmptyPile();

        bool hasEmptyFaceUp();

        string getName();

        void setPlayer(string name, int n, Deck d);

        Player(string name, int n, Deck d);

        Player();

    private:

        Pile playerPile;
        string playerName;
        int playerNo;

};



#endif