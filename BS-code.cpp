/**
 * Nom du fichier  : nicolet_labo10.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-10-11
 * Laboratoire n°  : 10
 * Description     : Ce programme permet de calculer la racine carrée d’un nombre de type double positif avec
 *                   10 chiffres significatifs grace à l’algorithme de Héron d’Alexandrie
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>
#include <iomanip>

const double PRECISION = 1.0E-10;
const double ESTIMATION_DE_DEPART = 2.0;

int main() {

   std::cout << std::setprecision(11);

   bool flagNegatif = false;
   int iterationHeron = 0;
   double valeurUtilisateur = 0.0, approximation =0.0;
   double division = 2.0;
   double precision = 1.0;

   while (not flagNegatif) {
      std::cout << "Entrer un nombre dont vous voulez connaitre la racine carree : ";
      std::cin >> valeurUtilisateur;
      std::cout << std::endl;

      if (valeurUtilisateur < 0) {
         std::cout << "Le nombre ne doit pas etre negatif ! " << std::endl;
      } else if (valeurUtilisateur == 0) {
         std::cout << "La racine de " << valeurUtilisateur << " est : " << approximation << std::endl;
         std::cout << "Il y a " << iterationHeron << " iterations." << std::endl;
         return 0;
      } else {
         flagNegatif = true;
      }
   }

   while (precision > PRECISION * approximation|| precision < -PRECISION * approximation) {
      iterationHeron++;
      approximation = valeurUtilisateur / division;
      division = (approximation + division) / 2.0;
      precision = approximation - division;
   }

   std::cout << "La racine de " << valeurUtilisateur << " est : " << approximation << std::endl;
   std::cout << "Il y a " << iterationHeron << " iterations." << std::endl;

   return 0;

}