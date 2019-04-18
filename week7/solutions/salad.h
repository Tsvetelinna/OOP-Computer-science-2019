#pragma once

class Salad : public Food {
private:
	int productsCount;
	bool isSpiced;

public:
	Salad(const int productsCount = 4, const bool isSpiced = true, 
		const int weight = 300, const int parts = 1, 
		const double price = 4.5);

	virtual void category();

	virtual Food* clone();

    void print();
};

#include "salad.cpp"