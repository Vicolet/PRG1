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
 *
 * @param val
 * @param base
 * @param typo
 * @return
 */
std::string changementBase(size_t val, size_t base = 10, size_t typo = 0);

std::vector<std::string> defaut = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19"};
std::vector<std::string> nombre = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19"};
std::vector<std::string> nombre = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19"};


int main() {
   size_t valeurUtilisateur, baseUtilisateur, typoUtilisateur;
   std::cout << "Donner un nombre et la base dans la quelle vous voulez le transformer\n"
             << "sous le format 1234(valeur) 2a20(base) 0a2(typo): ";
   std::cin >> valeurUtilisateur >> baseUtilisateur >> typoUtilisateur;

   if (valeurUtilisateur < 2 or valeurUtilisateur > 20) {
      std::cout << "Erreur: base invalide";
      return 0;
   } else if (typoUtilisateur < 0 or typoUtilisateur > 3) {
      std::cout << "Table de correspondance non disponible";
      return 0;
   }

   std::string test = changementBase(valeurUtilisateur, baseUtilisateur, typoUtilisateur);

   return 0;
}


std::string changementBase(size_t val, size_t base, size_t typo) {
   std::string str;
   while (val / base) {

   }
   return str;
}
