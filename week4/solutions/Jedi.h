#ifndef WEEK4_JEDI_H
#define WEEK4_JEDI_H

#include <iostream>
#include "Utils.h"

class Jedi {
public:
    Jedi();
    Jedi(const char *name, const char *saberColor, Rank rank, ushort age, double strength);
    Jedi(const Jedi& other);
    Jedi& operator=(const Jedi& other);
    ~Jedi();

    char* getName() const;
    void setName(const char *name);

    Rank getRank() const;
    void setRank(Rank rank);

    ushort getAge() const;
    void setAge(ushort age);

    char* getSaberColor() const;
    void setSaberColor(const char *saberColor);

    double getStrength() const;
    void setStrength(double strength);

    bool operator==(const Jedi& other) const;

    bool operator<(const Jedi& other) const;
    bool operator>(const Jedi& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Jedi& jedi);

private:
    char* name;
    char* saberColor;
    enum Rank rank;
    ushort age;
    double strength;

    void copy(const Jedi& other);
    void erase();
};

#endif //WEEK4_JEDI_H
