/**
 * Nom du fichier  : nicolet_labo12.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-10-18
 * Laboratoire n°  : 12
 * Description     : Ce programme imprime des carrés imbriqués avec les lettres de l’alphabet.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>

/**
 * Cette fonction nous permet de retourner un carrée de lettre
 * @param i Paramètre que rentre l'utilisateur
 */
void carreChar(int i);

int main() {
   int valeurUtilisateur = 0;

   std::cout << "Introduiser le nombre de carre voulu : ";
   std::cin >> valeurUtilisateur;

   carreChar(valeurUtilisateur);

   return 0;
}

void carreChar(int i) {
   int carre = i + i - 1;
   for (int axeY = 0; axeY != carre; axeY++) {
      std::cout << std::endl;
      for (int axeX = 0; axeX != carre; axeX++) {
         char lettre = 'A' + (i - 1);
         int min1 = std::min(axeY, axeX);
         int min2 = std::min(carre - 1 - axeY, carre - 1 - axeX);
         lettre -= std::min(min1, min2);
         std::cout << lettre;
      }
   }
}