#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <typename T> void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
  cout << i << ' ';
  cout << ']' << '\n';
}

class Solution {
private:
  void solve(vector<vector<int>> &ans, vector<int> nums, int start) {
    if (start == (int)nums.size() - 1) {
      ans.push_back(nums);
      return;
    }
    unordered_set<int> seen;
    for (int i = start; i < (int)nums.size(); ++i) {
      if (!seen.count(nums[i])){
        swap(nums[start], nums[i]);
        solve(ans, nums, start + 1);
        swap(nums[start], nums[i]);
        seen.insert(nums[i]);
      }
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    solve(ans, nums, 0);
    return ans;
  }
};

int main() {
  std::vector<int> v = {1, 1, 2, 2};

  Solution s;
  auto ans = s.permuteUnique(v);
  for (auto v : ans) {
    print_vec(v);
  }
  return 0;
}
