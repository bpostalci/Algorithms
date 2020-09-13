#include <iostream>

#include "union_find.h"

void ShouldBeConnected(const algo::UnionFind &union_find, int p, int q) {
  bool res = union_find.Connected(p, q);
  std::cout << p << ", " << q << " are connected (should be 1): " << res
            << " - ";
  if (res) {
    std::cout << "PASSED!\n";
  } else {
    std::cout << "FAILED!\n";
  }
}

void ShouldNotBeConnected(const algo::UnionFind &union_find, int p, int q) {
  bool res = union_find.Connected(p, q);
  std::cout << p << ", " << q << " are connected (should be 0): " << res
            << " - ";
  if (!res) {
    std::cout << "PASSED!\n";
  } else {
    std::cout << "FAILED!\n";
  }
}

// TODO: integrate with google test
int main() {
  algo::UnionFind union_find(10);

  union_find.Union(1, 2);
  ShouldBeConnected(union_find, 1, 2);

  union_find.Union(5, 9);
  ShouldBeConnected(union_find, 5, 9);

  union_find.Union(2, 9);
  ShouldBeConnected(union_find, 9, 2);
  ShouldBeConnected(union_find, 1, 9);
  ShouldBeConnected(union_find, 1, 5);

  ShouldNotBeConnected(union_find, 9, 6);

  union_find.Display();

  return 0;
}
