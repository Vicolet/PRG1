/**
 * Nom du fichier  : nicolet_labo8.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-10-04
 * Laboratoire n°  : 8
 * Description     : Ce programme permet de trouver un quadrilatère en fonction des coordonnées entrées par
 *                   l'utilisateur et indique si le quadrilatère est un carré, un rectangle, un losange,
 *                   un parallélogramme, un trapèze ou aucune de ces formes.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/



#include <iostream>

int main() {

   int x1, y1, x2, y2, x3, y3, x4, y4;

   std::cout << "Entrer 4 coordonnees sous forme (x,y) exemple -> 9 1" << std::endl;

   std::cout << "premiere Coordonnees : ";
   std::cin >> x1 >> y1;
   std::cout << std::endl;

   std::cout << "deuxieme Coordonnees : ";
   std::cin >> x2 >> y2;
   std::cout << std::endl;

   std::cout << "troisieme Coordonnees : ";
   std::cin >> x3 >> y3;
   std::cout << std::endl;

   std::cout << "quatrieme Coordonnees : ";
   std::cin >> x4 >> y4;
   std::cout << std::endl;

}

