#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max_value = nums[0];
    for (int i = 0; i < (int)nums.size(); ++i) {
      int win_sum = 0;
      for (int j = i; j < (int)nums.size(); ++j) {
        win_sum += nums[j];
        max_value = max(win_sum, max_value);
      }
    }
    return max_value;
  }
};

int main() {
  // std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::vector<int> v = {5, 4, -1, 7, 8};

  Solution s;
  cout << s.maxSubArray(v) << '\n';

  return 0;
}
