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
#include <string>
#include <iostream>

void Carte::display() const {
    switch (tip) {
        case 0:
            std::cout << "Inima";
            break;
        case 1:
            std::cout << "Romb";
            break;
        case 2:
            std::cout << "Trefla";
            break;
        default:
            std::cout << "Frunza";
            break;
    }
    std::cout << ' ';
    switch (numar) {
        case 11:
            std::cout << "J";
            break;
        case 12:
            std::cout << "Q";
            break;
        case 13:
            std::cout << "K";
            break;
        case 14:
            std::cout << "A";
            break;
        default:
            std::cout << numar;
            break;
    }
}

bool Carte::isNull() {
    return !(tip + numar);
}

