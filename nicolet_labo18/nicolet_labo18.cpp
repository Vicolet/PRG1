/**
 * Nom du fichier  : nicolet_labo18.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-11-23
 * Laboratoire n°  : 18
 * Description     : Manipulation sur les string et les vector
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include "nicolet_labo18.h"

std::string readFile (const std::string& fileName);

int main() {
   std::string nomFichier = "la_comedie_humaine.txt";
   std::string fichier = readFile(nomFichier);
   std::vector<Mot> vectorMot;


}

std::string readFile (const std::string& fileName){
   std::string file;
   std::ifstream input_file(fileName, std::ios::in);
   if (!input_file) {
      std::cerr << file << " not found!\n";
      exit(-1);
   }
   std::string original;
   std::getline(input_file, original, '\0');
   input_file.close();
   return original;
}

