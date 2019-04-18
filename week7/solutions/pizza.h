#include <iostream>
#include <string>
using namespace std;

class Pizza : public Food {
private:
	string type;

public:
	Pizza(const string type = "N/A",
		const int weight = 450, const int parts = 8, 
		const double price = 6.5) : Food(weight, parts, price){

		this->type = type;
	}

	void print() {

		Food::print();

		cout << "Type: " << type << endl;
	}

	void category() {

		cout << "PIZZA" << endl;
	}

	Food* clone() {

		return new Pizza(*this);
	}
};
