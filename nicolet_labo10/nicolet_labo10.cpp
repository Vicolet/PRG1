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

/**
 * Cette constante nous permet donner une précision de 10 chiffre après la virgule.+¦
 */
const double PRECISION = 1.0E-10;

int main() {

   /**
    * Nous permet de donner une précision à l'affichage (et d'afficher 10 chiffres
    */
   std::cout << std::setprecision(10);

   bool flagNegatif = false;
   int iterationHeron = 0;
   double valeurUtilisateur, approximation = 0.0;

   /**
    * Variable "division" initialisé à 2, car 2 est demandé comme première approximation.
    */
   double division = 2.0;

   /**
    * Variable "precision" initialisé à 1, car elle doit rentrer dans la boucle pour avoir ça vraie valeur.
    * (peut être initialisé avec toutes les valeurs sauf 0)
    */
   double precision = 1.0;

   /**
    * Cette boucle while permet de tester si la valeur entrée par l'utilisateur est négative ou égale à 0, si la valeur
    * est negative le programme demande une nouvelle valeur à l'utilisateur. Si la valeur est égale à 0 la structure de
    * mon programme m'oblige à en faire un cas exceptionnel.
    */
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

   /**
    * Cette boucle while permet d'effectuer l'algorithme d'Héron d’Alexandrie en fonction de la précision voulue, la
    * précision voulue est donné avant le main avec la constante PRECISION et dans ce cas elle modifié pour pouvoir être
    * efficace avec les très grand comme les très petit nombre.
    */
   while (precision > PRECISION * approximation || precision < -PRECISION * approximation) {
      iterationHeron++;
      approximation = valeurUtilisateur / division;
      division = (approximation + division) / 2.0;
      precision = approximation - division;
   }

   std::cout << "La racine de " << valeurUtilisateur << " est : " << approximation << std::endl;
   std::cout << "Il y a " << iterationHeron << " iterations." << std::endl;

   return 0;

}