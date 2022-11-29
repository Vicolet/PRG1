//
// Created by lord on 29.11.2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#ifndef NICOLET_LABO19_MOT_H
#define NICOLET_LABO19_MOT_H

class Mot {
public:
   void add() {
      redondance += 1;
   }

   Mot(std::string mot) {
      this->mot = mot;
   }

private:
   std::string mot;
   int redondance = 0;
};

#endif //NICOLET_LABO19_MOT_H
