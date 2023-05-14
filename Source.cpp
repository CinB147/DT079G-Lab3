#include <iostream>
#include <string>
#include <cstdlib> //srand
#include <ctime>
#include <random>
#include "p_queue.h"

struct order {
	
	int price;
	std::string broker;
	order(int price, std::string broker);
};

struct compare {
	bool operator() ( const order& order1, const order& order2 );
};

void print(p_queue<order, compare>& buyer, p_queue <order, compare>& seller);


int main() {
	std::random_device random_gen;
	std::mt19937 gen(random_gen());
	std::uniform_int_distribution<> distance(15, 30); //[15,30]

	p_queue<order, compare> buyerlist;
	p_queue<order, compare> sellerlist;

	

	for (int i = 0; i < 3; i++) {
		std::string person_name;
		if (i == 1) person_name = "Erik Pendel";
		else if (i == 2) person_name = "Jarl Wallenburg";
		else person_name = "Joakim Von Anka";

		for (int j = 0; j < 7; j++) {

			sellerlist.push(order(distance(gen), person_name));
			buyerlist.push(order(distance(gen), person_name));
		}
	}
	print(buyerlist, sellerlist);
	return 0;
}

order::order(int price, std::string broker) : price(price), broker(broker) {

}

bool compare::operator() (const order& order1, const order& order2) {
	return order1.price < order2.price;
}

void print(p_queue<order, compare>& buyer, p_queue <order, compare>& seller) {
	while (!buyer.empty()&&!seller.empty()) {
		auto Buy = buyer.pop();
		auto Sell = seller.pop();

		if (Sell.price <= Buy.price && Sell.broker != Buy.broker) {
			std::cout << Buy.broker << " bought " << Buy.price << " from " << Sell.broker << " for " << Sell.price << "\n";
		}
		//buyer.push(order(Buy.price, Buy.broker));

	}


}