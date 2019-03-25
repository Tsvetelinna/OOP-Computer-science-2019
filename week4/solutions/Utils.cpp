#include "Utils.h"

char* copydyn(const char* other) {
    char* ret = new char[strlen(other) + 1];
    strcpy(ret, other);
    return ret;
}

std::ostream& operator<<(std::ostream& os, Rank rank) {

    switch (rank) {
        case YOUNGLING:
            os << "YOUNGLING";
            break;
        case PADAWAN:
            os << "PADAWAN";
            break;
        case KNIGHT:
            os << "KNIGHT";
            break;
        case MASTER:
            os << "MASTER";
            break;
        case GRAND_MASTER:
            os << "GRAND_MASTER";
            break;
    }

    return os;
}

