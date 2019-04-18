#include <iostream>
#include <cassert>
using namespace std;

Food::Food(const int weight = 0, const int parts = 0,
		const double price = 0.0) {

	assert(weight > 0);
	assert(parts > 0);
	this->weight = weight;
	this->parts = parts;
	this->price = price;
	assert(parts != 0);
	this->weightPerPart = (double)weight/parts;
}

void Food::consume() {

	assert(parts > 0);
	this->weight -= weightPerPart;
	this->parts--;
}

void Food::print() {

	cout << "Weigh: " << weight << endl;
	cout << "Part: " << parts << endl;
	cout << "WeightPerPar: " << weightPerPart << endl;
	cout << "Price: " << price << endl;
}

int Food::getWeight() const{

	return this->weight;
}

int Food::getParts() const{

	return this->parts;
}

double Food::getPrice() const{

	return this->price;
}

double Food::getWeightPerPart() const{

	return this->weightPerPart;
}
