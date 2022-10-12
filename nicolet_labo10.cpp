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

// Cette constante nous permet de set la precision à 10 chiffre après la virgule.
const double PRECISION = 1.0E-10;

int main() {

   std::cout << std::setprecision(10);

   int iterationHeron = 0;
   double valeurUtilisateur, approximation = 0.0;

   // Variable "division" initialisé à 2, car 2 est demandé comme première approximation.
   double division = 2.0;
   // Variable "precision" initialisé à 1, car elle doit rentrer dans la boucle pour avoir ça vraie valeur.
   // (peut être initialisé avec toutes les valeurs sauf 0)
   double precision = 1.0;

   std::cout << "Enter un nombre dont vous voulez connaitre la racine carree : ";
   std::cin >> valeurUtilisateur;
   std::cout << std::endl;

   while (precision > PRECISION || precision < -PRECISION) {
      iterationHeron++;
      approximation = valeurUtilisateur / division;
      division = (approximation + division) / 2;
      precision = approximation - division;
   }

   std::cout << "il y a " << iterationHeron << " iterations." << std::endl;
   std::cout << "La racine de " << valeurUtilisateur << " est : " << approximation << std::endl;

   return 0;

}