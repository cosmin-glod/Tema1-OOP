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
    ~Game() = default;
    Game(const Game& obj) = default;
    Game& operator=(const Game& obj) {
        if (this != &obj) {
            players = obj.players;
            cartiJucate = obj.cartiJucate;
            gameOver = obj.gameOver;
            castigator = obj.castigator;
        }
        return *this;
    }

    void adaugaJucator(const Jucator& jucator);
    void adaugaCarteJucatorului(const Carte& c, int nr);
    static void afisareSeparator() {
        std::cout << "--------------------\n";
    };

    static bool existaRazboi(int &, std::vector<Carte>&);
    void razboiMode(const int&, std::vector<Carte>&, Pachet&);

   // void afisareCartiGoale() const;
    void joaca();

    [[nodiscard]] bool isGameOver() const;

    void afisareStatusJoc();
    [[nodiscard]] Jucator getCastigator() const;
    bool input();
};


#endif //OOP_GAME_H
