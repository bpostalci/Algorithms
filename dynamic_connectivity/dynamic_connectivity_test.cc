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

  union_find.Union(4, 3);
  ShouldBeConnected(union_find, 4, 3);

  union_find.Union(8, 3);
  ShouldBeConnected(union_find, 8, 3);

  union_find.Union(6, 5);
  ShouldBeConnected(union_find, 6, 5);

  union_find.Union(9, 4);
  ShouldBeConnected(union_find, 9, 4);

  union_find.Union(2, 1);
  ShouldBeConnected(union_find, 2, 1);

  union_find.Union(5, 0);
  ShouldBeConnected(union_find, 5, 0);

  union_find.Union(7, 2);
  ShouldBeConnected(union_find, 7, 2);

  union_find.Union(6, 1);
  ShouldBeConnected(union_find, 6, 1);

  union_find.Union(7, 3);
  ShouldBeConnected(union_find, 7, 3);

  union_find.Display();

  return 0;
}
