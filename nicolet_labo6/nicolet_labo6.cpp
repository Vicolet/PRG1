/**
 * Nom du fichier  : nicolet_labo6.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-09-28
 * Laboratoire n°  : 6
 * Description     : Ce programme permet de calculer la durée d'un trajet grace à deux entrée utilisateur.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>

int const MINUTE_PAR_HEURE = 60;
int const MINUTE_PAR_JOUR = 1440;

int main() {

   int heureDepart, heureArrivee, minuteDepart, minuteArrivee;
   char poubelleDepart, poubelleArrivee;

   std::cout << "entre une heure et une minute de depart : " << std::endl;
   std::cin >> heureDepart >> poubelleDepart >> minuteDepart;

   // Transforme les heures en minute
   minuteDepart += heureDepart * MINUTE_PAR_HEURE;

   std::cout << "entre une heure et une minute d'arrivee : " << std::endl;
   std::cin >> heureArrivee >> poubelleArrivee >> minuteArrivee;

   // Transforme les heures en minute
   minuteArrivee += heureArrivee * MINUTE_PAR_HEURE;

   // Convertie le trajet en minute en heure et minute
   int trajetDuree = ((minuteArrivee - minuteDepart) + MINUTE_PAR_JOUR) % MINUTE_PAR_JOUR;
   int trajetHeure = trajetDuree / MINUTE_PAR_HEURE;
   int trajetMinute = trajetDuree % MINUTE_PAR_HEURE;

   std::cout << trajetHeure << "h" << trajetMinute << std::endl;

   return 0;

}