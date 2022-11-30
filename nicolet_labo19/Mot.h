//
// Created by lord on 29.11.2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Mot.cpp"

#ifndef NICOLET_LABO19_MOT_H
#define NICOLET_LABO19_MOT_H

class Mot {
public:
   Mot(std::string mot) {
      this->mot = mot;
      redondance = 1;
   }

   void add() {
      redondance += 1;
   }

   std::string getMot() {
      return mot;
   }

   size_t getRedondance(){
      return redondance;
   }

private:
   std::string mot;
   size_t redondance;
};

#endif //NICOLET_LABO19_MOT_H
