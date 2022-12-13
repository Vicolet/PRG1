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

class Uint {
public:
   Uint();

   Uint(std::uint64_t val);

   Uint &operator+=(const Uint &add);

   friend Uint operator+(const Uint &terme1, const Uint &terme2) {
      Uint tmp = terme1;
      tmp += terme2;
      return tmp;
   }

   Uint &operator-=(const Uint &sub);

   friend Uint operator-(const Uint &terme1, const Uint &terme2) {
      Uint tmp = terme1;
      tmp -= terme2;
      return tmp;
   }

   Uint &operator*=(const Uint &mul);

   friend Uint operator*(const Uint &facteur1, const Uint &facteur2) {
      Uint tmp = facteur1;
      tmp *= facteur2;
      return tmp;
   }

   Uint &operator/=(const Uint &div);

   friend Uint operator/(const Uint &dividende, const Uint &diviseur) {
      Uint tmp = dividende;
      tmp /= diviseur;
      return tmp;
   }

   Uint &operator%=(const Uint &mod);

   friend Uint operator%(const Uint &dividende, const Uint &diviseur) {
      Uint tmp = dividende;
      tmp %= diviseur;
      return tmp;
   }

   void affiche();

   void ajustement(Uint &comparer);

   void enleveZero();

   Uint addition(Uint terme);

   Uint soustraction(Uint terme1);

   Uint multipication(Uint facteur);

   Uint division(Uint dividende);

private:
   std::string str;
};


#endif //NICOLET_LABO21_UINT_HPP
