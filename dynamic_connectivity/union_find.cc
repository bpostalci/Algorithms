#include "union_find.h"

#include <iostream>
#include <stdexcept>

void algo::UnionFind::CheckIndexes(int p, int q) const {
  if (p >= arr_size_ || q >= arr_size_) {
    throw std::out_of_range(
        "p or q arguments cannot be greater than initial size");
  }
}

int algo::UnionFind::Root(int i) const {
  while (i != arr_[i]) {
    arr_[i] = arr_[arr_[i]];
    i = arr_[i];
  }
  return i;
}

algo::UnionFind::UnionFind(size_t n)
    : arr_(new int[n]), sizes_(new int[n]), arr_size_(n) {
  // init set
  for (size_t i = 0; i < n; i++) {
    arr_[i] = i;
    sizes_[i] = 1;
  }
}

void algo::UnionFind::Union(int p, int q) {
  CheckIndexes(p, q);
  int rootp = Root(p);
  int rootq = Root(q);
  if (rootp == rootq) return;
  if (sizes_[rootp] < sizes_[rootq]) {
    arr_[rootp] = arr_[rootq];
    sizes_[rootq] += sizes_[rootp];
  } else {
    arr_[rootq] = arr_[rootp];
    sizes_[rootp] += sizes_[rootq];
  }
}

bool algo::UnionFind::Connected(int p, int q) const {
  CheckIndexes(p, q);
  return Root(p) == Root(q);
}

void algo::UnionFind::Display() const {
  std::cout << "Tree:\n";
  for (size_t i = 0; i < arr_size_; i++) {
    std::cout << "[" << i << "]: ";
    std::cout << arr_[i] << "  ";
  }
  std::cout << std::endl;
}