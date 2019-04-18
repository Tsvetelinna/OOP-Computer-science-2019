#include <iostream>
#include <cassert>
using namespace std;

void Menu::copy(const Menu& m) {

	this->size = m.size;
	this->capacity = m.capacity;
	this->foods = new Food*[capacity];

	for(int i = 0; i < size; i++) {

		foods[i] = m.foods[i]->clone();
	}
}

void Menu::erase() {

	for(int i = 0; i < size; i++) {

		delete foods[i];
	}

	delete[] foods;
}

void Menu::resize() {

	Food** temp = foods;
	this->capacity *= 2;
	this->foods = new Food*[capacity];

	for(int i = 0; i < size; i++) {

		foods[i] = temp[i];
	}

	delete[] temp;
}

Menu::Menu(int size, int capacity) {

	this->size = size;
	this->capacity = capacity;
	foods = new Food*[capacity];
}

Menu::Menu(const Menu& m) {

	copy(m);
}

Menu::~Menu() {

	erase();
}

Menu& Menu::operator=(const Menu& other) {

	if (this != &other) {

		erase();
		copy(other);
	}

	return *this;
}

void Menu::print() {

	for(int i = 0; i < size; i++) {

		foods[i]->category();
		foods[i]->print();
		cout << endl;
	}
}

const Food* Menu::operator[](int index) const {

	assert(index >= 0 && index < size);
	return this->foods[index];
}

void Menu::addFood(Food* f) {

	if(size + 1 > capacity) {

		resize();
	}

	foods[size] = f->clone();
	size++;
}

void Menu::remove(const Food* f) {

	for (int i = 0; i < size; i++) {

		if (foods[i] == f) {
				
			delete foods[i];
			foods[i] = foods[size - 1];
			foods[size - 1] = nullptr;
			size--;
			break;
		}
	}
}

void Menu::getCheapestFood() {

	assert(size > 0);

	if (size == 1) {

		foods[0]->print();
	}

	double cheapPrice = foods[0]->getPrice();
	int index = 0;

	for (int i = 1; i < size; i++) {

		if (foods[i]->getPrice() < cheapPrice) {

			cheapPrice = foods[i]->getPrice();
			index = i;
		}
	}

	cout << "Cheapiest Price: " << cheapPrice << endl;
	foods[index]->category();
	foods[index]->print();
}

void Menu::consumeFood(const Food* f) {

	for (int i = 0; i < size; i++) {

		if (foods[i] == f) {

			foods[i]->consume();

			if (foods[i]->getParts() == 0) {

				remove(foods[i]);
			}

			break;
		}
	}
}