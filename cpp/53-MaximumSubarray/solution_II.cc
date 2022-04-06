#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max_val = nums[0];
    int sum = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
      sum += nums[i];
      max_val = max(sum, max_val);
      if (sum < 0)
        sum = 0;
    }
    return max_val;
  }
};

int main() {
  std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  // std::vector<int> v = {5, 4, -1, 7, 8};

  Solution s;
  cout << s.maxSubArray(v) << '\n';

  return 0;
}
