#include <iostream>

int main() {
   int i, j ,k;

   i = (k = 2) + (j = 2) && (j * 3 + k * 4);

   std::cout << i << " " << j << " " << k << " " << std::endl;

   return 0;

}