/*Card.h*/

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Card{
	public:
		Card();
		Card(string name, int price, int mprice);
		Card(string name, int  market_price);
		string getName();
		int getPrice();
		int getMarketPrice();
		void printCard();
	private:
		string name;
		int price;
		int mprice;
};
#endif

