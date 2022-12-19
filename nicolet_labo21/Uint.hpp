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

   Uint &operator+=(const Uint &add);
   Uint &operator-=(const Uint &sub);
   Uint &operator*=(const Uint &mul);
   Uint &operator/=(const Uint &div);
   Uint &operator%=(const Uint &mod);
   Uint &operator<<=(const uint64_t &lhs);

   friend Uint operator+(Uint terme1, const Uint &terme2);
   friend Uint operator-(Uint terme1, const Uint &terme2);
   friend Uint operator*(Uint facteur1, const Uint &facteur2);
   friend Uint operator/(Uint dividende, const Uint &diviseur);
   friend Uint operator%(Uint dividende, const Uint &diviseur);
   friend Uint operator<<(Uint decalage, const uint64_t &position);

   int operator<=>(const Uint &comparer);
   bool operator==(const Uint &comparer);

   void ajustement(Uint &comparer);
   void enleveZero();
   void diviserReste(const Uint &a, Uint &quotient, Uint &reste);
   void set_base(int base, int charactere);


private:
   std::string str;
};

#endif //NICOLET_LABO21_UINT_HPP
