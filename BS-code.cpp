#include <iostream>

using namespace std;

int main() {
   char c = 'a';
   int s = 1;
   cout << "(" << c++ << ") ";
   for (int n = 1; n <= 5; ++n) {
      s = s + n;
      cout << s << " ";
   }
   // (a) 2 4 7 11 16

   s = 1;
   cout << "\n(" << c++ << ") ";
   for (int n = 1; n <= 10; cout << s << " ") {
      n = n + 2;
      s = s + n;
   }
   // (b)

   s = 1;
   int n;
   cout << "\n(" << c++ << ") ";
   for (n = 1; n <= 5; ++n) {
      s = s + n;
      n++;
   }
   cout << s << " " << n << endl;
   // (c)
}