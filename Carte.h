//
// Created by Cosmin on 18.03.2024.
//

#ifndef OOP_CARTE_H
#define OOP_CARTE_H
#include <string>
#include <iostream>
#include <utility>

class Carte {
    std::string tip;
    int numar;
public:
    Carte(); /// constructorul default
    Carte(std::string t, int nr); /// constructor parametrizat

    bool operator<(const Carte& other) const {
        return numar < other.numar;
    }
    bool operator>(const Carte& other) const {
        return numar > other.numar;
    }
    bool operator==(const Carte& other) const {
        return numar == other.numar;
    }

    bool operator>(const int nr) const {
        return numar > nr;
    }
    bool operator<(const int nr) const {
        return numar < nr;
    }

    friend std::ostream& operator<<(std::ostream &os, const Carte& obj) {
        if (obj.numar == 0) {
            std::cout << " ______ " << std::endl;
            std::cout << "|      |" << std::endl;
            std::cout << "|      |" << std::endl;
            std::cout << "|      |" << std::endl;
            std::cout << "|______|" << std::endl;
            std::cout << '\n';
        }
        else if (obj.numar == 10) {
            os << " ______ " << std::endl;
            os << "|" << 10 << "    |" << std::endl;
            os << "|" << obj.tip;
            for (unsigned long long i = 6; i > obj.tip.size(); --i)
                os << ' ';
            os << "|" << std::endl;
            os << "|      |" << std::endl;
            os << "|____" << 10 << "|" << std::endl;
        }
        else {
            int nr;
            if (obj.numar > 10) {
                switch (obj.numar) {
                    case 11:
                        nr = 74; /// ascii code for J
                        break;
                    case 12:
                        nr = 81; /// ascii code for Q
                        break;
                    case 13:
                        nr = 75;
                        break;
                    default:
                        nr = 65;
                        break;
                }
            }
            else {
                nr = obj.numar + 48;
            }
            os << " ______ " << std::endl;
            os << "|" << char(nr) << "     |" << std::endl;
            os << "|" << obj.tip;
            for (unsigned long long i = 6; i > obj.tip.size(); --i)
                os << ' ';
            os << "|" << std::endl;
            os << "|     " << " |" << std::endl;
            os << "|_____" << char(nr) << "|" << std::endl;
        }

        return os;
    }

    [[nodiscard]] int getNumar() const;

};


#endif //OOP_CARTE_H
