#include <iostream>
using namespace std;

Salad::Salad(const int productsCount, const bool isSpiced, 
		const int weight, const int parts, 
		const double price) : Food(weight, parts, price) {

	this->productsCount = productsCount;
	this->isSpiced = isSpiced;
}

void Salad::category() {

	cout << "SALAD" << endl;
}

Food* Salad::clone() {

    return new Salad(*this);
}

void Salad::print() {

  	Food::print();

    cout << "Product count: " << productsCount << endl;
    cout << "Spiced: " << boolalpha << isSpiced << endl;
}

