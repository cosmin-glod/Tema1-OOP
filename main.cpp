#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <unordered_map>

#include "Carte.h"
#include "Jucator.h"
#include "Game.h"

int main() {

    std::cout << "----------------------RAZBOI----------------------\n";

    std::cout << "\t  .------.------.------.------.\n"
                 "\t  |A_  _ |A /\\  |A _   |A .   |\n"
                 "\t  |( \\/ )| /  \\ | ( )  | / \\  |\n"
                 "\t  | \\  / | \\  / |(_x_) |(_,_) |\n"
                 "\t  |  \\/ A|  \\/ A|  Y  A|  I  A|\n"
                 "\t  `------^------^------'------'\n";

    /// Definire pachet de carti
    std::vector<Carte> pachetCarti;
    std::vector<std::string> suits = {"INIMA", "ROMB", "FRUNZA", "TREFLA"};
    std::vector<int> ranks = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            Carte aux{suit, rank};
            pachetCarti.push_back(aux);
        }
    }

    /// Amestecare pachet de carti - chat gpt
        // Seed the random number generator
        std::random_device rd;
        std::mt19937 gen(rd());

        // Use std::shuffle to shuffle the array
        std::shuffle(pachetCarti.begin(), pachetCarti.end(), gen);

    Game game;

    int numarBoti = 0;
    while (true) {
        std::cout << "Jocul se joaca in 2-4 jucatori\n";
        std::cout << "Cati boti doriti sa adaugati ? :";
        std::cin >> numarBoti;

        if (numarBoti < 1 || numarBoti > 3)
            std::cout << "Input invalid\n\n";
        else
            break;
    }
    Jucator jucator;
    std::cout << "Introdu numele tau ? :";
    std::cin >> jucator;

    while (!jucator.numeValid()) {
        std::cout << "Nume invalid! Trebuie folosite doar literele a-z si cifrele 0-9 !\n";
        std::cout << "Introdu numele tau ? :";
        std::cin >> jucator;
        std::cout << '\n';
    }

    game.adaugaJucator(jucator);

    for (int i = 1; i <= numarBoti; ++i) {
        Jucator aux;
        std::cout << "Nume bot " << i << " :";
        std::cin >> aux;

        if (!aux.numeValid()) {
            std::cout << "Nume invalid! Trebuie folosite doar literele a-z si cifrele 0-9 !\n";
            --i;
        }
        else
            game.adaugaJucator(aux);
    }

    /// Impart pachetul de carti la jucatori
    int ind = 0, numarJucatori = numarBoti + 1;
    for (auto &c : pachetCarti) {
        game.adaugaCarteJucatorului(c, ind++ % numarJucatori);
    }


    int round = 1;
    char actiune;
    while (!game.isGameOver()) {
        Game::afisareSeparator();
        std::cout << "Runda : " << round << '\n';
        std::cout << "Toata lumea pune carte jos !\n\n";
        std::cin >> actiune;

        if (actiune == '0') {
            game.afisareStatusJoc();
            Game::afisareSeparator();
        }
        else if (actiune == 'x') /// iesire din joc
            return 0;

        game.joaca();
        ++round;
    }
    std::cout << "JOCUL S-A INCHEIAT\nCASTIGATORUL ESTE ";
    std::cout << game.getCastigator();
    return 0;
}
