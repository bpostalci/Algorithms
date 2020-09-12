#include <iostream>

#include "union_find.h"

// TODO: integrate with google test
int main() {
  algo::UnionFind union_find(10);
  union_find.Union(1, 2);
  std::cout << "1, 2 are connected (should be 1): "
            << union_find.Connected(2, 1) << std::endl;

  union_find.Union(2, 9);
  std::cout << "9, 1 are connected (should be 1): "
            << union_find.Connected(9, 1) << std::endl;

  std::cout << "9, 2 are connected (should be 1): "
            << union_find.Connected(9, 2) << std::endl;

  std::cout << "9, 5 are connected (should be 0): "
            << union_find.Connected(9, 5) << std::endl;

  return 0;
}
