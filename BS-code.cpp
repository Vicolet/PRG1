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
#include <fstream>

const double PRECISION = 1.0E-10;

int main() {
   std::ofstream labo10;
   labo10.open("test.csv");
   labo10 << "x" << "," << "iteration"<< std::endl;

   for (double i = 1.0E-100; i < 1.0E+101; i *= 10) {


      int iterationHeron = 0;
      double valeurUtilisateur, approximation = 0.0;
      double division = 2.0;
      double precision = 1.0;

      valeurUtilisateur = i;

      while (precision > PRECISION * approximation || precision < -PRECISION * approximation) {
         iterationHeron++;
         approximation = valeurUtilisateur / division;
         division = (approximation + division) / 2.0;
         precision = approximation - division;
      }
      labo10 << valeurUtilisateur << "," << iterationHeron << std::endl;;
   }
   labo10.close();
   return 0;

}