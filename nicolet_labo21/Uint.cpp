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

Uint::Uint(std::uint64_t val) {
   std::string convertion;
   while (val != 0) {
      convertion = (val % 2 != 0 ? "1" : "0") + convertion;
      val /= 2;
   }
   this->str = convertion;
}

Uint &Uint::operator+=(const Uint &add) {
   Uint somme;
   Uint temp = add;
   this->ajustement(temp);
   int carry = 0;
   for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
      int ilhs = str[i] - '0', irhs = temp.str[i] - '0';
      int res = ilhs + irhs + carry;
      if (res == 0 or res == 2)
         somme.str = "0" + somme.str;
      else
         somme.str = "1" + somme.str;
      carry = res > 1 ? 1 : 0;
   }
   if (carry == 1)
      somme.str = "1" + somme.str;
   somme.enleveZero();

   return (*this = somme);
}

Uint &Uint::operator-=(const Uint &soustraction) {
   Uint result;
   int carry = 0;
   //todo gérer les soustractions par des nombres plus grands 8-7.

   for (int i = this->str.size() - 1; i >= 0; i--) {
      int x = this->str[i] - '0';
      int y = soustraction.str[i] - '0';
      int z = x - y - carry;
      carry = z < 0 ? 1 : 0;
      if (z < 0)
         z += 2;
      result.str.insert(0, 1, z + '0');
   }
   if (carry == 1)
      result.str.insert(0, 1, '1');
   result.enleveZero();
   return (*this = result);
}

Uint &Uint::operator*=(const Uint &mul) {

   Uint chiffre;
   Uint carry;
   Uint result;

   size_t taille = this->str.size() + mul.str.size();
   chiffre.str.resize(taille);
   carry.str.resize(taille);

   //====EXCEPTION====
   // Tester si un des deux nombres est égale à 0
   if ((str.size() == 1 && str.at(0) == 0) ||
       (mul.str.size() == 1 && mul.str.at(0) == 0)) {
      return *this = 0;
   }

   //====ALGO====
   // Ajoute des digits et des carrys
   for (auto i = 0; i <= this->str.size() - 1; i++) {
      for (auto j = 0; j <= mul.str.size() - 1; j++) {
         chiffre.str.at(i + j) += this->str.at(i) * mul.str.at(j) % 1;
         carry.str.at(i + j + 1) += this->str.at(i) * mul.str.at(j) / 1;
      }
   }
   //  Permet de merge les digits et les carrys
   int carrFlag = 0;
   for (auto i = 0; i <= taille - 1; i++) {
      int sum = chiffre.str.at(i) + carry.str.at(i) + carrFlag;
      result.str.push_back(sum % 1);
      carrFlag = sum / 1;
   }

   return (*this = result);
}

void Uint::affiche() {
   std::cout << this->str << std::endl;
}

void Uint::ajustement(Uint &comparer) {
   if (str.size() < comparer.str.size())
      str.insert(0, comparer.str.size() - str.size(), '0');
   else
      comparer.str.insert(0, str.size() - comparer.str.size(), '0');
}

void Uint::enleveZero() {
   this->str.erase(0, std::min(this->str.find_first_not_of('0'), this->str.size()-1));
}

Uint Uint::addition(Uint terme) {
   Uint somme;
   this->ajustement(terme);
   int carry = 0;
   for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
      int ilhs = str[i] - '0', irhs = terme.str[i] - '0';
      int res = ilhs + irhs + carry;
      if (res == 0 or res == 2)
         somme.str = "0" + somme.str;
      else
         somme.str = "1" + somme.str;
      carry = res > 1 ? 1 : 0;
   }
   if (carry == 1)
      somme.str = "1" + somme.str;

   return somme;
}

Uint Uint::soustraction(Uint terme) {
   Uint result;
   int carry = 0;

   for (int i = this->str.size() - 1; i >= 0; i--) {
      int x = this->str[i] - '0';
      int y = terme.str[i] - '0';
      int z = x - y - carry;
      carry = z < 0 ? 1 : 0;
      if (z < 0) z += 2;
      result.str.insert(0, 1, z + '0');
   }
   if (carry == 1) result.str.insert(0, 1, '1');
   result.enleveZero();
   return result;
}

Uint Uint::multipication(Uint facteur) {
   //this->ajustement(facteur);
   Uint produit;
   int multiplication = 0;
   for (size_t i = this->str.size() - 1; i != SIZE_MAX; --i) {
      Uint produitTemp;
      produitTemp.str.insert(0, multiplication, '0');
      for (size_t j = this->str.size() - 1; j != SIZE_MAX; --j) {
         int ilhs = this->str[j] - '0', irhs = facteur.str[i] - '0';
         int res = ilhs * irhs;
         produitTemp.str = res ? "1" + produitTemp.str : "0" + produitTemp.str;
      }
      multiplication++;
      produit.ajustement(produitTemp);
      produit += produitTemp;
   }
   produit.enleveZero();
   return produit;
}

Uint Uint::division(Uint dividende) {
   return Uint();
}








