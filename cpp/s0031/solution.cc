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
// 1, 5, 1 -> 5, 1, 1
// 5,4,7,5,3,2 -> 5,5,2,3,4,7

/*
1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index,
   just reverse
2. Find the largest index l > k such that nums[k] < nums[l]
3. Swap nums[k] and nums[l]
4. Reverse the sub-array nums[k + 1:]
*/

class Solution {
private:
public:
  void nextPermutation(vector<int> &nums) {
    int n = (int)nums.size(), i;
    for (i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i+1]) {
        break;
      }
    }
    if (i < 0) {
      reverse(nums.begin(), nums.end());
    } else {
      for (int j = n - 1; j > i; j--) {
        if (nums[i] < nums[j]) {
          swap(nums[i], nums[j]);
          reverse(nums.begin() + i + 1, nums.end());
          break;
        }
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
