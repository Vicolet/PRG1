#include <iostream>
#include <string>

int main() {
   std::string prenom;
   int age;
   int annee_naissance;

   std::cout << "Entrer votre prenom: ";
   getline(std::cin, prenom);

   std::cout << "Entrer votre age: ";
   std::cin >> age;

   annee_naissance = 2022 - age;

   std::cout << "Bonjour " << prenom << "," << std::endl;
   std::cout << "Vous avez " << age << " ans et vous etes ne en " << annee_naissance << "." << std::endl;

   return 0;
}