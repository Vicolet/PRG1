/**
 * Nom du fichier  : main.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-12-06
 * Laboratoire n°  : 20
 * Description     : Création d’une class Uint qui permet de manipuler des nombres entiers naturels
 *                   de taille quelconque.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include "Uint.h"
#include "Uint.cpp"

int main() {
   std::uint64_t valTest1 = 3, valTest2 = 1, valTestErreur = 0;

   Uint val1(valTest1);
   Uint val2(valTest2);
   Uint valErreur(valTestErreur);

   Uint testAdd = val1.addition(val2);
   testAdd.affiche();
   Uint testSub = val1.soustraction(val2);
   testSub.affiche();

   return 0;
}
