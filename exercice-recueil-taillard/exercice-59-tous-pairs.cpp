#include <iostream>
#include <vector>

bool vectorPairs(std::vector<int>& x);

int main() {
   std::vector<int> vec1;
   std::cout << vectorPairs(vec1) << std::endl;
   std::vector<int> vec2 {3};
   std::cout << vectorPairs(vec2) << std::endl;
   std::vector<int> vec3 {2};
   std::cout << vectorPairs(vec3) << std::endl;
   return 0;
}

bool vectorPairs(std::vector<int>& x) {
   if (x.empty())
      return true;
   for (auto i: x)
      if (i % 2 != 0)
         return false;
   return true;
}

