#ifndef War_H
#define War_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "player.h"

using namespace std;

class War {

    public:

        void run();

        void prerun();

        War(ifstream& inFile, string fn, Deck d);

        War();

    private:

        Deck deck;
        Player p1;
        Player p2;

        

};

#endif