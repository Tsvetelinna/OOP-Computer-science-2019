#include <iostream>
#include <string>
using namespace std;

Pizza::Pizza(const string type,
		const int weight, const int parts, 
		const double price) : Food(weight, parts, price){

		this->type = type;
}

void Pizza::print() {

	Food::print();

	cout << "Type: " << type << endl;
}

void Pizza::category() {

	cout << "PIZZA" << endl;
}

Food* Pizza::clone() {

	return new Pizza(*this);
}