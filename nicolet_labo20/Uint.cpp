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

void Uint::ajustement(Uint &comparer) {
   if (valString.size() < comparer.valString.size())
      valString.insert(0, comparer.valString.size() - valString.size(), '0');
   else
      comparer.valString.insert(0, valString.size() - comparer.valString.size(), '0');
}

Uint Uint::addition(Uint terme) {
   Uint somme;
   this->ajustement(terme);
   int carry = 0;
   for (size_t i = valString.size() - 1; i != SIZE_MAX; --i) {
      int ilhs = valString[i] - '0', irhs = terme.valString[i] - '0';
      int res = ilhs + irhs + carry;
      if (res == 0 or res == 2)
         somme.valString = "0" + somme.valString;
      else
         somme.valString = "1" + somme.valString;
      carry = res > 1 ? 1 : 0;
   }
   if (carry == 1)
      somme.valString = "1" + somme.valString;

   return somme;
}

Uint Uint::soustraction(Uint terme) {
   Uint difference;
   if (valString.size() < terme.valString.size())
      return difference.valString = ""

   return Uint();
}

Uint Uint::multiplication(Uint facteur) {
   Uint produit;
   int multiplication = 0;
   for (size_t i = valString.size() - 1; i != SIZE_MAX; --i) {
      std::string produitTemp;
      produitTemp.insert(0, multiplication, '0');
      for (size_t j = valString.size() - 1; j != SIZE_MAX; --j) {
         int ilhs = valString[j] - '0', irhs = facteur.valString[i] - '0';
         int res = ilhs * irhs;
         produitTemp = res ? "1" + produitTemp : "0" + produitTemp;
      }
      multiplication++;
      ajustement(produit, produitTemp);
      produit = addition(produitTemp, produit);
   }
   return produit;
}

Uint Uint::division(Uint dividende) {
   return Uint();
}


