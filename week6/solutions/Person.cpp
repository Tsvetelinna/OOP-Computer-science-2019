#include "Person.h"
#include <cstring>
#include <cassert>

Person::Person(const char* name, const char *EGN) {
    this->name = copydyn(name);

    int temp = strlen(EGN);
    assert(temp == 0 || temp == 10);
    strcpy(this->EGN, EGN);
}

Person::Person(const Person& other) {
    copy(other);
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

Person::~Person() {
    erase();
}

bool Person::operator==(const Person& other) const {
    return strcmp(this->name, other.name) == 0 && 
        strcmp(this->EGN, other.EGN) == 0;
}

const char* Person::getName() const {
    return name;
}

const char* Person::getEgn() const {
    return EGN;
}

void Person::setName(const char* name) {
    delete[] this->name;
    this->name = copydyn(name);
}

void Person::setEGN(const char* EGN) {
    assert(strlen(EGN) == 10);
    strcpy(this->EGN, EGN);
}