/**
 * Nom du fichier  : nicolet_labo3.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-09-21
 * Laboratoire n°  : 3
 * Description     : Ce programme transforme une durée, exprimée en seconde uniquement, vers des semaines, jours,
 *                   heures, minutes, secondes.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>

const int JOUR_PAR_SEMAINE = 7;
const int HEURE_PAR_JOUR = 24;
const int MINUTE_PAR_HEURE = 60;
const int SECONDE_PAR_MINUTE = 60;

int main() {

   int userValor, seconde, minute, heure, jour, semaine;

   std::cout << "Introduisez un nombre de seconde: ";
   std::cin >> userValor;
   std::cout << std::endl;

   minute = userValor / SECONDE_PAR_MINUTE;
   heure = minute / MINUTE_PAR_HEURE;
   jour = heure / HEURE_PAR_JOUR;
   semaine = jour / JOUR_PAR_SEMAINE;

   seconde = userValor % SECONDE_PAR_MINUTE;
   minute = minute % MINUTE_PAR_HEURE;
   heure = heure % HEURE_PAR_JOUR;
   jour = jour % JOUR_PAR_SEMAINE;

   std::cout << userValor << "s = "
             << semaine << "semaine "
             << jour << "jours "
             << heure << "heures "
             << minute << "minutes "
             << seconde << "secondes "
             << std::endl;

   return 0;

}