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
   std::uint64_t valTest1 = 2, valTest2 = 3, valTestErreur = 0;

   Uint val1(valTest1);
   Uint val2(valTest2);
   Uint valErreur(valTestErreur);

   std::cout << (Uint(2) < Uint(3)) << std::endl;

//   std::cout << "test des valeurs d'additions : " << std::endl;
//
//   Uint testAdd = val1.addition(val2);
//   std::cout << "membre ";
//   testAdd.affiche();
//
//   Uint operateurPlusEgale = val1;
//   operateurPlusEgale += val2;
//   std::cout << "+= ";
//   operateurPlusEgale.affiche();
//
//   Uint operateurPlus = val1 + val2;
//   std::cout << "+ ";
//   operateurPlus.affiche();

   std::cout << "test des valeurs de soustractions : " << std::endl;

//   Uint testSub = val1.soustraction(val2);
//   std::cout << "membre ";
//   testSub.affiche();

   Uint operateurMoinsEgale = val1;
   operateurMoinsEgale -= val2;
   std::cout << "-= ";
   operateurMoinsEgale.affiche();

   Uint operateurMoins = val1 - val2;
   std::cout << "- ";
   operateurMoins.affiche();

//   std::cout << "test des valeurs de multiplications : " << std::endl;
//
//   Uint testMul = val1.multipication(val2);
//   std::cout << "membre ";
//   testMul.affiche();
//
//   Uint operateurFoisEgale = val1;
//   operateurFoisEgale *= val2;
//   std::cout << "*= ";
//   operateurFoisEgale.affiche();
//
//   Uint operateurFois = val1 * val2;
//   std::cout << "* ";
//   operateurFois.affiche();

//   std::cout << "test des valeurs de divisions : " << std::endl;
//
//   Uint testDiv = val1.division(val2);
//   testDiv.affiche();
//
//   Uint operateurDiviserEgale = val1;
//   operateurDiviserEgale /= val2;
//   operateurDiviserEgale.affiche();
//
//   Uint operateurDiviser = val1 / val2;
//   operateurDiviser.affiche();
}
