#ifndef DYNAMIC_CONNECTIVITY_UNION_FIND_H_
#define DYNAMIC_CONNECTIVITY_UNION_FIND_H_

#include <cstdlib>

namespace algo {
class UnionFind {
 public:
  UnionFind(size_t n);
  ~UnionFind() { delete[] set_; }

  void Union(int p, int q);
  bool Connected(int p, int q);

 private:
  int *set_;
  size_t set_size_;
};
}  // namespace algo

#endif  // DYNAMIC_CONNECTIVITY_UNION_FIND_H_
