#ifndef PERSON_H
#define PERSON_H

#include <cstring>

char* copydyn(const char*);

class Person {
private:
    char* name;
    char EGN[11];

    void copy(const Person& other) {
        name = copydyn(other.name);
        strcpy(EGN, other.EGN);
    }

    void erase() {
        delete[] name;
    }
public:
    Person(const char* name = "", const char *EGN = "");
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    bool operator==(const Person& other) const;

    const char* getName() const;
    const char* getEgn() const;

    void setName(const char* name);
    void setEGN(const char* EGN);
};

#include "Person.cpp"

#endif // PERSON_H