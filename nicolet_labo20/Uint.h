/**
 * Nom du fichier  : main.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-12-06
 * Laboratoire n°  : 20
 * Description     : header de la class Uint qui permet de manipuler des nombres entiers naturels de taille quelconque.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#ifndef NICOLET_LABO20_UINT_H
#define NICOLET_LABO20_UINT_H

#include <iostream>
#include <string>
#include <cstdint>

class Uint {
public:
   Uint();

   Uint(std::uint64_t val);

   void affiche();

   Uint addition(Uint terme);

   Uint soustraction(Uint terme1, Uint terme2);

   Uint multiplication(Uint facteur1, Uint facteur2);

   Uint division(Uint dividende, Uint diviseur);

private:
   std::string valString;
};

#endif //NICOLET_LABO20_UINT_H
