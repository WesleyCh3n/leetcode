#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
    cout << i << ' ';
  cout << ']' << '\n';
}

// 1, 2, 3, 4 -> 1, 2, 4, 3
// 1, 3, 4, 2 -> 1, 4, 2, 3
// 1, 4, 3, 2 -> 2, 1, 3, 4
// 4, 3, 2, 1 -> 1, 2, 3, 4
// 1, 5, 1

class Solution {
private:
public:
  void nextPermutation(vector<int> &nums) {
    for (int i = (int)nums.size() - 1; i >= 0; --i) {
      if (i == 0) {
        reverse(nums.begin(), nums.end());
        return;
      }
      if (nums[i] > nums[i - 1]) {
        if (nums[i - 1] > nums[(int)nums.size() - 1]) {
          swap(nums[i - 1], nums[i]);
          sort(nums.begin() + i, nums.end());
        } else if (nums[i - 1] < nums[(int)nums.size() - 1]) {
          swap(nums[i - 1], nums[(int)nums.size() - 1]);
          sort(nums.begin() + i, nums.end());
        } else {
          swap(nums[i - 1], nums[i]);
        }
        return;
      }
    }
  }
};

int main() {
  std::vector<int> v = {5, 4, 7, 5, 3, 2};

  Solution s;
  s.nextPermutation(v);
  print_vec(v);
  return 0;
}
