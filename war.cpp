#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "war.h"

using namespace std;

void War::run(){

    vector<Card> p1FD, p2FD;
    Card c1, c2;
    int turn = 1;

    while(!p1.hasLost() && !p2.hasLost()){
        cout << string(23, '*') << " TURN " << turn << " " << string(22 + to_string(turn).size(), '*') << "\n\n";
        
        if(p1.hasEmptyPile()){
            cout << p1.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
            p1.turnOverNewPile();
        }
        
        if(p2.hasEmptyPile()){
            cout << p2.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
            p2.turnOverNewPile();
        }

        c1 = p1.drawTop();
        c2 = p2.drawTop();


        if(c1 < c2){
            cout << p1.getName() << " won this turn." << endl;
            cout << c1 << " beats " << c2 << endl;
            p1.playerTurnWin(c2, c1);
        } else if(c2 < c1){
            cout << p2.getName() << " won this turn." << endl;
            cout << c2 << " beats " << c1 << endl;
            p2.playerTurnWin(c1, c2);
        } else {

            cout << "Tie, " << c1 << " is tied with " << c2 << ", all similar-ranked cards are faced-down. Drawing again..." << endl;
            p1FD.push_back(c1);
            p2FD.push_back(c2);

            if(p1.hasEmptyPile()){
                cout << p1.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
                p1.turnOverNewPile();
            } 
            
            if(p2.hasEmptyPile()){
                cout << p2.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
                p2.turnOverNewPile();
            }    

            c1 = p1.drawTop();
            c2 = p2.drawTop();


            while(c1 == c2){

                cout << "Tie again, "  << c1 << " is tied with " << c2 << ", faced down drawn cards. Drawing again..." << endl;     

                if(p1.hasLost() || p2.hasLost()){
                    break;
                }

                if(p1.hasEmptyPile()){
                    cout << p1.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
                    p1.turnOverNewPile();
                }
                
                if(p2.hasEmptyPile()){
                    cout << p2.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
                    p2.turnOverNewPile();
                }

                p1FD.push_back(c1);
                p2FD.push_back(c2);

                c1 = p1.drawTop();
                c2 = p2.drawTop(); 

            }

            if(c1 < c2){
                cout << p1.getName() << " won this turn. All faced-down cards are rewarded." << endl;
                cout << c1 << " beats " << c2 << endl;
                p1.playerTieWin(p2FD, p1FD);
                p2.playerTieLose();
                p1.playerTurnWin(c2, c1);
            } else if(c2 < c1){
                cout << p2.getName() << " won this turn. All faced-down cards are rewarded." << endl;
                cout << c2 << " beats " << c1 << endl;
                p2.playerTieWin(p1FD, p2FD);
                p1.playerTieLose();
                p2.playerTurnWin(c1, c2);
            }

            
        }

        p1FD.clear(); p2FD.clear();

        cout << "\n" << p1 << endl;
        cout << p2 << "\n\n";

        ++turn;

        cout << string(55 + to_string(turn).size(), '*') << "\n\n";

    }

    

    if(p1.hasLost() && p2.hasLost()){
        cout << p1.getName() << " and " << p2.getName() << "are tied. Nobody won." << endl;
    }
    else if(p1.hasLost()){
        cout << p2.getName() << " has won!" << endl;
    } else if(p2.hasLost()){
        cout << p1.getName() << " has won!" << endl;
    }

    
}

void War::prerun(){

    cout << "GAME OF WAR: " << p1.getName() << " vs. " << p2.getName() << endl;
}

War::War(ifstream& inFile, string fn, Deck d){

    string name;

    inFile.open(fn);

    inFile >> name;
    this->p1.setPlayer(name, 1, d);

    inFile >> name;
    this->p2.setPlayer(name, 2, d);

    inFile.close();

}

War::War(){

    Deck d;
    Player one, two;

    deck = d;
    p1 = one;
    p2 = two;
}