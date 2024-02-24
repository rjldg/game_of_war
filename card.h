#ifndef player_H

#include <iostream>

using namespace std;

class Card {
	
	friend ostream& operator<<(ostream&, const Card&);

	friend bool operator == (const Card&, const Card&);
	friend bool operator > (const Card&, const Card&);
	friend bool operator < (const Card&, const Card&);

	public:
		
		int getRank();
		
		string getSuit();

		Card(int r, int s);

		Card();
		
	
	private:
		
		int rank;
		string suit;
		
	
	
};







#endif
