#include "union_find.h"

#include <iostream>
#include <stdexcept>

algo::UnionFind::UnionFind(size_t n) : set_(new int[n]), set_size_(n) {
  // init set
  for (size_t i = 0; i < n; i++) {
    set_[i] = i;
  }
}

void algo::UnionFind::Union(int p, int q) {
  if (!Connected(p, q)) {
    set_[q] = set_[p];
  }
  for (size_t i = 0; i < set_size_; i++) {
    std::cout << "[" << i << "]: " << set_[i] << "\n";
  }
}

bool algo::UnionFind::Connected(int p, int q) {
  if (p >= set_size_ || q >= set_size_) {
    throw std::out_of_range(
        "p or q arguments cannot be greater than initial size");
  }

  return set_[p] == set_[q];
}