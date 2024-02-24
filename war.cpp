#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "war.h"

using namespace std;

void War::run(){

    vector<Card> p1FD, p2FD;
    Card c1, c2;

    while(!p1.hasLost() && !p2.hasLost()){
        
        if(p1.hasEmptyPile()){
            cout << p1.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
            p1.turnOverNewPile();
            //cout << "reaches here 4" << endl;
        }
        
        if(p2.hasEmptyPile()){
            cout << p2.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
            p2.turnOverNewPile();
            //cout << "reaches here 4" << endl;
        }

        c1 = p1.drawTop();
        c2 = p2.drawTop();

        //cout << "reaches here inf" << endl;

        if(c1 < c2){
            cout << p1.getName() << " won this turn." << endl;
            cout << c1 << " beats " << c2 << endl;
            p1.playerTurnWin(c2, c1);
        } else if(c2 < c1){
            cout << p2.getName() << " won this turn." << endl;
            cout << c2 << " beats " << c1 << endl;
            p2.playerTurnWin(c1, c2);
        } else {

            cout << "Tie, all similar-ranked cards are faced-down. Drawing again..." << endl;
            p1FD.push_back(c1);
            p2FD.push_back(c2);

            if(p1.hasEmptyPile()){
                cout << p1.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
                p1.turnOverNewPile();
                //cout << "reaches here 3" << endl;
            } 
            
            if(p2.hasEmptyPile()){
                cout << p2.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
                p2.turnOverNewPile();
                //cout << "reaches here 3" << endl;
            }    

            c1 = p1.drawTop();
            c2 = p2.drawTop();

            //cout << "reaches here inf" << endl;

            while(c1 == c2){

                cout << "Tie again, faced down drawn cards. Drawing again..." << endl;     

                if(p1.hasEmptyPile()){
                    cout << p1.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
                    p1.turnOverNewPile();
                    //cout << "reaches here 2" << endl;
                }
                
                if(p2.hasEmptyPile()){
                    cout << p2.getName() << " has empty pile. Turning over face-up cards for a new pile..." << endl;
                    p2.turnOverNewPile();
                    //cout << "reaches here 2" << endl;
                }

                p1FD.push_back(c1);
                p2FD.push_back(c2);

                c1 = p1.drawTop();
                c2 = p2.drawTop(); 

                //cout << "reaches here inf" << endl;
            }

            if(c1 < c2){
                cout << p1.getName() << " won this turn. All faced-down cards are rewarded." << endl;
                cout << c1 << " beats " << c2 << endl;
                p1.playerTieWin(p2FD);
                p2.playerTieLose();
                p1.playerTurnWin(c2, c1);
            } else if(c2 < c1){
                cout << p2.getName() << " won this turn. All faced-down cards are rewarded." << endl;
                cout << c2 << " beats " << c1 << endl;
                p2.playerTieWin(p1FD);
                p1.playerTieLose();
                p2.playerTurnWin(c1, c2);
            }

            
        }

        p1FD.clear(); p2FD.clear();

    }

    if(p1.hasLost()){
        cout << p2.getName() << " has won!" << endl;
    } else if(p2.hasLost()){
        cout << p1.getName() << " has won!" << endl;
    }
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