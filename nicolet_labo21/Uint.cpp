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
#include "Prime.hpp"
#include <string>
#include <cstdint>
#include <cmath>
#include <vector>
#include <random>
#include <functional>

Uint::Uint() = default;

Uint::Uint(std::uint64_t val) {
    do {
        this->str += (val & 1) ? '1' : '0';
        val >>= 1;
    } while (val != 0);
    std::reverse(this->str.begin(), this->str.end());
}

uint64_t Uint::zeba = 10;

uint64_t Uint::table = 0;

Uint::operator uint64_t() const {
    uint64_t result = 0;
    uint64_t base = 1;
    for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
        if (str[i] == '1')
            result += base;
        base *= 2;
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const Uint &rhs) {
    os << rhs.change_base(Uint::get_base(), Uint::get_table());
    Uint::table = 0;
    Uint::zeba = 10;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Base &rhs) {
    return os;
}

Uint &Uint::operator+=(const Uint &add) {
    Uint somme;
    Uint temp = add;
    int carry = 0;

    this->ajustement(temp);
    somme.str.resize(temp.str.size(), '0');

    for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
        int terme1 = str[i] - '0', terme2 = temp.str[i] - '0';
        int res = terme1 + terme2 + carry;
        somme.str[i] = (res == 0 or res == 2) ? '0' : '1';
        carry = res > 1 ? 1 : 0;
    }
    if (carry == 1)
        somme.str = "1" + somme.str;

    somme.enleveZero();
    return *this = somme;
}

Uint &Uint::operator-=(const Uint &sub) {
    Uint diff;
    Uint temp = sub;
    int carry = 0;

    if (*this < temp) {
        this->str = "erreur";
        return *this;
    }

    this->ajustement(temp);
    diff.str.resize(temp.str.size(), '0');

    for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
        int terme1 = str[i] - '0', terme2 = temp.str[i] - '0';
        int res = terme1 - terme2 - carry;
        carry = res < 0 ? 1 : 0;
        if (res < 0)
            res += 2;
        diff.str[i] = res ? '1' : '0';
    }
    if (carry == 1)
        diff.str = "1" + diff.str;

    diff.enleveZero();
    return *this = diff;
}

Uint &Uint::operator*=(const Uint &mul) {
    Uint produit = 0;
    size_t multiple = 0;

    if (str == "0" or mul.str == "0") {
        str = "0";
        return *this;
    }

    for (size_t i = mul.str.size() - 1; i != SIZE_MAX; --i) {
        Uint tmp = *this;
        if (mul.str[i] == '1') {
            //tmp.str.insert(tmp.str.end(), multiple, '0');
            produit += tmp;
        }
        //multiple++;
        tmp.str.push_back('0');
    }
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

Uint &Uint::operator++() { return *this += 1; }

Uint Uint::operator++(int) {
    Uint temp = *this;
    ++*this;
    return temp;
}

Uint &Uint::operator--() { return *this -= 1; }

Uint Uint::operator--(int) {
    Uint temp = *this;
    --(*this);
    return temp;
}

Uint operator+(Uint terme1, const Uint &terme2) { return terme1 += terme2; }

Uint operator-(Uint terme1, const Uint &terme2) { return terme1 -= terme2; }

Uint operator*(Uint facteur1, const Uint &facteur2) { return facteur1 *= facteur2; }

Uint operator/(Uint dividende, const Uint &diviseur) { return dividende /= diviseur; }

Uint operator%(Uint dividende, const Uint &diviseur) { return dividende %= diviseur; }

Uint operator<<(Uint decalage, const uint64_t &position) { return decalage <<= position; }

int Uint::operator<=>(const Uint &comparer) {
    if (str == "0" && comparer.str == "0") return 0;
    if (str.size() > comparer.str.size())
        return 1;
    else if (str.size() < comparer.str.size())
        return -1;
    else {
        for (size_t i = 0; i < str.size(); i++) {
            if (str.at(i) < comparer.str.at(i))
                return -1;
            else if (str.at(i) > comparer.str.at(i))
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
    if (str == "0") {
        str = "0";
    } else {
        this->str.erase(0, std::min(this->str.find_first_not_of('0'), this->str.size() - 1));
    }
}

void Uint::diviserReste(const Uint &div, Uint &quotient, Uint &reste) {
    Uint diviseur = div;
    Uint dividende = *this;
//    Uint temp = quotient;

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
//    temp.str.resize(this->str.size(), '0');

//    size_t sup = temp.str.size();
//    for (size_t i = 0; !(diviseur < div); ++i) {
//        if ((dividende - diviseur).str != "erreur") {
//            temp.str[i] = '1';
//            dividende -= diviseur;
//        } else {
//            temp.str[i] = '0';
//        }
//        sup--;
//        diviseur.str.pop_back();
//    }


    while (!(diviseur < div)) {
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

Base set_base(uint64_t base, uint64_t charactere) {
    Uint::zeba = base;
    Uint::table = charactere;
    return Base();
}

uint64_t Uint::get_base() {
    return zeba;
}

uint64_t Uint::get_table() {
    return table;
}

std::vector<std::string> nombre0 = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
std::vector<std::string> nombre1 = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};

std::vector<std::vector<std::string>> typoChoix = {nombre0, nombre1};

std::string Uint::change_base(uint64_t base, uint64_t typo = 0) const {
    std::string resultat;
    Uint temp = *this;
    while (temp != 0) {
        resultat = typoChoix[typo][uint64_t(temp % base)] + resultat;
        temp = temp / base;
    }
    return resultat;
}

auto gen_bit0_1 = std::bind(std::uniform_int_distribution<uint64_t>(0, 1), std::mt19937(987));

Uint Uint::genere_uint_aleatoire(const Uint &premier) {
    Uint resultat;
    size_t taille = premier.str.size() - 1;
    resultat.str.resize(taille, '0');

    for (size_t i = premier.str.size() - 1; i != 0; --i) {
        resultat.str[i] = gen_bit0_1() ? '1' : '0';
    }
    resultat.enleveZero();
    if (resultat == 0) {
        resultat.str = "1";
        return resultat;
    }
    return resultat;
}

