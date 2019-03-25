#include <iostream>
#include "JediOrder.h"
using namespace std;

JediOrder::JediOrder(const char* planet, int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->planet = copydyn(planet);
    this->jedi = new Jedi[this->capacity];
}

JediOrder::JediOrder(const JediOrder& other) {
    copy(other);
}

JediOrder& JediOrder::operator=(const JediOrder& other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

JediOrder::~JediOrder() {
    erase();
}

void JediOrder::setPlanet(const char* planet) {
    delete[] this->planet;
    this->planet = copydyn(planet);
}

char* JediOrder::getPlanet() const {
    return this->planet;
}

bool JediOrder::contains(const Jedi& jedi) const {
    for (int i = 0; i < this->size; i++) {
        if (this->jedi[i] == jedi) {
            return true;
        }
    }

    return false;
}

void JediOrder::add(const Jedi& jedi) {
    if (this->size == this->capacity) {
        resize();
    }

    this->jedi[this->size++] = jedi;
}

bool JediOrder::remove(const Jedi& jedi) {
    if (!contains(jedi)) {
        return false;
    }

    for (int i = 0; i < this->size; i++) {
        if (this->jedi[i] == jedi) {
            for (int j = i; j < this->size - 1; j++) {
                this->jedi[j] = this->jedi[j + 1];
            }

            this->jedi[size - 1] = Jedi();
            this->size--;

            break;
        }
    }

    return true;
}

Jedi JediOrder::operator[](int index) const {
    if (index >= size) {
        cerr << "index out of bounds" << endl;
        exit(-1);
    }

    return this->jedi[index];
}

Jedi JediOrder::getStrongestJedi() const {
    if (this->size == 0) {
        return Jedi();
    }

    Jedi strongest = this->jedi[0];

    for (int i = 1; i < this->size; i++) {
        if (this->jedi[i] > strongest) {
            strongest = this->jedi[i];
        }
    }

    return strongest;
}

Jedi JediOrder::getYoungestJedi() const {
    if (this->size == 0) {
        return Jedi();
    }

    Jedi youngest = this->jedi[0];

    for (int i = 1; i < this->size; i++) {
        if (this->jedi[i].getAge() < youngest.getAge()) {
            youngest = this->jedi[i];
        }
    }

    return youngest;
}

JediOrder JediOrder::operator*(const JediOrder& other) const {
    JediOrder intersection = *this;

    // Нека планетата на новия JediOrder е планетата на по-големия от двата
    if (other.size > this->size) {
        intersection.setPlanet(other.planet);
    }

    for (int i = 0; i < intersection.size; i++) {
        if (!other.contains(intersection.jedi[i])) {
            intersection.remove(intersection.jedi[i]);
            i--;
        }
    }

    return intersection;
}

JediOrder JediOrder::operator+(const JediOrder& other) const {
    JediOrder orderUnion = *this;

    // Нека планетата на новия JediOrder е планетата на по-големия от двата
    if (other.size > this->size) {
        orderUnion.setPlanet(other.planet);
    }

    for (int i = 0; i < other.size; i++) {
        if (!orderUnion.contains(other.jedi[i])) {
            orderUnion.add(other.jedi[i]);
        }
    }

    return orderUnion;
}

JediOrder& JediOrder::operator*=(const JediOrder& other) {
    *this = this->operator*(other);

    return *this;
}

JediOrder& JediOrder::operator+=(const JediOrder& other) {
    *this = this->operator+(other);

    return *this;
}

char* JediOrder::getMostUsedSaberColor() const {
    const char* mostUsedColor = nullptr;
    int mostUsedCounter = 0;

    for (int i = 0; i < size; i++) {
        if (jedi[i].getRank() == Rank::MASTER) {
            mostUsedColor = jedi[i].getSaberColor();
            mostUsedCounter = 1;
            break;
        }
    }

    if (mostUsedCounter == 0) {
        return copydyn("");
    }

    for (int i = 0; i < size; i++) {
        char* currentColor = jedi[i].getSaberColor();
        int currentCounter = 1;
        bool isUsedByMaster = (jedi[i].getRank() == MASTER);

        for (int j = 1; j < size; j++) {
            if (strcmp(currentColor, jedi[j].getSaberColor()) == 0) {
                currentCounter++;

                if (jedi[j].getRank() == MASTER) {
                    isUsedByMaster = true;
                }
            }
        }

        if (isUsedByMaster && currentCounter > mostUsedCounter) {
            mostUsedColor = currentColor;
            mostUsedCounter = currentCounter;
        }
    }

    return copydyn(mostUsedColor);
}

void JediOrder::copy(const JediOrder& other) {
    this->planet = copydyn(other.planet);

    this->capacity = other.capacity;
    this->size = other.size;
    this->jedi = new Jedi[this->capacity];

    for (int i = 0; i < this->size; i++) {
        this->jedi[i] = other.jedi[i];
    }
}

void JediOrder::erase() {
    delete[] this->jedi;
    delete[] this->planet;
}

void JediOrder::resize() {
    this->capacity *= 2;
    Jedi* old = this->jedi;

    this->jedi = new Jedi[this->capacity];

    for (int i = 0; i < this->size; i++) {
        this->jedi[i] = old[i];
    }

    delete[] old;
}

ostream &operator<<(ostream& os, const JediOrder& order) {
    os << "{\n";
    os << "capacity: " << order.capacity << endl;
    os << "size: " << order.size << endl;
    for (int i = 0; i < order.size; i++) {
        os << i << ": " << order[i] << "\n\n";
    }
    os << "}";
    return os;
}
