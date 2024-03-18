#include <iostream>
#include <array>
#include <Helper.h>
#include <string>
#include <queue>

/// Chat GPT
#include <algorithm>
#include <ctime>  // For std::time
#include <cstdlib>  // For std::rand and std::srand
#include <random>
/// Chat GPT

#include "Carte.h"
#include "Jucator.h"
#include "Pachet.h"

bool gameOver = false;

int main() {

    std::cout << "------------------RAZBOI EGIPTEAN------------------\n";

    /// Definire pachet de carti
    Carte carti[52] = {{0, 2},{0, 3},{0, 4},{0, 5},{0, 6},{0, 7},{0, 8},{0, 9},{0, 10},{0, 11},{0, 12},{0, 13},{0, 14},
            {1, 2},{1, 3},{1, 4},{1, 5},{1, 6},{1, 7},{1, 8},{1, 9},{1, 10},{1, 11},{1, 12},{1, 13},{1, 14},
            {2, 2},{2, 3},{2, 4},{2, 5},{2, 6},{2, 7},{2, 8},{2, 9},{2, 10},{2, 11},{2, 12},{2, 13},{2, 14},
            {3, 2},{3, 3},{3, 4},{3, 5},{3, 6},{3, 7},{3, 8},{3, 9},{3, 10},{3, 11},{3, 12},{3, 13},{3, 14}
    };

    /// Amestecare pachet de carti
        // Seed the random number generator
        std::random_device rd;
        std::mt19937 gen(rd());

        // Use std::shuffle to shuffle the array
        std::shuffle(carti, carti + 52, gen);

    /// Impartire pachet carti

    std::cout << "Nume jucator :";
    std::string numeJucator;
    std::cin >> numeJucator;
    std::cin.get();

    Jucator bot{Pachet {carti}, "Bot"}; /// Player 1 - Bot
    Jucator player{Pachet {carti + 26}, numeJucator}; /// Player 2 - NumeJucator

    unsigned int runda = 0;
    Carte carte1;
    Carte carte2;

    while (!gameOver) {
        std::cout << ++runda << ":\n";

        carte1 = bot.extrageCarte();
        std::cout << bot << " a extras\t" << carte1;
        std::cin.get();

        carte2 = player.extrageCarte();
        std::cout << player << " a extras\t" << carte2;
        std::cin.get();

        if (carte1 > carte2) {
            std::cout << bot << " castiga aici";
            std::cin.get();
        }
        else if (carte1 < carte2) {
            std::cout << player << " castiga aici";
            std::cin.get();
        }
        else {
            std::cout << "Egalitate";
            std::cin.get();
        }
        std::cout << '\n';
        gameOver = !bot.maiAreCarti() || !player.maiAreCarti();
    }
    return 0;
}
