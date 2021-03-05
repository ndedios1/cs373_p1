//program1.cpp//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Card.h"

using namespace std;

//vector<int> computeMaxProfit(vector<string[]>

void create_market(string m_file, vector<Card> market){
	fstream marketfile(m_file);
	int line_num = 0;
	int cards;
	string myText;
	if(marketfile.is_open()){
		getline(marketfile, myText);
		cards = stoi(myText);
		while(cards != 0){
			getline(marketfile, myText, ' ');
			string name = myText;
			//cout << "This is the name: " << name << "\n";
			getline(marketfile, myText);
			int price = stoi(myText);
			//cout << "This is the price: " << price << "\n";
			Card m = Card(name,price);
			//m.printCard();
			market.push_back(m);
			cout << "Card added to market!\n";
			cards--;
			//cout << cards << "\n";
		}
		marketfile.close();
	}
	return;
}

int main(){
	fstream marketfile("market_price.txt");
	int line_num = 0;	//line being read in market_price.txt
	int cards;		//amount of cards in market_price.txt
	string myText;
	vector<Card> market;
	//Adds cards to the market
	if(marketfile.is_open()){
		getline(marketfile, myText);
		cards = stoi(myText);
		while(getline(marketfile, myText, ' ')){
			string name = myText;
			//cout << "This is the name: " << name << "\n";
			getline(marketfile, myText);
			int price = stoi(myText);
			//cout << "This is the price: " << price << "\n";
			Card m = Card(name,price);
			//m.printCard();
			market.push_back(m);
			cout << "Card added to market!\n";
		}
		marketfile.close();
	}
	//cout << "The amount of cards in Market: " << market.size() << "\n";
	//create_market("market_price.txt", market);
	cout << "The amount of cards in Market: " << market.size() << "\n";
	for(int i=0 ; i<market.size(); i++){
		cout << market.at(i).getName() << "\n";
	}
	fstream gertrude("price_list.txt");
	string g_text;
	int g_cards_num;
	if(gertrude.is_open()){
		getline(gertrude, g_text, ' ');
		g_cards_num = stoi(g_text);
		cout << "number of Gertrude's cards: " << g_cards_num << "\n";
		getline(gertrude, g_text);
		int allowance = stoi(g_text);
		cout << "allowance: $" << allowance << "\n";
		int index = g_cards_num;
		//getline(gertrude, g_text);
		while(index !=0){
			getline(gertrude, g_text);
			cout << g_text << "\n";
			index--;
		}

	}
	
//	vector<Card> g_cards;
//	string g_name;
//	for(int i=0; i < g_cards_num; i++){
//		getline(gertrude, g_name, ' ');
//		cout << "This is the name: " << g_name << "\n";
//		getline(gertrude, g_text);
//		int g_price = stoi(g_text);
//		Card g = Card(g_name, g_price);
//		g_cards.push_back(g);
		//g_cards.at(i).printCard();
//	}

	gertrude.close();	
	
	//writes to the output.txt file
	ofstream output;
	output.open("output.txt");
	if(output.is_open()){
		output << "Hello World!!\n";
	}
	output.close();
	return 0;
}
