#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "war.h"

using namespace std;

void printCards(Deck& d) {
    int cardCount = 0;
    vector<Card> cards = d.getDeck();
    const int columnWidth = 20;

    for (auto& card : cards) {
        cout << setw(columnWidth) << left << card.strValue() + " of " + card.getSuit();
        ++cardCount;

        if (cardCount % 4 == 0) {
            cout << endl;
        }
    }
}

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){

    Deck deck;
    char op;
    string filename;
    ifstream inFile;

    cout << "ENTER FILENAME OF PLAYERNAMES: ";
    getline(cin, filename);
    cout << "\n\n";

    printCards(deck);
    
    cout << "Would you like to SHUFFLE the deck? (Y/N): ";
    cin >> op;

    while(tolower(op) == 'y'){
        clearScreen();
        deck.shuffle();
        cout << "\nShuffled Deck:\n" << endl;

        printCards(deck);
        cout << "Would you like to RE-SHUFFLE the deck? (Y/N): ";
        cin >> op;

    }

    clearScreen();

    War game(inFile, filename, deck);

    game.prerun();
    cout << '\n';

    cout << "Press ENTER to start the game..." << "\n\n";
    cin.get();
    cin.ignore(100, '\n');

    clearScreen();

    game.run();

    return 0;
}
