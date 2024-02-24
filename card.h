#ifndef Card_H
#define Card_H

#include <iostream>

using namespace std;

class Card {
	
	friend ostream& operator<<(ostream&, Card&);

	friend bool operator == (const Card&, const Card&);
	friend bool operator > (const Card&, const Card&);
	friend bool operator < (const Card&, const Card&);

	public:
		
		Card& operator = (const Card& card);

		int getRank();
		
		string getSuit();

		string strValue();

		Card(int r, string s);

		Card();
		
	
	private:
		
		int rank;
		string suit;
		
	
	
};







#endif
