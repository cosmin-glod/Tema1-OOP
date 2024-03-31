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
        std::random_device rd;
        std::mt19937 gen(rd());

        std::shuffle(pachetCarti.begin(), pachetCarti.end(), gen);

    Game game;

    std::cout << "Jocul se joaca in 2-4 jucatori\n";
    std::cout << "Pachetul de carti este impartit in mod cat mai egal la toti jucatorii\n"
                 "La fiecare runda, toti jucatorii pun jos o carte\n"
                 "Jucatorul cu cartea cea mai mare le ia pe toate celelalte\n"
                 "Daca exista 2 carti egale puse jos, atunci incepe RAZBOIUL\n"
                 "Toata lumea va trebui sa puna x carti jos,\n"
                 "x fiind numarul de pe cartea care apare jos de mai multe ori\n"
                 "Jocul se incheie cand un singur jucator are in mana tot pachetul de carti!\n"
                 "Veti fi dumneavoastra plus un numar de boti pentru a atinge numarul de playeri doriti\n\n"
                 "La fiecare runda apasati o tasta pentru a pune cartile jos si a le vizualiza\n"
                 "Daca doriti sa incheiati jocul, apasati tasta \"x\"\n"
                 "Daca doriti sa vedeti toate cartile jucatorilor din motive de curiozitate,\n"
                 "scrieti \"status\"\n";

    int numarBoti = 0;
    while (true) {
        std::cout << "Cati boti doriti sa adaugati ?:";
        std::cin >> numarBoti;

        if (numarBoti < 1 || numarBoti > 3)
            std::cout << "Input invalid\nNumarul introdus trebuie sa fie in intervalul 1-3\n";
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

    while (!game.isGameOver()) {
        Game::afisareSeparator();
        std::cout << "Runda : " << round << '\n';
        std::cout << "Toata lumea pune carte jos !\n\n";
        if(game.input()) {
            game.joaca();
            ++round;
        }
        else
            return 0;
        if (game.isGameOver()) /// aici jocul se termina fortat
            return 0;
    }
    std::cout << std::endl;
    std::cout << "JOCUL S-A INCHEIAT\nCASTIGATORUL ESTE ";
    std::cout << game.getCastigator();
    return 0;
}
