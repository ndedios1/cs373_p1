//program1.cpp//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Card.h"

using namespace std;

int findMPrice(string name, vector<Card> m){
	for(int i = 0; i < m.size(); i++){
		if(m.at(i).getName() == name){
			cout << "Found " << name << "\n";
			cout << "Price: " << m.at(i).getPrice() << "\n";
			return m.at(i).getPrice();
		}

	}
	cout << "Error: card does not exist in the market \n";
	return 0; 
}	

vector<Card> computeMaxProfit(vector<Card> g, vector<Card> m,  int weight, int* p){
	int maxProfit = 0;
	vector<Card> S;
	vector<Card> M;
	int sum;
	for(int j=0; j < g.size(); j++){
		sum += g.at(j).getPrice();
	}
	if(sum <= weight){
		int iprofit =0;
		for(int k =0; k < g.size(); k++){
			iprofit += findMPrice(g.at(k).getName(), m) - g.at(k).getPrice();	
		cout << "Gertrude's Price: " << g.at(k).getPrice() << "\n" ;
		M.push_back(g.at(k));
		}
		iprofit+= weight;
		maxProfit = iprofit;
		*p = maxProfit;
		cout << "This is the total profit: " << iprofit << "\n";
		return M;
	}
	cout << sum << "\n";
	cout << "finished\n";
	return M;
}

int main(){
	int output1, output2, output3, output4;
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
	vector<Card> gcards;
	int allowance;
	if(gertrude.is_open()){
		getline(gertrude, g_text, ' ');
		g_cards_num = stoi(g_text);
		cout << "number of Gertrude's cards: " << g_cards_num << "\n";
		getline(gertrude, g_text);
		allowance = stoi(g_text);
		cout << "allowance: $" << allowance << "\n";
		int index = g_cards_num;
		//getline(gertrude, g_text);
		string g_name;
		int g_price;
		while(index !=0){
			getline(gertrude, g_text, ' ');
			g_name = g_text;
			getline(gertrude, g_text);
			g_price = stoi(g_text);
			//cout << "name: " << g_name << "\n";
			//cout << "price: " << g_price << "\n";
			Card g = Card(g_name, g_price);
			gcards.push_back(g);
			g.printCard();
			index--;
		}

	}

	gertrude.close();	
	int mProfit=0;
	computeMaxProfit(gcards, market, allowance, &mProfit);
	cout << "mProfit: " << mProfit << "\n";

	//writes to the output.txt file
	ofstream output;
	output1 = g_cards_num;
	output.open("output.txt");
	if(output.is_open()){
		output << output1;
	}
	output.close();
	return 0;
}
