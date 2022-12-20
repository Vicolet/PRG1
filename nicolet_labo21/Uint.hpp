/**
 * Nom du fichier  : Uint.hpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-12-12
 * Laboratoire n°  : 21
 * Description     :
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#ifndef NICOLET_LABO21_UINT_HPP
#define NICOLET_LABO21_UINT_HPP

#include <iostream>
#include <string>
#include <cstdint>
#include <cmath>

class Uint {
public:
    Uint();

    Uint(std::uint64_t val);

    explicit operator uint64_t() const;

    friend std::ostream &operator<<(std::ostream &os, const Uint &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Base &rhs);

    //todo demander si les commentaires comme ça ça ne fait pas trop.
    /**
     * @brief Fais l'addition de deux Uint.
     *
     * Cette surcharge d'opérateur permet de faire l'addition de deux Uint elle est constituer d'une boucle for qui fait
     * size() fois la boucle
     *
     * @complexity O(n)
     * @param add le Uint que nous voulons additioner.
     * @return nous retourne l'addition des deux Uint.
     */
    Uint &operator+=(const Uint &add);
    Uint &operator-=(const Uint &sub);
    Uint &operator*=(const Uint &mul);
    Uint &operator/=(const Uint &div);
    Uint &operator%=(const Uint &mod);
    Uint &operator<<=(const uint64_t &lhs);

    Uint &operator++();
    Uint operator++(int);
    Uint &operator--();
    Uint operator--(int);

    friend Uint operator+(Uint terme1, const Uint &terme2);
    friend Uint operator-(Uint terme1, const Uint &terme2);
    friend Uint operator*(Uint facteur1, const Uint &facteur2);
    friend Uint operator/(Uint dividende, const Uint &diviseur);
    friend Uint operator%(Uint dividende, const Uint &diviseur);
    friend Uint operator<<(Uint decalage, const uint64_t &position);


    int operator<=>(const Uint &comparer);
    bool operator==(const Uint &comparer);

    /**
     * Cette fonction permet d'ajuste la taille de deux Uint
     * @param comparer Uint qui est ajuster ou ajuste
     */
    void ajustement(Uint &comparer);

    /**
     * Cette fonction permet d'enlever les zéros en trop devant notre string pour passer par exemple de "00101" à "101".
     */
    void enleveZero();

    /**
     * @brief Calcul le reste et la division
     *
     * Cette fonction nous permet de calculer la différence et le reste de deux Uint
     *
     * @complexity O(n^2)
     * @param div Uint diviseur
     * @param quotient Uint du quotient de la division
     * @param reste Uint du reste de la division
     */
    void diviserReste(const Uint &div, Uint &quotient, Uint &reste);

    void set_base(int base, int charactere);


private:
    std::string str;
    static uint64_t base;
};

class Base{
public:
    Base(uint64_t);
    uint64_t get_base() const;
private:
    uint64_t val;
};

#endif //NICOLET_LABO21_UINT_HPP
