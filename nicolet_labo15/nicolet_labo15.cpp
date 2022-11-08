/**
 * Nom du fichier  : nicolet_labo15.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-11-08
 * Laboratoire n°  : 15
 * Description     : Exercer l’utilisation des string
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>
#include <string>
#include <fstream>

size_t find(std::string &str, std::string &s, size_t pos);
std::string & replace_all(std::string & str, const std::string & from, const std::string & to);

int main() {
   std::string fichier = "la_comedie_humaine.txt";
   //std::cout << "Nom du fichier: ";
   //std::getline(std::cin, fichier, '\n');

   std::ifstream input_file(fichier, std::ios::in);
   if (!input_file) {
      std::cerr << fichier << " not found!\n";
      exit(-1);
   }
   std::string original;
   std::getline(input_file, original, '\0');
   input_file.close();

   std::string from, to;
   std::cout << "Rechercher: ";
   std::getline(std::cin, from, '\n');
   std::cout << "Tout remplacer par: ";
   std::getline(std::cin, to, '\n');

   size_t nb = 0, pos = 0;
   while (pos < std::string::npos)
      if ((pos = find(original, from, pos)) < std::string::npos) {
         nb++;
         pos++;
      }
   std::cout << from << " trouve " << nb << " fois\n";

   std::string modif = original;
   replace_all(modif, from, to);
   std::cout << modif;
   replace_all(modif, to, from);
   if (modif == original)
      std::cout << "OK\n";
   else
      std::cout << "KO\n";


}

size_t find(std::string &str, std::string &s, size_t pos) {
   if (str.empty() || s.empty() || str.size() < s.size())
      return std::string::npos;
   for (size_t i = pos; i < str.size(); i++) {
      size_t j = 0;
      while (j < s.size() && str[i + j] == s[j])
         j++;
      if (j == s.size())
         return 1;
   }
   return std::string::npos;
}

std::string & replace_all(std::string & str, const std::string & from, const std::string & to){


}
