#ifndef DYNAMIC_CONNECTIVITY_UNION_FIND_H_
#define DYNAMIC_CONNECTIVITY_UNION_FIND_H_

#include <cstdlib>

namespace algo {
class UnionFind {
 public:
  UnionFind(size_t n);
  ~UnionFind() { delete[] arr_; }

  void Union(int p, int q);
  bool Connected(int p, int q) const;
  void Display() const;

 private:
  int *arr_;
  int *sizes_;
  size_t arr_size_;

  void CheckIndexes(int p, int q) const;
  int Root(int p) const;
};
}  // namespace algo

#endif  // DYNAMIC_CONNECTIVITY_UNION_FIND_H_
