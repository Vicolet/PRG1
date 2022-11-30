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

size_t dichotomie(std::vector<Mot> dico, Mot mot);

void afficheDico(std::vector<Mot> dico);

int main() {
   std::string fichier = readFile("text_test.txt");
   //
   std::vector<Mot> dictionnaire;
   for (size_t i = 0, j = 0; i < fichier.size(); ++i) {

      if (fichier.at(i) == ' ') {
         Mot mot = fichier.substr(j, i - j);
         //traiter le mot
         size_t pos = dichotomie(dictionnaire, mot);
         dictionnaire.insert(dictionnaire.begin() + pos, mot);
         j = i;
      }
   }
   afficheDico(dictionnaire);
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

size_t dichotomie(std::vector<Mot> dico, Mot mot) {
   size_t min = 0;
   size_t max = dico.size();
   while (0 != (max - min)) {
      size_t pos = (max + min) / 2;
      if (mot.getMot() < dico.at(pos).getMot())
         max = pos;
      else if (mot.getMot() > dico.at(pos).getMot())
         min = pos + 1;
      else
         return pos;
   }
   return 0;
}

void afficheDico(std::vector<Mot> dico) {
   for (Mot i: dico) {
      std::cout << i.getMot() << " : " << i.getRedondance() << std::endl;

   }
}