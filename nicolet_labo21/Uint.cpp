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

Uint &Uint::operator-=(const Uint &sub) {
   Uint diff;
   Uint temp = sub;
   int carry = 0;

   if ((*this) < temp) {
      std::cout << "test comparaison : " << std::endl;
      temp.str = "erreur";
      *this = temp;
      return *this;
   }

   this->ajustement(temp);

   for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
      int x = this->str[i] - '0';
      int y = temp.str[i] - '0';
      int z = x - y - carry;
      carry = z < 0 ? 1 : 0;
      if (z < 0) z += 2;
      diff.str.insert(0, 1, z + '0');
   }
   if (carry == 1) diff.str.insert(0, 1, '1');
   diff.enleveZero();
   return *this = diff;
}

Uint &Uint::operator*=(const Uint &mul) {
   Uint produit;
   Uint temp = mul;
   int multiple = 0;

   //test si un des deux facteurs est egale à 0
   if (this->str.size() == 1 and this->str[0] == '0')
      return *this;
   if (temp.str.size() == 1 and temp.str[0] == '0')
      return *this = temp;

   this->ajustement(temp);

   for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
      Uint produitTemp;
      produitTemp.str.insert(0, multiple, '0');
      for (size_t j = str.size() - 1; j != SIZE_MAX; --j) {
         int ilhs = this->str[j] - '0', irhs = temp.str[i] - '0';
         int res = ilhs * irhs;
         produitTemp.str = res ? "1" + produitTemp.str : "0" + produitTemp.str;
      }
      multiple++;
      produit.ajustement(produitTemp);
      produit += produitTemp;
   }
   produit.enleveZero();
   return *this = produit;
}

Uint &Uint::operator/=(const Uint &div) {
   Uint quotient;
   Uint reste = *this;
   Uint temp = div;

   if (temp == 0) {
      quotient.str = "erreur";
      return *this = quotient;
   }

   if (*this < temp)
      return *this;

   if (*this == 0) {
      quotient.str = "0";
      return *this = quotient;
   }

   temp.str.append(this->str.size() - temp.str.size(), '0'); //ajout de 0 à la fin de temp
   // todo trouver la condition pour ma boucle for
   while (reste >= temp) {
      reste = *this;
      if (*this < temp) {
         quotient.str = '0' + quotient.str;
      } else {
         quotient.str = '1' + quotient.str;
         *this -= temp;
      }
      temp.str.pop_back(); //enlève le dernier 0
   }
   quotient.enleveZero();
   return *this = quotient;
}

Uint &Uint::operator%=(const Uint &mod) {
}

Uint operator+(Uint terme1, const Uint &terme2) { return terme1 += terme2; }

Uint operator-(Uint terme1, const Uint &terme2) { return terme1 -= terme2; }

Uint operator*(Uint facteur1, const Uint &facteur2) { return facteur1 *= facteur2; }

Uint operator/(Uint dividende, const Uint &diviseur) { return dividende /= diviseur; }

Uint operator%(Uint dividende, const Uint &diviseur) { return dividende %= diviseur; }

int Uint::operator<=>(const Uint &comparer) {
   if (this->str.size() > comparer.str.size())
      return 1;
   else if (this->str.size() < comparer.str.size())
      return -1;
   else {
      for (size_t i = str.size() - 1; i != SIZE_MAX; --i) {
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
   this->str.erase(0, std::min(this->str.find_first_not_of('0'), this->str.size() - 1));
}

Uint Uint::division(Uint dividende) {
   return Uint();
}

int Uint::comparaison(Uint comparer) {
   if (this->str.size() > comparer.str.size())
      return 1;
   else if (this->str.size() < comparer.str.size())
      return -1;
   else {
      for (int i = 0; i < this->str.size() - 1; ++i) {
         if (this->str.at(i) < comparer.str.at(i))
            return -1;
         else if (this->str.at(i) > comparer.str.at(i))
            return 1;
      }
   }
   return 0;
}

void Uint::fonctionBS(Uint &x) {

}

















