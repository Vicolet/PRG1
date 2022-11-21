/**
 * Nom du fichier  : nicolet_labo2.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-09-21
 * Laboratoire n°  : 2
 * Description     : Calcul la date de naissance à partir de l'âge.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>
#include <string>

const int CETTE_ANNEE = 2022;

int main() {

   std::string prenom;
   int age;
   int anneeNaissance;

   std::cout << "Entrer votre prenom: ";
   getline(std::cin, prenom);

   std::cout << "Entrer votre age: ";
   std::cin >> age;

   anneeNaissance = CETTE_ANNEE - age;

   std::cout << "Bonjour " << prenom << "," << std::endl;
   std::cout << "Vous avez " << age << " ans et vous etes ne en " << anneeNaissance << "." << std::endl;

   return 0;

}