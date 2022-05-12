#include "essential.h"
#include <set>

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    if (nums.size() < 3)
      return {};
    if (nums[0] > 0)
      return {};
    vector<vector<int>> answer;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        break;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int left(i + 1), right(nums.size() - 1), sum(0);
      while (left < right) {
        sum = nums[i] + nums[left] + nums[right];
        if (sum > 0)
          right--;
        else if (sum < 0)
          left++;
        else {
          answer.push_back({nums[i], nums[left], nums[right]});
          int last_left = nums[left], last_right = nums[right];
          while (left < right && nums[left] == last_left) {
            left++;
          }
          while (left < right && nums[right] == last_right) {
            right--;
          }
        }
      }
    }

    return answer;
  }
  vector<vector<int>> threeSum_set(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    if (nums.size() < 3)
      return {};
    if (nums[0] > 0)
      return {};
    set<vector<int>> st;

    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        break;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int left(i + 1), right(nums.size() - 1), sum(0);
      while (left < right) {
        sum = nums[i] + nums[left] + nums[right];
        if (sum > 0)
          right--;
        else if (sum < 0)
          left++;
        else {
          st.insert({nums[i], nums[left], nums[right]});
          left++;
        }
      }
    }

    vector<vector<int>> answer(st.begin(), st.end());
    return answer;
  }
};

int main() {
  Solution s;
  vector<int> v = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = s.threeSum(v);
  for (auto v : result) {
    print_vec(v);
  }
  return 0;
}
