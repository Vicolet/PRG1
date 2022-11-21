<<<<<<< HEAD
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
||||||| 3935752
#include <iostream>
#include <iomanip>
#include <fstream>

const double PRECISION = 1.0E-10;

int main() {
   int iterationHeron;
   double valeurUtilisateur = 0.0, approximation;
   double division;
   double precision;

   std::cout << std::setprecision(10);
   std::ofstream labo10;
   labo10.open("nicolet_labo10_csv.csv");
   labo10 << "valeur de x, iteration \n";

   for (double i = 1; i < 1E9; i *= 10) {
      iterationHeron = 0;
      valeurUtilisateur = i;
      approximation = 0.0;
      division = 2.0;
      precision = 1.0;

      while (precision > PRECISION || precision < -PRECISION) {
         iterationHeron++;
         approximation = valeurUtilisateur / division;
         division = (approximation + division) / 2;
         precision = approximation - division;
      }
      labo10 << valeurUtilisateur << "," << iterationHeron << "\n";
   }

   labo10.close();
   return 0;

}
=======
>>>>>>> 631c032e69a5bf3a961bf46d33570e515767a618
