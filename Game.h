//
// Created by Cosmin on 23.03.2024.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <vector>
#include <iostream>
#include "Jucator.h"

class Game {
    std::vector<Jucator> players;
    std::vector<Carte> cartiJucate;
    bool gameOver = false;
    Jucator castigator;
public:
    Game() = default;

    void adaugaJucator(const Jucator& jucator);
    void adaugaCarteJucatorului(const Carte& c, int nr);
    static void afisareSeparator() {
        std::cout << "--------------------\n";
    };

    static bool existaRazboi(int &, std::vector<Carte>&);
    void razboiMode(int&, std::vector<Carte>&, Pachet&);

   // void afisareCartiGoale() const;
    void joaca();

    [[nodiscard]] bool isGameOver() const;

    void afisareStatusJoc();
    [[nodiscard]] Jucator getCastigator() const;
};


#endif //OOP_GAME_H
