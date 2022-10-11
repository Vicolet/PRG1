// calcul les racines carrées avec l'algo d'héron

#include<iostream>

#define PRECISION 1000

using namespace std;

int main() {
   int i;
   double n, x, y, z;
   cout << "\nEnter the Number: ";
   cin >> n;
   x = 1;
   while (1) {
      if (x * x > n) {
         break;
      }
      x++;
   }
   y = x - 1;
   for (i = 0; i < PRECISION; i++) {
      z = (x + y) / 2;
      if (n > (z * z)) {
         y = z;
      } else {
         x = z;
      }
   }
   cout << "\nThe Square root of " << n << " is " << z;
   return 0;
}

/*
#include <stdio.h>

void about(void);

int main(void) {

   int increment;
   float resultat;
   float acalculer;
   float an;
   float an1;
   about();
   do {
      printf("calcul des racines carrees par les approximation d'heron\n");
      printf("entrez un nombre dont on va calculer sa racine carre : \n");
      scanf("%f", &acalculer);
   } while (acalculer <= 0);
   an = acalculer;
   for (increment = 0; increment < 8; increment++) {

      an1 = (an + (acalculer) / an) / 2;
      an = an1;

   }
   resultat = an1;
   printf("resultat =  %f\n\n", resultat);
   if (getchar() == '\n')
      getchar();

   return 0;

}

void about(void) {
   printf("programmé par kjus\n");
}
*/