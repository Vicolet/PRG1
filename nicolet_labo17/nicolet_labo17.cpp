/**
 * Nom du fichier  : nicolet_labo17.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-11-22
 * Laboratoire n°  : 17
 * Description     : Manipulation sur les string et les vector
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>
#include <string>
#include <vector>

/**
 * Cette fonction permet de transformer en base 2 un size_t donné
 * @param val permet de connaître la valeur du size_t à mettre en base 2
 * @return un string de la valeur du size_t en base 2
 */
std::string baseDeux(size_t val);

/**
 *
 * @param val
 * @param base
 * @return
 */
std::string changementBase(size_t val, size_t base = 10);

int main() {
   size_t valeurUtilisateur;
   size_t baseUtilisateur;
   std::cout << "Donner un nombre et la base dans la quelle vous voulez le transformer\n"
             << "sous le format 1234(nombre a convertir) 2(base) : ";
   std::cin >> valeurUtilisateur >> baseUtilisateur;

   std::string test2 = changementBase(valeurUtilisateur, baseUtilisateur);
   std::cout << test2;

   return 0;

}

std::string baseDeux(size_t val) {
   std::string str;
   while (val != 0) {
      str = (val % 2 != 0 ? "1" : "0") + str;
      val /= 2;
   }
   return str;
}

std::string changementBase(size_t val, size_t base) {
   std::string str;
   while (!(val / base)) {
      str = (val % base) + str;
      val /= base;
   }
   return str;
}
