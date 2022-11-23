//
// Created by lord on 23.11.2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#ifndef NICOLET_LABO18_NICOLET_LABO18_H
#define NICOLET_LABO18_NICOLET_LABO18_H

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

#endif //NICOLET_LABO18_NICOLET_LABO18_H
