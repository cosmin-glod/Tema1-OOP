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
public:
    /// Constructor de initializare
    Jucator(const Pachet&, const std::string&);

    /// Getter nume
    std::string getNume() const;
    /// Getter Pachet
    Pachet getPachet();

    /// Extragere Carte
    Carte extrageCarte();

    /// mai exista carti
    bool maiAreCarti();

    /// Operatorul <<
    friend std::ostream& operator<<(std::ostream& os, const Jucator& obj) {
        os << obj.nume;
        return os;
    }
};


#endif //OOP_JUCATOR_H
