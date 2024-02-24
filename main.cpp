#include <iostream>
#include <fstream>
#include <string>
#include "war.h"

using namespace std;

int main(){

    Deck deck;
    char op;
    string filename;
    ifstream inFile;

    cout << "Enter filename of player names: ";
    getline(cin, filename);
    
    cout << "Would you like to shuffle the deck? (Y/N)" << endl;
    cin >> op;

    while(tolower(op) == 'y'){
        deck.shuffle();
        cout << "Would you like to shuffle the deck? (Y/N)" << endl;
        cin >> op;
    }

    War game(inFile, filename, deck);

    game.run();

    return 0;
}
