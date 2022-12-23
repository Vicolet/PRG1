/**
 * Nom du fichier  : main.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-12-12
 * Laboratoire n°  : 21
 * Description     :
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>
#include "Uint.hpp"
#include "Prime.hpp"
#include <ctime>

Uint fibo(size_t n) {
    Uint f_i_moins_1(0), f_i(1), f_i_plus_1;
    if (n == 0) return f_i_moins_1;
    if (n == 1) return f_i;
    for (size_t i = 2; i <= n; i++) {
        f_i_plus_1 = f_i_moins_1 + f_i;
        f_i_moins_1 = f_i;
        f_i = f_i_plus_1;
    }
    return f_i;
}

Uint factorielle(size_t n) {
    Uint res(1);
    for (size_t i = 2; i <= n; i++)
        res *= i;
    return res;
}

/*
 g++ -std=c++20 -g -O5 -Wall -Weffc++ -pedantic -pedantic-errors -Wextra -Wcast-align -Wcast-qual  -Wchar-subscripts  -Wcomment -Wconversion -Wdisabled-optimization -Wfloat-equal  -Wformat  -Wformat=2  -Wformat-nonliteral -Wformat-security  -Wformat-y2k -Wimport  -Winit-self  -Winvalid-pch   -Wunsafe-loop-optimizations  -Wmissing-braces -Wmissing-field-initializers -Wmissing-format-attribute   -Wmissing-include-dirs -Wmissing-noreturn -Wpacked  -Wparentheses  -Wpointer-arith -Wredundant-decls -Wreturn-type -Wsequence-point  -Wshadow -Wsign-compare  -Wsign-conversion -Wstack-protector -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch  -Wswitch-default -Wswitch-enum -Wtrigraphs  -Wuninitialized -Wunknown-pragmas  -Wunreachable-code -Wunused -Wunused-function  -Wunused-label  -Wunused-parameter -Wunused-value  -Wunused-variable  -Wvariadic-macros -Wvla -Wvolatile-register-var  -Wwrite-strings

 */

int main() {

//    Uint a(3), b(2);
//    Uint c = a + b;
//    std::cout << c;

//    Uint b(128);
//    for (int i = 0; i < 100; ++i) {
//        Uint a = Uint::genere_uint_aleatoire(b);
//        std::cout << a << ", ";
//    }


//    for (int i = 0; i < 100; ++i) {
//        Uint a = i;
//        if (prime(a))
//            std::cout << i << ", ";
//    }


    Uint a(1313451), b(2341);

    clock_t addStart = clock();
    for (int i = 0; i < 5000; ++i) {
        Uint c = a + b;
    }

    clock_t addEnd = clock();
    double add = (addEnd - addStart) / (double) CLOCKS_PER_SEC * 1000000;
    std::cout << "Tim to + : " << add << " microseconde" << std::endl;

    clock_t subStart = clock();
    for (int i = 0; i < 5000; ++i) {
        Uint c = a - b;
    }

    clock_t subEnd = clock();
    double sub = (subEnd - subStart) / (double) CLOCKS_PER_SEC * 1000000;
    std::cout << "Tim to - : " << sub << " microseconde" << std::endl;

    clock_t mulStart = clock();
    for (int i = 0; i < 5000; ++i) {
        Uint c = a * b;
    }

    clock_t mulEnd = clock();
    double mul = (mulEnd - mulStart) / (double) CLOCKS_PER_SEC * 1000000;
    std::cout << "Tim to * : " << mul << " microseconde" << std::endl;

    clock_t divStart = clock();
    for (int i = 0; i < 5000; ++i) {
        Uint c = a / b;
    }

    clock_t divEnd = clock();
    double div = (divEnd - divStart) / (double) CLOCKS_PER_SEC * 1000000;
    std::cout << "Tim to / : " << div << " microseconde" << std::endl;

    clock_t modStart = clock();
    for (int i = 0; i < 5000; ++i) {
        Uint c = a % b;
    }

    clock_t modEnd = clock();
    double mod = (modEnd - modStart) / (double) CLOCKS_PER_SEC * 1000000;
    std::cout << "Tim to % : " << mod << " microseconde" << std::endl;



/*
    clock_t start = clock();

    Uint a(10);
    std::cout << "Constructeur avec size_t OK\n";

    Uint b;
    std::cout << "Constructeur vide OK\n";

    b = 3;
    std::cout << "Affectation OK\n";

    const Uint c = 13;
    std::cout << uint64_t(c) << " = 13: cast explicite vers uint64_t\n";

    if (a < c)
        std::cout << "Operateur < OK\n";
    else
        std::cout << "a < c : " << (a < c) << " pas bon!!!\n";

    b += a;
    std::cout << "Operateur+=\n";

    if (c == b)
        std::cout << "Comparaison == OK\n";
    else
        std::cout << "c == b : " << (c == b) << " Operateur == ou += pas bon!!!\n";

    a = fibo(50);
    std::cout << "fibo(50)\n";

    b = fibo(51);
    const Uint d = fibo(52);
    if (d == a + b)
        std::cout << "Operateur+ OK\n";
    else
        std::cout << "+ ou == pas bon!!!\n";

    if (d - b != a)
        std::cout << "- ou != pas bon!!!\n";
    else
        std::cout << "Operateur- OK\n";

    a = factorielle(50);
    std::cout << "Factorielle\n";

    b = factorielle(51);
    if (51 * a == b)
        std::cout << "Operateur* et *= OK\n";
    else
        std::cout << "* ou *= ou == pas bon!!!\n";

    if (51 != b / a)
        std::cout << "/ ou != pas bon!!!\n";
    else
        std::cout << "Operateur/ OK\n";

    std::cout << "51! en base 10 = " << b << std::endl;

    //  Le modificateur set_base(...) n'affecte que la prochaine impression d'un Uint
    std::cout << set_base(16) << "Modificateur d'impression Uint\n";
    std::cout << "51! en base 16 = " << b << std::endl;

    std::cout << "52e terme de la suite de Fibonacci, en base 10 = " << d << std::endl;

    a = 1;
    a <<= 99;
    std::cout << "Operateur <<=\n";

    std::cout << "2 ^ 99 = " << a << std::endl;

    b = (Uint(1) << 100) - 1;
    std::cout << "Operateur <<\n";

    // initialisation de le constante
    const uint64_t LOWER_CASE = 1;

    std::cout << set_base(16, LOWER_CASE);
    std::cout << "2 ^ 100 - 1 (base 16, bas de casse) = " << b << std::endl;

    std::cout << "10 plus petits nombres premiers > 2^99\n";
    size_t nb = 0;
    while (nb < 10) {
        if (prime(a)) {
            std::cout << a << std::endl;
            nb++;
        }
        ++a;
    }
    std::cout << "10 plus grands nombres premiers < 2^100\n";
    nb = 0;
    while (nb < 10) {
        if (prime(b)) {
            std::cout << b << std::endl;
            nb++;
        }
        --b;
    }

    clock_t end = clock();
    double elapsed_time = (end - start) / (double) CLOCKS_PER_SEC * 1000;
    std::cout << "Temps d'exécution : " << elapsed_time << " milliseconds" << std::endl;

    return 0;
*/

}
