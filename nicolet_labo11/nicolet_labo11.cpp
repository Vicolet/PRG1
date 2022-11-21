/**
 * Nom du fichier  : nicolet_labo11.cpp
 * Auteur(s)       : Victor Nicolet <victor.nicolet@heig-vd.ch>
 * Date creation   : 2022-10-18
 * Laboratoire n°  : 11
 * Description     : 3.32 Ce programme permet de faire une approximation de π par la méthode Monte-Carlo.
 *                   3.33 Ce programme effectue plusieurs fois le problème de Monty Hall et en tire une conclusion.
 * Remarque(s)     :
 * Compilateur     : gcc version 11.2.0 (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders)
*/

#include <iostream>
#include <random>
#include <functional>

/**
 * Permet de générer un double aléatoire compris entre -1.0 et 1.0.
 */
auto gen_double01 = std::bind(std::uniform_real_distribution<double>(-1.0, 1.0), std::mt19937(1234));

/**
 * Permet de générer un int aléatoire compris entre 1 et 3.
 */
auto gen_int1_3 = std::bind(std::uniform_int_distribution<int>(1, 3), std::mt19937(987));

/**
 * Cette fonction nous permet de faire une approximation de PI en fonction d'un nombre de tir aléatoire dans un cercle
 * de rayon 1.
 * @param tir nous permet de connaitre le nombre de tir à effectuer pour l'approximation de Monte-Carlo.
 * @return l'approximation de PI.
 */
double approxPI(double tir);

/**
 * Cette fonction nous permet de connaitre le ration de gain d'une personne qui ne change jamais d'avis.
 * @param essaie nous permet de connaitre le nombre d'essaie à effectuer pour l'approximation de Monte-Carlo.
 * @return le ratio de gain si le joueur ne change jamais d'avis
 */
double nonChange(int essaie);

/**
 * Cette fonction nous permet de connaitre le ration de gain d'une personne qui change tout le temps d'avis.
 * @param essaie nous permet de connaitre le nombre d'essaie à effectuer pour l'approximation de Monte-Carlo.
 * @return le ratio de gain si le joueur change toujours d'avis
 */
double ouiChange(int essaie);

int main() {

   std::cout << "Exercice 3.32 :" << std::endl;

   double nbrTir = 51651; // donne le nombre de tirs pour l'approximation de Monte-Carlo

   std::cout << "Approximation de PI : " << approxPI(nbrTir) << std::endl;

   std::cout << "\nExercice 3.33 :" << std::endl;

   int nbrEssaie = 1000000;

   double avecChangement = ouiChange(nbrEssaie);
   double sansChangement = nonChange(nbrEssaie);

   std::cout << "Ratio de gains AVEC changement : " << avecChangement * 100 << "%" << std::endl;
   std::cout << "Ratio de gains SANS changement : " << sansChangement * 100 << "%" << std::endl;

   if (avecChangement > sansChangement) {
      std::cout << "les joueurs changeant tout le temps d'avis sont statistiquement plus gagnant" << std::endl;
   } else {
      std::cout << "les joueurs changeant jamais d'avis sont statistiquement plus gagnant" << std::endl;
   }

}

double approxPI(double tir) {
   double tirCercle = 0;
   for (int i = 0; i != tir; i++) {
      double axeX = gen_double01();
      double axeY = gen_double01();

      if (axeX * axeX + axeY * axeY <= 1) {
         ++tirCercle;
      }
   }
   double valeurPI = 4.0 * tirCercle / tir;
   return valeurPI;
}

double nonChange(int essaie) {
   int perteMeme = 0, gainMeme = 0;
   for (int i = 0; i != essaie; i++) {
      int porteGagnanteMeme = gen_int1_3();
      int porteJoueurMeme = gen_int1_3();

      if (porteGagnanteMeme == porteJoueurMeme) {
         gainMeme++;
      } else {
         perteMeme++;
      }
   }
   double ratioMeme = (double) gainMeme / essaie;
   return ratioMeme;
}

double ouiChange(int essaie) {
   int perteChange = 0, gainChange = 0;
   for (int i = 0; i != essaie; i++) {
      int porteGagnanteChange = gen_int1_3();
      int porteJoueurChange = gen_int1_3();
      if (porteGagnanteChange == porteJoueurChange) {
         perteChange++;
      } else {
         gainChange++;
      }
   }
   double ratioChange = (double) gainChange / essaie;
   return ratioChange;
}





