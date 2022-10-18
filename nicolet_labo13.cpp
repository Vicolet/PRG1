/**
 * Nom du fichier  : nicolet_labo13.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-10-18
 * Laboratoire n°  : 13
 * Description     : Ce programme permet de donner la suite de syracuse donné par un utilisateur.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>

/**
 * Cette fonction nous permet d'effectuer la suite de syracuse
 * @param syrac le nombre qui va être utiliser pour faire sa suite de syracuse
 * @return retourne le nombre d'itération qu'il a fallu au programme pour faire sa suite de syracuse
 */
int suiteSyracuse(int syrac);

int main() {
   int valeurUtilisateur = 0;

   std::cout << "Entrez un nombre entier dans l'intervalle [1, 1000] : ";
   std::cin >> valeurUtilisateur;
   std::cout << std::endl;

   int iterationSyrac = suiteSyracuse(valeurUtilisateur);

   std::cout << "Iteration suite de Syracuse pour n = " << valeurUtilisateur << " : " << iterationSyrac << std::endl;
   //  N = 7 : (7 , 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1)

}

int suiteSyracuse(int syrac) {
   int number_iteration = 0;
   std::cout << "N("<< syrac << ") = [";
   while (syrac != 1) {
      if (syrac % 2 == 0) {
         syrac = syrac / 2;
      } else {
         syrac = (syrac * 3) + 1;
      }
      std::cout << syrac << ", ";
      number_iteration++;
   }
   std::cout << "]" << std::endl;

   return number_iteration;
}

