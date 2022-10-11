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

int main() {
   /*
    * Prendre comme première approximation r = x/2
    * Si la valeur de r · r est trop éloignée de x, prendre comme nouvelle approximation la
    * moyenne de r et x/r
    * Recommencer jusqu’à ce que la valeur de r soit satisfaisante
    */
   double valeurUtilisateur = 0.0;
   double racine = 0.0;
   std::cout << "Enter un nombre dont vous voulez connaitre la racine carree : ";
   std::cin >> valeurUtilisateur;
   std::cout << std::endl;

   racine = valeurUtilisateur / 2;



}