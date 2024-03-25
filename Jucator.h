//
// Created by Cosmin on 18.03.2024.
//

#ifndef OOP_JUCATOR_H
#define OOP_JUCATOR_H
#include <string>
#include "Pachet.h"

class Jucator {
    std::string nume;
    Pachet pachet;
    bool activ = true;
public:
    /// Constructor de initializare
    Jucator() = default;
    explicit Jucator(std::string );
    ~Jucator() = default;
    Jucator(const Jucator& obj) = default;
    Jucator& operator=(const Jucator& obj) {
        if (this != &obj) {
            nume = obj.nume;
            pachet = obj.pachet;
            activ = obj.activ;
        }
        return *this;
    }

    /// Operatorul <<
    friend std::ostream& operator<<(std::ostream& os, const Jucator& obj) {
        os << obj.nume;
        return os;
    }
    /// Operatorul >>
    friend std::istream& operator>>(std::istream& os,Jucator& obj) {
        os >> obj.nume;
        return os;
    }

    /// Getter pachet
    [[nodiscard]] Pachet getPachet() const {
        return pachet;
    }

    [[nodiscard]] bool eActiv() const {
        return activ;
    }
    [[nodiscard]] bool areCarti() const {
        return !pachet.gol();
    }

    /// Verificare daca numele este unul valid
    [[nodiscard]] bool numeValid() const;

    void adaugaCarte(const Carte&);
    Carte extrageCarte();
    void eliminaDacaInactiv();
    [[nodiscard]] unsigned long long numarCarti() const;
};


#endif //OOP_JUCATOR_H
