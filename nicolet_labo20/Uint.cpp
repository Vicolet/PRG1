/**
 * Nom du fichier  : main.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-12-06
 * Laboratoire n°  : 20
 * Description     : Implémentation de la class Uint qui permet de manipuler des nombres entiers naturels
 *                   de taille quelconque.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include "Uint.h"

Uint::Uint() = default;

Uint::Uint(std::uint64_t val) {
   std::string convertion;
   while (val != 0) {
      convertion = (val % 2 != 0 ? "1" : "0") + convertion;
      val /= 2;
   }
   this->valString = convertion;
}

void Uint::affiche() {
   std::cout << this->valString << std::endl;
}

Uint Uint::addition(Uint terme) {
   Uint resultat;
   int carry = 0;
   for (size_t i = valString.size() - 1; i != SIZE_MAX; --i) {
      int ilhs = valString[i] - '0', irhs = terme.valString[i] - '0';
      int res = ilhs + irhs + carry;
      if (res == 0 or res == 2)
         resultat.valString = "0" + resultat.valString;
      else
         resultat.valString = "1" + resultat.valString;
      carry = res > 1 ? 1 : 0;
   }
   if (carry == 1)
      resultat.valString = "1" + resultat.valString;

   return resultat;
}

Uint Uint::soustraction(Uint terme1, Uint terme2) {
   return Uint();
}

Uint Uint::multiplication(Uint facteur1, Uint facteur2) {
   return Uint();
}

Uint Uint::division(Uint dividende, Uint diviseur) {
   return Uint();
}
