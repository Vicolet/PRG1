/**
 * Nom du fichier  : nicolet_labo4.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-09-26
 * Laboratoire n°  : 4
 * Description     : Ce programme demande à l'utilisateur d'introduire deux distance en kilomètres, mètres, centimètres
 *                   et millimètres puis les additionnes.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>

int main() {
   int firstUserDistance;
   std::cout << "Entrer une premiere distance : " << std::endl;
   std::cin >> firstUserDistance;

   int secondUserDistance;
   std::cout << "Entrer une seconde distance : " << std::endl;
   std::cin >> secondUserDistance;

   int finalDistance;
   finalDistance = firstUserDistance + secondUserDistance;

   std::cout << km << "km, " << m << "m, " << cm << "cm, " << mm << "mm + "

   Si l’utilisateur introduit
   2 34 56 7 et 9 87 65 4
   Le programme devra répondre
   2km, 34m, 56cm, 7mm + 9km, 87m, 65cm, 4mm font :
   11 km, 122 m, 22 cm, 1 mm







}