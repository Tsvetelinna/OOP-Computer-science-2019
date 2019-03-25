#include <cstring>
#include "Jedi.h"
#include "Utils.h"

Jedi::Jedi() : rank(PADAWAN), age(0), strength(0) {
    this->name = copydyn("");
    this->saberColor = copydyn("");
}

Jedi::Jedi(const char *name, const char *saberColor,
        Rank rank, ushort age, double strength)
        : rank(rank), age(age), strength(strength) {

    this->name = copydyn(name);
    this->saberColor= copydyn(saberColor);
}

Jedi::Jedi(const Jedi& other) {
    copy(other);
}

Jedi& Jedi::operator=(const Jedi& other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

Jedi::~Jedi() {
    erase();
}

char* Jedi::getName() const {
    return this->name;
}

void Jedi::setName(const char *name) {
    delete[] this->name;
    this->name = copydyn(name);
}

Rank Jedi::getRank() const {
    return this->rank;
}

void Jedi::setRank(Rank rank) {
    this->rank = rank;
}

ushort Jedi::getAge() const {
    return this->age;
}

void Jedi::setAge(ushort age) {
    this->age = age;
}

char* Jedi::getSaberColor() const {
    return this->saberColor;
}

void Jedi::setSaberColor(const char *saberColor) {
    delete[] this->saberColor;
    this->saberColor = copydyn(saberColor);
}

double Jedi::getStrength() const {
    return this->strength;
}

void Jedi::setStrength(double strength) {
    this->strength = strength;
}

bool Jedi::operator==(const Jedi& other) const {
    return
        strcmp(this->name, other.name) == 0 &&
        strcmp(this->saberColor, other.saberColor) == 0 &&
        this->rank == other.rank &&
        this->age == other.age &&
        this->strength == other.strength;
}

bool Jedi::operator<(const Jedi& other) const {
    return this->strength < other.strength;
}

bool Jedi::operator>(const Jedi& other) const {
    return this->strength > other.strength;
}

void Jedi::copy(const Jedi& other) {
    this->name = copydyn(other.name);
    this->saberColor = copydyn(other.saberColor);
    this->rank = other.rank;
    this->age = other.age;
    this->strength = other.strength;
}

void Jedi::erase() {
    delete[] this->name;
    delete[] this->saberColor;
}

std::ostream& operator<<(std::ostream& os, const Jedi& jedi) {
    os << "Jedi:\n";
    os << "..name = " << jedi.name << std::endl;
    os << "..saberColor = " << jedi.saberColor << std::endl;
    os << "..rank = " << jedi.rank << std::endl;
    os << "..age = " << jedi.age << std::endl;
    os << "..strength = " << jedi.strength;
    return os;
}
