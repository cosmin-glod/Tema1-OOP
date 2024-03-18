//
// Created by Cosmin on 18.03.2024.
//

#ifndef OOP_CARTE_H
#define OOP_CARTE_H
#include <string>

class Carte {
    int tip;
    int numar;
public:
    Carte() = default; /// constructorul default
    Carte(int t, int nr) : tip{t}, numar{nr} {}; /// constructor
    void display() const;

    bool isNull();

    bool operator<(const Carte& other) const {
        return numar < other.numar;
    }
    bool operator>(const Carte& other) const {
        return numar > other.numar;
    }

    friend std::ostream& operator<<(std::ostream& os, const Carte& obj) {
        obj.display();
        return os;
    }

};


#endif //OOP_CARTE_H
