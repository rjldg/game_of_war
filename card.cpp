#include <iostream>
#include <cassert>
#include <string>
#include "card.h"
#include "game.h"

using namespace std;

int Card::getRank(){
	return rank;
}

string Card::getSuit(){
	return suit;
}

Card::Card(int r, int s){
	rank = r;
	suit = s;
}

Card::Card(){
	rank = 0;
	suit = "";
}

ostream& operator << (ostream& os, const Card& card){
	os << card.rank << " of " << card.suit;
}

bool operator == (const Card& c1, const Card& c2){
	return c1.rank == c2.rank;
}

bool operator > (const Card& c1, const Card& c2){
	return c1.rank > c2.rank;
}

bool operator < (const Card& c1, const Card& c2){
	return c1.rank < c2.rank;
}





