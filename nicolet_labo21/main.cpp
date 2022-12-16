/**
 * Nom du fichier  : main.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-12-12
 * Laboratoire n°  : 21
 * Description     :
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include "iostream"
#include "Uint.cpp"

int main() {
   uint64_t x = 18;
   uint64_t y = 2;

   Uint a(x);
   Uint b(y);

   //addition OK
   //soustraction OK
   //multiplication OK

   a /= b;
   a.affiche();


}
