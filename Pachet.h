//
// Created by Cosmin on 18.03.2024.
//

#ifndef OOP_PACHET_H
#define OOP_PACHET_H
#include <queue>
#include "Carte.h"

class Pachet {
    std::queue<Carte> pachet;
public:
    Pachet(Carte[26]);
    Pachet() = default;
    void afisarePachet() const;

    Carte scoatePrimaCarte();
    int dimensiunePachet();
};


#endif //OOP_PACHET_H
