//program1.cpp//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include "Card.h"

using namespace std;

int findMPrice(string name, vector<Card> m){
	for(int i = 0; i < m.size(); i++){
		if(m.at(i).getName() == name){
			//cout << "Found " << name << "\n";
			//cout << "Price: " << m.at(i).getPrice() << "\n";
			return m.at(i).getPrice();
		}

	}
	cout << "Error: card does not exist in the market \n";
	exit(0);
	return 0; 
}	

vector<Card> computeMaxProfit(vector<Card> g, vector<Card> m,  int weight, int* p){
	int maxProfit = 0;
	vector<Card> S;
	vector<Card> M;
	//finds the sum of Gertrude's cards
	int sum;
	for(int j=0; j < g.size(); j++){
		sum += g.at(j).getPrice();
	}	
	//If allowance is more than the cost, all cards are purchased and makes profit
	if(sum <= weight){
		int iprofit =0;
		for(int k =0; k < g.size(); k++){
			iprofit += findMPrice(g.at(k).getName(), m) - g.at(k).getPrice();	
		//cout << "Gertrude's Price: " <i< g.at(k).getPrice() << "\n" ;
		M.push_back(g.at(k));
		}
		//iprofit+= weight;
		maxProfit = iprofit;
		*p = maxProfit;
		//cout << "This is the total profit: " << iprofit << "\n";
		return M;
	}
	//checks each subset to see if there is a bigger maxProfit
	int bit;
	int i=0;
	while(i < pow(2, g.size())){
		//creates the subset
		//cout << "New Subset: \n";
		S.clear();
		for(int j=0; j<g.size(); j++){
			bit = i;
			bit >>= j;
			bit &=1;
			if(bit ==1){
				S.push_back(g.at(j));
				//g.at(j).printCard();
			}
		}
		//checks if cost is greater than allowance
		int sub_cost =0;
		for(int y=0; y < S.size(); y++){
			sub_cost += S.at(y).getPrice();
			//cout << "added " << S.at(y).getPrice() << "\n";
		}
		//if able to purchase, check profit
		if(sub_cost <= weight){
			int subset_profit = 0;
			for(int x = 0; x < S.size(); x++){
				subset_profit += findMPrice(S.at(x).getName(), m) - S.at(x).getPrice();
			}
			//if profit is bigger than max, switch
			if(subset_profit > maxProfit){
				//cout << "found bigger profit\n";
				maxProfit = subset_profit;
				*p = maxProfit;
				M = S;
			}
		}
		//cout << "End of Subset\n";
		i++;
	}
	return M;
}

int main(){
	clock_t time_req;
	int output1, output2, output3;
       	float output4;
	//reading in market file
	fstream marketfile("market_price.txt");
	int line_num = 0;	//line being read in market_price.txt
	int cards;		//amount of cards in market_price.txt
	string myText;
	//creates market vector
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
		//	cout << "Card added to market!\n";
		}
		marketfile.close();
	}
	
	cout << "The amount of cards in Market: " << market.size() << "\n";
	//prints the market cards
	for(int i=0 ; i<market.size(); i++){
		market.at(i).printCard();
	}
	fstream gertrude("price_list.txt");
	ofstream output;
	output.open("output.txt");
	string g_text;
	int big_index = -1;
	vector<Card> gcards;
	output << "Size of input\t" << "Max profit\t" << "Num of cards\t" << "Time (s)\n";
	while(!gertrude.eof()){
		time_req = clock();
		int g_cards_num = 0;
		int allowance = 0;
		if(big_index = -1){
			if(getline(gertrude, g_text, ' ')){
				g_cards_num = stoi(g_text);
				cout << "\n Number of Gertrude's cards: " << g_cards_num << "\n";
				getline(gertrude, g_text);
				allowance = stoi(g_text);
				cout << "Allowance: $" << allowance << "\n";
			}
			big_index++;
		}
		
			string g_name;
			int g_price;
			int index = g_cards_num;
			while(index != 0){
				getline(gertrude, g_text, ' ');
				g_name = g_text;
				getline(gertrude,g_text);
				g_price = stoi(g_text);
				Card g = Card(g_name, g_price);
				gcards.push_back(g);
				//g.printCard();
				index--;	
			}
			int mProfit = 0;
			vector<Card> ret_vec = computeMaxProfit(gcards, market, allowance, &mProfit);
			if(ret_vec.size() != 0){	
				cout << "\nMax Profit: " << mProfit << "\n";
				cout << "Cards that profit the most: \n";
				for(int s=0; s< ret_vec.size(); s++){
					ret_vec.at(s).printCard();
				}
			}
			//writes to the output.txt file
			output1 = g_cards_num;
			output2 = mProfit;
			output3 = ret_vec.size();
			output4 = (float)time_req/CLOCKS_PER_SEC;
			if(output.is_open() && output1 != 0){
				output << output1 << "\t\t" << output2 << "\t\t" << output3 << "\t\t" << output4 << "\n";
				for(int r = 0; r < output3; r++){
					output << ret_vec.at(r).out() << "\n";
				}
			}
			gcards.clear();
			big_index = -1;


	}
	gertrude.close();
	output.close();
	return 0;
}
