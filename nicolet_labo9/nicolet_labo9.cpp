/**
 * Nom du fichier  : nicolet_labo9.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-10-11
 * Laboratoire n°  : 9
 * Description     : Ce programme permet de lire une suite de valeurs non négatives de type double et qui affiche leur
 *                   moyenne et leur variance.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>

int main() {
   double valeurUtilisateur = 0.0;
   double moyenne = 0.0;
   double variance = 0.0;
   double somme = 0.0;
   double sommeCarre = 0.0;
   int n = 0;

   while (1) {

      std::cout << "Entrer des valeurs non negatif de type double : ";
      std::cin >> valeurUtilisateur;
      std::cout << std::endl;

      if (valeurUtilisateur < 0) {
         break;
      }

      std::cout << "Si vous avez termine entrer une valeur negative." << std::endl;;

      ++n;
      somme = somme + valeurUtilisateur;
      sommeCarre = sommeCarre + valeurUtilisateur * valeurUtilisateur;
   }
   moyenne = somme / n;
   variance = (sommeCarre - somme * somme / n) / n - 1;

   if (n == 0) {
      std::cout << "On ne peut pas calculer la moyenne ni la variance si il n'y a pas plus de un nombre.";
   } else if (n <= 1) {
      std::cout << "Moyenne : " << moyenne << " Variance : On ne peut pas calculer la variance d'un nombre.";
   } else {
      std::cout << "Moyenne : " << moyenne << " Variance : " << variance;
   }

   return 0;

}

