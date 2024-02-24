#include <iostream>
#include <string>
#include "card.h"

using namespace std;

int Card::getRank(){
	return rank;
}

string Card::getSuit(){
	return suit;
}


string Card::strValue(){

	int r = this->rank;

	if(r == 1){
		return "Ace";
	} else if(r == 11){
		return "Jack";
	} else if(r == 12){
		return "Queen";
	} else if(r == 13){
		return "King";
	} else {
		return to_string(r);
	}

	return "";
}

ostream& operator << (ostream& os, Card& card){

	os << card.strValue() << " of " << card.getSuit();

	return os;
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


Card& Card::operator = (const Card& card){

	rank = card.rank;
	suit = card.suit;

	return *this;
}

Card::Card(int r, string s){
	rank = r;
	suit = s;
}

Card::Card(){
	rank = 1;
	suit = "Unknown";
}



