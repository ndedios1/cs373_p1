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
		while(getline(marketfile, myText, ' ')){
			string name = myText;
			//cout << "This is the name: " << name << "\n";
			getline(marketfile, myText);
			int price = stoi(myText);
			//cout << "This is the price: " << price << "\n";
			Card m = Card(name,price);
			m.printCard();
			market.push_back(m);
			cout << "Card added to market!\n";
		}
		marketfile.close();
		cout << "here2";
	}
	return;
}

int main(){
	//fstream marketfile("market_price.txt");
	//int line_num = 0;	//line being read in market_price.txt
	//int cards;		//amount of cards in market_price.txt
	//string myText;
	vector<Card> market;
	//Adds cards to the market
	//if(marketfile.is_open()){
	//	getline(marketfile, myText);
	//	cards = stoi(myText);
	//	while(getline(marketfile, myText, ' ')){
	//		string name = myText;
	//		//cout << "This is the name: " << name << "\n";
	//		getline(marketfile, myText);
	//		int price = stoi(myText);
	//		//cout << "This is the price: " << price << "\n";
	//		Card m = Card(name,price);
	//		m.printCard();
	//		market.push_back(m);
	//		cout << "Card added to market!\n";
	//	}
	//	marketfile.close();
//	}
//	cout << "The amount of cards in Market: " << cards << "\n";
	create_market("market_price.txt", market);
	for(int i=0 ; i<market.size(); i++){
		cout << market.at(i).getName() << "\n";
		cout << "here\n";
	}
	//fstream gertrude("price_list.txt");
			
	
	
	//writes to the output.txt file
	ofstream output;
	output.open("output.txt");
	if(output.is_open()){
		output << "Hello World!!\n";
	}
	output.close();
	return 0;
}
