//
// Created by Cosmin on 23.03.2024.
//
#include "Game.h"

void Game::adaugaJucator(const Jucator &jucator) {
    players.push_back(jucator);
}



void Game::adaugaCarteJucatorului(const Carte &c, const int nr) {
    players[nr].adaugaCarte(c);
}

bool Game::isGameOver() const {
    return gameOver;
}

//void Game::afisareCartiGoale() const {
//    for (auto &p : players) {
//        if (p.eActiv()) {
//            std::cout << p << '\n';
//            std::cout << " ______ " << std::endl;
//            std::cout << "|      |" << std::endl;
//            std::cout << "|      |" << std::endl;
//            std::cout << "|      |" << std::endl;
//            std::cout << "|______|" << std::endl;
//            std::cout << '\n';
//        }
//    }
//}

void Game::joaca() {
    std::vector<Carte> rundaCurenta;
    Pachet castig;

    /// Se pun primele carti jos
    /// Daca un player nu mai are carti, va iesi din joc !
    for (auto &p : players) {
        if (p.eActiv()) {
            std::cout << p << ' ' << p.numarCarti() << '\n';
            Carte aux = p.extrageCarte();
            if (aux != Carte{"0", 0}) {
                std::cout << aux << '\n';
                rundaCurenta.push_back(aux);
                castig.adaugaCarte(aux);
            }
            else {
                std::cout << "NU MAI ARE CARTI !\n";
                std::cout << "A IESIT DIN JOC !\n";
            }
        }
    }

    /// Cat timp exista razboi, sa se rezolve :)))
    int numarCartiRazboi = 0;
    while (existaRazboi(numarCartiRazboi, rundaCurenta)) {
        razboiMode(numarCartiRazboi, rundaCurenta, castig);
    }

    if (!gameOver) {
        /// Determinare castigator runda
        unsigned long long indexCastigator = 0;
        int maxim = 0;
        for (unsigned long long i = 0; i < rundaCurenta.size(); ++i) {
            if (rundaCurenta[i] > maxim) {
                maxim = rundaCurenta[i].getNumar();
                indexCastigator = i;
            }
        }

        std::cout << players[indexCastigator] << " a castigat aceasta runda si ia toate cartile !\n";

        /// Punem cartile castigatorului
        while (!castig.gol()) {
            players[indexCastigator].adaugaCarte(castig.extrageCarte());
        }
        /// Eliminam jucatorii care au ramas fara carti
        /// Verificare daca mai are rost sa continue jocul
        int jucatoriActivi = 0;
        for (auto &p: players) {
            p.eliminaDacaInactiv();
            if (p.eActiv())
                jucatoriActivi++;
        }
        if (jucatoriActivi < 2) {
            gameOver = true;
            for (const auto &player: players)
                if (player.eActiv()) {
                    castigator = player;
                    break;
                }
        }
    }
}

void Game::razboiMode(const int &numarCartiRazboi, std::vector<Carte> &rundaCurenta, Pachet &castig) {
    afisareSeparator();
    std::cout << "  _____           _           _ \n"
                 " |  __ \\         | |         (_)\n"
                 " | |__) |__ _ ___| |__   ___  _ \n"
                 " |  _  // _` |_  / '_ \\ / _ \\| |\n"
                 " | | \\ \\ (_| |/ /| |_) | (_) | |\n"
                 " |_|  \\_\\__,_/___|_.__/ \\___/|_|\n";
    std::cout << "Fiecare jucator trebuie sa puna jos " << numarCartiRazboi << " carti !\n";

    bool exista = true;
    for (int i = 1; i <= numarCartiRazboi; ++i) {
        std::cout << "Puneti jos a " << i << "-a carte !\n";
        if (input()) {
            if (exista) {
                exista = false;
                int j = 0;
                for (auto &p: players) {
                    if (p.eActiv()) {
                        if (p.areCarti()) {
                            std::cout << p << ' ' << p.numarCarti() << '\n';
                            Carte aux = p.extrageCarte();
                            castig.adaugaCarte(aux);
                            rundaCurenta[j] = aux;
                            std::cout << rundaCurenta[j] << '\n';
                            exista = true;
                        } else {
                            std::cout << "\"" << p << '\"' << " nu mai are carti, el ramane cu aceasta carte :\n";
                            std::cout << rundaCurenta[j] << '\n';
                        }
                        ++j;
                        afisareSeparator();
                    }
                }
            } else {
                std::cout << "TOTI JUCATORII AU RAMAS FARA CARTI !\n";
                std::cout << "Se folosesc cartile ramase pe masa de la fiecare !\n";
                break;
            }
        }
        else {
            gameOver = true;
            return;
        }
    }
}

bool Game::existaRazboi(int &numarCartiRazboi, std::vector<Carte> &rundaCurenta) {
    bool razboi = false;
    numarCartiRazboi = 0;
    for (unsigned long long i = 0; i < rundaCurenta.size(); ++i) {
        for (unsigned long long j = i + 1; j < rundaCurenta.size(); ++j) {
            if (rundaCurenta[i] == rundaCurenta[j]) {
                razboi = true;
                if (rundaCurenta[i] > numarCartiRazboi)
                    numarCartiRazboi = rundaCurenta[i].getNumar();
            }
        }
    }
    return razboi;
}

void Game::afisareStatusJoc() {
    for (auto &p : players) {
        std::cout << p << '\n';
        std::cout << p.getPachet() << "\n";
    }
}

Jucator Game::getCastigator() const {
    return castigator;
}

bool Game::input() {
    std::string actiune;
    std::cin >> actiune;
    if (actiune == "status") {
        afisareStatusJoc();
        Game::afisareSeparator();
        return true;
    }
    else if (actiune == "x" || actiune == "X") /// iesire din joc
        return false;
    return true;
}
