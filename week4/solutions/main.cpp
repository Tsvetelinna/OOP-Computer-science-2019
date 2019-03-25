#include <iostream>
#include "JediOrder.h"

using namespace std;

void test() {
    JediOrder jediOrder("Endor", 1);

    jediOrder.add(Jedi("Yoda", "green", Rank::GRAND_MASTER, 800, 500));
    jediOrder.add(Jedi("Obi-Wan", "blue", Rank::MASTER, 35, 200));
    jediOrder.add(Jedi("Ben", "blue", Rank::MASTER, 65, 150));

    cout << jediOrder << endl;

    JediOrder copy = jediOrder;
    copy.remove(Jedi("Obi-Wan", "blue", Rank::MASTER, 35, 200));
    cout << copy << endl;

    copy.add(Jedi("Yoda", "green", Rank::GRAND_MASTER, 800, 500));
    copy.add(Jedi("Obi-Wan", "blue", Rank::MASTER, 35, 200));
    copy.add(Jedi("Ben", "blue", Rank::MASTER, 65, 150));
    cout << copy << endl;
    cout << "\n\nMost used color: " << copy.getMostUsedSaberColor() << "\n\n";

    copy = jediOrder;
    cout << copy << endl;


    JediOrder jediOrder2("Planet");
    jediOrder2.add(Jedi("J1", "purple", MASTER, 40, 220));
    jediOrder2.add(Jedi("J2", "green", YOUNGLING, 7, 10));
    jediOrder2.add(Jedi("J3", "yellow", PADAWAN, 18, 60));
    jediOrder2.add(Jedi("J4", "yellow", PADAWAN, 18, 60));
    jediOrder2.add(Jedi("J5", "yellow", PADAWAN, 18, 60));
    jediOrder2.add(Jedi("J6", "blue", PADAWAN, 18, 60));
    jediOrder2.add(Jedi("J7", "purple", YOUNGLING, 6, 4));
    jediOrder2.add(Jedi("Obi-Wan", "blue", Rank::MASTER, 35, 200));

    cout << jediOrder2 << endl;
    cout << "\n\nMost used color: " << jediOrder2.getMostUsedSaberColor() << "\n\n";

    cout << jediOrder * jediOrder2 << endl;
//    jediOrder2 *= jediOrder;
//    cout << jediOrder2 << endl;

    cout << jediOrder + jediOrder2 << endl;
}

int main() {

   test();

    return 0;
}