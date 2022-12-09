/**
 * Nom du fichier  : main.cpp
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

   void affiche();

   void ajustement(Uint &comparer);

   Uint addition(Uint terme);

   Uint soustraction(Uint terme1);

   Uint multiplication(Uint facteur);

   Uint division(Uint dividende);

private:
   std::string valString;
};


#endif //NICOLET_LABO21_UINT_HPP
