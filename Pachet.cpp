//
// Created by Cosmin on 18.03.2024.
//

#include "Pachet.h"

void Pachet::adaugaCarte(const Carte &c) {
    pachet.push(c);
}

Carte Pachet::extrageCarte() {
    if (!pachet.empty()) {
        Carte aux = pachet.front();
        pachet.pop();
        return aux;
    }
    else
        return Carte{"0", 0};
}

unsigned long long Pachet::numarCarti() const {
    return pachet.size();
}