/**
 * Nom du fichier  : nicolet_labo5.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-09-27
 * Laboratoire n°  : 5
 * Description     : Imprime les minutes et les secondes en fonction de l'angle de l'aiguille des minutes
 *                   avec l'horizontale.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>

const int OFFSET = 900;
const int ANGLE_MAX = 3600;
const int SECONDE_PAR_MINUTE = 60;

int main() {

   int angleAiguille, angleReel;
   int minutes, secondes;

   std::cout << "Entrer un angle en dixième de degré : " << std::endl;
   std::cin >> angleAiguille;

   angleReel = angleAiguille % ANGLE_MAX;

   secondes = ((ANGLE_MAX - angleReel) + OFFSET) % ANGLE_MAX;
   minutes = secondes / SECONDE_PAR_MINUTE;
   secondes %= SECONDE_PAR_MINUTE;

   std::cout << minutes << " min. et " << secondes << " s" << std::endl;

   return 0;

}