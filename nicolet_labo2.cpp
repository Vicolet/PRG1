/**
 * Nom du fichier  : nicolet_labo2.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-09-21
 * Laboratoire n°  : 2
 * Description     : Calcul la date de naissance à partir de l'âge
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>
#include <string>

int main() {
   std::string prenom;
   int age;
   int annee_naissance;

   std::cout << "Entrer votre prenom: ";
   getline(std::cin, prenom);

   std::cout << "Entrer votre age: ";
   std::cin >> age;

   annee_naissance = 2022 - age;

   std::cout << "Bonjour " << prenom << "," << std::endl;
   std::cout << "Vous avez " << age << " ans et vous etes ne en " << annee_naissance << "." << std::endl;

   return 0;
}