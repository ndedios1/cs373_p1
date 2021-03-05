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
		Card(string name, int mprice);
		string getName();
		int getPrice();
		void printCard();
	private:
		string name;
		int price;
};
#endif

