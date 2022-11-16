/**
 * Nom du fichier  : nicolet_labo16.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-11-15
 * Laboratoire n°  : 16
 * Description     : Exercer l’utilisation des string
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>
#include <string>

/**
 *
 * @param val
 * @return
 */
std::string construire(size_t val);

/**
 *
 * @param val1
 * @param val2
 */
void ajustement(std::string &val1, std::string &val2);

/**
 *
 * @param lhs
 * @param rhs
 * @return
 */
std::string plus(const std::string &lhs, const std::string &rhs);

/**
 *
 * @param lhs
 * @param rhs
 * @return
 */
std::string fois(const std::string &lhs, const std::string &rhs);

int main() {
    size_t valeur1 = 3;
    size_t valeur2 = 3;

    std::string binValeur1 = construire(valeur1);
    std::string binValeur2 = construire(valeur2);

    std::cout << valeur1 << " convertie en binaire donne -> " << binValeur1 << std::endl;
    std::cout << valeur2 << " convertie en binaire donne -> " << binValeur2 << std::endl;

    std::cout << binValeur1 << " et " << binValeur2 << " ajuste donne ";
    ajustement(binValeur1, binValeur2);
    std::cout << binValeur1 << " et " << binValeur2 << std::endl;


    std::cout << binValeur1 << " + " << binValeur2 << " = " << plus(binValeur1, binValeur2) << std::endl;
    // faire une suite de fibo

    //std::cout << binValeur1 << " * " << binValeur2 << " = " << fois(binValeur1, binValeur2) << std::endl;
    // faire une factorielle

}

std::string construire(size_t val) {
    std::string construction;
    while (val != 0) {
        construction = (val % 2 != 0 ? "1" : "0") + construction;
        val /= 2;
    }
    return construction;
}

void ajustement(std::string &val1, std::string &val2) {
    if (val1.size() < val2.size())
        val1.insert(0, val2.size() - val1.size(), '0');
    else
        val2.insert(0, val1.size() - val2.size(), '0');
}

std::string plus(const std::string &lhs, const std::string &rhs) {
    std::string somme;
    int carry = 0;
    for (size_t i = lhs.size() - 1; i != SIZE_MAX; --i) {
        int ilhs = lhs[i] - '0', irhs = rhs[i] - '0';
        int res = ilhs + irhs + carry;
        if (res == 0 or res == 2)
            somme = "0" + somme;
        else if (res == 1 or res == 3)
            somme = "1" + somme;
        if (res > 1)
            carry = 1;
        else if (res <= 1)
            carry = 0;
    }
    if (carry == 1)
        somme = "1" + somme;

    return somme;
}

std::string fois(const std::string &lhs, const std::string &rhs) {
    std::string produit;
    for (size_t i = lhs.size() - 1; i != SIZE_MAX; --i) {
        for (size_t j = lhs.size() - 1; j != SIZE_MAX; --j) {
            int ilhs = lhs[j] - '0', irhs = rhs[i] - '0';
            int res = ilhs * irhs;





        }
    }
}

