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

class Solution {
private:
  void solve(vector<vector<int>> &ans, vector<int> nums, vector<int> comb,
             int size, int index) {
    ans.push_back(comb);
    if (size == 0) {
      return;
    }
    for (int i = index; i < (int)nums.size(); ++i) {
      if (i > index && nums[i] == nums[i - 1])
        continue;
      comb.push_back(nums[i]);
      solve(ans, nums, comb, size - 1, i + 1);
      comb.pop_back();
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> comb;
    sort(nums.begin(), nums.end());
    solve(ans, nums, comb, nums.size(), 0);
    return ans;
  }
};

int main() {
  std::vector<int> v = {1, 2, 2};
  Solution s;
  auto ans = s.subsetsWithDup(v);
  for (auto v : ans) {
    print_vec(v);
  }
  return 0;
}
