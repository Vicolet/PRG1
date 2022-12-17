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
    uint64_t x = 2000;// 10010
    uint64_t y = 5; // 10000

    Uint a(x);
    Uint b(y);

    //addition OK 10010 11
    //soustraction OK
    //multiplication OK

//    a -= b;
//    a.affiche();

    Uint reste(0), quotient(0);
    a.divReste(b, quotient, reste);
    std::cout << x << " / " << y << "\nquotient : ";
    quotient.affiche();
    std::cout << "reste : ";
    reste.affiche();


}
