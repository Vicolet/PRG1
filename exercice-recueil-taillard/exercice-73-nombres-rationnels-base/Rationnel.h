//
// Created by lord on 05.12.2022.
//

#ifndef EXERCICE_73_NOMBRES_RATIONNELS_BASE_RATIONNEL_H
#define EXERCICE_73_NOMBRES_RATIONNELS_BASE_RATIONNEL_H

class Rationnel {
public:
   Rationnel(int denom, int numer) {
      this->denominateur = denom;
      this->numerateur = numer;
   }

   Rationnel &operator+();

   Rationnel &operator-();

   Rationnel operator*=();

   Rationnel operator*();

   Rationnel operator/=();

   Rationnel operator/();

private:
   int denominateur = 0;
   int numerateur = 0;

};

#endif //EXERCICE_73_NOMBRES_RATIONNELS_BASE_RATIONNEL_H
