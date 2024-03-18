//
// Created by Cosmin on 18.03.2024.
//

#include "Pachet.h"
#include <iostream>

Pachet::Pachet(Carte *c) {
    for (int i = 0; i <= 25; ++i) {
        pachet.push(c[i]);
    }
}

void Pachet::afisarePachet() const {
    std::queue<Carte> p{pachet};
    while (!p.empty()) {
        p.front().display();
        p.pop();
    }
}

Carte Pachet::scoatePrimaCarte() {
    if(pachet.empty())
        return Carte{0, 0}; /// pachetul e gol, returnez carte vida

    Carte x = pachet.front();
    pachet.pop();
    return x;
}

int Pachet::dimensiunePachet() {
    return int(pachet.size());
}