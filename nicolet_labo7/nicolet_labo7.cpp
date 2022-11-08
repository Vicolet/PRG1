/**
 * Nom du fichier  : nicolet_labo7.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-10-04
 * Laboratoire n°  : 7
 * Description     : Ce programme permet de transformer des degrés Celsius en Fahrenheit et vice versa.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>

int main() {

   char uniteTemp;
   int temperature;
   int converseTemp, converseMod;

   std::cout << "Transformation Fahrenheit <-> Degre Celsius" << std::endl;
   std::cout << "Introduire le sens de la transformation (vers C ou F) : ";
   std::cin >> uniteTemp;
   std::cout << std::endl;

   if (uniteTemp == 'C' || uniteTemp == 'c') {
      std::cout << "Nombre de Fahrenheit: ";
      std::cin >> temperature;
      std::cout << std::endl;
      converseTemp = (temperature - 32) * 5 / 9;
      converseMod = (temperature - 32) * 5 % 9;
      if (converseMod < 0) {
         converseMod *= -1;
      }
      if (converseMod >= 5 && converseTemp >= 0) {
         converseTemp += 1;
      } else if (converseTemp < 0 && converseMod >= 5) {
         converseTemp -= 1;
      }
      std::cout << temperature << " Fahrenheit font " << converseTemp << " deg.Celsius" << std::endl;

   } else if (uniteTemp == 'F' || uniteTemp == 'f') {
      std::cout << "Nombre de deg.Celsius: ";
      std::cin >> temperature;
      std::cout << std::endl;
      converseTemp = temperature * 9 / 5 + 32;
      converseMod = (temperature * 9) % 5;
      if (converseMod < 0) {
         converseMod *= -1;
      }
      if (converseMod <= 3 && converseTemp >= 0) {
         converseTemp += 1;
      } else if (converseMod <= 3 && converseTemp < 0) {
         converseTemp -= 1;
      }
      std::cout << temperature << " deg.Celsius font " << converseTemp << " Fahrenheit" << std::endl;
   }

   return 0;

}

