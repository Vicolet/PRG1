/**
 * Nom du fichier  : nicolet_labo4.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-09-26
 * Laboratoire n°  : 4
 * Description     : Ce programme demande à l'utilisateur d'introduire deux distance en kilomètres, mètres, centimètres
 *                   et millimètres puis les additionnes.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>

const int MM_PAR_CM = 10;
const int CM_PAR_M = 100;
const int M_PAR_KM = 1000;

int main() {

   int km1, m1, cm1, mm1;
   int km2, m2, cm2, mm2;
   int km3, m3, cm3, mm3;
   int kmf, mf, cmf, mmf;

   std::cout << "Entrer une premiere distance : " << std::endl;
   std::cin >> km1 >> m1 >> cm1 >> mm1;

   std::cout << "Entrer une seconde distance : " << std::endl;
   std::cin >> km2 >> m2 >> cm2 >> mm2;

   km3 = km1 + km2;
   m3 = m1 + m2;
   cm3 = cm1 + cm2;
   mm3 = mm1 + mm2;

   mmf = mm3 % MM_PAR_CM;
   cm3 += mm3 / MM_PAR_CM;
   cmf = cm3 % CM_PAR_M;
   m3 += cm3 / CM_PAR_M;
   mf = m3 % M_PAR_KM;
   km3 += m3 / M_PAR_KM;
   kmf = km3;

   std::cout << km1 << "km, " << m1 << "m, " << cm1 << "cm, " << mm1 << "mm + "
             << km2 << "km, " << m2 << "m, " << cm2 << "cm, " << mm2 << "mm font : \n"
             << kmf << "km, " << mf << "m, " << cmf << "cm, " << mmf << "mm" << std::endl;

}