#include <iostream>
#include <iomanip>
#include <fstream>

const double PRECISION = 1.0E-10;

int main() {
   int iterationHeron;
   double valeurUtilisateur = 0.0, approximation;
   double division;
   double precision;

   std::cout << std::setprecision(10);
   std::ofstream labo10;
   labo10.open("nicolet_labo10_csv.csv");
   labo10 << "valeur de x, iteration \n";

   for (double i = 1; i < 1E9; i *= 10) {
      iterationHeron = 0;
      valeurUtilisateur = i;
      approximation = 0.0;
      division = 2.0;
      precision = 1.0;

      while (precision > PRECISION || precision < -PRECISION) {
         iterationHeron++;
         approximation = valeurUtilisateur / division;
         division = (approximation + division) / 2;
         precision = approximation - division;
      }
      labo10 << valeurUtilisateur << "," << iterationHeron << "\n";
   }

   labo10.close();
   return 0;

}