#ifndef EXERCICE_CLASS_MAIN_H
#define EXERCICE_CLASS_MAIN_H

#include "iostream"

class Point {
public:
   Point(double abcisse, double ordonnee) {
      x = abcisse;
      y = ordonnee;
   }

   // Exercice 68
   void replaceX(double abcisse);

   void replaceY(double ordonnee);

   void deplaceXY(double deltaX, double deltaY);

   void printX();

   void printY();

   // Exercice 69
   /*1. Connaître la distance ρ d’un point par rapport à l’origine
   2. Connaître l’angle θ que fait le segment origine-point par rapport à l’horizontale
   3. Faire subir une rotation d’un angle α à un point*/

   void distance (double point);

   double angleXY (double abcisse, double ordonnee);

   void rotation (double angle);


private:
   double x, y;
};

#endif //EXERCICE_CLASS_MAIN_H
