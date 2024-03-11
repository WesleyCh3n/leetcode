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
  int maxSubArray_on(vector<int> &nums) {
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
  int maxSubArray_on2(vector<int> &nums) {
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
  // std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::vector<int> v = {5, 4, -1, 7, 8};

  Solution s;
  cout << s.maxSubArray(v) << '\n';

  return 0;
}



















class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    int tmp_sum = 0;
    for (const int &num: nums) {
      if ((tmp_sum + num) > 0) {
        tmp_sum = tmp_sum + num;
        max_sum = max(max_sum, tmp_sum);
      } else {
        tmp_sum = 0;
        max_sum = max(max_sum, num);
      }
    }
    return max_sum;
  }
};
