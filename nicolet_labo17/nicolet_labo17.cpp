/**
 * Nom du fichier  : nicolet_labo17.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-11-22
 * Laboratoire n°  : 17
 * Description     : Manipulation sur les string et les vector
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>
#include <string>
#include <vector>

/**
 *
 * @param val
 * @param base
 * @param typo
 * @return
 */
std::string changementBase(size_t val, size_t base = 10, size_t typo = 0);

std::vector<std::string> nombre0 = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14",
                                    "15", "16", "17", "18", "19"};
std::vector<std::string> nombre1 = {"⓪", "①", "②", "③", "④", "⑤", "⑥", "⑦", "⑧", "⑨", "⑩", "⑪", "⑫", "⑬", "⑭",
                                    "⑮", "⑯", "⑰", "⑱", "⑲"};
std::vector<std::string> nombre2 = {"⓿", "❶", "❷", "❸", "❹", "❺", "❻", "❼", "❽", "❾", "❿", "⓫", "⓬", "⓭", "⓮",
                                    "⓯", "⓰", "⓱", "⓲", "⓳"};
std::vector<std::string> nombre3 = {"zero", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf",
                                    "dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept",
                                    "dix-huit", "dix-neuf"};
std::vector<std::vector<std::string>> typoChoix = {nombre0, nombre1, nombre2, nombre3};

int main() {

    size_t valeurUtilisateur, baseUtilisateur, typoUtilisateur;

    std::cout << "Donner un nombre et la base dans la quelle vous voulez le transformer\n"
              << "sous le format 1234(valeur) 2a20(base) 0a2(typo): ";
    std::cin >> valeurUtilisateur >> baseUtilisateur >> typoUtilisateur;

    if (baseUtilisateur < 2 or baseUtilisateur > 20) {
        std::cout << "Erreur: base invalide";
        return 0;
    } else if (typoUtilisateur < 0 or typoUtilisateur > 3) {
        std::cout << "Table de correspondance non disponible";
        return 0;
    }

    std::string test = changementBase(valeurUtilisateur, baseUtilisateur, typoUtilisateur);
    std::cout << test << std::endl;

    return 0;
}


std::string changementBase(size_t val, size_t base, size_t typo) {
    std::string str;
    while (val != 0) {
        str = typoChoix[typo][val % base] + str;
        val = val / base;
    }
    return str;
}
