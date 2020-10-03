#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct VecHash {
  size_t operator()(const std::vector<int>& v) const {
    std::hash<int> hasher;
    size_t seed = 0;
    for (int i : v) {
      seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

using Set = unordered_set<vector<int>, VecHash>;

vector<vector<int>> ThreeSum(vector<int>& nums) {
  vector<vector<int>> res;
  Set res_set;

  // sort
  sort(nums.begin(), nums.end());

  int size = nums.size();
  for (size_t i = 0; i < size; i++) {
    unordered_set<int> s;
    for (size_t j = i + 1; j < size; j++) {
      if (i > 0 && nums[i] == nums[i - 1]) break;
      int val = -(nums[i] + nums[j]);
      if (s.find(val) != s.end()) {
        vector<int> item{nums[i], nums[j], val};
        if (res_set.find(item) == res_set.end()) {
          res.emplace_back(item);
          res_set.insert(item);
        }
      } else {
        s.insert(nums[j]);
      }
    }
  }
  return res;
}

int main() {
  vector<int> nums{0, 0, 0, 0};

  auto res = ThreeSum(nums);

  for (const auto& vec : res) {
    cout << "{";
    for (auto it : vec) {
      cout << it << " ";
    }
    cout << "}" << endl;
  }

  return 0;
}