#ifndef Player_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "pile.h"

using namespace std;

class Player {

    public:

        Card drawTop();

        void playerTurnWin(Card& opCard, Card& drw);

        Card playerTurnLose(Card& drw);

        void playerTieWin(vector<Card> oppFD);

        vector<Card> playerTieLose();

        bool hasLost();

        Player(string name, int n, Deck d);

    private:

        Pile playerPile;
        string playerName;
        int playerNo;

};



#endif