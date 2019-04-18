#pragma once

class Food {
private:
	int weight;
	int parts;
	double price;
	double weightPerPart;

public:
	Food(const int weight, const int parts,
		 const double price);

	virtual void category() = 0;

	virtual Food* clone() = 0;

	void consume();

	virtual void print();

	int getWeight() const;

	int getParts() const;

	double getPrice() const;

	double getWeightPerPart() const;
};

#include "food.cpp"