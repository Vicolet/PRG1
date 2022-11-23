/**
 * Écrire une fonction qui prend un entier n non négatif en argument et qui retourne un vecteur comportant les n
 * premiers nombres premiers.
 **/

#include <iostream>
#include <vector>

std::vector<size_t> nombrePremier(size_t n);

int main() {

   size_t valeurUtilisateur = 3;
   std::vector<size_t> reponseUtilisateur = nombrePremier(valeurUtilisateur);
    std::cout << reponseUtilisateur.back() << std::endl;
}

std::vector<size_t> nombrePremier(size_t n) {
   std::vector<size_t> liste;
   if (n == 0)
      return liste;
   liste.push_back(2);
   size_t i = 3;
   while (liste.size() < n) {
      size_t j = 0;
      while ((i % liste[j] != 0) && (i / liste[j] > liste[j]))
         j++;
      if (i % liste[j] != 0)
         liste.push_back(i);
      i += 2;
   }
   return liste;
}