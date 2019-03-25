#ifndef WEEK4_UTILS_H
#define WEEK4_UTILS_H

#include <cstring>
#include <iostream>

using ushort = unsigned short;

char* copydyn(const char* other);

enum Rank {YOUNGLING, PADAWAN, KNIGHT, MASTER, GRAND_MASTER};

std::ostream& operator<<(std::ostream& os, Rank rank);

#endif //WEEK4_UTILS_H
