//
// Created by Cosmin on 18.03.2024.
//

#include "Jucator.h"
#include <string>
#include <utility>

Jucator::Jucator(std::string  n) : nume{std::move(n)} {}


bool Jucator::numeValid() const {
    for (char c : nume) {
        if (!std::isalnum(c))
            return false;
    }
    return true;
}

void Jucator::adaugaCarte(const Carte &c) {
    pachet.adaugaCarte(c);
}

Carte Jucator::extrageCarte() {
    Carte aux = pachet.extrageCarte();
    if (aux == Carte{"0", 0}) {
        activ = false;
    }
    return aux;
}

void Jucator::eliminaDacaInactiv() {
    if (activ && !areCarti()) {
        activ = false;
        std::cout << '\n' << nume << " a pierdut !\n\n";
    }
}

unsigned long long Jucator::numarCarti() const {
    return pachet.numarCarti();
}