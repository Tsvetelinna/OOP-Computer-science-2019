#ifndef WEEK4_JEDIORDER_H
#define WEEK4_JEDIORDER_H

#include <iostream>
#include "Jedi.h"

class JediOrder {
public:
    JediOrder(const char* planet = "", int capacity = 8);
    JediOrder(const JediOrder& other);
    JediOrder &operator=(const JediOrder& other);
    ~JediOrder();

    void setPlanet(const char* planet);
    char* getPlanet() const;

    bool contains(const Jedi& jedi) const;
    void add(const Jedi& jedi);
    bool remove(const Jedi& jedi);
    Jedi operator[](int index) const;

    Jedi getStrongestJedi() const;
    Jedi getYoungestJedi() const;

    JediOrder operator*(const JediOrder& other) const;
    JediOrder operator+(const JediOrder& other) const;
    JediOrder& operator*=(const JediOrder& other);
    JediOrder& operator+=(const JediOrder& other);

    char* getMostUsedSaberColor() const;

    friend std::ostream &operator<<(std::ostream& os, const JediOrder& order);

private:
    Jedi* jedi;
    int capacity;
    int size;
    char* planet;

    void copy(const JediOrder& other);
    void erase();
    void resize();
};

#endif //WEEK4_JEDIORDER_H
