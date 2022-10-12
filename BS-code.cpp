#include <iostream>

using namespace std;

int main() {
   char c = 'a';
   cout << "(" << c++ << ")\n";
   for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 4; ++j) {
         cout << "*";
      }
      cout << endl;
   }

   cout << "\n(" << c++ << ")\n";
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++j) {
         cout << "*";
      }
      cout << endl;
   }

   cout << "\n(" << c++ << ")\n";
   for (int i = 1; i <= 4; ++i) {
      for (int j = 1; j <= i; ++j) {
         cout << "*";
      }
      cout << endl;
   }

   cout << "\n(" << c++ << ")\n";
   for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 5; ++j) {
         if (j % 2 == 0) {
            cout << "*";
         } else {
            cout << "_";
         }
      }
      cout << endl;
   }

   cout << "\n(" << c++ << ")\n";
   for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 5; ++j) {
         if ((i + j) % 2 == 0) {
            cout << "*";
         } else {
            cout << " ";
         }
      }
      cout << endl;
   }
}