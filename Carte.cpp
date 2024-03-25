//
// Created by Cosmin on 18.03.2024.
//

/*
 * Inima 0
 * Romb 1
 * Trefla 2
 * Frunza 3
 */

#include "Carte.h"
#include <iostream>

int Carte::getNumar() const {
    return numar;
}

Carte::Carte(std::string t, int nr) : tip{std::move(t)}, numar{nr} {}
