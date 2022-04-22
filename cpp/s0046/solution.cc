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
  void solve(vector<vector<int>> &ans, vector<int> nums, int start) {
    if (start == (int)nums.size() - 1) {
      ans.push_back(nums);
      return;
    }
    for (int i = start; i < (int)nums.size(); ++i) {
      swap(nums[start], nums[i]);
      solve(ans, nums, start + 1);
      swap(nums[start], nums[i]);
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    solve(ans, nums, 0);
    return ans;
  }
};

int main() {
  std::vector<int> v = {1, 2, 3};

  Solution s;
  auto ans = s.permute(v);
  for (auto v : ans) {
    print_vec(v);
  }
  return 0;
}
