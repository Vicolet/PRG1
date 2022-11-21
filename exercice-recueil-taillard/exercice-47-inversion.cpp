#include <iostream>
#include <string>

using namespace std;

void reverseStr(string &str) {
   int n = str.length();
   for (int i = 0; i < n / 2; i++)
      swap(str[i], str[n - i - 1]);
}

int main() {
   string str = "Victor n'est pas un mage noir";
   reverseStr(str);
   cout << str;
   return 0;
}
