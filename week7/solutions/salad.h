#include <iostream>
using namespace std;

class Salad : public Food {
private:
	int productsCount;
	bool isSpiced;

public:
	Salad(const int productsCount = 4, const bool isSpiced = true, const int weight = 300, const int parts = 1, 
		const double price = 4.5) : Food(weight, parts, price) {

		this->productsCount = productsCount;
		this->isSpiced = isSpiced;
	}

	virtual void category() {

		cout << "SALAD" << endl;
	}

	virtual Food* clone() {
        return new Salad(*this);
    }

    void print() {

    	Food::print();
    	cout << "Product count: " << productsCount << endl;
    	cout << "Spiced: " << boolalpha << isSpiced << endl;
    }
};
