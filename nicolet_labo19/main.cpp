/**
 * Nom du fichier  : main.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-11-29
 * Laboratoire n°  : 19
 * Description     : Manipulation sur les string et les vector
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include "Mot.h"

std::string readFile(const std::string &fileName);

int main() {
   std::string fichier = readFile("text_test.txt");
   std::vector<Mot> Dictionnaire;
   for (size_t i = 0, j = 0; i < fichier.size(); ++i) {
      if (fichier.at(i) == ' ') {
         Mot m = fichier.substr(j, i - j);
         dichotomi(Dictionnaire, m);
      }
   }
}

std::string readFile(const std::string &fileName) {
   std::ifstream input_file(fileName, std::ios::in);
   if (!input_file) {
      std::cerr << fileName << " not found!\n";
      exit(-1);
   }
   std::string file;
   std::getline(input_file, file, '\0');
   input_file.close();
   return file;
}