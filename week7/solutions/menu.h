#pragma once

class Menu {
private:
	Food** foods;
	int size;
	int capacity;

	void copy(const Menu& m);

	void erase();

	void resize();

public:
	Menu(int size = 0, int capacity = 8);

	Menu(const Menu& m);

	~Menu();

	Menu& operator=(const Menu& other);

	void print();

	const Food* operator[](int index) const;

	void addFood(Food* f);

	void remove(const Food* f);
	

	void getCheapestFood();

	void consumeFood(const Food* f);
};

#include "menu.cpp"
