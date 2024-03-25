//
// Created by Cosmin on 18.03.2024.
//

#ifndef OOP_PACHET_H
#define OOP_PACHET_H
#include <queue>
#include "Carte.h"
#include <iostream>

class Pachet {
    std::queue<Carte> pachet;
public:
    Pachet() = default;
    ~Pachet() = default;
    Pachet(const Pachet& obj) = default;
    Pachet& operator=(const Pachet& obj) {
        if (this != &obj)
            pachet = obj.pachet;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &os, Pachet obj) {
        while (!obj.pachet.empty()) {
            std::cout << obj.pachet.front();
            obj.pachet.pop();
        }
        return os;
    }

    void adaugaCarte(const Carte& c);

    [[nodiscard]] bool gol() const {
        return pachet.empty();
    }
    Carte extrageCarte();
    [[nodiscard]] unsigned long long numarCarti() const;
};


#endif //OOP_PACHET_H
