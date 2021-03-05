/*Card.cpp*/

#include <sstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Card.h"

using namespace std;

Card::Card(){
	name;
	price;
	mprice;
}

Card::Card(string n, int price, int market_price){
	name = n;
	price = price;
	mprice = market_price;
}

Card::Card(string n, int market_price){
	name = n;
	mprice = market_price;
}

string Card::getName(){
	return name;
}

int Card::getPrice(){
	return price;
}

int Card::getMarketPrice(){
	return mprice;
}

void Card::printCard(){
	cout << "Name: " << name << " Market Price: " << mprice << "\n";
}
