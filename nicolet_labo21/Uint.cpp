/**
 * Nom du fichier  : Uint.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-12-12
 * Laboratoire n°  : 21
 * Description     : Implémentation de la class Uint qui permet de manipuler des nombres entiers naturels
 *                   de taille quelconque.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include "Uint.hpp"

Uint::Uint() = default;

//Uint::Uint(std::uint64_t val) {
//   std::string convertion;
//   while (val != 0) {
//      convertion = (val % 2 != 0 ? "1" : "0") + convertion;
//      val /= 2;
//   }
//   this->str = convertion;
//}

Uint::Uint(std::uint64_t val) {
    do {
        this->str += (val & 1) ? '1' : '0';
        val >>= 1;
    } while (val != 0);
    std::reverse(this->str.begin(), this->str.end());
}


Uint::operator uint64_t() const {
    uint64_t result = 0;
    uint64_t base = 1;
    for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
        if (str[i] == '1') {
            result += base;
        }
        base *= 2;
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const Uint &rhs) {
    os << rhs.str;
    return os;
}

Uint &Uint::operator+=(const Uint &add) {
    Uint somme;
    Uint temp = add;
    int carry = 0;

    this->ajustement(temp);

    for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
        int terme1 = str[i] - '0', terme2 = temp.str[i] - '0';
        int res = terme1 + terme2 + carry;
        somme.str = (res == 0 or res == 2) ? somme.str = "0" + somme.str : somme.str = "1" + somme.str;
        carry = res > 1 ? 1 : 0;
    }
    if (carry == 1)
        somme.str = "1" + somme.str;
    somme.enleveZero();

    return (*this = somme);
}

Uint &Uint::operator-=(const Uint &sub) {
    Uint diff;
    Uint temp = sub;
    int carry = 0;

    // todo régler le problème de ce warning
    if (*this < temp) {
        this->str = "erreur";
        return *this;
    }

    this->ajustement(temp);

    for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
        int terme1 = str[i] - '0', terme2 = temp.str[i] - '0';
        int res = terme1 - terme2 - carry;
        carry = res < 0 ? 1 : 0;
        if (res < 0)
            res += 2;
        diff.str = res ? "1" + diff.str : "0" + diff.str;
    }
    if (carry == 1)
        diff.str = "1" + diff.str;
    diff.enleveZero();
    return *this = diff;
}

Uint &Uint::operator*=(const Uint &mul) {
    Uint produit;
    Uint temp = mul;
    int multiple = 0;

    if (str == "0" or temp.str == "0") {
        str = "0";
        return *this;
    }

    this->ajustement(temp);

    for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
        Uint produitTemp;
        produitTemp.str.insert(0, multiple, '0');
        for (size_t j = str.size() - 1; j != SIZE_MAX; --j) {
            int facteur1 = this->str[j] - '0', facteur2 = temp.str[i] - '0';
            int res = facteur1 * facteur2;
            produitTemp.str = res ? "1" + produitTemp.str : "0" + produitTemp.str;
        }
        multiple++;
        produit += produitTemp;
    }

    produit.enleveZero();
    return *this = produit;
}

Uint &Uint::operator/=(const Uint &div) {
    Uint quotient, reste;
    this->diviserReste(div, quotient, reste);
    return *this = quotient;
}

Uint &Uint::operator%=(const Uint &mod) {
    Uint quotient, reste;
    this->diviserReste(mod, quotient, reste);
    return *this = reste;
}

Uint &Uint::operator<<=(const uint64_t &lhs) {
    str.append(lhs, '0');
    return *this;
}

Uint operator+(Uint terme1, const Uint &terme2) { return terme1 += terme2; }

Uint operator-(Uint terme1, const Uint &terme2) { return terme1 -= terme2; }

Uint operator*(Uint facteur1, const Uint &facteur2) { return facteur1 *= facteur2; }

Uint operator/(Uint dividende, const Uint &diviseur) { return dividende /= diviseur; }

Uint operator%(Uint dividende, const Uint &diviseur) { return dividende %= diviseur; }

Uint operator<<(Uint decalage, const uint64_t &position) {return decalage <<= position;}

int Uint::operator<=>(const Uint &comparer) {
    if (this->str.size() > comparer.str.size())
        return 1;
    else if (this->str.size() < comparer.str.size())
        return -1;
    else {
        for (size_t i = 0; i != str.size() - 1; ++i) {
            if (this->str.at(i) < comparer.str.at(i))
                return -1;
            else if (this->str.at(i) > comparer.str.at(i))
                return 1;
        }
    }
    return 0;
}

bool Uint::operator==(const Uint &comparer) {
    return *this <=> comparer == 0;
}

void Uint::ajustement(Uint &comparer) {
    if (str.size() < comparer.str.size())
        str.insert(0, comparer.str.size() - str.size(), '0');
    else
        comparer.str.insert(0, str.size() - comparer.str.size(), '0');
}

void Uint::enleveZero() {
    this->str.erase(0, std::min(this->str.find_first_not_of('0'), this->str.size() - 1));
}

void Uint::diviserReste(const Uint &a, Uint &quotient, Uint &reste) {
    Uint diviseur = a;
    Uint dividende = *this;

    if (dividende.str == "0") {
        quotient.str = "erreur";
        return;
    } else if (diviseur > dividende) {
        reste = dividende;
        quotient.str = "0";
        return;
    } else if (diviseur.str == "1") {
        reste.str = "0";
        quotient = dividende;
        return;
    }

    diviseur.str.append(dividende.str.size() - diviseur.str.size(), '0');

    while (!(diviseur < a)) {
        if ((dividende - diviseur).str != "erreur") {
            quotient.str = quotient.str + '1';
            dividende -= diviseur;
        } else {
            quotient.str = quotient.str + '0';
        }
        diviseur.str.pop_back();
    }
    quotient.enleveZero();
    reste = dividende;
}

void Uint::set_base(int base, int charactere) {

}






























