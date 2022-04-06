#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int sum = nums[0];
    int max_val = nums[0];
    for (int i = 1; i < (int)nums.size(); ++i) {
      sum = max(nums[i], sum + nums[i]);
      max_val = max(max_val, sum);
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
