/**
 * Nom du fichier  : nicolet_labo14.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-11-01
 * Laboratoire n°  : 14
 * Description     : Ce programme permet d'implémenter des fonctions simples.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>
#include <functional>
#include <random>

/**
 *
 * @param base
 * @param exposant
 * @param modulo
 * @return
 */
uint64_t exponentiationModulaire(uint64_t base, uint64_t exposant, uint64_t modulo);

/**
 *
 * @param nombrePremier ce paramètre représente la valeur sur la quelle on veut faire le test de primalité.
 * @return un booléen pour savoir si le nombre tester est premier True si premier False si pas premier.
 */
bool testPrimalite(uint64_t nombrePremier);

int main() {
   uint64_t valeurUtilisateur;
   std::cout << "Entrer une valeur dont vous voulez tester le primalite : ";
   std::cin >> valeurUtilisateur;
   std::cout << std::endl;
   if (testPrimalite(valeurUtilisateur)) {
      std::cout << valeurUtilisateur << " est un nombre premier." << std::endl;
   } else {
      std::cout << valeurUtilisateur << " n'est pas un nombre premier." << std::endl;
   }
   return 0;
}

uint64_t exponentiationModulaire(uint64_t base, uint64_t exposant, uint64_t modulo) {
   uint64_t r = 1;

   while (exposant > 0) {
      if (exposant % 2 == 0) {
         base = base * base % modulo;
         exposant = exposant / 2;
      } else {
         r = r * base % modulo;
         exposant--;
      }
   }
   return r;
}

bool testPrimalite(uint64_t nombrePremier) {
   if (nombrePremier < 2) {
      return false;
   }
   if (nombrePremier == 2) {
      return true;
   }
   for (uint64_t i = 0; i != 10; i++) {
      auto gen_int1_3 = std::bind(std::uniform_int_distribution<uint64_t>(1, nombrePremier - 1), std::mt19937(987));
      uint64_t nombreAleatoire = gen_int1_3();

      if (exponentiationModulaire(nombreAleatoire, nombrePremier - 1, nombrePremier) != 1) {
         return false;
      }

      uint64_t q = 1, u = nombrePremier - 1;

      while ((u % 2 == 0) && (q == 1)) {
         u = u / 2;
         q = exponentiationModulaire(nombreAleatoire, u, nombrePremier);

         if ((q != 1) && (q != nombrePremier - 1)) {
            return false;
         }
      }
   }
   return true;
}
