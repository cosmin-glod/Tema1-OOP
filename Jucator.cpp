//
// Created by Cosmin on 18.03.2024.
//

#include "Jucator.h"
#include <string>

Jucator::Jucator(const Pachet& p, const std::string& name) : pachet{p}, nume{name} {}

std::string Jucator::getNume() const { return nume; }

Pachet Jucator::getPachet() { return pachet; }

Carte Jucator::extrageCarte() {
    return pachet.scoatePrimaCarte();
}

bool Jucator::maiAreCarti() {
    return pachet.dimensiunePachet();
}